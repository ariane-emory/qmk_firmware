// -*- c-backslash-column: 128; c-backslash-max-column: 128 -*-

#include QMK_KEYBOARD_H

#include <stdbool.h>

#include "key_aliases.h"
#include "secrets.h" // #define AE_PIN1 and AE_PIN2 in this file.

#if defined(HOME_ROW_MODS) || defined(HOME_SHIFT) || defined(BOTTOM_SHIFT)
#  define USE_ACHORDION
#  include "features/achordion.h"
#endif

#ifdef RGBLIGHT_ENABLE
#  include "features/rgb_fader.h"
rgb_fader_t rgb_fader;
#endif

#if CONSOLE_ENABLE
#  include "print.h"
#endif

// ==============================================================================
// Init
// ==============================================================================

void keyboard_post_init_user(void) {
#if CONSOLE_ENABLE
  debug_enable   = false;
  debug_matrix   = false;
  debug_keyboard = false;
  debug_mouse    = false;
#endif

#ifdef RGBLIGHT_ENABLE
  rgblight_enable_noeeprom();
  rgb_fader_init(&rgb_fader, MY_RGB_DEFAULT);
#endif
}

// ==============================================================================
// Define local macros
// ==============================================================================

#define KEYRECORD_FUN(name, t) t name(uint16_t keycode, keyrecord_t *record)

#ifdef SEND_STRING_ENABLE
#  define MY_SS_DELAY 25
void send_string_without_mods_P(const char * const string) {
  const uint8_t current_mods = get_mods();
  clear_mods();
  send_keyboard_report();
  send_string_with_delay_P(string, MY_SS_DELAY);
  set_mods(current_mods);
}
#  define SEND_STRING_WITHOUT_MODS_P(string) send_string_without_mods_P(string)
void send_string_without_mods(const char * const string) {
  const uint8_t current_mods = get_mods();
  clear_mods();
  send_keyboard_report();
  send_string_with_delay(string, MY_SS_DELAY);
  set_mods(current_mods);
}
#  define SEND_STRING_WITHOUT_MODS(string) send_string_without_mods(string)
#else
#  define SEND_STRING_WITHOUT_MODS_P(str) (((void)0))
#  define SEND_STRING_WITHOUT_MODS(str) (((void)0))
#endif

// ==============================================================================
// Custom keycodes
// ==============================================================================

uint32_t release_lgui_callback(uint32_t trigger_time, void *cb_arg) {
  unregister_code(KC_LGUI);
  return 0;
}

static uint16_t idle_timer = 0;

#define LL SS_TAP(X_LEFT)
#define UU SS_TAP(X_UP)
#define TB SS_TAP(X_TAB)
#define CR SS_TAP(X_ENT)

#define REPEAT_SHELL_CMD (SS_DOWN(X_LGUI)SS_TAP(X_A)SS_UP(X_LGUI)SS_TAP(X_BSPC)SS_TAP(X_ENT)"11"SS_TAP(X_ENT))

#define FOR_EACH_SHIFTABLE_OR_CTRLABLE_SEND_STRING_KEYCODE(DO)                                                                  \
  DO(SS_DICT,      (SS_TAP(X_F24)SS_TAP(X_F24)),            (SS_DOWN(X_F24)SS_DELAY(50)SS_TAP(X_SPC)SS_UP(X_F24)),   (""))      \
  DO(EM_CHG_BUF,   (SS_LCTL("x")SS_DELAY(50)"b"),           (""),                                                    (""))      \
  DO(EM_KIL_BUF,   (SS_LCTL("x")SS_DELAY(50)SS_LCTL("k")),  (""),                                                    (""))      \
  DO(EM_REVERT,    (SS_LCTL("x")SS_DELAY(50)SS_LCTL("r")),  (""),                                                    (""))      \
  DO(EM_LASTARG,   (" "SS_LCTL("c")SS_DELAY(50)"."),        (""),                                                    (""))      \
  DO(SS_BANGBANG,  ("11"SS_TAP(X_ENT)),                     REPEAT_SHELL_CMD,                                        (""))      \
  DO(SS_PIN1,      (AE_PIN1),                               (AE_PIN2),                                               (""))      \
  DO(SS_ARROW,     ("->"),                                  ("490"LL), /* $() */                                     ("``"LL))  \
  DO(SS_DIR,       ("~/"),                                  ("../"),                                                 ("./"))    \
  DO(SS_LBRACK,    ("9"),                                   ("["),                                                   ("{"))     \
  DO(SS_RBRACK,    ("0"),                                   ("]"),                                                   ("}"))     \
  DO(SS_BRACKS,    ("90" LL),                               ("[" CR CR "]" UU TB),                                   ("{}" LL))

