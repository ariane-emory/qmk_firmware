// =======================================================================================
// Combos
// =======================================================================================

#define DEFINE_COMBO_KEYS(name, ...)                                            \
  const uint16_t PROGMEM keys_ ## name[] = { __VA_ARGS__, COMBO_END };

//========================================================================================
// Define left hand combo keys
//========================================================================================
/* Left number row */
DEFINE_COMBO_KEYS(l_num_trpi,    KC_3,    KC_4,      KC_5);
DEFINE_COMBO_KEYS(l_num_trpm,    KC_2,    KC_3,      KC_4);
DEFINE_COMBO_KEYS(l_num_trpo,    KC_1,    KC_2,      KC_3);
DEFINE_COMBO_KEYS(l_num_sprd,    KC_2,    KC_4);
DEFINE_COMBO_KEYS(l_num_rech,    KC_4,    KC_5);
DEFINE_COMBO_KEYS(l_num_edge,    KC_1,    KC_2);
DEFINE_COMBO_KEYS(l_num_innr,    KC_3,    KC_4);
DEFINE_COMBO_KEYS(l_num_outr,    KC_2,    KC_3);
//========================================================================================
/* Left top row */
DEFINE_COMBO_KEYS(l_top_trpi,    KC_E,    KC_R,      KC_T);
DEFINE_COMBO_KEYS(l_top_trpm,    KC_W,    KC_E,      KC_R);
DEFINE_COMBO_KEYS(l_top_trpo,    KC_Q,    KC_W,      KC_E);
DEFINE_COMBO_KEYS(l_top_sprd,    KC_W,    KC_R);
DEFINE_COMBO_KEYS(l_top_rech,    KC_T,    KC_R);
DEFINE_COMBO_KEYS(l_top_edge,    KC_Q,    KC_W);
DEFINE_COMBO_KEYS(l_top_innr,    KC_E,    KC_R);
DEFINE_COMBO_KEYS(l_top_outr,    KC_W,    KC_E);
//========================================================================================
/* Left middle row */
DEFINE_COMBO_KEYS(l_mid_trpi,    KC_D,    KC_F,      KC_G);
DEFINE_COMBO_KEYS(l_mid_trpm,    KC_S,    KC_D,      KC_F);
DEFINE_COMBO_KEYS(l_mid_trpo,    KC_A,    KC_S,      KC_D);
DEFINE_COMBO_KEYS(l_mid_sprd,    KC_S,    KC_F);
DEFINE_COMBO_KEYS(l_mid_rech,    KC_F,    KC_G);
DEFINE_COMBO_KEYS(l_mid_edge,    KC_A,    KC_S);
DEFINE_COMBO_KEYS(l_mid_innr,    KC_D,    KC_F);
DEFINE_COMBO_KEYS(l_mid_outr,    KC_S,    KC_D);
//========================================================================================
/* Left bottom row */
DEFINE_COMBO_KEYS(l_bot_trpi,    KC_C,    KC_V,      KC_B);
DEFINE_COMBO_KEYS(l_bot_trpm,    KC_X,    KC_C,      KC_V);
DEFINE_COMBO_KEYS(l_bot_trpo,    KC_Z,    KC_X,      KC_C);
DEFINE_COMBO_KEYS(l_bot_sprd,    KC_X,    KC_V);
DEFINE_COMBO_KEYS(l_bot_rech,    KC_V,    KC_B);
DEFINE_COMBO_KEYS(l_bot_edge,    KC_Z,    KC_X);
DEFINE_COMBO_KEYS(l_bot_innr,    KC_C,    KC_V);
DEFINE_COMBO_KEYS(l_bot_outr,    KC_X,    KC_C);
//========================================================================================
/* Left middle/bottom row */
DEFINE_COMBO_KEYS(l_pinky_dip,       KC_F,    KC_Z);
//========================================================================================

