#include QMK_KEYBOARD_H

#include <stdbool.h>

#if defined(HOME_ROW_MODS) || defined(BOTTOM_ROW_MODS)
#define USE_ACHORDION
#include "features/achordion.h"
#endif

#include "key_aliases.h"
#include "features/rgb_fader.h"
#include "secrets.h" // #define AE_PIN1 and AE_PIN2 in this file:

rgb_fader_t rgb_fader;

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

  rgblight_enable_noeeprom();
  rgb_fader_init(&rgb_fader, RGB_DEFAULT);
}

// ==============================================================================
// Define local macros
// ==============================================================================

#ifdef RGBLIGHT_ENABLE
#define RGBLIGHT_SETRGB(...) rgb_fader_set_target(&rgb_fader, __VA_ARGS__)
#else
#define RGBLIGHT_SETRGB(...) (((void)0))
#endif

#define KEYRECORD_FUN(name, t)                                                  \
  t name(uint16_t keycode, keyrecord_t *record)

#ifdef TOGGLED_LAYER_TIMEOUT
#define MANAGE_TOGGLED_LAYER_TIMEOUT(layer, idle_time_limit_ms, timer)          \
  {                                                                             \
    if (layer_state_is(layer) &&                                                \
        timer_elapsed(timer) >= idle_time_limit_ms)                             \
      layer_off(layer);                                                         \
  }                                                                             
#else
#define MANAGE_TOGGLED_LAYER_TIMEOUT(layer, idle_time_limit_ms, timer) ((void))
#endif

#ifdef SEND_STRING_ENABLE
#define SEND_STRING_WITHOUT_MODS(str)                                           \
  {                                                                             \
    const uint8_t current_mods = get_mods();                                    \
    clear_mods();                                                               \
    SEND_STRING(str);                                                           \
    set_mods(current_mods);                                                     \
  }                                                                         
#else
#define SEND_STRING_WITHOUT_MODS(str) (((void)0))                                
#endif

#define KC_TAP_CASE(kc, blk)                                                    \
  case kc:                                                                      \
  if (record->event.pressed)                                                    \
  {                                                                             \
    blk;                                                                        \
  }                                                                             \
  return false;                                                                 

// ==============================================================================
// Custom keycodes
// ==============================================================================

enum arianes_keycodes {
  SS_PIN1 = SAFE_RANGE,
  SS_PIN2,
  SS_GRAV,
  SS_LPAR,
  SS_RPAR,
  SS_RPAR_SCLN,
  SS_TILD,
  SS_TILD_SLSH,
  SS_SPC_TILD_SLSH,
  SS_UPDIR,
  SS_THISDIR,
  EM_LASTARG,
  EM_REPEAT,
  EM_REVERT,
  SS_ARROW,
  EM_CHG_BUF,
  INSERT_UPP,
  HOLD_GUI,
  SHOLD_GUI,
  SS_SIRI,
  VS_FORMAT_DOC,
  RGB_TOGGLE_NOEE,
  VS_CLOSE,
};

uint32_t release_lgui_callback(uint32_t trigger_time, void *cb_arg) {
  unregister_code(KC_LGUI);
  return 0;
}

static uint16_t idle_timer = 0;

