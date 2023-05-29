#ifdef COMBO_ENABLE
#include "key_aliases.h"

// =======================================================================================
// Combos
// =======================================================================================

#define __(...)

#define MY_COMBOS                                                               \
  XX(l_num_edge,    DF(0),             KC_1,    KC_2)                           \
  XX(l_num_innr,    DF(2),             KC_3,    KC_4)                           \
  XX(l_num_outr,    DF(1),             KC_2,    KC_3)                           \
  XX(l_num_rech,    DF(3),             KC_4,    KC_5)                           \
  __(l_num_sprd,    KC___,             KC_2,    KC_4)                           \
  __(l_num_trpi,    KC___,             KC_3,    KC_4,              KC_5)        \
  __(l_num_trpm,    KC___,             KC_2,    KC_3,              KC_4)        \
  __(l_num_trpo,    KC___,             KC_1,    KC_2,              KC_3)        \
                                                                                \
  XX(l_top_edge,    SS_GRAV,           KC_Q,    KC_W)                           \
  __(l_top_innr,    KC___,             KC_E,    KC_R)                           \
  XX(l_top_outr,    SS_TILD,           KC_W,    KC_E)                           \
  XX(l_top_rech,    SS_TILD_SLSH,      KC_T,    KC_R)                           \
  __(l_top_sprd,    KC___,             KC_W,    KC_R)                           \
  __(l_top_trpi,    KC___,             KC_E,    KC_R,              KC_T)        \
  __(l_top_trpm,    KC___,             KC_W,    KC_E,              KC_R)        \
  __(l_top_trpo,    KC___,             KC_Q,    KC_W,              KC_E)        \
                                                                                \
  XX(l_mid_edge,    LALT(LGUI(KC_W)),  QH_A,    QH_S)                           \
  XX(l_mid_innr,    KC_ENT,            QH_D,    QH_F)                           \
  XX(l_mid_outr,    LALT(LGUI(KC_R)),  QH_S,    QH_D)                           \
  XX(l_mid_rech,    LALT(LGUI(KC_E)),  QH_F,    KC_G)                           \
  __(l_mid_sprd,    KC___,             QH_S,    QH_F)                           \
  __(l_mid_trpi,    KC___,             QH_D,    QH_F,              KC_G)        \
  XX(l_mid_trpm,    EM_SWITCH_BUFFER,  QH_S,    QH_D,              QH_F)        \
  __(l_mid_trpo,    KC___,             QH_A,    QH_S,              QH_D)        \
                                                                                \
  XX(l_bot_edge,    LCTL(KC_X),        QB_Z,    QB_X)                           \
  XX(l_bot_innr,    LGUI(KC_Z),        QB_C,    QB_V)                           \
  XX(l_bot_outr,    LCTL(KC_C),        QB_X,    QB_C)                           \
  XX(l_bot_rech,    EM_SWITCH_BUFFER,  QB_V,    KC_B)                           \
  __(l_bot_sprd,    KC___,             QB_X,    QB_V)                           \
  __(l_bot_trpi,    KC___,             QB_C,    QB_V,              KC_B)        \
  XX(l_bot_trpm,    EM_SWITCH_BUFFER,  QB_X,    QB_C,              QB_V)        \
  __(l_bot_trpo,    KC___,             QB_Z,    QB_X,              QB_C)        \
  __(l_pinky_dip,   KC___,             QH_F,    QB_Z)                           \
                                                                                \
  XX(r_top_edge,    EM_REVERT,         KC_O,    KC_P)                           \
  XX(r_top_innr,    SS_LPAR,           KC_U,    KC_I)                           \
  XX(r_top_outr,    SS_RPAR,           KC_I,    KC_O)                           \
  __(r_top_rech,    KC___,             KC_Y,    KC_U)                           \
  __(r_top_sprd,    KC___,             KC_U,    KC_O)                           \
  __(r_top_trpi,    KC___,             KC_Y,    KC_U,              KC_I)        \
  __(r_top_trpm,    KC___,             KC_U,    KC_I,              KC_O)        \
  __(r_top_trpo,    KC___,             KC_I,    KC_O,              KC_P)        \
                                                                                \
  XX(r_mid_EXTR,    LALT(LGUI(KC_A)),  QH_QUOT, RCTL_T(KC_DQUO))                \
  XX(r_mid_edge,    KC_SCLN,           QH_L,    QH_QUOT)                        \
  XX(r_mid_innr,    KC_ENT,            QH_J,    QH_K)                           \
  XX(r_mid_outr,    KC_RBRC,           QH_K,    QH_L)                           \
  XX(r_mid_rech,    KC_LBRC,           KC_H,    QH_J)                           \
  XX(r_mid_sprd,    KC_EQL,            QH_J,    QH_L)                           \
  XX(r_mid_trpi,    LALT(LGUI(KC_V)),  KC_H,    QH_J,               QH_K)       \
  XX(r_mid_trpm,    LALT(LGUI(KC_D)),  QH_J,    QH_K,               QH_L)       \
  XX(r_mid_trpo,    LALT(LGUI(KC_A)),  QH_K,    QH_L,               QH_QUOT)    \
                                                                                \
  XX(r_bot_edge,    SS_THISDIR,        QB_DOT,  KC_SLSH)                        \
  XX(r_bot_innr,    LGUI(KC_Z),        QB_M,    QB_COMM)                        \
  XX(r_bot_outr,    SS_ARROW,          QB_COMM, QB_DOT)                         \
  XX(r_bot_rech,    EM_LASTARG,        KC_N,    QB_M)                           \
  __(r_bot_sprd,    KC___,             QB_M,    QB_DOT)                         \
  XX(r_bot_trpi,    EM_REPEAT,         KC_N,    QB_M,              QB_COMM)     \
  XX(r_bot_trpm,    LALT(LGUI(KC_S)),  QB_M,    QB_COMM,           QB_DOT)      \
  XX(r_bot_trpo,    SS_UPDIR,          QB_COMM, QB_DOT,            QB_SLSH)     \
  XX(r_pinky_dip,   SS_UPDIR,          QH_J,    KC_SLSH)

//========================================================================================
// Defone combo keys
//========================================================================================

#define XX(name, ig__red, ...) const uint16_t PROGMEM name[] = { __VA_ARGS__, COMBO_END };
MY_COMBOS
#undef XX

//========================================================================================
// Bind combos
//========================================================================================

#define XX(name, binding, ...) COMBO(name, binding),
combo_t key_combos[] = { MY_COMBOS };
#undef XX

uint16_t COMBO_LEN = ARRAY_SIZE(key_combos);

//========================================================================================

bool combo_should_trigger(
  uint16_t     combo_index,
  combo_t *    combo,
  uint16_t     keycode,
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

#undef __
#endif