//========================================================================================
// Define right hand combo keys
//========================================================================================
/* Right top row */
DEFINE_COMBO_KEYS(r_top_trpi,    KC_Y,    KC_U,      KC_I);
DEFINE_COMBO_KEYS(r_top_trpm,    KC_U,    KC_I,      KC_O);
DEFINE_COMBO_KEYS(r_top_trpo,    KC_I,    KC_O,      KC_P);
DEFINE_COMBO_KEYS(r_top_sprd,    KC_U,    KC_O);
DEFINE_COMBO_KEYS(r_top_rech,    KC_Y,    KC_U);
DEFINE_COMBO_KEYS(r_top_edge,    KC_O,    KC_P);
DEFINE_COMBO_KEYS(r_top_innr,    KC_U,    KC_I);
DEFINE_COMBO_KEYS(r_top_outr,    KC_I,    KC_O);
//========================================================================================
/* Right middle row */
DEFINE_COMBO_KEYS(r_mid_trpi,    KC_H,    KC_J,      KC_K);
DEFINE_COMBO_KEYS(r_mid_trpm,    KC_J,    KC_K,      KC_L);
DEFINE_COMBO_KEYS(r_mid_trpo,    KC_K,    KC_L,      KC_QUOT);
DEFINE_COMBO_KEYS(r_mid_sprd,    KC_J,    KC_L);
DEFINE_COMBO_KEYS(r_mid_rech,    KC_H,    KC_J);
DEFINE_COMBO_KEYS(r_mid_edge,    KC_L,    KC_QUOT);
DEFINE_COMBO_KEYS(r_mid_innr,    KC_J,    KC_K);
DEFINE_COMBO_KEYS(r_mid_outr,    KC_K,    KC_L);
//========================================================================================
/* Right bottom row */
DEFINE_COMBO_KEYS(r_bot_trpi,    KC_N,    KC_M,      KC_COMM);
DEFINE_COMBO_KEYS(r_bot_trpm,    KC_M,    KC_COMM,   KC_DOT);
DEFINE_COMBO_KEYS(r_bot_trpo,    KC_COMM, KC_DOT,    KC_SLSH);
DEFINE_COMBO_KEYS(r_bot_sprd,    KC_M,    KC_DOT);
DEFINE_COMBO_KEYS(r_bot_rech,    KC_N,    KC_M);
DEFINE_COMBO_KEYS(r_bot_edge,    KC_DOT,  KC_SLASH);
DEFINE_COMBO_KEYS(r_bot_innr,    KC_M,    KC_COMM);
DEFINE_COMBO_KEYS(r_bot_outr,    KC_COMM, KC_DOT);
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
  /* SECTION: Left num row */
  COMBO(keys_l_num_rech,         DF(3)),
  // COMBO(keys_l_num_trpi,         KC_NO),
  COMBO(keys_l_num_innr,         DF(2)),        
  // COMBO(keys_l_num_trpm,         KC_NO),
  COMBO(keys_l_num_outr,         DF(1)),        
  // COMBO(keys_l_num_trpo,         KC_NO),
  COMBO(keys_l_num_edge,         DF(0)),
  // COMBO(keys_l_num_sprd,         KC_NO),
  //======================================================================================
  /* SECTION: Left top row */ 
  // COMBO(keys_l_top_rech,         KC_NO),
  // COMBO(keys_l_top_trpi,         KC_NO),
  // COMBO(keys_l_top_innr,         KC_NO),
  // COMBO(keys_l_top_trpm,         KC_NO),
  // COMBO(keys_l_top_outr,         KC_NO),
  // COMBO(keys_l_top_trpo,         KC_NO),
  // COMBO(keys_l_top_edge,         KC_NO),
  // COMBO(keys_l_top_sprd,         KC_NO),
  //======================================================================================
  /* SECTION: Left middle row */
  COMBO(keys_l_mid_rech,         SS_GRAV),
  // COMBO(keys_l_mid_trpi,         KC_NO),
  COMBO(keys_l_mid_innr,         KC_ENT),
  COMBO(keys_l_mid_trpm,         SS_TILD_SLASH),
  COMBO(keys_l_mid_outr,         SS_TILD),
  // COMBO(keys_l_mid_topm,         KC_NO),
  // COMBO(keys_l_mid_edge,         KC_NO),
  // COMBO(keys_l_mid_sprd,         KC_NO),
  //======================================================================================
  /* SECTION: Left bottom row */
  // COMBO(keys_l_bot_rech,      KC_NO),
  // COMBO(keys_l_bot_trpi,      KC_NO),
  COMBO(keys_l_bot_innr,         LGUI(KC_Z)),
  // COMBO(keys_l_bot_trpm,      KC_NO),
  // COMBO(keys_l_bot_outr,      KC_NO)
  // COMBO(keys_l_bot_topm,      KC_NO),
  // COMBO(keys_l_bot_edge,      KC_NO),
  COMBO(keys_l_bot_sprd,         KC_ESC),
  //======================================================================================
  /* Left middle/bottom row */
  // COMBO(keys_l_pinky_dip,     KC_NO),
  //======================================================================================
  
  //======================================================================================
  // Bind right hand combos
  //======================================================================================
  /* SECTION: Right top row */
  COMBO(keys_r_top_rech,         SS_LPAR),          // (
  COMBO(keys_r_top_trpi,         LCTL(KC_K)),       // kill line
  COMBO(keys_r_top_innr,         SS_LPAR),          // (
  COMBO(keys_r_top_trpm,         LCTL(KC_Y)),       // yank
  COMBO(keys_r_top_outr,         SS_RPAR),          // )
  COMBO(keys_r_top_trpo,         LCTL(KC_W)),       // kill region
  // COMBO(keys_r_top_edge,         KC_NO),            // 
  COMBO(keys_r_top_sprd,         LCTL(KC_SPC)),     // mark
  //======================================================================================
  /* SECTION: Right middle row */
  COMBO(keys_r_mid_rech,         KC_LBRC),          // {
  COMBO(keys_r_mid_trpi,         LALT(LGUI(KC_V))), // previous buffer/
  COMBO(keys_r_mid_innr,         KC_ENT),           // <CR>
  COMBO(keys_r_mid_trpm,         LALT(LGUI(KC_D))), // dired
  COMBO(keys_r_mid_outr,         KC_RBRC),          // }
  COMBO(keys_r_mid_trpo,         LALT(LGUI(KC_A))), // all buffers
  COMBO(keys_r_mid_edge,         KC_SCLN),          // ;
  COMBO(keys_r_mid_sprd,         KC_EQL),           // =
  //======================================================================================
  /* SECTION: Right bottom row */
  // COMBO(keys_r_bot_rech,         KC_NO),            // 
  // COMBO(keys_r_bot_trpi,         KC_NO),            // 
  COMBO(keys_r_bot_innr,         LGUI(KC_Z)),       // 
  COMBO(keys_r_bot_trpm,         LALT(LGUI(KC_S))), // shell
  // COMBO(keys_r_bot_outr,         KC_NO),            // 
  // COMBO(keys_r_bot_trpo,         KC_NO),            // 
  COMBO(keys_r_bot_edge,         SS_UPDIR),         // 
  COMBO(keys_r_bot_sprd,         KC_ESC),           // 
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
          layer_state_is(1) ||
          layer_state_is(2) ||
          layer_state_is(3) ||
          layer_state_is(4) ||
          layer_state_is(5) ||
          (layer_state_is(6) && combo_index <= 8));
}
//========================================================================================

// =======================================================================================
// Undefine local macros
// =======================================================================================

#undef DEFINE_COMBO_KEYS
