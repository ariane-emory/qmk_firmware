#ifdef COMBO_ENABLE

#include "key_aliases.h"

// =======================================================================================
// Combos
// =======================================================================================

#define DEFINE_COMBO_KEYS(name, ...)                                            \
  const uint16_t PROGMEM keys_ ## name[] = { __VA_ARGS__, COMBO_END };

//========================================================================================
// Define left hand combo keys
//========================================================================================
/* Left number row */
DEFINE_COMBO_KEYS(l_num_trpi,    KC_3,            KC_4,              KC_5);
DEFINE_COMBO_KEYS(l_num_trpm,    KC_2,            KC_3,              KC_4);
DEFINE_COMBO_KEYS(l_num_trpo,    KC_1,            KC_2,              KC_3);
DEFINE_COMBO_KEYS(l_num_sprd,    KC_2,            KC_4);
DEFINE_COMBO_KEYS(l_num_rech,    KC_4,            KC_5);
DEFINE_COMBO_KEYS(l_num_edge,    KC_1,            KC_2);
DEFINE_COMBO_KEYS(l_num_innr,    KC_3,            KC_4);
DEFINE_COMBO_KEYS(l_num_outr,    KC_2,            KC_3);
//========================================================================================
/* Left top row */
DEFINE_COMBO_KEYS(l_top_trpi,    KC_E,            KC_R,              KC_T);
DEFINE_COMBO_KEYS(l_top_trpm,    KC_W,            KC_E,              KC_R);
DEFINE_COMBO_KEYS(l_top_trpo,    KC_Q,            KC_W,              KC_E);
DEFINE_COMBO_KEYS(l_top_sprd,    KC_W,            KC_R);
DEFINE_COMBO_KEYS(l_top_rech,    KC_T,            KC_R);
DEFINE_COMBO_KEYS(l_top_edge,    KC_Q,            KC_W);
DEFINE_COMBO_KEYS(l_top_innr,    KC_E,            KC_R);
DEFINE_COMBO_KEYS(l_top_outr,    KC_W,            KC_E);
//========================================================================================
/* Left middle row */
DEFINE_COMBO_KEYS(l_mid_trpi,    QH_D,            QH_F,              KC_G);
DEFINE_COMBO_KEYS(l_mid_trpm,    QH_S,            QH_D,              QH_F);
DEFINE_COMBO_KEYS(l_mid_trpo,    QH_A,            QH_S,              QH_D);
DEFINE_COMBO_KEYS(l_mid_sprd,    QH_S,            QH_F);
DEFINE_COMBO_KEYS(l_mid_rech,    QH_F,            KC_G);
DEFINE_COMBO_KEYS(l_mid_edge,    QH_A,            QH_S);
DEFINE_COMBO_KEYS(l_mid_innr,    QH_D,            QH_F);
DEFINE_COMBO_KEYS(l_mid_outr,    QH_S,            QH_D);
//========================================================================================
/* Left bottom row */
DEFINE_COMBO_KEYS(l_bot_trpi,    QB_C,            QB_V,              KC_B);
DEFINE_COMBO_KEYS(l_bot_trpm,    QB_X,            QB_C,              QB_V);
DEFINE_COMBO_KEYS(l_bot_trpo,    QB_Z,            QB_X,              QB_C);
DEFINE_COMBO_KEYS(l_bot_sprd,    QB_X,            QB_V);
DEFINE_COMBO_KEYS(l_bot_rech,    QB_V,            KC_B);
DEFINE_COMBO_KEYS(l_bot_edge,    QB_Z,            QB_X);
DEFINE_COMBO_KEYS(l_bot_innr,    QB_C,            QB_V);
DEFINE_COMBO_KEYS(l_bot_outr,    QB_X,            QB_C);
//========================================================================================
/* Left middle/bottom row */
DEFINE_COMBO_KEYS(l_pinky_dip,   QH_F,            QB_Z);
//========================================================================================

//========================================================================================
// Define right hand combo keys
//========================================================================================
/* Right top row */
DEFINE_COMBO_KEYS(r_top_trpi,    KC_Y,            KC_U,              KC_I);
DEFINE_COMBO_KEYS(r_top_trpm,    KC_U,            KC_I,              KC_O);
DEFINE_COMBO_KEYS(r_top_trpo,    KC_I,            KC_O,              KC_P);
DEFINE_COMBO_KEYS(r_top_sprd,    KC_U,            KC_O);
DEFINE_COMBO_KEYS(r_top_rech,    KC_Y,            KC_U);
DEFINE_COMBO_KEYS(r_top_edge,    KC_O,            KC_P);
DEFINE_COMBO_KEYS(r_top_innr,    KC_U,            KC_I);
DEFINE_COMBO_KEYS(r_top_outr,    KC_I,            KC_O);
//========================================================================================
/* Right middle row */
DEFINE_COMBO_KEYS(r_mid_trpi,    KC_H,            QH_J,               QH_K);
DEFINE_COMBO_KEYS(r_mid_trpm,    QH_J,            QH_K,               QH_L);
DEFINE_COMBO_KEYS(r_mid_trpo,    QH_K,            QH_L,               QH_QUOT);
DEFINE_COMBO_KEYS(r_mid_sprd,    QH_J,            QH_L);
DEFINE_COMBO_KEYS(r_mid_rech,    KC_H,            QH_J);
DEFINE_COMBO_KEYS(r_mid_edge,    QH_L,            QH_QUOT);
DEFINE_COMBO_KEYS(r_mid_innr,    QH_J,            QH_K);
DEFINE_COMBO_KEYS(r_mid_outr,    QH_K,            QH_L);
DEFINE_COMBO_KEYS(r_mid_EXTR,    QH_QUOT,         RCTL_T(KC_DQUO));
//========================================================================================
/* Right bottom row */
DEFINE_COMBO_KEYS(r_bot_trpi,    KC_N,            QB_M,              QB_COMM);
DEFINE_COMBO_KEYS(r_bot_trpm,    QB_M,            QB_COMM,           QB_DOT);
DEFINE_COMBO_KEYS(r_bot_trpo,    QB_COMM,         QB_DOT,            QB_SLSH);
DEFINE_COMBO_KEYS(r_bot_sprd,    QB_M,            QB_DOT);
DEFINE_COMBO_KEYS(r_bot_rech,    KC_N,            QB_M);
DEFINE_COMBO_KEYS(r_bot_edge,    QB_DOT,          KC_SLSH);
DEFINE_COMBO_KEYS(r_bot_innr,    QB_M,            QB_COMM);
DEFINE_COMBO_KEYS(r_bot_outr,    QB_COMM,         QB_DOT);
//========================================================================================
/* Right middle/bottom row */
DEFINE_COMBO_KEYS(r_pinky_dip,   QH_J,            KC_SLSH);
//========================================================================================


