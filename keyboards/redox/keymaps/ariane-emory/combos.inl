// =======================================================================================
// Combos
// =======================================================================================

#define DEFINE_COMBO_KEYS(name, ...)                                            \
  const uint16_t PROGMEM keys_ ## name[] = { __VA_ARGS__, COMBO_END };

//========================================================================================
// Define left hand combo keys
//========================================================================================
/* Left number row */
DEFINE_COMBO_KEYS(l_num_triple, KC_2,    KC_3,      KC_4);
DEFINE_COMBO_KEYS(l_num_spr,    KC_2,    KC_4);
DEFINE_COMBO_KEYS(l_num_rch,    KC_4,    KC_5);
DEFINE_COMBO_KEYS(l_num_edg,    KC_1,    KC_2);
DEFINE_COMBO_KEYS(l_num_inr,    KC_3,    KC_4);
DEFINE_COMBO_KEYS(l_num_out,    KC_2,    KC_3);
//========================================================================================
/* Left top row */
DEFINE_COMBO_KEYS(l_top_triple, KC_W,    KC_E,      KC_R);
DEFINE_COMBO_KEYS(l_top_spr,    KC_W,    KC_R);
DEFINE_COMBO_KEYS(l_top_rch,    KC_T,    KC_R);
DEFINE_COMBO_KEYS(l_top_edg,    KC_Q,    KC_W);
DEFINE_COMBO_KEYS(l_top_inr,    KC_E,    KC_R);
DEFINE_COMBO_KEYS(l_top_out,    KC_W,    KC_E);
//========================================================================================
/* Left middle row */
DEFINE_COMBO_KEYS(l_mid_triple, KC_S,    KC_D,      KC_F);
DEFINE_COMBO_KEYS(l_mid_spr,    KC_S,    KC_F);
DEFINE_COMBO_KEYS(l_mid_rch,    KC_F,    KC_G);
DEFINE_COMBO_KEYS(l_mid_edg,    KC_A,    KC_S);
DEFINE_COMBO_KEYS(l_mid_inr,    KC_D,    KC_F);
DEFINE_COMBO_KEYS(l_mid_out,    KC_S,    KC_D);
//========================================================================================
/* Left bottom row */
DEFINE_COMBO_KEYS(l_bot_triple, KC_X,    KC_C,      KC_V);
DEFINE_COMBO_KEYS(l_bot_spr,    KC_X,    KC_V);
DEFINE_COMBO_KEYS(l_bot_rch,    KC_V,    KC_B);
DEFINE_COMBO_KEYS(l_bot_edg,    KC_Z,    KC_X);
DEFINE_COMBO_KEYS(l_bot_inr,    KC_C,    KC_V);
DEFINE_COMBO_KEYS(l_bot_out,    KC_X,    KC_C);
//========================================================================================
/* Left middle/bottom row */
DEFINE_COMBO_KEYS(l_pinky_dip,       KC_F,    KC_Z);
//========================================================================================

//========================================================================================
// Define right hand combo keys
//========================================================================================
/* Right top row */
DEFINE_COMBO_KEYS(r_top_triple, KC_U,    KC_I,      KC_O);
DEFINE_COMBO_KEYS(r_top_spr,    KC_U,    KC_O);
DEFINE_COMBO_KEYS(r_top_rch,    KC_Y,    KC_U);
DEFINE_COMBO_KEYS(r_top_edg,    KC_O,    KC_P);
DEFINE_COMBO_KEYS(r_top_inr,    KC_U,    KC_I);
DEFINE_COMBO_KEYS(r_top_out,    KC_I,    KC_O);
//========================================================================================
/* Right middle row */
DEFINE_COMBO_KEYS(r_mid_triple, KC_J,    KC_K,      KC_L);
DEFINE_COMBO_KEYS(r_mid_spr,    KC_J,    KC_L);
DEFINE_COMBO_KEYS(r_mid_rch,    KC_H,    KC_J);
DEFINE_COMBO_KEYS(r_mid_edg,    KC_L,    KC_QUOT);
DEFINE_COMBO_KEYS(r_mid_inr,    KC_J,    KC_K);
DEFINE_COMBO_KEYS(r_mid_out,    KC_K,    KC_L);
//========================================================================================
/* Right bottom row */
DEFINE_COMBO_KEYS(r_bot_triple, KC_M,    KC_COMM,   KC_DOT);
DEFINE_COMBO_KEYS(r_bot_spr,    KC_M,    KC_DOT);
DEFINE_COMBO_KEYS(r_bot_rch,    KC_N,    KC_M);
DEFINE_COMBO_KEYS(r_bot_edg,    KC_DOT,  KC_SLASH);
DEFINE_COMBO_KEYS(r_bot_inr,    KC_M,    KC_COMM);
DEFINE_COMBO_KEYS(r_bot_out,    KC_COMM, KC_DOT);
//========================================================================================
/* Right middle/bottom row */
DEFINE_COMBO_KEYS(r_pinky_dip,       KC_J,    KC_SLASH);
//========================================================================================


