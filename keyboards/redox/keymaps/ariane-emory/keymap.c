// -*- c-backslash-column: 150; c-backslash-max-column: 150 -*-

#include QMK_KEYBOARD_H
#include <quantum/mousekey.h>
#include <stdbool.h>

#include "src/key-aliases.h"
#include "src/secrets.h" // #define AE_PIN1 and AE_PIN2 in this file.

#define USE_ACHORDION
#include "src/achordion.h"

#ifdef RGBLIGHT_ENABLE
#  include "src/rgb_led_t_fader.h"
rgb_led_t_fader_t rgb_led_t_fader;
#endif

#if CONSOLE_ENABLE
#  include "print.h"
#endif

#include "src/util.h"
#include "src/tap_number.h"

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
  rgb_led_t_fader_init(&rgb_led_t_fader, MY_RGB_DEFAULT);
#endif
}

// ==============================================================================
// Define local macros
// ==============================================================================

#define KEYRECORD_FUN(name, t) t name(uint16_t keycode, keyrecord_t *record)
#define KEYRECORD_C_FUN(name, t) t name(uint16_t keycode, keyrecord_t const * const record)

#ifdef SEND_STRING_ENABLE
#  define MY_SS_DELAY 10
#  define SEND_STRING_WITHOUT_MODS(string) send_string_without_mods(string)
#  define SEND_STRING_WITHOUT_MODS_P(string) send_string_without_mods_P(string)
void send_string_without_mods(const char * const string) {
  const uint8_t current_mods = get_mods();
  clear_mods();
  send_keyboard_report();
  send_string_with_delay(string, MY_SS_DELAY);
  set_mods(current_mods);
}
void send_string_without_mods_P(const char * const string) {
  const uint8_t current_mods = get_mods();
  clear_mods();
  send_keyboard_report();
  send_string_with_delay_P(string, MY_SS_DELAY);
  set_mods(current_mods);
}
#else
#  define SEND_STRING_WITHOUT_MODS(str) (((void)0))
#  define SEND_STRING_WITHOUT_MODS_P(str) (((void)0))
#endif

// ==============================================================================
// Custom keycodes
// ==============================================================================

#define T(x)                 SS_TAP(x)
#define LL(_)                T(X_LEFT)
#define RR(_)                T(X_RIGHT)
#define UU(_)                T(X_UP) 
#define TB(_)                T(X_TAB)
#define CR(_)                T(X_ENT)
#define SCR_L()              SS_LCTL(T(X_F13))
#define SCR_R()              SS_LCTL(T(X_F14))
#define ESC()                T(X_ESC)
#define SPC()                T(X_SPC)
#define CLR()                SS_LGUI("a") SS_TAP(X_BSPC) CR()
#define DD()                 SS_DELAY(100)

#define GUI_CLICK(_)         SS_DOWN(X_LGUI) T(X_BTN1) SS_UP(X_LGUI)
#define GUI_CLICK_AND_TAB(_) GUI_CLICK() SS_LCTL(T(X_TAB))
#define REPEAT_SHELL_CMD(_)  SS_DOWN(X_LGUI) T(X_A) SS_UP(X_LGUI) T(X_BSPC) T(X_ENT) "11" CR() T(X_HOME)
#define TELEPORT(_)                                                                                                                                   \
  GUI_CLICK() DD() SS_LCTL(T(X_TAB)) DD() SS_LGUI("l") DD() SS_LGUI("a") DD() SS_LGUI("x") DD() SS_LGUI("w") DD()                                     \
  SS_LGUI("`") DD() SCR_R() SS_DELAY(200) T(X_BTN1) DD() ESC() DD()                                                                                   \
  SS_LGUI("l") DD() SS_LGUI("a") DD() SS_LGUI("v") DD() T(X_ENT) SS_DELAY(2500)                                                                       \
  T(X_F) DD() RR() DD() RR() DD()                                                                                                                     \
  SS_LGUI("`") DD() SCR_L()
