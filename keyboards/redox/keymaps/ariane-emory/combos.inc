#ifdef COMBO_ENABLE
#include "key_aliases.h"

// =======================================================================================
// Combos
// =======================================================================================

#define __(...)
#define ____________
#define ______________________________________________________________________________

#define FOR_EACH_COMBO(DO)                                                       \
  ______________________________________________________________________________ \
  DO(l_num_edge,    DF(0),        KC_1,    KC_2                                ) \
  DO(l_num_innr,    DF(2),        KC_3,    KC_4                                ) \
  DO(l_num_outr,    DF(1),        KC_2,    KC_3                                ) \
  DO(l_num_rech,    DF(3),        KC_4,    KC_5                                ) \
  __(l_num_sprd,    ____________, KC_2,    KC_4                                ) \
  __(l_num_trpi,    ____________, KC_3,    KC_4,      KC_5                     ) \
  __(l_num_trpm,    ____________, KC_2,    KC_3,      KC_4                     ) \
  __(l_num_trpo,    ____________, KC_1,    KC_2,      KC_3                     ) \
  ______________________________________________________________________________ \
  DO(l_top_edge,    SS_GRAV,      QT_Q,    QT_W                                ) \
  __(l_top_innr,    ____________, QT_E,    QT_R                                ) \
  DO(l_top_outr,    SS_TILD,      QT_W,    QT_E                                ) \
  DO(l_top_rech,    SS_TILD_SLSH, QT_T,    QT_R                                ) \
  __(l_top_sprd,    ____________, QT_W,    QT_R                                ) \
  __(l_top_trpi,    ____________, QT_E,    QT_R,      QT_T                     ) \
  __(l_top_trpm,    ____________, QT_W,    QT_E,      QT_R                     ) \
  __(l_top_trpo,    ____________, QT_Q,    QT_W,      QT_E                     ) \
  ______________________________________________________________________________ \
  DO(l_mid_edge,    EM_BGN_MAC,   QH_A,    QH_S                                ) \
  DO(l_mid_innr,    KC_ENT,       QH_D,    QH_F                                ) \
  DO(l_mid_outr,    EM_RPT_MAC,   QH_S,    QH_D                                ) \
  DO(l_mid_rech,    EM_END_MAC,   QH_F,    QH_G                                ) \
  __(l_mid_sprd,    ____________, QH_S,    QH_F                                ) \
  __(l_mid_trpi,    ____________, QH_D,    QH_F,      QH_G                     ) \
  DO(l_mid_trpm,    EM_CHG_BUF,   QH_S,    QH_D,      QH_F                     ) \
  __(l_mid_trpo,    ____________, QH_A,    QH_S,      QH_D                     ) \
  ______________________________________________________________________________ \
  DO(l_bot_edge,    EM_CTL_X,     QB_Z,    QB_X                                ) \
  DO(l_bot_innr,    KA_UNDO,      QB_C,    QB_V                                ) \
  DO(l_bot_outr,    EM_CTL_C,     QB_X,    QB_C                                ) \
  DO(l_bot_rech,    EM_CHG_BUF,   QB_V,    QB_B                                ) \
  __(l_bot_sprd,    ____________, QB_X,    QB_V                                ) \
  __(l_bot_trpi,    ____________, QB_C,    QB_V,      QB_B                     ) \
  DO(l_bot_trpm,    EM_CHG_BUF,   QB_X,    QB_C,      QB_V                     ) \
  __(l_bot_trpo,    ____________, QB_Z,    QB_X,      QB_C                     ) \
  __(l_pinky_dip,   ____________, QH_F,    QB_Z                                ) \
  ______________________________________________________________________________ \
  DO(r_top_edge,    EM_REVERT,    QT_O,    QT_P                                ) \
  DO(r_top_innr,    SS_LPAR,      QT_U,    QT_I                                ) \
  DO(r_top_outr,    SS_RPAR,      QT_I,    QT_O                                ) \
  __(r_top_rech,    ____________, QT_Y,    QT_U                                ) \
  __(r_top_sprd,    ____________, QT_U,    QT_O                                ) \
  __(r_top_trpi,    ____________, QT_Y,    QT_U,      QT_I                     ) \
  __(r_top_trpm,    ____________, QT_U,    QT_I,      QT_O                     ) \
  __(r_top_trpo,    ____________, QT_I,    QT_O,      QT_P                     ) \
  ______________________________________________________________________________ \
  DO(r_mid_EXTR,    EM_LWRAP,     QH_QUOT, RCTL_DQUO                           ) \
  DO(r_mid_edge,    KC_SCLN,      QH_L,    QH_QUOT                             ) \
  DO(r_mid_innr,    KC_ENT,       QH_J,    QH_K                                ) \
  DO(r_mid_outr,    KC_RBRC,      QH_K,    QH_L                                ) \
  DO(r_mid_rech,    KC_LBRC,      QH_H,    QH_J                                ) \
  DO(r_mid_sprd,    KC_EQL,       QH_J,    QH_L                                ) \
  DO(r_mid_trpi,    EM_PRV_BUF,   QH_H,    QH_J,       QH_K                    ) \
  DO(r_mid_trpm,    EM_DIRED,     QH_J,    QH_K,       QH_L                    ) \
  DO(r_mid_trpo,    EM_ALL_BUF,   QH_K,    QH_L,       QH_QUOT                 ) \
  ______________________________________________________________________________ \
  DO(r_bot_edge,    SS_THISDIR,   QB_DOT,  QB_SLSH                             ) \
  DO(r_bot_innr,    KA_UNDO,      QB_M,    QB_COMM                             ) \
  DO(r_bot_outr,    SS_ARROW,     QB_COMM, QB_DOT                              ) \
  DO(r_bot_rech,    EM_LASTARG,   QB_N,    QB_M                                ) \
  __(r_bot_sprd,    ____________, QB_M,    QB_DOT                              ) \
  DO(r_bot_trpi,    EM_REPEAT,    QB_N,    QB_M,      QB_COMM                  ) \
  DO(r_bot_trpm,    EM_SHELL,     QB_M,    QB_COMM,   QB_DOT                   ) \
  DO(r_bot_trpo,    SS_UPDIR,     QB_COMM, QB_DOT,    QB_SLSH                  ) \
  DO(r_pinky_dip,   SS_UPDIR,     QH_J,    QB_SLSH                             ) \
  ______________________________________________________________________________

//========================================================================================
// Define combo keys
//========================================================================================

#define DEFINE_COMBO_KEYS(name, ignored, ...) const uint16_t PROGMEM name[] = { __VA_ARGS__, COMBO_END };
FOR_EACH_COMBO(DEFINE_COMBO_KEYS)
#undef DEFINE_COMBO_KEYS

//========================================================================================
// Bind combos
//========================================================================================

#define BIND_COMBO(name, binding, ...) COMBO(name, binding),
combo_t key_combos[] = { FOR_EACH_COMBO(BIND_COMBO) };
#undef BIND_COMBO

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
#undef ____________
#undef ______________________________________________________________________________
#undef FOR_EACH_COMBO

#endif
