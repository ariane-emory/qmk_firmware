#ifdef COMBO_ENABLE

#include "key_aliases.h"

// =======================================================================================
// Combos
// =======================================================================================

#define MY_COMBOS                                                               \
  CCC(l_num_trpi,    KC_NO,            KC_3,    KC_4,              KC_5);       \
  CCC(l_num_trpm,    KC_NO,            KC_2,    KC_3,              KC_4);       \
  CCC(l_num_trpo,    KC_NO,            KC_1,    KC_2,              KC_3);       \
  CCC(l_num_sprd,    KC_NO,            KC_2,    KC_4);                          \
  CCC(l_num_rech,    DF(3),            KC_4,    KC_5);                          \
  CCC(l_num_edge,    DF(0),            KC_1,    KC_2);                          \
  CCC(l_num_innr,    DF(2),            KC_3,    KC_4);                          \
  CCC(l_num_outr,    DF(1),            KC_2,    KC_3);                          \
  CCC(l_top_trpi,    KC_NO,            KC_E,    KC_R,              KC_T);       \
  CCC(l_top_trpm,    KC_NO,            KC_W,    KC_E,              KC_R);       \
  CCC(l_top_trpo,    KC_NO,            KC_Q,    KC_W,              KC_E);       \
  CCC(l_top_sprd,    KC_NO,            KC_W,    KC_R);                          \
  CCC(l_top_rech,    SS_TILD_SLSH,     KC_T,    KC_R);                          \
  CCC(l_top_edge,    SS_GRAV,          KC_Q,    KC_W);                          \
  CCC(l_top_innr,    KC_NO,            KC_E,    KC_R);                          \
  CCC(l_top_outr,    SS_TILD,          KC_W,    KC_E);                          \
  CCC(l_mid_trpi,    KC_NO,            QH_D,    QH_F,              KC_G);       \
  CCC(l_mid_trpm,    EM_SWICH_BUFFER,  QH_S,    QH_D,              QH_F);       \
  CCC(l_mid_trpo,    KC_NO,            QH_A,    QH_S,              QH_D);       \
  CCC(l_mid_sprd,    KC_NO,            QH_S,    QH_F);                          \
  CCC(l_mid_rech,    LALT(LGUI(KC_E)), QH_F,    KC_G);                          \
  CCC(l_mid_edge,    LALT(LGUI(KC_W)), QH_A,    QH_S);                          \
  CCC(l_mid_innr,    KC_ENTR,          QH_D,    QH_F);                          \
  CCC(l_mid_outr,    LALT(LGUI(KC_R)), QH_S,    QH_D);                          \
  CCC(l_bot_trpi,    KC_NO,            QB_C,    QB_V,              KC_B);       \
  CCC(l_bot_trpm,    EM_SWICH_BUFFER,  QB_X,    QB_C,              QB_V);       \
  CCC(l_bot_trpo,    KC_NO,            QB_Z,    QB_X,              QB_C);       \
  CCC(l_bot_sprd,    KC_NO,            QB_X,    QB_V);                          \
  CCC(l_bot_rech,    EM_SWITCH_BUFFER, QB_V,    KC_B);                          \
  CCC(l_bot_edge,    LCTL(KC_X),       QB_Z,    QB_X);                          \
  CCC(l_bot_innr,    LGUI(KC_Z),       QB_C,    QB_V);                          \
  CCC(l_bot_outr,    LCTL(KC_C),       QB_X,    QB_C);                          \
  CCC(l_pinky_dip,   QKC_NO,           QH_F,    QB_Z);                          \
  CCC(r_top_trpi,    KC_NO,            KC_Y,    KC_U,              KC_I);       \
  CCC(r_top_trpm,    KC_NO,            KC_U,    KC_I,              KC_O);       \
  CCC(r_top_trpo,    KC_NO,            KC_I,    KC_O,              KC_P);       \
  CCC(r_top_sprd,    KC_NO,            KC_U,    KC_O);                          \
  CCC(r_top_rech,    KC_NO,            KC_Y,    KC_U);                          \
  CCC(r_top_edge,    EM_REVERT,        KC_O,    KC_P);                          \
  CCC(r_top_innr,    SS_LPAR,          KC_U,    KC_I);                          \
  CCC(r_top_outr,    SS_RPAR,          KC_I,    KC_O);                          \
  CCC(r_mid_trpi,    LALT(LGUI(KC_V)), KC_H,    QH_J,               QH_K);      \
  CCC(r_mid_trpm,    LALT(LGUI(KC_D)), QH_J,    QH_K,               QH_L);      \
  CCC(r_mid_trpo,    LALT(LGUI(KC_A)), QH_K,    QH_L,               QH_QUOT);   \
  CCC(r_mid_sprd,    KC_EQL,           QH_J,    QH_L);                          \
  CCC(r_mid_rech,    KC_LBRC,          KC_H,    QH_J);                          \
  CCC(r_mid_edge,    KC_SCLN,          QH_L,    QH_QUOT);                       \
  CCC(r_mid_innr,    KC_ENTR,          QH_J,    QH_K);                          \
  CCC(r_mid_outr,    KC_RBR,           QH_K,    QH_L);                          \
  CCC(r_mid_EXTR,    LALT(LGUI(KC_A))  QH_QUOT, RCTL_T(KC_DQUO));               \
  CCC(r_bot_trpi,    EM_REPEAT,        KC_N,    QB_M,              QB_COMM);    \
  CCC(r_bot_trpm,    LALT(LGUI(KC_S)), QB_M,    QB_COMM,           QB_DOT);     \
  CCC(r_bot_trpo,    SS_UPDIR,         QB_COMM, QB_DOT,            QB_SLSH);    \
  CCC(r_bot_sprd,    KC_NO,            QB_M,    QB_DOT);                        \
  CCC(r_bot_rech,    EM_LASTARG,       KC_N,    QB_M);                          \
  CCC(r_bot_edge,    SS_THISDIR,       QB_DOT,  KC_SLSH);                       \
  CCC(r_bot_innr,    LGUI(KC_Z),       QB_M,    QB_COMM);                       \
  CCC(r_bot_outr,    SS_ARRPW,         QB_COMM, QB_DOT);                        \
  CCC(r_pinky_dip,   SS_UPDIR,         QH_J,    KC_SLSH);