#define TELEPORT2(_)                                                                                                                                  \
  GUI_CLICK() SS_LCTL(T(X_TAB)) SS_LGUI("l") SS_LGUI("a") SS_LGUI("x") SS_LGUI("w")                                                                   \
  SS_LGUI("`") SCR_R() SS_DELAY(200) T(X_BTN1) ESC()                                                                                                  \
  SS_LGUI("l") SS_LGUI("a") SS_LGUI("v") T(X_ENT) SS_DELAY(2500)                                                                                      \
  T(X_F) RR() RR()                                                                                                                                    \
  SS_LGUI("`") SCR_L()

#define FOR_EACH_SHIFTABLE_OR_CTRLABLE_SEND_STRING_KEYCODE(DO)                                                                                        \
  DO(SS_TELEPORT2,         (TELEPORT2()),                        (""),                                   (""))                                        \
  DO(SS_GUI_CLICK,         (GUI_CLICK()),                        (TELEPORT()),                           (GUI_CLICK_AND_TAB()))                       \
  DO(SS_GUI_CLICK_AND_TAB, (GUI_CLICK_AND_TAB()),                (""),                                   (""))                                        \
  DO(SS_FULLSCR,           (SS_DOWN(X_F24) T(X_F) SS_UP(X_F24)), (""),                                   (""))                                        \
  DO(SS_DICT,              (T(X_F24) T(X_F24)),                  (SS_DOWN(X_F24) T(X_SPC) SS_UP(X_F24)), (""))                                        \
  DO(EM_CHG_BUF,           (SS_LCTL("x") "b"),                   (""),                                   (""))                                        \
  DO(EM_KIL_BUF,           (SS_LCTL("x") SS_LCTL("k")),          (""),                                   (""))                                        \
  DO(EM_REVERT,            (SS_LCTL("x") SS_LCTL("r")),          (""),                                   (""))                                        \
  DO(EM_LASTARG,           (" " SS_LCTL("c") "."),               (""),                                   (""))                                        \
  DO(SS_BANGBANG,          (REPEAT_SHELL_CMD()),                 ("11" T(X_ENT)),                        (""))                                        \
  DO(SS_PIN1,              (AE_PIN1),                            (AE_PIN2),                              (ROUTER_PWD))                                \
  DO(SS_ARROW,             ("->"),                               (" => "),                               ("490" LL()))                                \
  DO(SS_DIR,               ("~/"),                               ("../"),                                ("./"))                                      \
  DO(SS_LBRACK,            ("9"),                                ("["),                                  ("{"))                                       \
  DO(SS_RBRACK,            ("0"),                                ("]"),                                  ("}"))                                       \
  DO(SS_BRACKS,            ("90" LL()),                          ("[" CR() CR() "]" UU() TB()),          ("{}" LL()))                                 \
  DO(SS_SMILEY,            (" :0"),                              (" :/"),                                (" >_>"))                                    \
  DO(SS_SMILEY2,           (" ;0"),                              (" :P"),                                (" :D"))                                     \
  DO(SS_AND_AND,           (" 77 "),                             (" || "),                               (" @>7! "))                                  \
  
#define enum_item(kc, str, ...)                                                     kc,
#define define_tagged_progmem_string(tag, kc, str, ...)                             static const char tag##_str_##kc[] PROGMEM = str;
#define define_nomods_progmem_string(kc, nomods_str, ...)                           define_tagged_progmem_string(nomods, kc, nomods_str, __VA_ARGS__)
#define define_shifted_progmem_string(kc, nomods_str, shifted_str, ...)             define_tagged_progmem_string(shifted, kc, shifted_str, __VA_ARGS__)
#define define_ctrled_progmem_string(kc, nomods_str, shifted_str, ctrled_str, ...)  define_tagged_progmem_string(ctrled, kc, ctrled_str, __VA_ARGS__)

FOR_EACH_SHIFTABLE_OR_CTRLABLE_SEND_STRING_KEYCODE(define_nomods_progmem_string);
FOR_EACH_SHIFTABLE_OR_CTRLABLE_SEND_STRING_KEYCODE(define_shifted_progmem_string);
FOR_EACH_SHIFTABLE_OR_CTRLABLE_SEND_STRING_KEYCODE(define_ctrled_progmem_string);

