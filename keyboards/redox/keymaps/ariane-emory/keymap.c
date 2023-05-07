#include QMK_KEYBOARD_H

// ================================================================================
// Tap dance
// ================================================================================

// enum tap_dance_events {
//   TD_SPC_LALT,
// };

// qk_tap_dance_action_t tap_dance_actions[] = {
//   [TD_SPC_LALT]  = ACTION_TAP_DANCE_DOUBLE(KC_SPC, KC_LALT),
// };

// ================================================================================
// Combos
// ================================================================================

enum combo_events {
  EVENT_DBL_TUCK,
  /* EVENT_UI, */
  /* EVENT_IO, */
  EVENT_JK,
  EVENT_KL,
  EVENT_JL,
  EVENT_HJ,
  EVENT_MCOMMA,
  COMBO_LENGTH
};

uint16_t COMBO_LEN = COMBO_LENGTH; // remove the COMBO_COUNT define and use this instead!

const uint16_t PROGMEM keys_dbl_tuck_combo[] = { MO(3), MO(4), COMBO_END };
/* const uint16_t PROGMEM keys_ui[]        = { KC_U, KC_I, COMBO_END }; */
/* const uint16_t PROGMEM keys_io[]        = { KC_I, KC_O, COMBO_END }; */
const uint16_t PROGMEM keys_jk[]        = { KC_J, KC_K, COMBO_END };
const uint16_t PROGMEM keys_kl[]        = { KC_K, KC_L, COMBO_END };
const uint16_t PROGMEM keys_jl[]        = { KC_J, KC_L, COMBO_END };
const uint16_t PROGMEM keys_hj[]        = { KC_H, KC_J, COMBO_END };
const uint16_t PROGMEM keys_mcomma[]    = { KC_M, KC_COMM, COMBO_END };

combo_t key_combos[] = {
  [EVENT_DBL_TUCK] = COMBO(keys_dbl_tuck_combo, KC_LCTL),
  /* [EVENT_UI]       = COMBO(keys_ui, KC_LCBR), */
  /* [EVENT_IO]       = COMBO(keys_io, KC_RCBR), */
  [EVENT_JK]       = COMBO(keys_jk, KC_LBRC),
  [EVENT_KL]       = COMBO(keys_kl, KC_RBRC),
  [EVENT_JL]       = COMBO(keys_jl, KC_EQL),
  [EVENT_HJ]       = COMBO(keys_hj, KC_EQL),
  [EVENT_MCOMMA]   = COMBO(keys_mcomma, KC_EQL)
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
  SS_UPDIR = SAFE_RANGE,
  SS_NUM,
  SS_NUM2
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case SS_NUM:
    if (record->event.pressed) {
      SEND_STRING("6851");
    }
    return false;
  case SS_NUM2:
    if (record->event.pressed) {
      SEND_STRING("^*%!");
    }
    return false;
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
// Unicode
// ================================================================================

enum unicode_names {
  KITTY
};

const uint32_t unicode_map[] PROGMEM = {
  [KITTY]  = 0x1F408,  // ‽
  };


// ================================================================================
// Autoshift
// ================================================================================

uint16_t get_autoshift_timeout(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
  case AUTO_SHIFT_ALPHA:
    return get_generic_autoshift_timeout() + 80;
  case AUTO_SHIFT_SPECIAL:
    return get_generic_autoshift_timeout() + 40;
  case AUTO_SHIFT_NUMERIC:
  default:
    return get_generic_autoshift_timeout();
  }
}

// ================================================================================
// Include inlines
// ================================================================================

#include "keymap.inl"