//========================================================================================
// Bind combos
//========================================================================================
combo_t key_combos[] = {
  //======================================================================================
  // Bind left hand combos
  //======================================================================================
  /* Left num row */
  // COMBO(keys_l_num_triple,   KC_NO),          // 5
  // COMBO(keys_l_num_spr,      KC_NO),          // 4
  COMBO(keys_l_num_rch,         DF(2)),          // 0
  // COMBO(keys_l_num_edg,      KC_NO),          // 1
  COMBO(keys_l_num_inr,         DF(1)),          // 2
  COMBO(keys_l_num_out,         DF(0)),          // 3
  //======================================================================================
  /* Left top row */
  // COMBO(keys_l_top_triple,   KC_NO),          // 5
  // COMBO(keys_l_top_spr,      KC_NO),          // 4
  // COMBO(keys_l_top_rch,      KC_NO),          // 0
  // COMBO(keys_l_top_edg,      KC_NO),          // 1
  // COMBO(keys_l_top_inr,      KC_NO),          // 2
  // COMBO(keys_l_top_out,      KC_NO),          // 3
  //======================================================================================
  /* Left middle row */
  COMBO(keys_l_mid_triple,      SS_TILD_SLASH),  // 11
  // COMBO(keys_l_mid_spr,      KC_NO),          // 10
  COMBO(keys_l_mid_rch,         KC_ENT),         // 6
  // COMBO(keys_l_mid_edg,      KC_NO),          // 7
  COMBO(keys_l_mid_inr,         SS_TILD),        // 8
  COMBO(keys_l_mid_out,         SS_GRAV),        // 9
  //======================================================================================
  /* Left bottom row */
  // COMBO(keys_l_bot_triple,   KC_NO),          // 17
  // COMBO(keys_l_bot_spr,      KC_NO),          // 16
  COMBO(keys_l_bot_rch,         LGUI(KC_Z)),     // 12
  // COMBO(keys_l_bot_edg,      KC_NO),          // 13
  // COMBO(keys_l_bot_inr,      KC_NO),          // 14
  // COMBO(keys_l_bot_out,      KC_NO),          // 15
  //======================================================================================
  /* Left middle/bottom row */
  // COMBO(keys_l_pinky_dip,    KC_NO),          // 18
  //======================================================================================

  //======================================================================================
  // Bind right hand combos
  //======================================================================================
  /* Right top row */
  // COMBO(keys_r_top_triple,   LGUI(KC_SPC)),
  // COMBO(keys_r_top_spr,      LCTL(KC_Y)),
  COMBO(keys_r_top_rch,         LCTL(KC_Y)),
  COMBO(keys_r_top_edg,         LCTL(KC_SPC)),
  COMBO(keys_r_top_inr,         LCTL(KC_K)),
  COMBO(keys_r_top_out,         LCTL(KC_W)),
  //======================================================================================
  /* Right middle row */
  COMBO(keys_r_mid_triple,      KC_SCLN),
  COMBO(keys_r_mid_spr,         KC_EQL),
  COMBO(keys_r_mid_rch,         KC_ENT),
  // COMBO(keys_r_mid_edg,      KC_NO), 
  COMBO(keys_r_mid_inr,         KC_LBRC), 
  COMBO(keys_r_mid_out,         KC_RBRC),
  //======================================================================================
  /* Right bottom row */
  COMBO(keys_r_bot_triple,      KC_ESC),
  COMBO(keys_r_bot_spr,         LCTL(KC_SPC)),
  COMBO(keys_r_bot_rch,         LGUI(KC_Z)),
  COMBO(keys_r_bot_edg,         SS_UPDIR),
  COMBO(keys_r_bot_inr,         SS_LPAR),
  COMBO(keys_r_bot_out,         SS_RPAR),
  //======================================================================================
  /* Right middle/bottom row */
  COMBO(keys_r_pinky_dip,       SS_UPDIR),
  //======================================================================================
};
//========================================================================================

//========================================================================================
uint16_t COMBO_LEN = ARRAY_SIZE(key_combos);

bool combo_should_trigger(
  uint16_t combo_index,
  combo_t *combo,
  uint16_t keycode,
  keyrecord_t *record) {
  return (layer_state_is(0) ||
          layer_state_is(7) ||
          (layer_state_is(2) && combo_index <= 4));
}
//========================================================================================

// =======================================================================================
// Undefine local macros
// =======================================================================================

#undef DEFINE_COMBO_KEYS