enum arianes_keycodes {
  KC_DUMMY = SAFE_RANGE,
  HOLD_GUI,
  INSERT_UPP,
  RGB_TOGGLE_NOEE,
  FOR_EACH_SHIFTABLE_OR_CTRLABLE_SEND_STRING_KEYCODE(enum_item)
};

#define shiftable_or_ctrlable_send_string_keycodes_row(kc, ...) { kc, nomods_str_##kc, shifted_str_##kc, ctrled_str_##kc },
typedef struct {
  uint16_t kc;
  const char * str;
  const char * shifted_str;
  const char * ctrled_str;
} shiftable_or_ctrlable_send_string_keycodes_t;

static const shiftable_or_ctrlable_send_string_keycodes_t shiftable_or_ctrlable_send_string_keycodes[] = {
  FOR_EACH_SHIFTABLE_OR_CTRLABLE_SEND_STRING_KEYCODE(shiftable_or_ctrlable_send_string_keycodes_row)
};

KEYRECORD_C_FUN(process_shiftable_or_ctrlable_send_string, bool) {
  for (uint8_t ix = 0; ix < ARRAY_SIZE(shiftable_or_ctrlable_send_string_keycodes); ix++) {
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

KEYRECORD_C_FUN(dynamic_macros_handler, bool) {
#ifdef   DYNAMIC_MACRO_ENABLE
  if (record->event.pressed)
    dynamic_macro_stop_recording();
#endif // DYNAMIC_MACRO_ENABLE
  return true;
}

KEYRECORD_C_FUN(insert_upp_handler, bool) {
#ifdef INSERT_UPP_ENABLED
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
#endif // INSERT_UPP_ENABLED
  return false;
}

KEYRECORD_C_FUN(disable_mouse_layer_handler, bool) {
  layer_off(6);
  return true;
};

typedef bool(*keycode_handler_fun_t)(const uint16_t keycode, const keyrecord_t * const record);

static const struct { uint16_t keycode; keycode_handler_fun_t handler; } keycode_handlers[] PROGMEM = {
  { QK_DYNAMIC_MACRO_PLAY_1, dynamic_macros_handler      },
  { QK_DYNAMIC_MACRO_PLAY_2, dynamic_macros_handler      },
  { KC_LOWER,                disable_mouse_layer_handler },
#ifdef    HOLD_GUI_ENABLED
  { HOLD_GUI,                hold_gui_handler            },
#endif    // HOLD_GUI_ENABLED
#ifdef    INSERT_UPP_ENABLED
  { INSERT_UPP,              insert_upp_handler          },
#endif // INSERT_UPP_ENABLED
};

// ==============================================================================
// Tap handling
// ==============================================================================

static const struct { uint16_t matched; uint16_t tapped; } tap_cases[] PROGMEM = {
  { RSFT_T(VD_ALL),        VD_ALL        },
  { RSFT_T(VD_RIGHT),      VD_RIGHT      },
  { LALT_T(VD_LEFT),       VD_LEFT       },
  { LCTL_T(VD_RIGHT),      VD_RIGHT      },
  { LGUI_T(LCA(KC_RIGHT)), LCA(KC_RIGHT) }, 
  { L9_OR_DASH,            KC_MINS       },
  { L12_OR_DASH,           KC_MINS       },
  { L13_OR_USCORE,         LSFT(KC_MINS) },
  { RCTL_DQUO,             KC_DQUO       },
  { LSFT_T(LSA(KC_LBRC)),  LSA(KC_LBRC)  },
  { LT11_OR_CMD_W,         LGUI(KC_W)    },
};

bool process_tap_case(uint16_t keycode, keyrecord_t const * const record)  {
  for (uint8_t ix = 0; ix < ARRAY_SIZE(tap_cases); ix++) {
    if (pgm_read_word(&tap_cases[ix].matched) == keycode) {
      if (record->tap.count && record->event.pressed) {
        tap_code16(pgm_read_word(&tap_cases[ix].tapped));
        return false;
      }
      return true;
    }
  }
  return true;
}

// ==============================================================================
// Mouse key overlap fixer function
// ==============================================================================

KEYRECORD_FUN(process_mouse_keys, bool) {
  {
    static bool m_l, m_r, m_u, m_d = false;
  
    switch (keycode) {
    case KC_MS_L:
      if (record->event.pressed) {
        m_l = true;
      } else {
        if (m_r) {
          mousekey_on(KC_MS_R);
        }
        m_l = false;
      }
      return true;
    case KC_MS_R:
      if (record->event.pressed) {
        m_r = true;
      } else {
        if (m_l) {
          mousekey_on(KC_MS_L);
        }
        m_r = false;
      }
      return true;
    case KC_MS_U:
      if (record->event.pressed) {
        m_u = true;
      } else {
        if (m_d) {
          mousekey_on(KC_MS_D);
        }
        m_u = false;
      }
      return true;
    case KC_MS_D:
      if (record->event.pressed) {
        m_d = true;
      } else {
        if (m_u) {
          mousekey_on(KC_MS_U);
        }
        m_d = false;
      }
      return true;
    default:
      return false;
    }
  }
}

// ==============================================================================
// process_record_user and co.
// ==============================================================================

static uint16_t idle_timer = 0;

KEYRECORD_FUN(process_record_user, bool) {
  idle_timer = timer_read();

#ifdef USE_ACHORDION
  if (! process_achordion(keycode, record)) return false;
#endif // USE_ACHORDION
  
  if (! process_shiftable_or_ctrlable_send_string(keycode, record)) return false;

  if (! process_tap_case(keycode, record)) return false;

  if (process_mouse_keys(keycode, record)) return true;
    
  for (uint8_t ix = 0; ix < ARRAY_SIZE(keycode_handlers); ix++) {
    if (keycode_handlers[ix].keycode == keycode) {
      keycode_handler_fun_t handler = (keycode_handler_fun_t)(pgm_read_ptr(&keycode_handlers[ix].handler));
      return (*handler)(keycode, record);
    }
  }
  
  return true;
}

// ==============================================================================
// Dynamic macro related
// ==============================================================================

static bool currently_recording_macro = false;

void dynamic_macro_record_start_user(int8_t direction) {
  currently_recording_macro = true;
}

void dynamic_macro_record_end_user(int8_t direction) {
  currently_recording_macro = false;
}

// ==============================================================================
// RGB fades
// ==============================================================================

#ifdef RGBLIGHT_ENABLE
bool rgb_led_t_fader_set_target_if_recording_macro(rgb_led_t_fader_t * const this) {
  if (! currently_recording_macro)
    return false;
  rgb_led_t_fader_set_target(this, MY_RGB_RECORDING_MACRO);
  return true;
}

void rgb_led_t_fader_set_target_by_layer(rgb_led_t_fader_t * const this) {
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

  const layer_to_rgb_t * row = &layer_to_rgbs[0];
  
  for (size_t ix = 1; ix < ARRAY_SIZE(layer_to_rgbs); ix++) {
    if (IS_LAYER_ON(layer_to_rgbs[ix].layer)) {
      row = &layer_to_rgbs[ix];
      break;
    }
  }

  rgb_led_t_fader_set_target(this, row->r, row->g, row->b);
}
#endif

// ==============================================================================
// Toggled mouse layer management
// ==============================================================================

#ifdef TOGGLED_LAYER_TIMEOUT
void manage_toggled_layer_timeout(const uint8_t layer, const uint16_t idle_time_limit_ms, const uint16_t timer)
{
  if (layer_state_is(layer) &&
      timer_elapsed(timer) >= idle_time_limit_ms)
    layer_off(layer);
}
#endif

// ==============================================================================
// Toggled mouse layer management
// ==============================================================================

void matrix_scan_user(void) {  
#ifdef USE_ACHORDION
  achordion_task();
#endif // USE_ACHORDION

#ifdef TOGGLED_LAYER_TIMEOUT
  manage_toggled_layer_timeout(TOGGLED_LAYER, TOGGLED_LAYER_TIMEOUT, idle_timer);
#endif // TOGGLED_LAYER_TIMEOUT
  
#if defined(RGBLIGHT_ENABLE) && defined(MY_RGB_LAYERS)
#  define DIM(x) (x >> DIM_RGBS)
  if (!rgb_led_t_fader_set_target_if_recording_macro(&rgb_led_t_fader))
    rgb_led_t_fader_set_target_by_layer(&rgb_led_t_fader);
  rgb_led_t_fader_step(&rgb_led_t_fader);
  rgblight_setrgb(
    DIM(rgb_led_t_fader.current.r),
    DIM(rgb_led_t_fader.current.g),
    DIM(rgb_led_t_fader.current.b));
#endif // defined(RGBLIGHT_ENABLE) && defined(MY_RGB_LAYERS)
}

// ==============================================================================
// Achordion
// ==============================================================================

static const uint16_t achordion_bilat_keys[] PROGMEM = {
  QH_S, QH_D, QH_F, QH_G, QH_H, QH_J, QH_K, QH_L, 
  MH_S, MH_D, MH_F, MH_G, MH_H, MH_J, MH_K, MH_L,
};

static const keycode_pair_t achordion_exceptions[] PROGMEM = {
  // Left GUI
  { QH_S,    KC_TAB          }, // app switcher
  { QH_S,    QB_Z            }, // undo
  { QH_S,    QT_R            }, // refresh
  { QH_S,    QT_T            }, // new tab
  { QH_S,    QB_C            }, // copy
  { QH_S,    QB_V            }, // paste

  // Left Alt
  { QH_D,    KC_TAB          }, // alt+tab
  { QH_D,    QT_W            }, // close
  { QH_D,    QT_R            }, // refresh
  { QH_D,    QH_F            }, // forwards word
  { QH_D,    QB_B            }, // backwards word
  { QH_D,    QT_T            }, // new tab
  { QH_D,    KC_ENT          }, // M-<return>

  // Left Control
  { QH_F,    QH_A            }, // beginning of line
  { QH_F,    QH_D            }, // delete forwards char
  { QH_F,    QT_E            }, // end of line
  { QH_F,    QT_T            }, // new tab
  { QH_F,    QT_W            }, // close
  { QH_F,    QH_S            }, // i-search
  { QH_F,    KC_ENT          }, // C-<return>

  // Left shift
  { QH_G,    KC_SPC },

  // Right  shift
  { QH_H,    KC_SPC },
  
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
};

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

  // If it isn't a home row mod/shift, process normally.
  if (!array_contains_keycode_P(tap_hold_keycode, achordion_bilat_keys, ARRAY_SIZE(achordion_bilat_keys)))
    return true;
  
  // Exceptionally consider the following chords as holds, even though they
  // are on the same hand.
  if (array_contains_keycode_pair_P((keycode_pair_t){ tap_hold_keycode, other_keycode }, achordion_exceptions, ARRAY_SIZE(achordion_exceptions)))
    return true;
   
  return achordion_opposite_hands(tap_hold_record, other_record);
}

bool achordion_eager_mod(uint8_t mod) {
  return true;  // Eagerly apply all mods.
}

// ==============================================================================
// Mod-tap interrupt
// ==============================================================================

static const uint16_t hold_on_other_keypress_keys[] PROGMEM = {
  LCTL_ESC,
  RCTL_DQUO,
  LSFT_T(KC_MINS),
  RSFT_T(KC_MINS),
};

KEYRECORD_FUN(get_hold_on_other_key_press, bool) {
  return ((keycode >= QK_MOD_TAP) &&
          (keycode <= QK_MOD_TAP_MAX) &&
          array_contains_keycode_P(keycode, hold_on_other_keypress_keys, ARRAY_SIZE(hold_on_other_keypress_keys)));
}

static const uint16_t layer0_permissive_hold_keys[] PROGMEM = {
  LALT_OR_SPC,
  LGUI_OR_BSPC,
  QH_A, QH_S, QH_D, QH_F,
  QH_J, QH_K, QH_L, QH_QUOT,  
};

static const uint16_t layer1_permissive_hold_keys[] PROGMEM = {
  LALT_OR_SPC,
  LGUI_OR_BSPC,
  CH_A, CH_R, CH_S, CH_T,
  CH_N, CH_E, CH_I, CH_QUOT,
};

KEYRECORD_FUN(get_permissive_hold, bool) {
  if ((IS_LAYER_ON(0) && array_contains_keycode_P(keycode, layer0_permissive_hold_keys, ARRAY_SIZE(layer0_permissive_hold_keys))) ||
      (IS_LAYER_ON(1) && array_contains_keycode_P(keycode, layer1_permissive_hold_keys, ARRAY_SIZE(layer1_permissive_hold_keys))))
    return false; // Do not select the hold action when another key is tapped.
  return true; // Select the hold action when another key is tapped.
}

uint16_t keycode_config(uint16_t keycode) {
  return keycode;
}

// ==============================================================================
// Leader key
// ==============================================================================

#define END()      SS_TAP(X_END)
#define CLR()      SS_LGUI("a") SS_TAP(X_BSPC) CR()
#define CLR_LINE() END() SS_LCTL("e") SS_LCTL(SS_TAP(X_SPC)) SS_LCTL("a") SS_TAP(X_BSPC)

#ifdef LEADER_ENABLE
void leader_end_user(void) {
  if (leader_sequence_one_key(NUM_1)) {
      SEND_STRING_WITHOUT_MODS_P(PSTR(CLR() "11" CR()));
  }
  else if (leader_sequence_one_key(KC_0)) {
    SEND_STRING_WITHOUT_MODS_P(PSTR(REPEAT_SHELL_CMD(_)));
  }
  else if (leader_sequence_one_key(KC_Q)) {
    SEND_STRING_WITHOUT_MODS_P(PSTR(CLR() "cdkm; qmkc" CR()));
  }
  else if (leader_sequence_two_keys(KC_Q, KC_W)) {
    SEND_STRING_WITHOUT_MODS_P(PSTR(CLR() "cdkm; qmkupd" CR()));
  }
  else if (leader_sequence_one_key(KC_S)) {
    SEND_STRING_WITHOUT_MODS_P(PSTR(CLR_LINE() "shove" CR()));
  }
  else if (leader_sequence_two_keys(KC_C, KC_D)) {
    SEND_STRING_WITHOUT_MODS_P(PSTR("D:" CR() AE_CD CR()));
  }
  else if (leader_sequence_two_keys(KC_G, KC_D)) {
    SEND_STRING_WITHOUT_MODS_P(PSTR("git diff " CR()));
  }
  else if (leader_sequence_two_keys(KC_G, KC_S)) {
    SEND_STRING_WITHOUT_MODS_P(PSTR("git status " CR()));
  }
  else if (leader_sequence_two_keys(KC_G, KC_C)) {
    SEND_STRING_WITHOUT_MODS_P(PSTR("git commit "));
  }
  else if (leader_sequence_three_keys(KC_G, KC_C, KC_M)) {
    SEND_STRING_WITHOUT_MODS_P(PSTR("git commit -m \"\"" LL()));
  }
  else if (leader_sequence_four_keys(KC_G, KC_C, KC_A, KC_M)) {
    SEND_STRING_WITHOUT_MODS_P(PSTR("git commit -a -m \"\"" LL()));
  }
  else if (leader_sequence_two_keys(KC_G, KC_H)) {
    SEND_STRING_WITHOUT_MODS_P(PSTR("git checkout "));
  }
  else if (leader_sequence_two_keys(KC_G, KC_M)) {
    SEND_STRING_WITHOUT_MODS_P(PSTR("git merge "));
  }
  else if (leader_sequence_two_keys(KC_G, KC_P)) {
    SEND_STRING_WITHOUT_MODS_P(PSTR("git push " CR()));
  }
  else if (leader_sequence_two_keys(KC_G, KC_U)) {
    SEND_STRING_WITHOUT_MODS_P(PSTR("git pull " CR()));
  }
  else if (leader_sequence_three_keys(KC_G, KC_R, KC_H)) {
    SEND_STRING_WITHOUT_MODS_P(PSTR("git reset --hard " CR()));
  }
  else if (leader_sequence_two_keys(KC_G, KC_R)) {
    SEND_STRING_WITHOUT_MODS_P(PSTR("git reset "));
  }
  else if (leader_sequence_one_key(0)) {
    tap_code16(LCA(KC_X));
  }
}
#endif // LEADER_ENABLE

// ==============================================================================
// Include combos 
// ==============================================================================

#include "src/combos.inc"

// ==============================================================================
// Include keymap
// ==============================================================================

#include "keymap.inc"
