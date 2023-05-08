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

//==============================================================================
/* Left top row */
DEFINE_COMBO_KEYS(r_t,         KC_F, KC_G);            /* reach   */
DEFINE_COMBO_KEYS(e_r,         KC_E, KC_R);            /* inner   */
DEFINE_COMBO_KEYS(w_e,         KC_W, KC_E);            /* outer   */
DEFINE_COMBO_KEYS(w_r,         KC_W, KC_R);            /* stretch */
DEFINE_COMBO_KEYS(w_e_r,       KC_W, KC_E, KC_R);      /* triple  */
//==============================================================================
/* Left middle row */
DEFINE_COMBO_KEYS(f_g,         KC_F, KC_G);            /* reach   */
DEFINE_COMBO_KEYS(d_f,         KC_D, KC_F);            /* inner   */
DEFINE_COMBO_KEYS(s_d,         KC_S, KC_D);            /* outer   */
DEFINE_COMBO_KEYS(s_f,         KC_S, KC_F);            /* stretch */
DEFINE_COMBO_KEYS(s_d_f,       KC_S, KC_D, KC_F);      /* triple  */
//==============================================================================
/* Left bottom row */
DEFINE_COMBO_KEYS(v_b,         KC_V, KC_B);            /* reach   */
DEFINE_COMBO_KEYS(c_v,         KC_C, KC_V);            /* inner   */
DEFINE_COMBO_KEYS(x_c,         KC_X, KC_C);            /* outer   */ 
DEFINE_COMBO_KEYS(x_v,         KC_X, KC_V);            /* stretch */
DEFINE_COMBO_KEYS(x_c_v,       KC_X, KC_C, KC_V);      /* triple  */
//==============================================================================
/* Right top row */
DEFINE_COMBO_KEYS(y_u,         KC_Y, KC_U);            /* reach   */
DEFINE_COMBO_KEYS(u_i,         KC_U, KC_I);            /* inner   */
DEFINE_COMBO_KEYS(i_o,         KC_I, KC_O);            /* outer   */
DEFINE_COMBO_KEYS(u_o,         KC_U, KC_O);            /* stretch */
DEFINE_COMBO_KEYS(u_i_o,       KC_U, KC_I, KC_O);      /* triple  */
//==============================================================================
/* Right middle row */
DEFINE_COMBO_KEYS(h_j,         KC_H, KC_J);            /* reach   */
DEFINE_COMBO_KEYS(j_k,         KC_J, KC_K);            /* inner   */
DEFINE_COMBO_KEYS(k_l,         KC_K, KC_L);            /* outer   */
DEFINE_COMBO_KEYS(j_l,         KC_J, KC_L);            /* stretch */
DEFINE_COMBO_KEYS(j_k_l,       KC_J, KC_K, KC_L);      /* triple  */
//------------------------------------------------------------------------------
DEFINE_COMBO_KEYS(l_quot,      KC_L, KC_QUOT);
DEFINE_COMBO_KEYS(k_quot,      KC_K, KC_QUOT);         /* stretch */
DEFINE_COMBO_KEYS(j_quot,      KC_J, KC_QUOT);         /* stretch */
//==============================================================================
/* Right bottom row */
DEFINE_COMBO_KEYS(n_m,         KC_N, KC_M);            /* reach   */
DEFINE_COMBO_KEYS(m_comma,     KC_M, KC_COMM);         /* inner   */
DEFINE_COMBO_KEYS(comma_dot,   KC_COMM, KC_DOT);       /* outer   */
DEFINE_COMBO_KEYS(m_dot,       KC_M, KC_DOT);          /* stretch */
DEFINE_COMBO_KEYS(m_comma_dot, KC_M, KC_COMM, KC_DOT); /* triple  */
//==============================================================================

#undef DEFINE_COMBO_KEYS

combo_t key_combos[] = {
  //============================================================================
  /* Left top row */
  COMBO(keys_e_r,         LCTL(KC_TAB)),            /* inner  */
  COMBO(keys_w_e,         LSFT(LCTL(KC_TAB))),      /* outer  */
  //============================================================================
  /* Left middle row */
  COMBO(keys_d_f,         KC_F22),                  /* inner   */
  COMBO(keys_s_d,         KC_F21),                  /* outer   */
  COMBO(keys_s_d_f,       KC_F23),                  /* triple  */
  //============================================================================
  /* Left bottom row */
  COMBO(keys_c_v,         LCTL(KC_TAB)),            /* inner   */
  COMBO(keys_x_c,         LSFT(LCTL(KC_TAB))),      /* outer   */
  //============================================================================
  /* Right middle row */
  COMBO(keys_h_j,         KC_ENT),                  /* reach   */
  COMBO(keys_j_k,         KC_LBRC),                 /* inner   */
  COMBO(keys_k_l,         KC_RBRC),                 /* outer   */
  COMBO(keys_j_l,         KC_SCLN),                 /* stretch */
  COMBO(keys_j_k_l,       KC_EQL),                  /* triple  */
  //============================================================================
  /* Right bottom row */
  COMBO(keys_n_m,         LGUI(KC_Z)),              /* reach   */
  COMBO(keys_m_comma,     LGUI(KC_Z)),              /* inner   */
  //============================================================================
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
// Include inlines
// ================================================================================

#include "keymap.inl"