#define enum_item(kc, str, ...)                                                  kc,
#define define_tagged_progmem_string(tag, kc, str, ...)                          static const char tag##_str_##kc[] PROGMEM = str;
#define define_nomods_progmem_string(kc, nomods_str, ...)                        define_tagged_progmem_string(nomods, kc, nomods_str, __VA_ARGS__)
#define define_shifted_progmem_string(kc, nomods_str, shifted_str, ...)            define_tagged_progmem_string(shifted, kc, shifted_str, __VA_ARGS__)
#define define_ctrled_progmem_string(kc, nomods_str, shifted_str, ctrled_str, ...)  define_tagged_progmem_string(ctrled, kc, ctrled_str, __VA_ARGS__)

enum arianes_keycodes {
  KC_DUMMY = SAFE_RANGE,
  HOLD_GUI,
  INSERT_UPP,
  RGB_TOGGLE_NOEE,
  SHOLD_GUI,
  VS_CLOSE,
  VS_FORMAT_DOC,
  FOR_EACH_SHIFTABLE_OR_CTRLABLE_SEND_STRING_KEYCODE(enum_item)
};

FOR_EACH_SHIFTABLE_OR_CTRLABLE_SEND_STRING_KEYCODE(define_nomods_progmem_string);
FOR_EACH_SHIFTABLE_OR_CTRLABLE_SEND_STRING_KEYCODE(define_shifted_progmem_string);
FOR_EACH_SHIFTABLE_OR_CTRLABLE_SEND_STRING_KEYCODE(define_ctrled_progmem_string);

#ifdef USE_SEND_STRING_KEYCODES_TABLE
#  define shiftable_or_ctrlable_send_string_keycodes_row(kc, ...) { kc, nomods_str_##kc, shifted_str_##kc, ctrled_str_##kc },
typedef struct {
  uint16_t kc;
  const char * str;
  const char * shifted_str;
  const char * ctrled_str;
} shiftable_or_ctrlable_send_string_keycodes_t;

static const shiftable_or_ctrlable_send_string_keycodes_t shiftable_or_ctrlable_send_string_keycodes[] = {
  FOR_EACH_SHIFTABLE_OR_CTRLABLE_SEND_STRING_KEYCODE(shiftable_or_ctrlable_send_string_keycodes_row)
};

static const uint8_t shiftable_or_ctrlable_send_string_keycodes_length = ARRAY_SIZE(shiftable_or_ctrlable_send_string_keycodes);

bool process_shiftable_or_ctrlable_send_string(
  const uint16_t keycode,
  const keyrecord_t * const record) {
  for (uint8_t ix = 0; ix < shiftable_or_ctrlable_send_string_keycodes_length; ix++) {
    if (shiftable_or_ctrlable_send_string_keycodes[ix].kc == keycode) {      
      if (record->event.pressed) {
        if (
          (pgm_read_byte(shiftable_or_ctrlable_send_string_keycodes[ix].shifted_str) != 0) &&
          (get_mods() & MOD_MASK_SHIFT)) {
          SEND_STRING_WITHOUT_MODS_P(shiftable_or_ctrlable_send_string_keycodes[ix].shifted_str);
        }
        else if (
          (pgm_read_byte(shiftable_or_ctrlable_send_string_keycodes[ix].ctrled_str) != 0) &&
          (get_mods() & MOD_MASK_CTRL)) {
          SEND_STRING_WITHOUT_MODS_P(shiftable_or_ctrlable_send_string_keycodes[ix].ctrled_str);
        }
        else {
          SEND_STRING_WITHOUT_MODS_P(shiftable_or_ctrlable_send_string_keycodes[ix].str);
        }
      }
      return false;
    }
  }
  return true;
}
#endif // USE_SEND_STRING_KEYCODES_TABLE

