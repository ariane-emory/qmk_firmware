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

#define SEND_STRING_WITHOUT_MODS(str)  \
  {                                    \
    uint8_t current_mods = get_mods(); \
    clear_mods();                      \
    SEND_STRING(str);                  \
    set_mods(current_mods);            \
  }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case SS_PIN1:
    if (record->event.pressed)
      SEND_STRING_WITHOUT_MODS(AE_PIN1);
    return false;
  case SS_PIN2:
    if (record->event.pressed)
      SEND_STRING_WITHOUT_MODS(AE_PIN2);
    return false;
  case SS_UPDIR:
    if (record->event.pressed)
      SEND_STRING_WITHOUT_MODS("../");
    return false;
  case SS_LPAR:
    if (record->event.pressed)
      SEND_STRING_WITHOUT_MODS("9");
    return false;
  case SS_RPAR:
    if (record->event.pressed)
      SEND_STRING_WITHOUT_MODS("0");
    return false;
  case SS_TILD:
    if (record->event.pressed)
      SEND_STRING_WITHOUT_MODS("~");
    return false;
  case SS_TILD_SLASH:
    if (record->event.pressed)
      SEND_STRING_WITHOUT_MODS("~/");
    return false;
  case SS_GRAV:
    if (record->event.pressed)
      SEND_STRING_WITHOUT_MODS("`");
    return false;
  }

  return true;
}

#undef SEND_STRING_WITHOUT_MODS
  
// ================================================================================
// Include combos 
// ================================================================================

#include "combos.inl"

// ================================================================================
// Mod tap interrupt
// ================================================================================

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
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

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
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

uint16_t get_autoshift_timeout(uint16_t keycode, keyrecord_t *record) {
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

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case MT(MOD_LALT,KC_SPC):
    return TAPPING_TERM + 60;
  default:
    return TAPPING_TERM;
  }
}

// ================================================================================
// Include keymap
// ================================================================================

#include "keymap.inl"

