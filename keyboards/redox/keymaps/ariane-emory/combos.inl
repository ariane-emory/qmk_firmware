// =======================================================================================
// Combos
// =======================================================================================

#define DEFINE_COMBO_KEYS(name, ...)                                            \
  const uint16_t PROGMEM keys_ ## name[] = { __VA_ARGS__, COMBO_END };

//========================================================================================
/* Left top row */
DEFINE_COMBO_KEYS(l_top_reach,         KC_F, KC_G);
DEFINE_COMBO_KEYS(l_top_inner,         KC_E, KC_R);
DEFINE_COMBO_KEYS(l_top_outer,         KC_W, KC_E);
DEFINE_COMBO_KEYS(l_top_stretch,       KC_W, KC_R);
DEFINE_COMBO_KEYS(l_top_far_stretch,   KC_Q, KC_R);
DEFINE_COMBO_KEYS(l_top_triple,        KC_W, KC_E, KC_R);
//========================================================================================
/* Left middle row */
DEFINE_COMBO_KEYS(l_mid_reach,         KC_F, KC_G);
DEFINE_COMBO_KEYS(l_mid_inner,         KC_D, KC_F);
DEFINE_COMBO_KEYS(l_mid_outer,         KC_S, KC_D);
DEFINE_COMBO_KEYS(l_mid_stretch,       KC_S, KC_F);
DEFINE_COMBO_KEYS(l_mid_far_stretch,   KC_A, KC_F);
DEFINE_COMBO_KEYS(l_mid_triple,        KC_S, KC_D, KC_F);
//========================================================================================
/* Left bottom row */
DEFINE_COMBO_KEYS(l_bot_reach,         KC_V, KC_B);
DEFINE_COMBO_KEYS(l_bot_inner,         KC_C, KC_V);
DEFINE_COMBO_KEYS(l_bot_outer,         KC_X, KC_C);
DEFINE_COMBO_KEYS(l_bot_stretch,       KC_X, KC_V);
DEFINE_COMBO_KEYS(l_bot_far_stretch,   KC_Z, KC_V);
DEFINE_COMBO_KEYS(l_bot_triple,        KC_X, KC_C, KC_V);
//========================================================================================

//========================================================================================
/* Right top row */
DEFINE_COMBO_KEYS(r_top_reach,         KC_Y, KC_U);
DEFINE_COMBO_KEYS(r_top_inner,         KC_U, KC_I);
DEFINE_COMBO_KEYS(r_top_outer,         KC_I, KC_O);
DEFINE_COMBO_KEYS(r_top_stretch,       KC_U, KC_O);
DEFINE_COMBO_KEYS(r_top_far_stretch,   KC_U, KC_P);
DEFINE_COMBO_KEYS(r_top_triple,        KC_U, KC_I, KC_O);
//========================================================================================
/* Right middle row */
DEFINE_COMBO_KEYS(r_mid_reach,         KC_H, KC_J);
DEFINE_COMBO_KEYS(r_mid_inner,         KC_J, KC_K);
DEFINE_COMBO_KEYS(r_mid_outer,         KC_K, KC_L);
DEFINE_COMBO_KEYS(r_mid_stretch,       KC_J, KC_L);
DEFINE_COMBO_KEYS(r_mid_far_stretch,   KC_J, KC_QUOT);
DEFINE_COMBO_KEYS(r_mid_triple,        KC_J, KC_K, KC_L);
//========================================================================================
/* Right bottom row */
DEFINE_COMBO_KEYS(r_bot_reach,         KC_N, KC_M);
DEFINE_COMBO_KEYS(r_bot_inner,         KC_M, KC_COMM);
DEFINE_COMBO_KEYS(r_bot_outer,         KC_COMM, KC_DOT);
DEFINE_COMBO_KEYS(r_bot_stretch,       KC_M, KC_DOT);
DEFINE_COMBO_KEYS(r_bot_far_stretch,   KC_M, KC_SLASH);
DEFINE_COMBO_KEYS(r_bot_triple, KC_M,  KC_COMM, KC_DOT);
//========================================================================================

#undef DEFINE_COMBO_KEYS

combo_t key_combos[] = {
  //========================================================================================
  /* Left top row */
  COMBO(keys_l_top_reach,                     KC_TRNS),
  COMBO(keys_l_top_inner,                     LCTL(KC_TAB)),
  COMBO(keys_l_top_outer,                     LSFT(LCTL(KC_TAB))),
  COMBO(keys_l_top_stretch,                   KC_TRNS),
  COMBO(keys_l_top_far_stretch,               KC_TRNS),
  COMBO(keys_l_top_triple,                    KC_TRNS),
  //========================================================================================
  /* Left middle row */
  COMBO(keys_l_mid_reach,                     KC_ENT),
  COMBO(keys_l_mid_inner,                     KC_F22),
  COMBO(keys_l_mid_outer,                     KC_F21),
  COMBO(keys_l_mid_stretch,                   KC_TRNS),
  COMBO(keys_l_mid_far_stretch,               KC_TRNS),
  COMBO(keys_l_mid_triple,                    KC_F23),
  //========================================================================================
  /* Left bottom row */
  COMBO(keys_l_bot_reach,                     LGUI(KC_Z)),
  COMBO(keys_l_bot_inner,                     LCTL(KC_TAB)),
  COMBO(keys_l_bot_outer,                     LSFT(LCTL(KC_TAB))),
  COMBO(keys_l_bot_stretch,                   KC_TRNS),
  COMBO(keys_l_bot_far_stretch,               KC_TRNS),
  COMBO(keys_l_bot_triple,                    KC_TRNS),
  //========================================================================================

  //========================================================================================
  /* Right top row */
  COMBO(keys_r_top_reach,                     KC_TRNS),
  COMBO(keys_r_top_inner,                     KC_TRNS),
  COMBO(keys_r_top_outer,                     KC_TRNS),
  COMBO(keys_r_top_stretch,                   KC_TRNS),
  COMBO(keys_r_top_far_stretch,               KC_TRNS),
  COMBO(keys_r_top_triple,                    KC_TRNS),
  //========================================================================================
  /* Right middle row */
  COMBO(keys_r_mid_reach,                     KC_ENT),
  COMBO(keys_r_mid_inner,                     KC_LBRC),
  COMBO(keys_r_mid_outer,                     KC_RBRC),
  COMBO(keys_r_mid_stretch,                   KC_SCLN),
  COMBO(keys_r_mid_far_stretch,               KC_TRNS),
  COMBO(keys_r_mid_triple,                    KC_EQL),
  //========================================================================================
  /* Right bottom row */
  COMBO(keys_r_bot_reach,                     LGUI(KC_Z)),
  COMBO(keys_r_bot_inner,                     KC_ENT),
  COMBO(keys_r_bot_outer,                     KC_TRNS),
  COMBO(keys_r_bot_stretch,                   KC_TRNS),
  COMBO(keys_r_bot_far_stretch,               KC_TRNS),
  COMBO(keys_r_bot_triple,                    KC_TRNS),
  //========================================================================================
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

