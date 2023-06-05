// -*- c-backslash-column: 120; c-backslash-max-column: 120; -*-

#include QMK_KEYBOARD_H

#include <stdbool.h>

#if defined(HOME_ROW_MODS) || defined(BOTTOM_ROW_MODS)
#  define USE_ACHORDION
#  include "features/achordion.h"
#endif

#include "key_aliases.h"
#ifdef RGBLIGHT_ENABLE
#  include "features/rgb_fader.h"
rgb_fader_t rgb_fader;
#endif

#include "secrets.h" // #define AE_PIN1 and AE_PIN2 in this file:

// ==============================================================================
// Init
// ==============================================================================

void keyboard_post_init_user(void) {
#if CONSOLE_ENABLE
  debug_enable   = true;
  debug_matrix   = true;
  debug_keyboard = true;
  debug_mouse    = true;
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
#define SEND_STRING_WITHOUT_MODS(string) send_string_without_mods(string)
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

// #define FOR_EACH_SEND_STRING_KEYCODE(DO)                                                          
// #define FOR_EACH_CTRLABLE_SEND_STRING_KEYCODE(DO)

#define LL SS_TAP(X_LEFT)
#define UU SS_TAP(X_UP)
#define TB SS_TAP(X_TAB)
#define CR SS_TAP(X_ENT)

#define FOR_EACH_CTRLABLE_OR_ALTABLE_SEND_STRING_KEYCODE(DO)                                                            \
  DO(SS_SIRI,           (SS_DOWN(X_F24)SS_DELAY(50)SS_TAP(X_SPC)SS_UP(X_F24)),  (""),                   (""))           \
  DO(SS_DICT,           (SS_TAP(X_F24)SS_TAP(X_F24)),                           (""),                   (""))           \
  DO(EM_LASTARG,        (" "SS_LCTL("c")SS_DELAY(50)"."),                       (""),                   (""))           \
  DO(EM_CHG_BUF,        (SS_LCTL("x")SS_DELAY(50)"b"),                          (""),                   (""))           \
  DO(EM_REVERT,         (SS_LCTL("x")SS_DELAY(50)SS_LCTL("r")),                 (""),                   (""))           \
  DO(SS_BANGBANG,       ("11"SS_TAP(X_ENT)),                                    (""),                   (""))           \
  DO(SS_PIN1,           (AE_PIN1),                                              (AE_PIN2),              (""))           \
  DO(SS_ARROW,          ("->"),                                                 ("490"LL),              ("``"LL))       \
  DO(SS_DIR,            ("~/"),                                                 ("../"),                ("./"))         \
  DO(SS_LBRACK,         ("9"),                                                  ("{"),                  ("["))          \
  DO(SS_RBRACK,         ("0"),                                                  ("}"),                  ("]"))          \
  DO(SS_BRACKS,         ("90" LL),                                              ("{" CR CR "}" UU TB),  ("[]" LL))

#define enum_item(kc, str, ...) kc,

#define define_progmem_string(kc, str, ...)                                                                             \
  static const char nomod_str_##kc[] PROGMEM = str;
#define define_progmem_ctrled_string(kc, str, ctrled_str, ...)                                                          \
  static const char ctrled_str_##kc[] PROGMEM = ctrled_str;
#define define_progmem_alted_string(kc, str, ctrled_str, alted_str, ...)                                                \
  static const char alted_str_##kc[] PROGMEM = alted_str;

enum arianes_keycodes {
  AE_DUMMY = SAFE_RANGE,
  HOLD_GUI,
  INSERT_UPP,
  RGB_TOGGLE_NOEE,
  SHOLD_GUI,
  VS_CLOSE,
  VS_FORMAT_DOC,
  // FOR_EACH_SEND_STRING_KEYCODE(enum_item)
  // FOR_EACH_CTRLABLE_SEND_STRING_KEYCODE(enum_item)
  FOR_EACH_CTRLABLE_OR_ALTABLE_SEND_STRING_KEYCODE(enum_item)
};

// FOR_EACH_SEND_STRING_KEYCODE(define_progmem_string);

/* FOR_EACH_CTRLABLE_SEND_STRING_KEYCODE(define_progmem_string); */
/* FOR_EACH_CTRLABLE_SEND_STRING_KEYCODE(define_progmem_ctrled_string); */

FOR_EACH_CTRLABLE_OR_ALTABLE_SEND_STRING_KEYCODE(define_progmem_string);
FOR_EACH_CTRLABLE_OR_ALTABLE_SEND_STRING_KEYCODE(define_progmem_ctrled_string);
FOR_EACH_CTRLABLE_OR_ALTABLE_SEND_STRING_KEYCODE(define_progmem_alted_string);

#undef enum_item
#undef define_progmem_string
#undef define_progmem_ctrled_string
#undef define_progmem_alted_string

#define USE_SEND_STRING_KEYCODES_TABLE

#ifdef USE_SEND_STRING_KEYCODES_TABLE
#  define send_string_keycodes_row(kc, str) { kc, str_##kc },
typedef struct {
  uint16_t kc;
  const char * str;
} send_string_keycodes_table_row_t;
/* static const send_string_keycodes_table_row_t send_string_keycodes[] = { */
/*   FOR_EACH_SEND_STRING_KEYCODE(send_string_keycodes_row) */
/* }; */
/* static const uint8_t send_string_keycodes_size = ARRAY_SIZE(send_string_keycodes); */
#  undef send_string_keycodes_row
 
#  define ctrlable_send_string_keycodes_row(kc, str, ctrlable_str) { kc, str_##kc, ctrled_str_##kc },
/* typedef struct { */
/*   uint16_t kc; */
/*   const char * str; */
/*   const char * ctrled_str; */
/* } ctrlable_send_string_keycodes_table_row_t; */
/* static const ctrlable_send_string_keycodes_table_row_t ctrlable_send_string_keycodes[] = { */
/*   FOR_EACH_CTRLABLE_SEND_STRING_KEYCODE(ctrlable_send_string_keycodes_row) */
/* }; */
/* static const uint8_t ctrlable_send_string_keycodes_size = ARRAY_SIZE(ctrlable_send_string_keycodes); */
#  undef ctrlable_send_string_keycodes_row

#  define ctrlable_or_altable_send_string_keycodes_row(kc, str, str2, altable_str) { kc, nomod_str_##kc, ctrled_str_##kc, alted_str_##kc },
typedef struct {
  uint16_t kc;
  const char * str;
  const char * ctrled_str;
  const char * alted_str;
} ctrlable_or_altable_send_string_keycodes_table_row_t;
static const ctrlable_or_altable_send_string_keycodes_table_row_t ctrlable_or_altable_send_string_keycodes[] = {
  FOR_EACH_CTRLABLE_OR_ALTABLE_SEND_STRING_KEYCODE(ctrlable_or_altable_send_string_keycodes_row)
};
static const uint8_t ctrlable_or_altable_send_string_keycodes_size = ARRAY_SIZE(ctrlable_or_altable_send_string_keycodes);
#  undef ctrlable_or_altable_send_string_keycodes_row

bool process_ctrlable_or_altable_send_string(
  const uint16_t keycode,
  const keyrecord_t * const record,
  const uint8_t ix) {
  if (ctrlable_or_altable_send_string_keycodes[ix].kc == keycode) {      
    if (record->event.pressed) {
      if (
        (pgm_read_byte(ctrlable_or_altable_send_string_keycodes[ix].ctrled_str) != 0) &&
        (get_mods() & MOD_MASK_CTRL)) {
        SEND_STRING_WITHOUT_MODS_P(ctrlable_or_altable_send_string_keycodes[ix].ctrled_str);
      }
      else if (
        (pgm_read_byte(ctrlable_or_altable_send_string_keycodes[ix].alted_str) != 0) &&
        (get_mods() & MOD_MASK_ALT)) {
        SEND_STRING_WITHOUT_MODS_P(ctrlable_or_altable_send_string_keycodes[ix].alted_str);
      }
      else {
        SEND_STRING_WITHOUT_MODS_P(ctrlable_or_altable_send_string_keycodes[ix].str);
      }
    }
    return true;
  }
  return false;
}

/* bool process_ctrlable_send_string( */
/*   const uint16_t keycode, */
/*   const keyrecord_t * const record, */
/*   const uint8_t ix) { */
/*   if (ctrlable_send_string_keycodes[ix].kc == keycode) {       */
/*     if (record->event.pressed) { */
/*       if ( */
/*         (pgm_read_byte(ctrlable_send_string_keycodes[ix].ctrled_str) != 0) && */
/*         (get_mods() & MOD_MASK_CTRL)) { */
/*         SEND_STRING_WITHOUT_MODS_P(ctrlable_send_string_keycodes[ix].ctrled_str); */
/*       } else { */
/*         SEND_STRING_WITHOUT_MODS_P(ctrlable_send_string_keycodes[ix].str); */
/*       } */
/*     } */
/*     return true; */
/*   } */
/*   return false; */
/* } */

/* bool process_send_string( */
/*   const uint16_t keycode, */
/*   const keyrecord_t * const record, */
/*   const uint8_t ix) { */
/*   if (send_string_keycodes[ix].kc == keycode) { */
/*     if (record->event.pressed)  */
/*       SEND_STRING_WITHOUT_MODS_P(send_string_keycodes[ix].str); */
/*     return true; */
/*   } */
/*   return false; */
/* } */
#endif // USE_SEND_STRING_KEYCODES_TABLE

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

#ifdef USE_ACHORDION
  if (!process_achordion(keycode, record))
    return false;
#endif

#ifdef USE_SEND_STRING_KEYCODES_TABLE
  /* for (uint8_t ix = 0; ix < send_string_keycodes_size; ix++) { */
  /*   if (process_send_string(keycode, record, ix)) */
  /*     return false; */
  /* } */
  /* for (uint8_t ix = 0; ix < ctrlable_send_string_keycodes_size; ix++) { */
  /*   if (process_ctrlable_send_string(keycode, record, ix)) */
  /*     return false; */
  /* } */
  for (uint8_t ix = 0; ix < ctrlable_or_altable_send_string_keycodes_size; ix++) {
    if (process_ctrlable_or_altable_send_string(keycode, record, ix))
      return false;
  }
#endif

  switch (keycode) {
  case VS_CLOSE:
    if (record->event.pressed) {
      tap_number(12388);
    }
    return false;
#ifndef USE_SEND_STRING_KEYCODES_TABLE
#  define kc_tap_case_ctrlable_or_altable_send_string(kc, str, ctrled_str, alted_str)                                   \
    case kc:                                                                                                            \
      if (record->event.pressed) {                                                                                      \
        if (                                                                                                            \
          (ctrled_str_##kc[0] != '\0') &&                                                                               \
          (get_mods() & MOD_MASK_CTRL)) {                                                                               \
          SEND_STRING_WITHOUT_MODS_P(ctrled_str_##kc);                                                                  \
        } else if (                                                                                                     \
          (alted_str_##kc[0] != '\0') &&                                                                                \
          (get_mods() & MOD_MASK_ALT)) {                                                                                \
          SEND_STRING_WITHOUT_MODS_P(alted_str_##kc);                                                                   \
        } else {                                                                                                        \
          SEND_STRING_WITHOUT_MODS_P(str_##kc);                                                                         \
        }                                                                                                               \
      }                                                                                                                 \
      return false;
    FOR_EACH_CTRLABLE_OR_ALTABLE_SEND_STRING_KEYCODE(kc_tap_case_ctrlable_or_altable_send_string)
#  undef  kc_tap_case_ctrlable_or_altable_send_string
/* #  define kc_tap_case_ctrlable_send_string(kc, str, ctrled_str)                                     \ */
/*       case kc:                                                                                      \ */
/*         if (record->event.pressed) {                                                                \ */
/*           if (                                                                                      \ */
/*             (ctrled_str_##kc[0] != '\0') &&                                                         \ */
/*             (get_mods() & MOD_MASK_CTRL)) {                                                         \ */
/*             SEND_STRING_WITHOUT_MODS_P(ctrled_str_##kc);                                            \ */
/*           } else {                                                                                  \ */
/*             SEND_STRING_WITHOUT_MODS_P(str_##kc);                                                   \ */
/*           }                                                                                         \ */
/*         }                                                                                           \ */
/*         return false; */
/*       FOR_EACH_CTRLABLE_SEND_STRING_KEYCODE(kc_tap_case_ctrlable_send_string) */
/* #  undef  kc_tap_case_ctrlable_send_string */
#  define kc_tap_case_send_string(kc, str)                                                                              \
      case kc:                                                                                                          \
        if (record->event.pressed)                                                                                      \
          SEND_STRING_WITHOUT_MODS_P(str_##kc);                                                                         \
        return false;
      FOR_EACH_SEND_STRING_KEYCODE(kc_tap_case_send_string)
#  undef  kc_tap_case_send_string
#endif // ! USE_SEND_STRING_KEYCODES_TABLE
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
      token = defer_exec(1000, release_lgui_callback, NULL);
    }
    return false;                                                                 
  case QK_TRI_LAYER_LOWER:
    layer_off(6);
    return true;
  case RCTL_DQUO:
    // KC_DQUO is not "basic" so we have to tap it manually
    if (record->tap.count && record->event.pressed) {
      tap_code16(KC_DQUO);
      return false;
    }
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
  } rgb_table_row_t;

  static const rgb_table_row_t rgb_table[] = {
    {TOGGLED_LAYER,          MY_RGB_DEFAULT          },
    {TRI_LAYER_ADJUST_LAYER, MY_RGB_ADJUST_LAYER_ON  },
    {TRI_LAYER_UPPER_LAYER,  MY_RGB_UPPER_LAYER_ON   },
    {TRI_LAYER_LOWER_LAYER,  MY_RGB_LOWER_LAYER_ON   },
    {TOGGLED_LAYER,          MY_RGB_TOGGLED_LAYER_ON },
  };
  static const size_t rgb_table_length = ARRAY_SIZE(rgb_table);

  const rgb_table_row_t *row = &rgb_table[0];
  
  for (size_t ix = 1; ix < rgb_table_length; ix++) {
    if (IS_LAYER_ON(rgb_table[ix].layer)) {
      row = &rgb_table[ix];
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

/* void housekeeping_task_user(void) { */
/* } */

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
bool achordion_chord(
  uint16_t      tap_hold_keycode,
  keyrecord_t * tap_hold_record,
  uint16_t      other_keycode,
  keyrecord_t * other_record) {
  if (IS_LAYER_ON(0) && (
#ifndef HOME_SHIFT
        tap_hold_keycode == QH_A    ||
        tap_hold_keycode == QH_QUOT ||
#endif
#if defined(BOTTOM_SHIFT) && ! defined(BOTTOM_ROW_MODS)
        /* tap_hold_keycode == QB_Z    || */
        /* tap_hold_keycode == QB_SLSH || */
#endif
#ifdef HOME_ROW_MODS
        tap_hold_keycode == QH_S    ||
        tap_hold_keycode == QH_D    ||
        tap_hold_keycode == QH_F    ||
        // tap_hold_keycode == QH_G    || // not a mod currently
        // tap_hold_keycode == QH_H    || // not a mod currently
        tap_hold_keycode == QH_J    ||
        tap_hold_keycode == QH_K    ||
        tap_hold_keycode == QH_L    ||
#endif // HreewwwOME_ROW_MODS
#ifdef BOTTOM_ROW_MODS
        tap_hold_keycode == QB_Z    ||
        tap_hold_keycode == QB_X    ||
        tap_hold_keycode == QB_C    ||
        tap_hold_keycode == QB_V    ||
        // tap_hold_keycode == QB_B    || // not a mod currently
        // tap_hold_keycode == QB_N    || // not a mod currently
        tap_hold_keycode == QB_M    ||
        tap_hold_keycode == QB_COMM ||
        tap_hold_keycode == QB_DOT  ||
        tap_hold_keycode == QB_SLSH ||
#endif
        false))
  {
    // Exceptionally consider the following chords as holds, even though they
    // are on the same hand.
    if (
#ifdef TOP_SHIFT
      (tap_hold_keycode == QH_A &&
       (other_keycode == LSFT_T(KC_MINS))) ||
      (tap_hold_keycode == QH_QUOT &&
       (other_keycode == RSFT_T(KC_MINS))) ||
#endif
#ifdef BOTTOM_SHIFT
      (tap_hold_keycode == QB_Z &&
       (other_keycode == LSFT_T(KC_MINS))) ||
      (tap_hold_keycode == QB_SLSH &&
       (other_keycode == RSFT_T(KC_MINS))) ||
#endif
#ifdef HOME_ROW_MODS
      // Left side
      (tap_hold_keycode == QH_S &&
       (other_keycode == KC_TAB ||
        other_keycode == QB_Z ||
        other_keycode == QT_R ||
        other_keycode == QT_T ||
        other_keycode == QB_C ||
        other_keycode == QB_V)) ||
      (tap_hold_keycode == QH_D &&
       (other_keycode == KC_TAB ||
        other_keycode == SS_ARROW ||
        other_keycode == SS_DIR ||
        other_keycode == SS_LBRACK ||
        other_keycode == SS_RBRACK ||
        other_keycode == SS_BRACKS ||
        other_keycode == QT_W ||
        other_keycode == QT_R ||
        other_keycode == QH_F ||
        other_keycode == QB_B ||
        other_keycode == QT_T)) ||
      (tap_hold_keycode == QH_F &&
       (other_keycode == SS_ARROW ||
        other_keycode == SS_DIR ||
        other_keycode == SS_LBRACK ||
        other_keycode == SS_RBRACK ||
        other_keycode == SS_BRACKS ||
        other_keycode == QH_A ||
        other_keycode == QT_E ||
        other_keycode == QT_T ||
        other_keycode == QT_W ||
        other_keycode == QH_S)) ||
      // Right side
      (tap_hold_keycode == QH_J &&
       (other_keycode == QH_H ||
        other_keycode == QH_K ||
        other_keycode == QH_L ||
        other_keycode == QT_Y ||
        other_keycode == QB_N ||
        other_keycode == QT_P)) ||
      (tap_hold_keycode == QH_K &&
       (other_keycode == QH_L ||
        other_keycode == QT_P ||
        other_keycode == LT(12,KC_BSLS) ||
        other_keycode == QB_N)) ||
      (tap_hold_keycode == QH_L &&
       (other_keycode == QH_K ||
        other_keycode == LT(12,KC_BSLS))) ||
#endif
#ifdef BOTTOM_ROW_MODS
      (tap_hold_keycode == QB_SLSH &&
       other_keycode == QH_K) ||
#endif
      false)
      return true;
    
    goto process_bilaterally;
  }
  
  if (IS_LAYER_ON(1) && (
#ifndef HOME_SHIFT
        tap_hold_keycode == CH_A    ||
        tap_hold_keycode == CH_QUOT ||
#endif
#if defined(BOTTOM_SHIFT) && ! defined(BOTTOM_ROW_MODS)
        tap_hold_keycode == CB_Z    ||
        tap_hold_keycode == CB_SLSH ||
#endif
#ifdef HOME_ROW_MODS
        tap_hold_keycode == CH_R    ||
        tap_hold_keycode == CH_S    ||
        tap_hold_keycode == CH_T    ||
        // tap_hold_keycode == CH_D    || // not a mod currently
        // tap_hold_keycode == CH_H    || // not a mod currently
        tap_hold_keycode == CH_N    ||
        tap_hold_keycode == CH_E    ||
        tap_hold_keycode == CH_I    ||
#endif
#ifdef BOTTOM_ROW_MODS
        tap_hold_keycode == CB_Z    ||
        tap_hold_keycode == CB_X    ||
        tap_hold_keycode == CB_C    ||
        tap_hold_keycode == CB_V    ||
        // tap_hold_keycode == CB_B    || // not a mod currently
        // tap_hold_keycode == CB_K    || // not a mod currently
        tap_hold_keycode == CB_M    ||
        tap_hold_keycode == CB_COMM ||
        tap_hold_keycode == CB_DOT  ||
        tap_hold_keycode == CB_SLSH ||
#endif
        false))
  {
    // Exceptionally consider the following chords as holds, even though they
    // are on the same hand.
#ifdef HOME_ROW_MODS
    if ((tap_hold_keycode == CH_T &&
         other_keycode == CH_A) ||
        false)
      return true;
#endif
    
    goto process_bilaterally;
  }

// process_normally:
  return true;
  
process_bilaterally:
  // Also allow same-hand holds when the other key is in the rows below the
  // alphas. I need the `% (MATRIX_ROWS / 2)` because my keyboard is split.
  if (other_record->event.key.row % (MATRIX_ROWS / 2) >= 4)
    return true;
  
  // Require bilateral
  return achordion_opposite_hands(tap_hold_record, other_record);
}

bool achordion_eager_mod(uint8_t mod) {
  /* switch (mod) { */
  /* case MOD_LGUI: */
  /* case MOD_RGUI: */
  /* case MOD_LALT: */
  /* case MOD_RALT: */
  /* case MOD_LSFT: */
  /* case MOD_RSFT: */
  /* case MOD_LCTL: */
  /* case MOD_RCTL: */
  return true;  // Eagerly apply all mods.
  /* default: */
  /*   return false; */
  /* } */
}
#endif

// ==============================================================================
// Include combos 
// ==============================================================================

#include "combos.inc"

// ==============================================================================
// Mod tap interrupt
// ==============================================================================

KEYRECORD_FUN(get_hold_on_other_key_press, bool) {
  switch (keycode) {
  case QK_MOD_TAP ... QK_MOD_TAP_MAX:
    if (keycode == LCTL_T(KC_ESC)  ||
        keycode == RCTL_T(KC_DQUO) ||
        keycode == LSFT_T(KC_MINS) ||
        keycode == RSFT_T(KC_MINS)) {
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
    case MT(MOD_RGUI,KC_SPC):
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

// ==============================================================================
// Autoshift
// ==============================================================================

#ifdef AUTO_SHIFT_ENABLE
KEYRECORD_FUN(get_autoshift_timeout, uint16_t) {
  if (keycode == KC_TAB)
    return 5000;
  return get_generic_autoshift_timeout();
/*   switch(keycode) { */
/*   case AUTO_SHIFT_ALPHA: */
/*     return get_generic_autoshift_timeout() + 60; */
/*   case AUTO_SHIFT_SPECIAL: */
/*     return get_generic_autoshift_timeout() + 30; */
/*   case AUTO_SHIFT_NUMERIC: */
/*   default: */
/*     return get_generic_autoshift_timeout(); */
/*   } */
}
#endif

// ==============================================================================
// Tapping term
// ==============================================================================

/* KEYRECORD_FUN(get_tapping_term, uint16_t) { */
/*   switch (keycode) { */
/*   case MT(MOD_LALT,KC_SPC): */
/*     return TAPPING_TERM + 60; */
/*   default: */
/*     return TAPPING_TERM; */
/*   } */
/* } */

// ==============================================================================
// Undefine local macros
// ==============================================================================

#undef KC_TAP_CASE
#undef KEYRECORD_FUN
#undef MANAGE_TOGGLED_LAYER_TIMEOUT
#undef RGBLIGHT_SETRGB
#undef SEND_STRING_WITHOUT_MODS

// ==============================================================================
// Include keymap
// ==============================================================================

#include "keymap.inc"
