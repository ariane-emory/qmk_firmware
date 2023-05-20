#include QMK_KEYBOARD_H

#if defined(HOME_ROW_MODS) || defined(BOTTOM_ROW_MODS)
#define USE_ACHORDION
#include "features/achordion.h"
#endif

#include "key_aliases.h"
#include "secrets.h" // #define AE_PIN1 and AE_PIN2 in this file:

// ==============================================================================
// Init
// ==============================================================================

void keyboard_post_init_user(void) {
#if CONSOLE_ENABLE
  debug_enable=true;
  debug_matrix=true;
  debug_keyboard=true;
  debug_mouse=true;
#endif
  // rgblight_enable();
}

// ==============================================================================
// Define local macros
// ==============================================================================

#ifdef RGBLIGHT_ENABLE
#define RGBLIGHT_SETHSV(hsv) rgblight_sethsv_noeeprom(hsv)
#else
#define RGBLIGHT_SETHSV(hsv) (((void)0))
#endif

#define KEYRECORD_FUN(name, t)                                                  \
  t name(uint16_t keycode, keyrecord_t *record)

#define MANAGE_TOGGLED_LAYER_TIMEOUT(layer, idle_time_limit_ms, timer)          \
  {                                                                             \
    if (layer_state_is(layer) &&                                                \
        timer_elapsed(timer) >= idle_time_limit_ms)                             \
      layer_off(layer);                                                         \
  }                                                                             

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
  EM_SWITCH_BUFFER,
  INSERT_UPP,
  HOLD_GUI,
  SHOLD_GUI,
  SS_SIRI,
};

uint32_t release_lgui_callback(uint32_t trigger_time, void *cb_arg) {
  unregister_code(KC_LGUI);
  return 0;
}

static uint16_t idle_timer = 0;
static bool     asleep     = false;
#ifdef IGNORE_WAKING_KEY
static uint16_t waking_key = KC_NO;
#endif

