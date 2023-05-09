#include QMK_KEYBOARD_H

#include "secrets.h" // #define AE_PIN1 and AE_PIN2 in this file.

// ================================================================================
// Init
// ================================================================================

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  /* debug_enable=true; */
  /* debug_matrix=true; */
  /* debug_keyboard=true; */
  /* debug_mouse=true; */
}

// ================================================================================
// Custom keycodes
// ================================================================================

enum arianes_keycodes {
  SS_UPDIR = SAFE_RANGE,
  SS_PIN1,
  SS_PIN2,
  SS_LPAR,
  SS_RPAR,
  SS_GRAV,
  SS_TILD,
  SS_TILD_SLASH,
};

#define SEND_STRING_WITHOUT_MODS_CASE(kc, str)                                       \
  case kc:                                                                      \
    if (record->event.pressed)                                                  \
    {                                                                           \
      const uint8_t current_mods = get_mods();                                  \
      clear_mods();                                                             \
      SEND_STRING(str);                                                         \
      set_mods(current_mods);                                                   \
    }                                                                           \
    return false;

#define KEYRECORD_FUN(t, name) t name(uint16_t keycode, keyrecord_t *record)

KEYRECORD_FUN(bool, process_record_user) {
  switch (keycode) {
    SEND_STRING_WITHOUT_MODS_CASE(SS_PIN1,       AE_PIN1);
    SEND_STRING_WITHOUT_MODS_CASE(SS_PIN2,       AE_PIN2);
    SEND_STRING_WITHOUT_MODS_CASE(SS_UPDIR,      "../");
    SEND_STRING_WITHOUT_MODS_CASE(SS_LPAR,       "9");
    SEND_STRING_WITHOUT_MODS_CASE(SS_RPAR,       "0");
    SEND_STRING_WITHOUT_MODS_CASE(SS_TILD,       "~");
    SEND_STRING_WITHOUT_MODS_CASE(SS_TILD_SLASH, "~/");
    SEND_STRING_WITHOUT_MODS_CASE(SS_GRAV,       "`");
  default:
    return true;
  }
}

// ================================================================================
// Include combos 
// ================================================================================

#include "combos.inl"

// ================================================================================
// Mod tap interrupt
// ================================================================================

KEYRECORD_FUN(bool, get_hold_on_other_key_press) {
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

KEYRECORD_FUN(bool, get_permissive_hold) {
  switch (keycode) {
  case MT(MOD_LALT,KC_SPC):
    // Do not select the hold action when another key is tapped.
    return false;
  default:
    // Immediately select the hold action when another key is tapped.
    return true;
  }
}

// ================================================================================
// Autoshift
// ================================================================================

KEYRECORD_FUN(uint16_t, get_autoshift_timeout) {
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

// ================================================================================
// Tapping term
// ================================================================================

KEYRECORD_FUN(uint16_t, get_tapping_term) {
  switch (keycode) {
  case MT(MOD_LALT,KC_SPC):
    return TAPPING_TERM + 60;
  default:
    return TAPPING_TERM;
  }
}

// ================================================================================
// Undefine local macros
// ================================================================================

#undef KEYRECORD_FUN
#undef SEND_STRING_WITHOUT_MODS
  
// ================================================================================
// Include keymap
// ================================================================================

#include "keymap.inl"

