// =======================================================================================
// Combos
// =======================================================================================

#define DEFINE_COMBO_KEYS(name, ...)                                            \
  const uint16_t PROGMEM keys_ ## name[] = { __VA_ARGS__, COMBO_END };

//========================================================================================
/* Left top row */
DEFINE_COMBO_KEYS(l_top_reach,         KC_F, KC_G);            /* l_top_reach       */
DEFINE_COMBO_KEYS(l_top_inner,         KC_E, KC_R);            /* l_top_inner       */
DEFINE_COMBO_KEYS(l_top_outer,         KC_W, KC_E);            /* l_top_outer       */
DEFINE_COMBO_KEYS(l_top_stretch,       KC_W, KC_R);            /* l_top_stretch     */
DEFINE_COMBO_KEYS(l_top_far_stretch,   KC_Q, KC_R);            /* l_top_far_stretch */
DEFINE_COMBO_KEYS(l_top_triple,        KC_W, KC_E, KC_R);      /* l_top_triple      */
//========================================================================================
/* Left middle row */
DEFINE_COMBO_KEYS(l_mid_reach,         KC_F, KC_G);            /* l_mid_reach       */
DEFINE_COMBO_KEYS(l_mid_inner,         KC_D, KC_F);            /* l_mid_inner       */
DEFINE_COMBO_KEYS(l_mid_outer,         KC_S, KC_D);            /* l_mid_outer       */
DEFINE_COMBO_KEYS(l_mid_stretch,       KC_S, KC_F);            /* l_mid_stretch     */
DEFINE_COMBO_KEYS(l_mid_far_stretch,   KC_A, KC_F);            /* l_mid_far_stretch */
DEFINE_COMBO_KEYS(l_mid_triple,        KC_S, KC_D, KC_F);      /* l_mid_triple      */
//========================================================================================
/* Left bottom row */
DEFINE_COMBO_KEYS(l_bot_reach,         KC_V, KC_B);            /* l_bot_reach       */
DEFINE_COMBO_KEYS(l_bot_inner,         KC_C, KC_V);            /* l_bot_inner       */
DEFINE_COMBO_KEYS(l_bot_outer,         KC_X, KC_C);            /* l_bot_outer       */ 
DEFINE_COMBO_KEYS(l_bot_stretch,       KC_X, KC_V);            /* l_bot_stretch     */
DEFINE_COMBO_KEYS(l_bot_far_stretch,   KC_Z, KC_V);            /* l_bot_far_stretch */
DEFINE_COMBO_KEYS(l_bot_triple,        KC_X, KC_C, KC_V);      /* l_bot_triple      */
//========================================================================================

//========================================================================================
/* Right top row */
DEFINE_COMBO_KEYS(r_top_reach,         KC_Y, KC_U);            /* r_top_reach       */
DEFINE_COMBO_KEYS(r_top_inner,         KC_U, KC_I);            /* r_top_inner       */
DEFINE_COMBO_KEYS(r_top_outer,         KC_I, KC_O);            /* r_top_outer       */
DEFINE_COMBO_KEYS(r_top_stretch,       KC_U, KC_O);            /* r_top_stretch     */
DEFINE_COMBO_KEYS(r_top_far_stretch,   KC_U, KC_P);            /* r_top_far_stretch */
DEFINE_COMBO_KEYS(r_top_triple,        KC_U, KC_I, KC_O);      /* r_top_triple      */
//========================================================================================
/* Right middle row */
DEFINE_COMBO_KEYS(r_mid_reach,         KC_H, KC_J);            /* r_mid_reach       */
DEFINE_COMBO_KEYS(r_mid_inner,         KC_J, KC_K);            /* r_mid_inner       */
DEFINE_COMBO_KEYS(r_mid_outer,         KC_K, KC_L);            /* r_mid_outer       */
DEFINE_COMBO_KEYS(r_mid_stretch,       KC_J, KC_L);            /* r_mid_stretch     */
DEFINE_COMBO_KEYS(r_mid_far_stretch,   KC_J, KC_QUOT);         /* r_mid_far_stretch */
DEFINE_COMBO_KEYS(r_mid_triple,        KC_J, KC_K, KC_L);      /* r_mid_triple      */
//========================================================================================
/* Right bottom row */
DEFINE_COMBO_KEYS(r_bot_reach,         KC_N, KC_M);            /* r_bot_reach       */
DEFINE_COMBO_KEYS(r_bot_inner,         KC_M, KC_COMM);         /* r_bot_inner       */
DEFINE_COMBO_KEYS(r_bot_outer,         KC_COMM, KC_DOT);       /* r_bot_outer       */
DEFINE_COMBO_KEYS(r_bot_stretch,       KC_M, KC_DOT);          /* r_bot_stretch     */
DEFINE_COMBO_KEYS(r_bot_far_stretch,   KC_M, KC_SLASH);        /* r_bot_far_stretch */
DEFINE_COMBO_KEYS(r_bot_triple, KC_M,  KC_COMM, KC_DOT);       /* r_bot_triple      */
//========================================================================================

#undef DEFINE_COMBO_KEYS

combo_t key_combos[] = {
  //======================================================================================
  /* Left top row */
  COMBO(keys_top_inner,         LCTL(KC_TAB)),            /* inner  */
  COMBO(keys_top_outer,         LSFT(LCTL(KC_TAB))),      /* outer  */
  //======================================================================================
  /* Left middle row */
  COMBO(keys_mid_inner,         KC_F22),                  /* inner   */
  COMBO(keys_mid_outer,         KC_F21),                  /* outer   */
  COMBO(keys_mid_triple,       KC_F23),                  /* triple  */
  //======================================================================================
  /* Left bottom row */
  COMBO(keys_bot_inner,         LCTL(KC_TAB)),            /* inner   */
  COMBO(keys_bot_outer,         LSFT(LCTL(KC_TAB))),      /* outer   */
  //======================================================================================
  
  //======================================================================================
  /* Right middle row */
  COMBO(keys_h_j,         KC_ENT),                  /* reach   */
  COMBO(keys_j_k,         KC_LBRC),                 /* inner   */
  COMBO(keys_k_l,         KC_RBRC),                 /* outer   */
  COMBO(keys_j_l,         KC_SCLN),                 /* stretch */
  COMBO(keys_j_k_l,       KC_EQL),                  /* triple  */
  //======================================================================================
  /* Right bottom row */
  COMBO(keys_n_m,         LGUI(KC_Z)),              /* reach   */
  COMBO(keys_m_comma,     LGUI(KC_Z)),              /* inner   */
  //======================================================================================
};

//========================================================================================

uint16_t COMBO_LEN = ARRAY_SIZE(key_combos);

bool combo_should_trigger(
  uint16_t combo_index,
  combo_t *combo,
  uint16_t keycode,
  keyrecord_t *record) {
  if (layer_state_is(0) || layer_state_is(1)) {
    return true;
  }

  return false;
}