KEYRECORD_FUN(process_record_user, bool) {
  idle_timer = timer_read();

#ifdef USE_ACHORDION
  if (!process_achordion(keycode, record))
    return false;
#endif
  
  switch (keycode) {
    KC_TAP_CASE(SS_PIN1,           SEND_STRING_WITHOUT_MODS(AE_PIN1));
    KC_TAP_CASE(SS_PIN2,           SEND_STRING_WITHOUT_MODS(AE_PIN2));
#ifdef COMBO_ENABLE
    KC_TAP_CASE(SS_GRAV,           SEND_STRING_WITHOUT_MODS("`"));
    KC_TAP_CASE(SS_LPAR,           SEND_STRING_WITHOUT_MODS("9"));
    KC_TAP_CASE(SS_RPAR,           SEND_STRING_WITHOUT_MODS("0"));
    KC_TAP_CASE(SS_RPAR_SCLN,      SEND_STRING_WITHOUT_MODS("0;"));
    KC_TAP_CASE(SS_TILD,           SEND_STRING_WITHOUT_MODS("~"));
    KC_TAP_CASE(SS_TILD_SLSH,      SEND_STRING_WITHOUT_MODS("~/"));
    KC_TAP_CASE(SS_SPC_TILD_SLSH,  SEND_STRING_WITHOUT_MODS(" ~/"));
    KC_TAP_CASE(SS_UPDIR,          SEND_STRING_WITHOUT_MODS("../"));
    KC_TAP_CASE(SS_THISDIR,        SEND_STRING_WITHOUT_MODS("./"));
    KC_TAP_CASE(SS_ARROW,          SEND_STRING_WITHOUT_MODS("->"));
    KC_TAP_CASE(EM_LASTARG,        SEND_STRING_WITHOUT_MODS(" "SS_LCTL("c")SS_DELAY(50)"."));
    KC_TAP_CASE(EM_REPEAT,         SEND_STRING_WITHOUT_MODS(SS_LCTL("x")SS_DELAY(50)"z"));
    KC_TAP_CASE(EM_REVERT,         SEND_STRING_WITHOUT_MODS(SS_LCTL("x")SS_DELAY(50)SS_LCTL("r")));
    KC_TAP_CASE(EM_CHG_BUF,        SEND_STRING_WITHOUT_MODS(SS_LCTL("x")SS_DELAY(50)"b"));
    // KC_TAP_CASE(VS_FORMAT_DOC,     SEND_STRING_WITHOUT_MODS(SS_LALT("e")SS_DELAY(250)"v"SS_LALT("e")SS_DELAY(250)"v"SS_DELAY(250)"a"SS_LALT("f")SS_DELAY(250)"s"));
#endif
  case QK_DYNAMIC_MACRO_PLAY_1:
  case QK_DYNAMIC_MACRO_PLAY_2:
    if (record->event.pressed)
      dynamic_macro_stop_recording();
    return true;
  case VS_CLOSE:
    if (record->event.pressed)
    {
      SEND_STRING_WITHOUT_MODS(SS_LALT("f")SS_DELAY(100)"c");
    }
    return false;
  case VS_FORMAT_DOC:
    if (record->event.pressed)
    {
      tap_code(KC_F7);
      SEND_STRING_WITHOUT_MODS(SS_DELAY(1500)SS_LALT("e")SS_DELAY(500)"v"SS_LALT("e")SS_DELAY(500)"v"SS_DELAY(500)"a"SS_LALT("f")SS_DELAY(500)"s");
    }
    return false;
  case SS_SIRI:
    if (record->event.pressed)
    {
      register_code(KC_F24);
      SEND_STRING_WITHOUT_MODS(SS_DELAY(50));
      tap_code(KC_SPC);
      unregister_code(KC_F24);
    }
    return false;
  case RGB_TOGGLE_NOEE:
    /* if (record->event.pressed) */
    /* { */
    /*   rgblight_toggle_noeeprom(); */
    /* } */
    return false;
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

bool setrgb_if_recording_macro(void) {
  if (! currently_recording_macro)
    return false;
  RGBLIGHT_SETRGB(RGB_MAGENTA);
  return true;
}

void setrgb_by_layer(void) {
  typedef struct {
    uint8_t layer;
    uint8_t r;
    uint8_t g;
    uint8_t b;
  } rgb_table_row_t;
  
  static const rgb_table_row_t rgb_table[] = {
    { TOGGLED_LAYER,          RGB_DEFAULT          },
    { TRI_LAYER_ADJUST_LAYER, RGB_ADJUST_LAYER_ON  },
    { TRI_LAYER_UPPER_LAYER,  RGB_UPPER_LAYER_ON   },
    { TRI_LAYER_LOWER_LAYER,  RGB_LOWER_LAYER_ON   },
    { TOGGLED_LAYER,          RGB_TOGGLED_LAYER_ON },
  };
  static const size_t rgb_table_length = ARRAY_SIZE(rgb_table);

  const rgb_table_row_t * row = &row[0];
  
  for (size_t ix = 1; ix < rgb_table_length; ix++) {
    if (IS_LAYER_ON(rgb_table[ix].layer)) {
      row = &rgb_table[ix];
      break;
    }
  }

  RGBLIGHT_SETRGB(row->r, row->g, row->b);
}

void matrix_scan_user(void) {
#ifdef USE_ACHORDION
  achordion_task();
#endif

  MANAGE_TOGGLED_LAYER_TIMEOUT(TOGGLED_LAYER, TOGGLED_LAYER_TIMEOUT, idle_timer);

#if defined(RGBLIGHT_ENABLE) && defined(MY_RGB_LAYERS)
  if (! setrgb_if_recording_macro())
    setrgb_by_layer();
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
        tap_hold_keycode == QB_Z    ||
        tap_hold_keycode == QB_SLSH ||
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
#endif // HOME_ROW_MODS
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
        other_keycode == QT_W ||
        other_keycode == QT_R ||
        other_keycode == QH_F ||
        other_keycode == QB_B ||
        other_keycode == QT_T)) ||
      (tap_hold_keycode == QH_F &&
       (other_keycode == QH_A ||
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
       (other_keycode == QT_P ||
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