#ifdef USE_TAP_CASE_TABLE
typedef struct {
  uint16_t match_keycode;
  uint16_t tap_keycode;
} tap_case_t;

static const tap_case_t tap_cases[] = {
  { RSFT_T(KC_DUMMY), VD_ALL        },
  { LT(9,KC_MINS),    LSFT(KC_MINS) },
  { RCTL_DQUO,        KC_DQUO       },
};

static const size_t tap_cases_length = ARRAY_SIZE(tap_cases);

bool process_tap_case(
  const uint16_t keycode,
  const keyrecord_t * const record) {
  for (uint8_t ix = 0; ix < tap_cases_length; ix++) {
    if (tap_cases[ix].match_keycode == keycode) {
      if (record->tap.count && record->event.pressed) {
        tap_code16(tap_cases[ix].tap_keycode);
        return false;
      }
      return true;
    }
  }
  return true;
}
#endif // USE_TAP_CASE_TABLE
 
void tap_number(uint16_t num) {
  static const uint8_t max_digits = 5;
  const uint8_t current_mods = get_mods();
  clear_mods();
  send_keyboard_report();
  uint16_t buf[max_digits];
  uint8_t  ix = max_digits - 1;

  while (num) {
    const uint8_t modulo = num % 10;    
    num -= modulo;
    num /= 10;
    buf[ix] = (modulo == KC_0) ? KC_0 : KC_1 + modulo - 1;
    if (num) ix--;
  }
  
  for (;ix < max_digits; ix++)
    tap_code16(LSFT(buf[ix]));
  
  set_mods(current_mods);
}

