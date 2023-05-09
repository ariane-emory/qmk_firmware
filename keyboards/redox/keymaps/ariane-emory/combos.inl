// =======================================================================================
// Combos
// =======================================================================================

#define DEFINE_COMBO_KEYS(name, ...)                                            \
  const uint16_t PROGMEM keys_ ## name[] = { __VA_ARGS__, COMBO_END };

//========================================================================================
/* Left top row */
DEFINE_COMBO_KEYS(l_top_rch,         KC_T,    KC_R);
DEFINE_COMBO_KEYS(l_top_edg,         KC_Q,    KC_W);
DEFINE_COMBO_KEYS(l_top_inr,         KC_E,    KC_R);
DEFINE_COMBO_KEYS(l_top_out,         KC_W,    KC_E);
DEFINE_COMBO_KEYS(l_top_spr,         KC_W,    KC_R);
DEFINE_COMBO_KEYS(l_top_triple,      KC_W,    KC_E,      KC_R);
//========================================================================================
/* Left middle row */
DEFINE_COMBO_KEYS(l_mid_rch,         KC_F,    KC_G);
DEFINE_COMBO_KEYS(l_mid_edg,         KC_A,    KC_S);
DEFINE_COMBO_KEYS(l_mid_inr,         KC_D,    KC_F);
DEFINE_COMBO_KEYS(l_mid_out,         KC_S,    KC_D);
DEFINE_COMBO_KEYS(l_mid_spr,         KC_S,    KC_F);
DEFINE_COMBO_KEYS(l_mid_triple,      KC_S,    KC_D,      KC_F);
//========================================================================================
/* Left bottom row */
DEFINE_COMBO_KEYS(l_bot_rch,         KC_V,    KC_B);
DEFINE_COMBO_KEYS(l_bot_edg,         KC_Z,    KC_X);
DEFINE_COMBO_KEYS(l_bot_inr,         KC_C,    KC_V);
DEFINE_COMBO_KEYS(l_bot_out,         KC_X,    KC_C);
DEFINE_COMBO_KEYS(l_bot_spr,         KC_X,    KC_V);
DEFINE_COMBO_KEYS(l_bot_triple,      KC_X,    KC_C,      KC_V);
//========================================================================================
/* Left middle/bottom row */
DEFINE_COMBO_KEYS(l_pinky_dip,       KC_F,    KC_Z);
//========================================================================================

//========================================================================================
/* Right top row */
DEFINE_COMBO_KEYS(r_top_rch,         KC_Y,    KC_U);
DEFINE_COMBO_KEYS(r_top_edg,         KC_O,    KC_P);
DEFINE_COMBO_KEYS(r_top_inr,         KC_U,    KC_I);
DEFINE_COMBO_KEYS(r_top_out,         KC_I,    KC_O);
DEFINE_COMBO_KEYS(r_top_spr,         KC_U,    KC_O);
DEFINE_COMBO_KEYS(r_top_triple,      KC_U,    KC_I,      KC_O);
//========================================================================================
/* Right middle row */
DEFINE_COMBO_KEYS(r_mid_rch,         KC_H,    KC_J);
DEFINE_COMBO_KEYS(r_mid_edg,         KC_L,    KC_QUOT);
DEFINE_COMBO_KEYS(r_mid_inr,         KC_J,    KC_K);
DEFINE_COMBO_KEYS(r_mid_out,         KC_K,    KC_L);
DEFINE_COMBO_KEYS(r_mid_spr,         KC_J,    KC_L);
DEFINE_COMBO_KEYS(r_mid_triple,      KC_J,    KC_K,      KC_L);
//========================================================================================
/* Right bottom row */
DEFINE_COMBO_KEYS(r_bot_rch,         KC_N,    KC_M);
DEFINE_COMBO_KEYS(r_bot_edg,         KC_DOT,  KC_SLASH);
DEFINE_COMBO_KEYS(r_bot_inr,         KC_M,    KC_COMM);
DEFINE_COMBO_KEYS(r_bot_out,         KC_COMM, KC_DOT);
DEFINE_COMBO_KEYS(r_bot_spr,         KC_M,    KC_DOT);
DEFINE_COMBO_KEYS(r_bot_triple,      KC_M,    KC_COMM,   KC_DOT);
//========================================================================================
/* Right middle/bottom row */
DEFINE_COMBO_KEYS(r_pinky_dip,       KC_J,    KC_SLASH);
//========================================================================================