//========================================================================================
// Bind combos
//========================================================================================
combo_t key_combos[] = {
  //======================================================================================
  // Bind left hand combos
  //================================================================================s======
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
  COMBO(keys_l_top_rech,         KC_NO),            //
  COMBO(keys_l_top_trpi,         SS_SPC_TILD_SLSH), // '  ~/'
  // COMBO(keys_l_top_innr,         KC_NO),            //
  COMBO(keys_l_top_trpm,         SS_TILD_SLSH),     // ~/
  COMBO(keys_l_top_outr,         SS_TILD),          // ~
  COMBO(keys_l_top_trpo,         INSERT_UPP),       // insert a UPP
  COMBO(keys_l_top_edge,         SS_GRAV),          // `
  // COMBO(keys_l_top_sprd,         KC_NO),            //
  //======================================================================================
  /* SECTION: Left middle row */
  // COMBO(keys_l_mid_rech,         KC_NO),            //
  COMBO(keys_l_mid_trpi,         LALT(LGUI(KC_E))), // macro end  
  COMBO(keys_l_mid_innr,         KC_ENT),           // enter
  COMBO(keys_l_mid_trpm,         LALT(LGUI(KC_R))), // macro repeat
  // COMBO(keys_l_mid_outr,         KC_NO),            //
  COMBO(keys_l_mid_trpo,         LALT(LGUI(KC_W))), // macro start
  // COMBO(keys_l_mid_edge,         KC_NO),            //
  // COMBO(keys_l_mid_sprd,         KC_NO),            //
  //======================================================================================
  /* SECTION: Left bottom row */
  COMBO(keys_l_bot_rech,         EM_SWITCH_BUFFER), // switch buffer
  // COMBO(keys_l_bot_trpi,         KC_NO),            //
  COMBO(keys_l_bot_innr,         LGUI(KC_Z)),       // undo
  // COMBO(keys_l_bot_trpm,         KC_NO),            //
  COMBO(keys_l_bot_outr,         LCTL(KC_C)),       // C-c
  // COMBO(keys_l_bot_trpo,         KC_NO),            //
  COMBO(keys_l_bot_edge,         LCTL(KC_X)),       // C-x
  COMBO(keys_l_bot_sprd,         KC_ESC),           // escape
  //======================================================================================
  /* Left middle/bottom row */
  // COMBO(keys_l_pinky_dip,     KC_NO),
  //======================================================================================
  
  //======================================================================================
  // Bind right hand combos
  //======================================================================================
  /* SECTION: Right top row */
  // COMBO(keys_r_top_rech,         KC_NO),            // 
  // COMBO(keys_r_top_trpi,         KC_NO),            // 
  COMBO(keys_r_top_innr,         SS_LPAR),          // (
  // COMBO(keys_r_top_trpm,         KC_NO),            // 
  COMBO(keys_r_top_outr,         SS_RPAR),          // )
  COMBO(keys_r_top_trpo,         SS_RPAR_SCLN),     // ); 
  COMBO(keys_r_top_edge,         EM_REVERT),        // revert buffer
  // COMBO(keys_r_top_sprd,         KC_NO),            // 
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
  // COMBO(keys_r_mid_EXTR,         KC_NO),            // 
  //======================================================================================
  /* SECTION: Right bottom row */
  COMBO(keys_r_bot_rech,         EM_LASTARG),       // last arg
  COMBO(keys_r_bot_trpi,         EM_REPEAT),        // repeat last 
  COMBO(keys_r_bot_innr,         LGUI(KC_Z)),       // undo
  COMBO(keys_r_bot_trpm,         LALT(LGUI(KC_S))), // shell
  COMBO(keys_r_bot_outr,         SS_ARROW),         // -> 
  COMBO(keys_r_bot_trpo,         SS_UPDIR),         // ../
  COMBO(keys_r_bot_edge,         SS_THISDIR),       // ./
  COMBO(keys_r_bot_sprd,         KC_ESC),           // escape
  //======================================================================================
  /* Right middle/bottom row */
  COMBO(keys_r_pinky_dip,        SS_UPDIR),
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
  return (layer_state_is(0)
          || layer_state_is(1)
          || layer_state_is(2)
          || layer_state_is(3)
          || layer_state_is(4)
          || layer_state_is(5) 
          // || (layer_state_is(6) && combo_index <= 10)
          );
}
//========================================================================================

// =======================================================================================
// Undefine local macros
// =======================================================================================

#undef DEFINE_COMBO_KEYS

#endif
