#ifdef COMBO_ENABLE
#include "key_aliases.h"

// =======================================================================================
// Combos
// =======================================================================================

#define _(...)
#define ____________
#define _____________________________________________________________________________

#define FOR_EACH_COMBO(X)                                                       \
  X(l_num_edge,    DF(0),        KC_1,    KC_2                                ) \
  X(l_num_innr,    DF(2),        KC_3,    KC_4                                ) \
  X(l_num_outr,    DF(1),        KC_2,    KC_3                                ) \
  X(l_num_rech,    DF(3),        KC_4,    KC_5                                ) \
  _(l_num_sprd,    ____________, KC_2,    KC_4                                ) \
  _(l_num_trpi,    ____________, KC_3,    KC_4,      KC_5                     ) \
  _(l_num_trpm,    ____________, KC_2,    KC_3,      KC_4                     ) \
  _(l_num_trpo,    ____________, KC_1,    KC_2,      KC_3                     ) \
  _____________________________________________________________________________ \
  X(l_top_edge,    SS_GRAV,      KC_Q,    KC_W                                ) \
  _(l_top_innr,    ____________, KC_E,    KC_R                                ) \
  X(l_top_outr,    SS_TILD,      KC_W,    KC_E                                ) \
  X(l_top_rech,    SS_TILD_SLSH, KC_T,    KC_R                                ) \
  _(l_top_sprd,    ____________, KC_W,    KC_R                                ) \
  _(l_top_trpi,    ____________, KC_E,    KC_R,      KC_T                     ) \
  _(l_top_trpm,    ____________, KC_W,    KC_E,      KC_R                     ) \
  _(l_top_trpo,    ____________, KC_Q,    KC_W,      KC_E                     ) \
  _____________________________________________________________________________ \
  X(l_mid_edge,    EM_BGN_MAC,   QH_A,    QH_S                                ) \
  X(l_mid_innr,    KC_ENT,       QH_D,    QH_F                                ) \
  X(l_mid_outr,    EM_RPT_MAC,   QH_S,    QH_D                                ) \
  X(l_mid_rech,    EM_END_MAC,   QH_F,    KC_G                                ) \
  _(l_mid_sprd,    ____________, QH_S,    QH_F                                ) \
  _(l_mid_trpi,    ____________, QH_D,    QH_F,      KC_G                     ) \
  X(l_mid_trpm,    EM_CHG_BUF,   QH_S,    QH_D,      QH_F                     ) \
  _(l_mid_trpo,    ____________, QH_A,    QH_S,      QH_D                     ) \
  _____________________________________________________________________________ \
  X(l_bot_edge,    EM_CTL_X,     QB_Z,    QB_X                                ) \
  X(l_bot_innr,    KA_UNDO,      QB_C,    QB_V                                ) \
  X(l_bot_outr,    EM_CTL_C,     QB_X,    QB_C                                ) \
  X(l_bot_rech,    EM_CHG_BUF,   QB_V,    KC_B                                ) \
  _(l_bot_sprd,    ____________, QB_X,    QB_V                                ) \
  _(l_bot_trpi,    ____________, QB_C,    QB_V,      KC_B                     ) \
  X(l_bot_trpm,    EM_CHG_BUF,   QB_X,    QB_C,      QB_V                     ) \
  _(l_bot_trpo,    ____________, QB_Z,    QB_X,      QB_C                     ) \
  _(l_pinky_dip,   ____________, QH_F,    QB_Z                                ) \
  _____________________________________________________________________________ \
  X(r_top_edge,    EM_REVERT,    KC_O,    KC_P                                ) \
  X(r_top_innr,    SS_LPAR,      KC_U,    KC_I                                ) \
  X(r_top_outr,    SS_RPAR,      KC_I,    KC_O                                ) \
  _(r_top_rech,    ____________, KC_Y,    KC_U                                ) \
  _(r_top_sprd,    ____________, KC_U,    KC_O                                ) \
  _(r_top_trpi,    ____________, KC_Y,    KC_U,      KC_I                     ) \
  _(r_top_trpm,    ____________, KC_U,    KC_I,      KC_O                     ) \
  _(r_top_trpo,    ____________, KC_I,    KC_O,      KC_P                     ) \
  _____________________________________________________________________________ \
  X(r_mid_EXTR,    EM_LWRAP,     QH_QUOT, RCTL_DQUO                           ) \
  X(r_mid_edge,    KC_SCLN,      QH_L,    QH_QUOT                             ) \
  X(r_mid_innr,    KC_ENT,       QH_J,    QH_K                                ) \
  X(r_mid_outr,    KC_RBRC,      QH_K,    QH_L                                ) \
  X(r_mid_rech,    KC_LBRC,      KC_H,    QH_J                                ) \
  X(r_mid_sprd,    KC_EQL,       QH_J,    QH_L                                ) \
  X(r_mid_trpi,    EM_PRV_BUF,   KC_H,    QH_J,       QH_K                    ) \
  X(r_mid_trpm,    EM_DIRED,     QH_J,    QH_K,       QH_L                    ) \
  X(r_mid_trpo,    EM_ALL_BUF,   QH_K,    QH_L,       QH_QUOT                 ) \
  _____________________________________________________________________________ \
  X(r_bot_edge,    SS_THISDIR,   QB_DOT,  KC_SLSH                             ) \
  X(r_bot_innr,    KA_UNDO,      QB_M,    QB_COMM                             ) \
  X(r_bot_outr,    SS_ARROW,     QB_COMM, QB_DOT                              ) \
  X(r_bot_rech,    EM_LASTARG,   KC_N,    QB_M                                ) \
  _(r_bot_sprd,    ____________, QB_M,    QB_DOT                              ) \
  X(r_bot_trpi,    EM_REPEAT,    KC_N,    QB_M,      QB_COMM                  ) \
  X(r_bot_trpm,    EM_SHELL,     QB_M,    QB_COMM,   QB_DOT                   ) \
  X(r_bot_trpo,    SS_UPDIR,     QB_COMM, QB_DOT,    QB_SLSH                  ) \
  X(r_pinky_dip,   SS_UPDIR,     QH_J,    KC_SLSH                            )

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

#undef s
#undef ____________
#undef _____________________________________________________________________________                                                                                
#undef FOR_EACH_COMBO

#endif
