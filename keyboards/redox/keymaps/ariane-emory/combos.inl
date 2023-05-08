// ================================================================================
// Combos
// ================================================================================

#define DEFINE_COMBO_KEYS(name, ...)                                            \
  const uint16_t PROGMEM keys_ ## name[] = { __VA_ARGS__, COMBO_END };

//==============================================================================
/* Left top row */
DEFINE_COMBO_KEYS(__r_t,         KC_F, KC_G);            /* l_top_reach       */
DEFINE_COMBO_KEYS(__e_r,         KC_E, KC_R);            /* l_top_inner       */
DEFINE_COMBO_KEYS(__w_e,         KC_W, KC_E);            /* l_top_outer       */
DEFINE_COMBO_KEYS(__w_r,         KC_W, KC_R);            /* l_top_stretch     */
DEFINE_COMBO_KEYS(__q_r,         KC_Q, KC_R);            /* l_top_far_stretch */
DEFINE_COMBO_KEYS(__w_e_r,       KC_W, KC_E, KC_R);      /* l_top_triple      */
//==============================================================================
/* Left middle row */
DEFINE_COMBO_KEYS(__f_g,         KC_F, KC_G);            /* l_mid_reach       */
DEFINE_COMBO_KEYS(__d_f,         KC_D, KC_F);            /* l_mid_inner       */
DEFINE_COMBO_KEYS(__s_d,         KC_S, KC_D);            /* l_mid_outer       */
DEFINE_COMBO_KEYS(__s_f,         KC_S, KC_F);            /* l_mid_stretch     */
DEFINE_COMBO_KEYS(__a_f,         KC_A, KC_F);            /* l_mid_far_stretch */
DEFINE_COMBO_KEYS(__s_d_f,       KC_S, KC_D, KC_F);      /* l_mid_triple      */
//==============================================================================
/* Left bottom row */
DEFINE_COMBO_KEYS(__v_b,         KC_V, KC_B);            /* l_bot_reach       */
DEFINE_COMBO_KEYS(__c_v,         KC_C, KC_V);            /* l_bot_inner       */
DEFINE_COMBO_KEYS(__x_c,         KC_X, KC_C);            /* l_bot_outer       */ 
DEFINE_COMBO_KEYS(__x_v,         KC_X, KC_V);            /* l_bot_stretch     */
DEFINE_COMBO_KEYS(__z_v,         KC_Z, KC_V);            /* l_bot_far_stretch */
DEFINE_COMBO_KEYS(__x_c_v,       KC_X, KC_C, KC_V);      /* l_bot_triple      */
//==============================================================================

//==============================================================================
/* Right top row */
DEFINE_COMBO_KEYS(__y_u,         KC_Y, KC_U);            /* r_top_reach       */
DEFINE_COMBO_KEYS(__u_i,         KC_U, KC_I);            /* r_top_inner       */
DEFINE_COMBO_KEYS(__i_o,         KC_I, KC_O);            /* r_top_outer       */
DEFINE_COMBO_KEYS(__u_o,         KC_U, KC_O);            /* r_top_stretch     */
DEFINE_COMBO_KEYS(__u_p,         KC_U, KC_P);            /* r_top_far_stretch */
DEFINE_COMBO_KEYS(__u_i_o,       KC_U, KC_I, KC_O);      /* r_top_triple      */
//==============================================================================
/* Right middle row */
DEFINE_COMBO_KEYS(__h_j,         KC_H, KC_J);            /* r_mid_reach       */
DEFINE_COMBO_KEYS(__j_k,         KC_J, KC_K);            /* r_mid_inner       */
DEFINE_COMBO_KEYS(__k_l,         KC_K, KC_L);            /* r_mid_outer       */
DEFINE_COMBO_KEYS(__j_l,         KC_J, KC_L);            /* r_mid_stretch     */
DEFINE_COMBO_KEYS(__j_quot,      KC_J, KC_QUOT);         /* r_mid_far_stretch */
DEFINE_COMBO_KEYS(__j_k_l,       KC_J, KC_K, KC_L);      /* r_mid_triple      */
//==============================================================================
/* Right bottom row */
DEFINE_COMBO_KEYS(__n_m,         KC_N, KC_M);            /* r_bot_reach       */
DEFINE_COMBO_KEYS(__m_comma,     KC_M, KC_COMM);         /* r_bot_inner       */
DEFINE_COMBO_KEYS(__comma_dot,   KC_COMM, KC_DOT);       /* r_bot_outer       */
DEFINE_COMBO_KEYS(__m_dot,       KC_M, KC_DOT);          /* r_bot_stretch     */
DEFINE_COMBO_KEYS(__m_slash,     KC_M, KC_SLASH);        /* r_bot_far_stretch */
DEFINE_COMBO_KEYS(__m_comma_dot, KC_M, KC_COMM, KC_DOT); /* r_bot_triple      */
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

