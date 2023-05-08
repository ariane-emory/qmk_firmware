#include QMK_KEYBOARD_H

#include "secrets.h" // #define AE_PIN1 and AE_PIN2 in this file.

// ================================================================================
// Custom keycodes
// ================================================================================

enum arianes_keycodes {
  SS_UPDIR = SAFE_RANGE,
  SS_PIN1,
  SS_PIN2,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case SS_PIN1:
    if (record->event.pressed) {
      SEND_STRING(AE_PIN1);
    }
    return false;
  case SS_PIN2:
    if (record->event.pressed) {
      SEND_STRING(AE_PIN2);
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
// Combos
// ================================================================================

#define DEFINE_COMBO_KEYS(name, ...)                                            \
  const uint16_t PROGMEM keys_ ## name[] = { __VA_ARGS__, COMBO_END };

DEFINE_COMBO_KEYS(i_k,         KC_I, KC_K);
DEFINE_COMBO_KEYS(lwr_f,       QK_TRI_LAYER_LOWER, KC_F);
DEFINE_COMBO_KEYS(upr_j,       QK_TRI_LAYER_UPPER, KC_J);

/* Right top row */
DEFINE_COMBO_KEYS(y_u,         KC_Y, KC_U);
DEFINE_COMBO_KEYS(u_i,         KC_U, KC_I);
DEFINE_COMBO_KEYS(i_o,         KC_I, KC_O);
DEFINE_COMBO_KEYS(o_p,         KC_O, KC_P);
DEFINE_COMBO_KEYS(u_o,         KC_U, KC_O);         /* stretch */

/* Right middle row */
DEFINE_COMBO_KEYS(h_j,         KC_H, KC_J);
DEFINE_COMBO_KEYS(j_k,         KC_J, KC_K);
DEFINE_COMBO_KEYS(k_l,         KC_K, KC_L);
DEFINE_COMBO_KEYS(l_quot,      KC_L, KC_QUOT);
DEFINE_COMBO_KEYS(k_quot,      KC_K, KC_QUOT);      /* stretch */
DEFINE_COMBO_KEYS(j_l,         KC_J, KC_L);         /* stretch */

/* Right bottom row */
DEFINE_COMBO_KEYS(n_m,         KC_N, KC_M);
DEFINE_COMBO_KEYS(m_comma,     KC_M, KC_COMM);
DEFINE_COMBO_KEYS(comma_dot,   KC_COMM, KC_DOT);
DEFINE_COMBO_KEYS(dot_slash,   KC_DOT, KC_SLASH);
DEFINE_COMBO_KEYS(comma_slash, KC_COMMA, KC_SLASH); /* stretch */
DEFINE_COMBO_KEYS(m_dot,       KC_M, KC_DOT);       /* stretch */

#undef DEFINE_COMBO_KEYS

combo_t key_combos[] = {
  COMBO(keys_upr_j, LGUI(KC_Z)),
  
  /* COMBO(keys_u_i,       RALT(KC_B)),  */
  /* COMBO(keys_i_o,       RALT(KC_F)),  */
  
  COMBO(keys_j_k,         KC_LBRC),
  COMBO(keys_k_l,         KC_RBRC),
  COMBO(keys_k_quot,      KC_SCLN),
  COMBO(keys_l_quot,      KC_SCLN), 
  COMBO(keys_j_l,         KC_EQL),

  COMBO(keys_n_m,         LGUI(KC_Z)),
  COMBO(keys_m_comma,     KC_ENT),
  COMBO(keys_comma_slash, SS_UPDIR),
  COMBO(keys_dot_slash,   SS_UPDIR),
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
   case QK_MOD_TAP ... QK_MOD_TAP_MAX:
     if (keycode == MT(MOD_LALT,KC_SPC)) {
       return false;
     }
     else {
       return true;
     }
  default:
    return false;
   }
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
// Tapping term
// ================================================================================

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
      /* case SFT_T(KC_SPC): */
      /*   return 5000; */
    default:
      return TAPPING_TERM;
    }
}

// ================================================================================
// Include inlines
// ================================================================================

#include "keymap.inl"

