#include QMK_KEYBOARD_H

#include "features/achordion.h"

// #define AE_PIN1 and AE_PIN2 in this file:
#include "secrets.h"

// ==============================================================================
// Init
// ==============================================================================

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  /* debug_enable=true; */
  /* debug_matrix=true; */
  /* debug_keyboard=true; */
  /* debug_mouse=true; */
}

// ==============================================================================
// Define local macros
// ==============================================================================

#define KEYRECORD_FUN(name, t)                                                  \
  t name(uint16_t keycode, keyrecord_t *record)

#define MANAGE_TOGGLED_LAYER_TIMEOUT(layer, idle_time_limit_ms)                 \
  {                                                                             \
    static uint16_t key_timer = 0;                                              \
    if (layer_state_is(layer) &&                                                \
        timer_elapsed(key_timer) >= idle_time_limit_ms) {                       \
      layer_off(layer);                                                         \
    }                                                                           \
    key_timer = timer_read();                                                   \
  }

#define SEND_STRING_WITHOUT_MODS(str)                                           \
  {                                                                             \
    const uint8_t current_mods = get_mods();                                    \
    clear_mods();                                                               \
    SEND_STRING(str);                                                           \
    set_mods(current_mods);                                                     \
  }                                                                             

#define KC_CASE(kc, blk)                                                        \
  case kc:                                                                      \
  if (record->event.pressed)                                                    \
  {                                                                             \
    blk;                                                                        \
  }                                                                             \
  return false;                                                                 

// ==============================================================================
// Custom keycodes
// ==============================================================================

#define SS_LASTARG_STR SS_LCTL("c") SS_DELAY(50) "."

enum arianes_keycodes {
  SS_PIN1 = SAFE_RANGE,
  SS_PIN2,
  SS_GRAV,
  SS_LPAR,
  SS_RPAR,
  SS_TILD,
  SS_TILD_SLASH,
  SS_UPDIR,
  SS_LASTARG,
  SS_REPEAT,
};
  
KEYRECORD_FUN(process_record_user, bool) {
  MANAGE_TOGGLED_LAYER_TIMEOUT(4, TOGGLED_LAYER_TIMEOUT);

  if (!process_achordion(keycode, record)) { return false; }
  
  switch (keycode) {
    KC_CASE(SS_PIN1,       SEND_STRING_WITHOUT_MODS(AE_PIN1));
    KC_CASE(SS_PIN2,       SEND_STRING_WITHOUT_MODS(AE_PIN2));
    KC_CASE(SS_GRAV,       SEND_STRING_WITHOUT_MODS("`"));
    KC_CASE(SS_LPAR,       SEND_STRING_WITHOUT_MODS("9"));
    KC_CASE(SS_RPAR,       SEND_STRING_WITHOUT_MODS("0"));
    KC_CASE(SS_TILD,       SEND_STRING_WITHOUT_MODS("~"));
    KC_CASE(SS_TILD_SLASH, SEND_STRING_WITHOUT_MODS(" ~/"));
    KC_CASE(SS_UPDIR,      SEND_STRING_WITHOUT_MODS("../"));
    KC_CASE(SS_LASTARG,    SEND_STRING_WITHOUT_MODS(" "SS_LCTL("c")SS_DELAY(50)"."));
    KC_CASE(SS_REPEAT,     SEND_STRING_WITHOUT_MODS(SS_LCTL("x")SS_DELAY(50)"z"));
  default:
    return true;
  }
}

void matrix_scan_user(void) {
  achordion_task();
}

bool achordion_chord(
  uint16_t tap_hold_keycode,
  keyrecord_t* tap_hold_record,
  uint16_t other_keycode,
  keyrecord_t* other_record) {
  if (
    tap_hold_keycode == LCTL_T(KC_F)    ||
    tap_hold_keycode == LALT_T(KC_D)    ||
    tap_hold_keycode == LGUI_T(KC_S)    ||
    tap_hold_keycode == LSFT_T(KC_A)    ||
    tap_hold_keycode == RCTL_T(KC_J)    ||
    tap_hold_keycode == RALT_T(KC_K)    ||
    tap_hold_keycode == RGUI_T(KC_L)    ||
    tap_hold_keycode == RSFT_T(KC_QUOT)
      )
    // Require bilateral
    return achordion_opposite_hands(tap_hold_record, other_record);

  /* if (tap_hold_keycode == MT(MOD_LALT,KC_SPC)) { */
  /*   if (other_keycode == KC_LEFT  || */
  /*       other_keycode == KC_DOWN  || */
  /*       other_keycode == KC_UP    || */
  /*       other_keycode == KC_RIGHT) */
  /*     return true; // tap */
  /* } */
  
  // Process normally
  return true;
}

// ==============================================================================
// Include combos 
// ==============================================================================

#include "combos.inl"

// ==============================================================================
// Mod tap interrupt
// ==============================================================================

KEYRECORD_FUN(get_hold_on_other_key_press, bool) {
  switch (keycode) {
  case QK_MOD_TAP ... QK_MOD_TAP_MAX:
    if (keycode == LCTL_T(KC_ESC)  ||
        keycode == RCTL_T(KC_SCLN) ||
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
  switch (keycode) {
  case MT(MOD_LALT,KC_SPC):
    // Do not select the hold action when another key is tapped.
    return false;
  default:
    // Immediately select the hold action when another key is tapped.
    return true;
  }
}

// ==============================================================================
// Autoshift
// ==============================================================================

#ifdef AUTO_SHIFT_ENABLE
KEYRECORD_FUN(get_autoshift_timeout, uint16_t) {
  switch(keycode) {
  case AUTO_SHIFT_ALPHA:
    return get_generic_autoshift_timeout() + 60;
  case AUTO_SHIFT_SPECIAL:
    return get_generic_autoshift_timeout() + 30;
  case AUTO_SHIFT_NUMERIC:
  default:
    return get_generic_autoshift_timeout();
  }
}
#endif

// ==============================================================================
// Tapping term
// ==============================================================================

KEYRECORD_FUN(get_tapping_term, uint16_t) {
  switch (keycode) {
  case MT(MOD_LALT,KC_SPC):
    return TAPPING_TERM + 60;
  default:
    return TAPPING_TERM;
  }
}

// ==============================================================================
// Undefine local macros
// ==============================================================================

#undef KC_CASE
#undef KEYRECORD_FUN
#undef MANAGE_TOGGLED_LAYER_TIMEOUT
#undef SEND_STRING_WITHOUT_MODS
  
// ==============================================================================
// Include keymap
// ==============================================================================

#include "keymap.inl"

