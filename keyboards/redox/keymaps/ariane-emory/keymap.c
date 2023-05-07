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

#define DEFINE_COMBO_KEYS(name, ...)                                                           \
  const uint16_t PROGMEM keys_ ## name[] = { __VA_ARGS__, COMBO_END};

DEFINE_COMBO_KEYS(mo3mo4, MO(3), MO(4));
DEFINE_COMBO_KEYS(ik,             KC_I, KC_K);
DEFINE_COMBO_KEYS(mo3f,           MO(3), KC_F);
DEFINE_COMBO_KEYS(mo4j,           MO(4), KC_J);

DEFINE_COMBO_KEYS(yu,             KC_Y, KC_U);
DEFINE_COMBO_KEYS(ui,             KC_U, KC_I);
DEFINE_COMBO_KEYS(io,             KC_I, KC_O);
DEFINE_COMBO_KEYS(op,             KC_O, KC_P);
DEFINE_COMBO_KEYS(uo,             KC_U, KC_O);

DEFINE_COMBO_KEYS(hj,             KC_H, KC_J);

DEFINE_COMBO_KEYS(jk,             KC_J, KC_K);

DEFINE_COMBO_KEYS(kl,             KC_K, KC_L);
DEFINE_COMBO_KEYS(lquot,          KC_L, KC_QUOT);
DEFINE_COMBO_KEYS(jl,             KC_J, KC_L);

DEFINE_COMBO_KEYS(nm,             KC_N, KC_M);
DEFINE_COMBO_KEYS(mcomma,         KC_M, KC_COMM);
DEFINE_COMBO_KEYS(commadot,       KC_COMM, KC_DOT);
DEFINE_COMBO_KEYS(dotslash,       KC_DOT, KC_SLASH);
DEFINE_COMBO_KEYS(mdot,           KC_M, KC_DOT);

#undef DEFINE_COMBO_KEYS

combo_t key_combos[] = {
  COMBO(keys_mo3mo4, KC_LCTL),
  
  COMBO(keys_ik,     TG(2)),
  COMBO(keys_mo3f,   MO(5)),
  COMBO(keys_mo4j,   MO(9)),

  COMBO(keys_ui,     RALT(KC_B)), 
  COMBO(keys_io,     RALT(KC_F)), 

  COMBO(keys_jk,     KC_LBRC),
  COMBO(keys_kl,     KC_RBRC),
  COMBO(keys_lquot,  KC_SCLN), 
  COMBO(keys_jl,     KC_EQL),

  COMBO(keys_nm,     LGUI(KC_Z)),
  COMBO(keys_mcomma, KC_ENT),
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

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case LALT_T(KC_SPC):
    return false;
  default:
    return true;
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

