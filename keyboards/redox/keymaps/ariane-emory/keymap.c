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

#define CC(name, ...)                                                           \
  const uint16_t PROGMEM name[] = { __VA_ARGS__, COMBO_END};

CC(keys_dbl_tuck_combo, MO(3), MO(4));
CC(keys_ik,             KC_I, KC_K);
CC(keys_mo3f,           MO(3), KC_F);
CC(keys_mo4j,           MO(4), KC_J);

CC(keys_yu,             KC_Y, KC_U);
CC(keys_ui,             KC_U, KC_I);
CC(keys_io,             KC_I, KC_O);
CC(keys_op,             KC_O, KC_P);
CC(keys_uo,             KC_U, KC_O);

CC(keys_hj,             KC_H, KC_J);

CC(keys_jk,             KC_J, KC_K);

CC(keys_kl,             KC_K, KC_L);
CC(keys_lquot,          KC_L, KC_QUOT);
CC(keys_jl,             KC_J, KC_L);

CC(keys_nm,             KC_N, KC_M);
CC(keys_mcomma,         KC_M, KC_COMM);
CC(keys_commadot,       KC_COMM, KC_DOT);
CC(keys_dotslash,       KC_DOT, KC_SLASH);
CC(keys_mdot,           KC_M, KC_DOT);

#undef CC

combo_t key_combos[] = {
  COMBO(keys_dbl_tuck_combo, KC_LCTL),
  
  COMBO(keys_ik,       TG(2)),
  COMBO(keys_mo3f,     MO(5)),
  COMBO(keys_mo4j,     MO(9)),

  /* COMBO(keys_yu,       KC_EQL), */
  COMBO(keys_ui,       RALT(KC_B)), 
  COMBO(keys_io,       RALT(KC_F)), 
  /* COMBO(keys_op,       KC_EQL), */
  /* COMBO(keys_uo,       KC_EQL), */

  /* COMBO(keys_hj,       KC_EQL), */
  COMBO(keys_jk,       KC_LBRC),
  COMBO(keys_kl,       KC_RBRC),
  COMBO(keys_lquot,    KC_SCLN), 
  COMBO(keys_jl,       KC_EQL),

  COMBO(keys_nm,       LGUI(KC_Z)),
  COMBO(keys_mcomma,   KC_ENT),
  /* [EVENT_COMMADOT] = COMBO(keys_commadot, KC_NO), */
  /* [EVENT_DOTSLASH] = COMBO(keys_dotslash, KC_NO), */
  /* [EVENT_MDOT]     = COMBO(keys_mdot,     KC_NO), */
};

uint16_t COMBO_LEN = ARRAY_SIZE(key_combos);

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
  if (layer_state_is(0) || layer_state_is(1)) {
    return true;
  }

  return false;
}

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

