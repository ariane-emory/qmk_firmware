#include QMK_KEYBOARD_H

// ================================================================================
// Tap dance
// ================================================================================

enum td_events {
  TD_SPC_LALT,
};
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_SPC_LALT]  = ACTION_TAP_DANCE_DOUBLE(KC_SPC, KC_LALT),
};

// ================================================================================
// Combos
// ================================================================================

enum combo_events {
  DBL_SPC,
  COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH; // remove the COMBO_COUNT define and use this instead!

const uint16_t PROGMEM dbl_spc_combo[] = {LALT_T(KC_SPC), RGUI_T(KC_BSPC), COMBO_END};

combo_t key_combos[] = {
  [DBL_SPC]       = COMBO(dbl_spc_combo, RCTL(KC_SPC)),
};

// ================================================================================
// Mod tap interrupt
// ================================================================================

bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case LALT_T(KC_SPC):
    // Do not force the mod-tap key press to be handled as a modifier
    // if any other key was pressed while the mod-tap key is held down.
    return true;
  default:
    // Force the mod-tap key press to be handled as a modifier if any
    // other key was pressed while the mod-tap key is held down.
    return false;
  }
}

// ================================================================================
// Custom keycodes
// ================================================================================

enum arianes_keycodes {
  SS_UPDIR = SAFE_RANGE
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case SS_UPDIR:
    if (record->event.pressed) {
      SEND_STRING("../");
    }
    return false;
  }

  return true;
}

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
// Include inlines
// ================================================================================

#include "keymap.inl"