#undef DEFINE_COMBO_KEYS

combo_t key_combos[] = {
  //========================================================================================
  /* Left top row */
  // COMBO(keys_l_top_rch,                       KC_NO),       // 0
  // COMBO(keys_l_top_edg,                       KC_NO),       // 1
  // COMBO(keys_l_top_inr,                       KC_NO),       // 2
  // COMBO(keys_l_top_out,                       KC_NO),       // 3
  // COMBO(keys_l_top_spr,                       KC_NO),       // 4
  // COMBO(keys_l_top_triple,                    KC_NO),       // 5
  //========================================================================================
  /* Left middle row */
  COMBO(keys_l_mid_rch,                       KC_ENT),      // 6
  // COMBO(keys_l_mid_edg,                       KC_NO),       // 7
  // COMBO(keys_l_mid_inr,                       KC_NO),       // 8
  // COMBO(keys_l_mid_out,                       KC_NO),       // 9
  // COMBO(keys_l_mid_spr,                       KC_NO),       // 10
  // COMBO(keys_l_mid_triple,                    KC_NO),       // 11
  //========================================================================================
  /* Left bottom row */
  COMBO(keys_l_bot_rch,                       LGUI(KC_Z)),  // 12
  // COMBO(keys_l_bot_edg,                       KC_NO),       // 13
  // COMBO(keys_l_bot_inr,                       KC_NO),       // 14
  // COMBO(keys_l_bot_out,                       KC_NO),       // 15
  // COMBO(keys_l_bot_spr,                       KC_NO),       // 16
  // COMBO(keys_l_bot_triple,                    KC_NO),       // 17
  //========================================================================================
  /* Left middle/bottom row */
  // COMBO(keys_l_pinky_dip,                     KC_NO),       // 18
  //========================================================================================

  //========================================================================================
  /* Right top row */
  COMBO(keys_r_top_rch,                       LCTL(KC_Y)),
  COMBO(keys_r_top_edg,                       LCTL(KC_SPC)),
  COMBO(keys_r_top_inr,                       LCTL(KC_W)),
  COMBO(keys_r_top_out,                       LCTL(KC_K)),
// COMBO(keys_r_top_spr,                         LCTL(KC_Y)),
  // COMBO(keys_r_top_triple,                    LGUI(KC_SPC)),
  //========================================================================================
  /* Right middle row */
  COMBO(keys_r_mid_rch,                       KC_ENT),
  // COMBO(keys_r_mid_edg,                       KC_NO), 
  COMBO(keys_r_mid_inr,                       KC_LBRC), 
  COMBO(keys_r_mid_out,                       KC_RBRC),
  COMBO(keys_r_mid_spr,                       KC_EQL),
  COMBO(keys_r_mid_triple,                    KC_SCLN),  
  //========================================================================================
  /* Right bottom row */
  COMBO(keys_r_bot_rch,                       LGUI(KC_Z)),
  COMBO(keys_r_bot_edg,                       SS_UPDIR),
  COMBO(keys_r_bot_inr,                       SS_LPAR),
  COMBO(keys_r_bot_out,                       SS_RPAR),
  COMBO(keys_r_bot_spr,                       KC_ESC),
  COMBO(keys_r_bot_triple,                    LCTL(KC_SPC)),
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
  if (layer_state_is(0) || layer_state_is(1) ||
      (layer_state_is(2) && combo_index <= 1))
    return true;

  return false;
}
