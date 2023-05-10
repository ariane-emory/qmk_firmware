#include QMK_KEYBOARD_H

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

#define SEND_STRING_WITHOUT_MODS_CASE(kc, str)                                  \
  case kc:                                                                      \
    if (record->event.pressed)                                                  \
    {                                                                           \
      const uint8_t current_mods = get_mods();                                  \
      clear_mods();                                                             \
      SEND_STRING(str);                                                         \
      set_mods(current_mods);                                                   \
    }                                                                           \
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
  SS_TILD,
  SS_TILD_SLASH,
  SS_UPDIR,
};
  
KEYRECORD_FUN(process_record_user, bool) {
  MANAGE_TOGGLED_LAYER_TIMEOUT(3, 2500);
  
  switch (keycode) {
    SEND_STRING_WITHOUT_MODS_CASE(SS_PIN1,       AE_PIN1);
    SEND_STRING_WITHOUT_MODS_CASE(SS_PIN2,       AE_PIN2);
    SEND_STRING_WITHOUT_MODS_CASE(SS_GRAV,       "`");
    SEND_STRING_WITHOUT_MODS_CASE(SS_LPAR,       "9");
    SEND_STRING_WITHOUT_MODS_CASE(SS_RPAR,       "0");
    SEND_STRING_WITHOUT_MODS_CASE(SS_TILD,       "~");
    SEND_STRING_WITHOUT_MODS_CASE(SS_TILD_SLASH, "~/");
    SEND_STRING_WITHOUT_MODS_CASE(SS_UPDIR,      "../");
  default:
    return true;
  }
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

#undef KEYRECORD_FUN
#undef MANAGE_TOGGLED_LAYER_TIMEOUT
#undef SEND_STRING_WITHOUT_MODS
  
// ==============================================================================
// Include keymap
// ==============================================================================

#include "keymap.inl"