KEYRECORD_FUN(process_record_user, bool) {
  idle_timer = timer_read();

#ifdef IGNORE_WAKING_KEY
  if (asleep) {
    if (record->event.pressed && waking_key == KC_NO) {
      waking_key = keycode;
    }
    else if (keycode == waking_key) {
      asleep = false;
      waking_key = KC_NO;
    }
    return false;
  }
#else
  if (asleep)
    asleep = false;
#endif

#ifdef USE_ACHORDION
  if (!process_achordion(keycode, record))
    return false;
#endif
  
  switch (keycode) {
#ifdef COMBO_ENABLE
    KC_TAP_CASE(SS_PIN1,           SEND_STRING_WITHOUT_MODS(AE_PIN1));
    KC_TAP_CASE(SS_PIN2,           SEND_STRING_WITHOUT_MODS(AE_PIN2));
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
    KC_TAP_CASE(EM_SWITCH_BUFFER,  SEND_STRING_WITHOUT_MODS(SS_LCTL("x")SS_DELAY(50)"b"));
#endif
  case SS_SIRI:
    if (record->event.pressed)
    {
      register_code(KC_F24);
      SEND_STRING_WITHOUT_MODS(SS_DELAY(50));
      tap_code(KC_SPC);
      unregister_code(KC_F24);
    }
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
  case RCTL_T(KC_DQUO):
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

void matrix_scan_user(void) {
#ifdef USE_ACHORDION
  achordion_task();
#endif

#ifdef TOGGLED_LAYER_TIMEOUT
  MANAGE_TOGGLED_LAYER_TIMEOUT(TOGGLED_LAYER, TOGGLED_LAYER_TIMEOUT, idle_timer);
#endif

  if (false) {}
#ifdef SLEEP_TIMEOUT
  else if (asleep || timer_elapsed(idle_timer) >= SLEEP_TIMEOUT)
  {
    asleep = true;
    RGBLIGHT_SETHSV(HSV_ASLEEP);
  }
#endif
#if defined(RGBLIGHT_ENABLE) && defined(MY_RGB_LAYERS)
  else if (IS_LAYER_ON(TRI_LAYER_ADJUST_LAYER))
    RGBLIGHT_SETHSV(HSV_ADJUST_LAYER_ON);
  else if (IS_LAYER_ON(TRI_LAYER_UPPER_LAYER))
    RGBLIGHT_SETHSV(HSV_UPPER_LAYER_ON);
  else if (IS_LAYER_ON(TRI_LAYER_LOWER_LAYER))
    RGBLIGHT_SETHSV(HSV_LOWER_LAYER_ON);
  else if (IS_LAYER_ON(TOGGLED_LAYER))
    RGBLIGHT_SETHSV(HSV_TOGGLED_LAYER_ON);
  else
    RGBLIGHT_SETHSV(HSV_TOGGLED_LAYER_OFF);
#endif
}

// ==============================================================================
// Achordion
// ==============================================================================

#ifdef USE_ACHORDION
bool achordion_chord(
  uint16_t tap_hold_keycode,
  keyrecord_t* tap_hold_record,
  uint16_t other_keycode,
  keyrecord_t* other_record) {
  if (
    (IS_LAYER_ON(0) && (
#ifdef HOME_ROW_MODS
      tap_hold_keycode == QH_A    ||
      tap_hold_keycode == QH_S    ||
      tap_hold_keycode == QH_D    ||
      tap_hold_keycode == QH_F    ||
      // tap_hold_keycode == QH_G    || // not a mod currently
      // tap_hold_keycode == QH_H    || // not a mod currently
      tap_hold_keycode == QH_J    ||
      tap_hold_keycode == QH_K    ||
      tap_hold_keycode == QH_L    ||
      tap_hold_keycode == QH_QUOT ||
#endif
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
      false)))
  {
    // Exceptionally consider the following chords as holds, even though they
    // are on the same hand.
    if (
#ifdef HOME_ROW_MODS
      (tap_hold_keycode == QH_A &&
       (other_keycode == LSFT_T(KC_MINS))) ||
      (tap_hold_keycode == QH_S &&
       (other_keycode == KC_TAB)) ||
      (tap_hold_keycode == QH_D &&
       (other_keycode == KC_TAB ||
        other_keycode == KC_W)) ||
      (tap_hold_keycode == QH_F &&
       (other_keycode == QH_A ||
        other_keycode == KC_E ||
        other_keycode == KC_T ||
        other_keycode == KC_W ||
        other_keycode == QH_S)) ||

      (tap_hold_keycode == QH_J &&
       (other_keycode == QH_K ||
        other_keycode == KC_Y ||
        other_keycode == KC_N ||
        other_keycode == KC_P)) ||
      (tap_hold_keycode == QH_K &&
       (other_keycode == KC_P ||
        other_keycode == QB_N)) ||
      (tap_hold_keycode == QH_L &&
       (other_keycode == QH_K)) ||
      (tap_hold_keycode == QH_QUOT &&
       (other_keycode == RSFT_T(KC_MINS))) ||
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
#ifdef HOME_ROW_MODS
        tap_hold_keycode == CH_A    ||
        tap_hold_keycode == CH_R    ||
        tap_hold_keycode == CH_S    ||
        tap_hold_keycode == CH_T    ||
        // tap_hold_keycode == CH_D    || // not a mod currently
        // tap_hold_keycode == CH_H    || // not a mod currently
        tap_hold_keycode == CH_N    ||
        tap_hold_keycode == CH_E    ||
        tap_hold_keycode == CH_I    ||
        tap_hold_keycode == QH_QUOT ||
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
#undef RGBLIGHT_SETHSV
#undef SEND_STRING_WITHOUT_MODS

// ==============================================================================
// Include keymap
// ==============================================================================

#include "keymap.inc"
