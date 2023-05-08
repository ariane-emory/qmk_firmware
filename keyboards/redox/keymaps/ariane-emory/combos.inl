// =======================================================================================
// Combos
// =======================================================================================

#define DEFINE_COMBO_KEYS(name, ...)                                            \
  const uint16_t PROGMEM keys_ ## name[] = { __VA_ARGS__, COMBO_END };

//========================================================================================
/* Left top row */
DEFINE_COMBO_KEYS(l_top_rch,         KC_T, KC_R);
DEFINE_COMBO_KEYS(l_top_inr,         KC_E, KC_R);
DEFINE_COMBO_KEYS(l_top_out,         KC_W, KC_E);
DEFINE_COMBO_KEYS(l_top_str,         KC_W, KC_R);
DEFINE_COMBO_KEYS(l_top_far,         KC_Q, KC_R);
DEFINE_COMBO_KEYS(l_top_triple,      KC_W, KC_E, KC_R);
//========================================================================================
/* Left middle row */
DEFINE_COMBO_KEYS(l_mid_rch,         KC_F, KC_G);
DEFINE_COMBO_KEYS(l_mid_inr,         KC_D, KC_F);
DEFINE_COMBO_KEYS(l_mid_out,         KC_S, KC_D);
DEFINE_COMBO_KEYS(l_mid_str,         KC_S, KC_F);
DEFINE_COMBO_KEYS(l_mid_far,         KC_A, KC_F);
DEFINE_COMBO_KEYS(l_mid_triple,      KC_S, KC_D, KC_F);
//========================================================================================
/* Left bottom row */
DEFINE_COMBO_KEYS(l_bot_rch,         KC_V, KC_B);
DEFINE_COMBO_KEYS(l_bot_inr,         KC_C, KC_V);
DEFINE_COMBO_KEYS(l_bot_out,         KC_X, KC_C);
DEFINE_COMBO_KEYS(l_bot_str,         KC_X, KC_V);
DEFINE_COMBO_KEYS(l_bot_far,         KC_Z, KC_V);
DEFINE_COMBO_KEYS(l_bot_triple,      KC_X, KC_C, KC_V);
//========================================================================================
/* Left middle/bottom row */
DEFINE_COMBO_KEYS(l_pinky_dip,       KC_F, KC_Z);
//========================================================================================

//========================================================================================
/* Right top row */
DEFINE_COMBO_KEYS(r_top_rch,         KC_Y, KC_U);
DEFINE_COMBO_KEYS(r_top_inr,         KC_U, KC_I);
DEFINE_COMBO_KEYS(r_top_out,         KC_I, KC_O);
DEFINE_COMBO_KEYS(r_top_str,         KC_U, KC_O);
DEFINE_COMBO_KEYS(r_top_far,         KC_U, KC_P);
DEFINE_COMBO_KEYS(r_top_triple,      KC_U, KC_I, KC_O);
//========================================================================================
/* Right middle row */
DEFINE_COMBO_KEYS(r_mid_rch,         KC_H, KC_J);
DEFINE_COMBO_KEYS(r_mid_inr,         KC_J, KC_K);
DEFINE_COMBO_KEYS(r_mid_out,         KC_K, KC_L);
DEFINE_COMBO_KEYS(r_mid_str,         KC_J, KC_L);
DEFINE_COMBO_KEYS(r_mid_far,         KC_J, KC_QUOT);
DEFINE_COMBO_KEYS(r_mid_triple,      KC_J, KC_K, KC_L);
//========================================================================================
/* Right bottom row */
DEFINE_COMBO_KEYS(r_bot_rch,         KC_N, KC_M);
DEFINE_COMBO_KEYS(r_bot_inr,         KC_M, KC_COMM);
DEFINE_COMBO_KEYS(r_bot_out,         KC_COMM, KC_DOT);
DEFINE_COMBO_KEYS(r_bot_str,         KC_M, KC_DOT);
DEFINE_COMBO_KEYS(r_bot_far,         KC_M, KC_SLASH);
DEFINE_COMBO_KEYS(r_bot_triple,      KC_M,  KC_COMM, KC_DOT);
//========================================================================================
/* Right middle/bottom row */
DEFINE_COMBO_KEYS(r_pinky_dip,       KC_J, KC_SLASH);
//========================================================================================

#undef DEFINE_COMBO_KEYS

combo_t key_combos[] = {
  //========================================================================================
  /* Left top row */
  COMBO(keys_l_top_rch,                       KC_NO),
  COMBO(keys_l_top_inr,                       LCTL(KC_TAB)),
  COMBO(keys_l_top_out,                       LSFT(LCTL(KC_TAB))),
  COMBO(keys_l_top_str,                       KC_NO),
  COMBO(keys_l_top_far,                       KC_NO),
  COMBO(keys_l_top_triple,                    KC_NO),
  //========================================================================================
  /* Left middle row */
  COMBO(keys_l_mid_rch,                       KC_ENT),
  COMBO(keys_l_mid_inr,                       KC_F22),
  COMBO(keys_l_mid_out,                       KC_F21),
  COMBO(keys_l_mid_str,                       KC_NO),
  COMBO(keys_l_mid_far,                       KC_NO),
  COMBO(keys_l_mid_triple,                    KC_F23),
  //========================================================================================
  /* Left bottom row */
  COMBO(keys_l_bot_rch,                       LGUI(KC_Z)),
  COMBO(keys_l_bot_inr,                       LCTL(KC_TAB)),
  COMBO(keys_l_bot_out,                       LSFT(LCTL(KC_TAB))),
  COMBO(keys_l_bot_str,                       KC_NO),
  COMBO(keys_l_bot_far,                       KC_NO),
  COMBO(keys_l_bot_triple,                    KC_NO),
  //========================================================================================
  /* Left middle/bottom row */
  COMBO(keys_l_pinky_dip,                     KC_NO),
  //========================================================================================

  //========================================================================================
  /* Right top row */
  COMBO(keys_r_top_rch,                       KC_NO),
  COMBO(keys_r_top_inr,                       KC_NO),
  COMBO(keys_r_top_out,                       KC_NO),
  COMBO(keys_r_top_str,                       KC_NO),
  COMBO(keys_r_top_far,                       KC_NO),
  COMBO(keys_r_top_triple,                    KC_NO),
  //========================================================================================
  /* Right middle row */
  COMBO(keys_r_mid_rch,                       KC_ENT),
  COMBO(keys_r_mid_inr,                       KC_LBRC),
  COMBO(keys_r_mid_out,                       KC_RBRC),
  COMBO(keys_r_mid_str,                       KC_SCLN),
  COMBO(keys_r_mid_far,                       KC_NO),
  COMBO(keys_r_mid_triple,                    KC_EQL),
  //========================================================================================
  /* Right bottom row */
  COMBO(keys_r_bot_rch,                       LGUI(KC_Z)),
  COMBO(keys_r_bot_inr,                       KC_ENT),
  COMBO(keys_r_bot_out,                       KC_NO),
  COMBO(keys_r_bot_str,                       KC_NO),
  COMBO(keys_r_bot_far,                       KC_NO),
  COMBO(keys_r_bot_triple,                    KC_NO),
  //========================================================================================
  /* Right middle/bottom row */
  COMBO(keys_r_pinky_dip,                     SS_UPDIR),
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