KEYRECORD_FUN(process_record_user, bool) {
  idle_timer = timer_read();

  if (false
#ifdef USE_ACHORDION
      || (! process_achordion(keycode, record))
#endif // USE_ACHORDION
#ifdef USE_SEND_STRING_KEYCODES_TABLE
      || (! process_shiftable_or_ctrlable_send_string(keycode, record))
#endif // USE_SEND_STRING_KEYCODES_TABLE
#ifdef USE_TAP_CASE_TABLE
      || (! process_tap_case(keycode, record))
#endif // USE_TAP_CASE_TABLE
      )
    return false;
  
  switch (keycode) {
  case VS_CLOSE:
    if (record->event.pressed)
      tap_number(128);
    return false;
  case QK_DYNAMIC_MACRO_PLAY_1:
  case QK_DYNAMIC_MACRO_PLAY_2:
    if (record->event.pressed)
      dynamic_macro_stop_recording();
    return true;
  case HOLD_GUI:
    if (record->event.pressed)
    {
      register_code(KC_LGUI);
    }
    else {
      static deferred_token token = INVALID_DEFERRED_TOKEN;
      if (token != INVALID_DEFERRED_TOKEN) {
        cancel_deferred_exec(token);
        token = INVALID_DEFERRED_TOKEN;
      }
      token = defer_exec(400, release_lgui_callback, NULL);
    }
    return false;                                                                 
  case QK_TRI_LAYER_LOWER:
    layer_off(6);
    return true;

#ifdef INSERT_UPP_ENABLED
  case INSERT_UPP:
    if (record->event.pressed) {
      for (uint8_t ix = 0; ix < 6; ix++) {
        static const uint16_t hex_keycodes[] = {
          KC_2, KC_3, KC_4, KC_5, KC_6, KC_7,
          KC_8, KC_9, KC_A, KC_B, QB_C, 
        };
        const uint8_t roll = ((rand() % 6) + 1) + ((rand() % 6) + 1);
        const uint16_t hex_kc = LSFT(hex_keycodes[roll - 2]);
        tap_code16(hex_kc);
      }
      tap_code(KC_ENTER);
    }
    return false;
#endif // INSERT_UPP_ENABLED

#ifndef USE_SEND_STRING_KEYCODES_TABLE
#  define kc_tap_case_shiftable_or_ctrlable_send_string(kc, str, shifted_str, ctrled_str)                                       \
    case kc:                                                                                                                    \
      if (record->event.pressed) {                                                                                              \
        if (                                                                                                                    \
          (shifted_str_##kc[0] != '\0') &&                                                                                      \
          (get_mods() & MOD_MASK_CTRL)) {                                                                                       \
          SEND_STRING_WITHOUT_MODS_P(shifted_str_##kc);                                                                         \
        } else if (                                                                                                             \
          (ctrled_str_##kc[0] != '\0') &&                                                                                       \
          (get_mods() & MOD_MASK_ALT)) {                                                                                        \
          SEND_STRING_WITHOUT_MODS_P(ctrled_str_##kc);                                                                          \
        } else {                                                                                                                \
          SEND_STRING_WITHOUT_MODS_P(str_##kc);                                                                                 \
        }                                                                                                                       \
      }                                                                                                                         \
      return false;
    FOR_EACH_SHIFTABLE_OR_CTRLABLE_SEND_STRING_KEYCODE(kc_tap_case_shiftable_or_ctrlable_send_string)
#  define kc_tap_case_send_string(kc, str)                                                                                      \
      case kc:                                                                                                                  \
        if (record->event.pressed)                                                                                              \
          SEND_STRING_WITHOUT_MODS_P(str_##kc);                                                                                 \
        return false;
      FOR_EACH_SEND_STRING_KEYCODE(kc_tap_case_send_string)
#endif // ! USE_SEND_STRING_KEYCODES_TABLE

#ifndef USE_TAP_CASE_TABLE
  case LT(9,KC_MINS):
    if (record->tap.count && record->event.pressed) {
      tap_code16(LSFT(KC_MINS));
      return false;
    }
    return true;
  case RSFT_T(KC_DUMMY):
    if (record->tap.count && record->event.pressed) {
      tap_code16(VD_ALL);
      return false;
    }
    return true;
  case RCTL_DQUO:
    // KC_DQUO is not "basic" so we have to tap it manually
    if (record->tap.count && record->event.pressed) {
      tap_code16(KC_DQUO);
      return false;
    }
    return true;
#endif
    
  default:
    return true;
  }
}

static bool currently_recording_macro = false;

void dynamic_macro_record_start_user(int8_t direction) {
  currently_recording_macro = true;
}

void dynamic_macro_record_end_user(int8_t direction) {
  currently_recording_macro = false;
}

#ifdef RGBLIGHT_ENABLE
bool rgb_fader_set_target_if_recording_macro(rgb_fader_t * const this) {
  if (! currently_recording_macro)
    return false;
  rgb_fader_set_target(this, MY_RGB_RECORDING_MACRO);
  return true;
}

void rgb_fader_set_target_by_layer(rgb_fader_t * const this) {
  typedef struct {
    uint8_t layer;
    uint8_t r;
    uint8_t g;
    uint8_t b;
  } layer_to_rgb_t;
  
  static const layer_to_rgb_t layer_to_rgbs[] = {
    {TOGGLED_LAYER,          MY_RGB_DEFAULT          },
    {TRI_LAYER_ADJUST_LAYER, MY_RGB_ADJUST_LAYER_ON  },
    {TRI_LAYER_UPPER_LAYER,  MY_RGB_UPPER_LAYER_ON   },
    {TRI_LAYER_LOWER_LAYER,  MY_RGB_LOWER_LAYER_ON   },
    {TOGGLED_LAYER,          MY_RGB_TOGGLED_LAYER_ON },
  };

  static const size_t layer_to_rgbs_length = ARRAY_SIZE(layer_to_rgbs);

  const layer_to_rgb_t *row = &layer_to_rgbs[0];
  
  for (size_t ix = 1; ix < layer_to_rgbs_length; ix++) {
    if (IS_LAYER_ON(layer_to_rgbs[ix].layer)) {
      row = &layer_to_rgbs[ix];
      break;
    }
  }

  rgb_fader_set_target(&rgb_fader, row->r, row->g, row->b);
}
#endif

#ifdef TOGGLED_LAYER_TIMEOUT
void manage_toggled_layer_timeout(uint8_t layer, uint16_t idle_time_limit_ms, uint16_t timer)
{
  if (layer_state_is(layer) &&
      timer_elapsed(timer) >= idle_time_limit_ms)
    layer_off(layer);
}                                                                             
#endif

void matrix_scan_user(void) {
#ifdef USE_ACHORDION
  achordion_task();
#endif

#ifdef TOGGLED_LAYER_TIMEOUT
  manage_toggled_layer_timeout(TOGGLED_LAYER, TOGGLED_LAYER_TIMEOUT, idle_timer);
#endif
  
#if defined(RGBLIGHT_ENABLE) && defined(MY_RGB_LAYERS)
  if (!rgb_fader_set_target_if_recording_macro(&rgb_fader))
    rgb_fader_set_target_by_layer(&rgb_fader);
  rgb_fader_step(&rgb_fader);
  rgblight_setrgb(rgb_fader.current.r, rgb_fader.current.g, rgb_fader.current.b);
#endif
}

// ==============================================================================
// Achordion
// ==============================================================================

#ifdef USE_ACHORDION
bool is_achordion_bilat_key(uint16_t keycode) {
  typedef uint16_t achordion_bilat_key_t;

  static const achordion_bilat_key_t achordion_bilat_keys[] = {
#  ifdef HOME_SHIFT
    QH_A, QH_QUOT,
#  endif // HOME_SHIFT
#  ifdef BOTTOM_SHIFT
    QB_Z, QB_SLSH,
#  endif // BOTTOM_SHIFT
#  ifdef HOME_ROW_MODS
    QH_S, QH_D, QH_F, QH_J, QH_K, QH_L,
#  endif // HOME_ROW_MODS
    KC_NO
  };

  static const uint8_t achordion_bilat_keys_length = ARRAY_SIZE(achordion_bilat_keys);

  for (uint8_t ix = 0; ix < achordion_bilat_keys_length; ix++) {
    if (achordion_bilat_keys[ix] == keycode) {
      return true;
    }
  }

  return false;
}

bool is_achordion_exception(uint16_t tap_hold_keycode, uint16_t other_keycode) {
  typedef struct {
    uint16_t tap_hold_keycode;
    uint16_t other_keycode;
  } achordion_exception_t;

  static const achordion_exception_t achordion_exceptions[] PROGMEM = {
    // Both Shifts
#  ifdef HOME_SHIFT
    { QH_A,    LSFT_T(KC_MINS) }, // underscore
    { QH_QUOT, RSFT_T(KC_MINS) }, // underscore
#  endif // HOME_SHIFT
#  ifdef BOTTOM_SHIFT
    { QH_QUOT, KC_BSLS         }, // pipe
    { QB_Z,    LSFT_T(KC_MINS) }, // underscore
    { QB_SLSH, RSFT_T(KC_MINS) }, // underscore
#  endif // BOTTOM_SHIFT
#  ifdef HOME_ROW_MODS
    /* // Left GUI */
    { QH_S,    KC_TAB          }, // app switcher
    { QH_S,    QB_Z            }, // undo
    { QH_S,    QT_R            }, // refresh
    { QH_S,    QT_T            }, // new tab
    { QH_S,    QB_C            }, // copy
    { QH_S,    QB_V            }, // paste
    /* // Left Alt */
    { QH_D,    KC_TAB          }, // alt+tab
    /* { QH_D,    SS_ARROW        }, // */
    /* { QH_D,    SS_DIR          }, // */
    /* { QH_D,    SS_LBRACK       }, // */
    /* { QH_D,    SS_RBRACK       }, // */
    /* { QH_D,    SS_BRACKS       }, // */
    { QH_D,    QT_W            }, // close
    { QH_D,    QT_R            }, // refresh
    { QH_D,    QH_F            }, // forwards word
    { QH_D,    QB_B            }, // backwards word
    { QH_D,    QT_T            }, // new tab
    // Left Control
    /* { QH_F,    SS_ARROW        }, // */
    /* { QH_F,    SS_DIR          }, // */
    /* { QH_F,    SS_LBRACK       }, // */
    /* { QH_F,    SS_RBRACK       }, // */
    /* { QH_F,    SS_BRACKS       }, // */
    { QH_F,    QH_A            }, // beginning of line
    { QH_F,    QH_D            }, // delete forwards char
    { QH_F,    QT_E            }, // end of line
    { QH_F,    QT_T            }, // new tab
    { QH_F,    QT_W            }, // close
    { QH_F,    QH_S            }, // i-search
    // Right Control
    { QH_J,    QH_H            }, // backspace
    { QH_J,    QH_K            }, // kill line
    { QH_J,    QH_L            }, // recenter / address bar
    { QH_J,    QT_Y            }, // yank
    { QH_J,    QB_N            }, // next line
    { QH_J,    QT_P            }, // prev line
    // Right Alt
    { QH_K,    QH_L            }, // address bar?
    { QH_K,    QT_P            }, // prev command
    { QH_K,    KC_BSLS         }, // ???
    { QH_K,    QB_N            }, // next command
    // Right GUI
    { QH_L,    QH_K            }, // ???
    { QH_L,    KC_BSLS         }, // ???
#  endif // HOME_ROW_MODS
    // Dummy
    { KC_NO,   KC_NO           }, // dummy
  };

  static const uint8_t achordion_exceptions_length = ARRAY_SIZE(achordion_exceptions);

// Exceptionally consider the following chords as holds, even though they
// are on the same hand.

  for (uint8_t ix = 0; ix < achordion_exceptions_length; ix++) {
    if (pgm_read_word(&achordion_exceptions[ix].tap_hold_keycode) == tap_hold_keycode &&
        pgm_read_word(&achordion_exceptions[ix].other_keycode)    == other_keycode)
      return true;
  }

  return false;
}

bool achordion_chord(
  uint16_t      tap_hold_keycode,
  keyrecord_t * tap_hold_record,
  uint16_t      other_keycode,
  keyrecord_t * other_record) {
  // custom keycodes are not subject to achordion:
  if (other_keycode >= SAFE_RANGE)
    return true;

  // Allow same-hand holds when the other key is in the rows below the
  // alphas. I need the `% (MATRIX_ROWS / 2)` because my keyboard is split.
  if (other_record->event.key.row % (MATRIX_ROWS / 2) >= 4)
    return true;

  if (! is_achordion_bilat_key(tap_hold_keycode))
    return true;

  if (is_achordion_exception(tap_hold_keycode, other_keycode))
    return true;
   
  return achordion_opposite_hands(tap_hold_record, other_record);
}

bool achordion_eager_mod(uint8_t mod) {
  return true;  // Eagerly apply all mods.
}
#endif

// ==============================================================================
// Mod tap interrupt
// ==============================================================================

KEYRECORD_FUN(get_hold_on_other_key_press, bool) {
  switch (keycode) {
  case QK_MOD_TAP ... QK_MOD_TAP_MAX:
    if (false
        || keycode == LCTL_T(KC_ESC) 
        || keycode == RCTL_T(KC_DQUO)
        || keycode == LSFT_T(KC_MINS)
        || keycode == RSFT_T(KC_MINS)) {
      return true;
    }
    else {
      return false;
    }
  default:
    return false;
  }
}

KEYRECORD_FUN(get_permissive_hold, bool) {
  if (IS_LAYER_ON(0)) {
    switch (keycode) {
    case MT(MOD_LALT,KC_SPC):
#ifdef HOME_ROW_MODS
    case QH_A: case QH_S: case QH_D: case QH_F:
      // case QH_G: case QH_H: // not mods currently
    case QH_J: case QH_K: case QH_L: case QH_QUOT:
#endif
#ifdef BOTTOM_ROW_MODS
    case QB_Z: case QB_X: case QB_C: case QB_V:
      // case QB_B: case QB_N: // not mods currently
    case QB_M: case QB_COMM: case QB_DOT: case QB_SLSH:
#endif
      return false; // Do not select the hold action when another key is tapped.
    }
  }

  if (IS_LAYER_ON(1)) {
    switch (keycode) {
    case MT(MOD_LALT,KC_SPC):
    case MT(MOD_RGUI,KC_SPC):
#ifdef HOME_ROW_MODS
    case CH_A: case CH_R: case CH_S: case CH_T:
      // case CH_D: case CH_H: // not mods currently
    case CH_N: case CH_E: case CH_I: case CH_QUOT:
#endif
#ifdef BOTTOM_ROW_MODS
    case CB_Z: case CB_X: case CB_C: case CB_V:
      // case CB_B: case CB_K: // not mods currently
    case CB_M: case CB_COMM: case CB_DOT: case CB_SLSH:
#endif
      // Do not select the hold action when another key is tapped.
      return false;
    }
  }    
  return true; // Select the hold action when another key is tapped.
}

uint16_t keycode_config(uint16_t keycode) {
  return keycode;
}

// ==============================================================================
// Include combos 
// ==============================================================================

#include "combos.inc"

// ==============================================================================
// Include keymap
// ==============================================================================

#include "keymap.inc"