#define CCC(name, ignored, ...)                                                 \
  const uint16_t PROGMEM keys_ ## name[] = { __VA_ARGS__, COMBO_END };

MY_COMBOS;

#undef CCC

//========================================================================================
// Bind combos
//========================================================================================
combo_t key_combos[] = {
#define CCC(name, binding, ...) COMBO(name, binding),
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
  COMBO(keys_l_top_rech,         SS_TILD_SLSH),     // ~/
  // COMBO(keys_l_top_trpi,         SS_SPC_TILD_SLSH), // '  ~/'
  // COMBO(keys_l_top_innr,         KC_NO),            //
  // COMBO(keys_l_top_trpm,         KC_NO),            //
  COMBO(keys_l_top_outr,         SS_TILD),          // ~
  // COMBO(keys_l_top_trpo,         INSERT_UPP),       // insert a UPP
  COMBO(keys_l_top_edge,         SS_GRAV),          // `
  // COMBO(keys_l_top_sprd,         KC_NO),            //
  //======================================================================================
  /* SECTION: Left middle row */
  COMBO(keys_l_mid_rech,         LALT(LGUI(KC_E))), // macro end  
  // COMBO(keys_l_mid_trpi,         KC_NO),            //
  COMBO(keys_l_mid_innr,         KC_ENT),           // enter
  COMBO(keys_l_mid_trpm,         EM_SWITCH_BUFFER), // switch buffer
  COMBO(keys_l_mid_outr,         LALT(LGUI(KC_R))), // macro repeat
  // COMBO(keys_l_mid_trpo,         KC_NO),            //
  COMBO(keys_l_mid_edge,         LALT(LGUI(KC_W))), // macro start
  // COMBO(keys_l_mid_sprd,         KC_NO),            //
  //======================================================================================
  /* SECTION: Left bottom row */
  COMBO(keys_l_bot_rech,         EM_SWITCH_BUFFER), // switch buffer
  // COMBO(keys_l_bot_trpi,         KC_NO),            //
  COMBO(keys_l_bot_innr,         LGUI(KC_Z)),       // undo
  COMBO(keys_l_bot_trpm,         EM_SWITCH_BUFFER), // switch buffer
  COMBO(keys_l_bot_outr,         LCTL(KC_C)),       // C-c
  // COMBO(keys_l_bot_trpo,         KC_NO),            //
  COMBO(keys_l_bot_edge,         LCTL(KC_X)),       // C-x
  // COMBO(keys_l_bot_sprd,         KC_NO),         // 
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
  // COMBO(keys_r_top_trpo,         SS_RPAR_SCLN),     // ); 
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
  COMBO(keys_r_mid_EXTR,         LALT(LGUI(KC_L))), // line wrap
  //======================================================================================
  /* SECTION: Right bottom row */
  COMBO(keys_r_bot_rech,         EM_LASTARG),       // last arg
  COMBO(keys_r_bot_trpi,         EM_REPEAT),        // repeat last 
  COMBO(keys_r_bot_innr,         LGUI(KC_Z)),       // undo
  COMBO(keys_r_bot_trpm,         LALT(LGUI(KC_S))), // shell
  COMBO(keys_r_bot_outr,         SS_ARROW),         // -> 
  COMBO(keys_r_bot_trpo,         SS_UPDIR),         // ../
  COMBO(keys_r_bot_edge,         SS_THISDIR),       // ./
  // COMBO(keys_r_bot_sprd,         KC_NO),            // 
//======================================================================================
  /* Right middle/bottom row */
  COMBO(keys_r_pinky_dip,        SS_UPDIR),
  //======================================================================================
#undef CCC
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
