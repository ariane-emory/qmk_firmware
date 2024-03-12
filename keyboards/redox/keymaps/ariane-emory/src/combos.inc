// -*- c-backslash-column: 90; c-backslash-max-column: 90 -*-

#include "key-aliases.h"
#include "src/util.h"

// =======================================================================================
// Combos
// =======================================================================================

#define __(...)
#define ____________
#define _______________________________________________________________________________________

#define FOR_EACH_COMBO(DO)                                                                \
  _______________________________________________________________________________________ \
  DO(both_str_thumbs,        KC_INS,        STR_LFT, STR_RGT                            ) \
  DO(both_thu_thumbs,        CAPS_WORD,     THU_LFT, THU_RGT                            ) \
  DO(both_crl_thumbs,        LOCAL_CAPS,    CRL_LFT, CRL_RGT                            ) \
  _______________________________________________________________________________________ \
  DO(l_top_rech,             OTHER_WIN,     QT_Q,    QT_W                               ) \
  DO(l_top_outr,             KC_GRV,        QT_W,    QT_E                               ) \
  DO(l_top_innr,             LSFT(KC_GRV),  QT_E,    QT_R                               ) \
  DO(l_top_curl,             KC_1,          QT_R,    QT_T                               ) \
  __(l_top_trpo,             _____________, QT_Q,    QT_W,      QT_E                    ) \
  __(l_top_sprd,             _____________, QT_W,               QT_R                    ) \
  __(l_top_trpm,             _____________, QT_W,    QT_E,      QT_R                    ) \
  __(l_top_trpi,             _____________, QT_E,    QT_R,      QT_T                    ) \
  _______________________________________________________________________________________ \
  __(l_top_rech_diag_up,     _____________, QH_S,    QT_Q                               ) \
  __(l_top_rech_diag_dn,     _____________, QH_A,    QT_W                               ) \
  __(l_top_outr_diag_up,     _____________, QH_D,    QT_W                               ) \
  __(l_top_outr_diag_dn,     _____________, QH_S,    QT_E                               ) \
  DO(l_top_innr_diag_up,     LSFT(KC_1),    QH_F,    QT_E                               ) \
  __(l_top_innr_diag_dn,     _____________, QH_D,    QT_R                               ) \
  DO(l_top_curl_diag_up,     LSFT(KC_1),    QH_G,    QT_R                               ) \
  __(l_top_curl_diag_dn,     _____________, QH_F,    QT_T                               ) \
  _______________________________________________________________________________________ \
  DO(l_mid_rech,             EM_MAC_END,    QH_A,    QH_S                               ) \
  DO(l_mid_outr,             EM_MAC_BGN,    QH_S,    QH_D                               ) \
  DO(l_mid_innr,             EM_MAC_RPT,    QH_D,    QH_F                               ) \
  DO(l_mid_curl,             CAPS_WORD,     QH_F,    QH_G                               ) \
  DO(l_mid_trpo,             EM_SPLIT_V,    QH_A,    QH_S,      QH_D                    ) \
  __(l_mid_sprd,             -------------, QH_S,               QH_F                    ) \
  DO(l_mid_trpm,             TOGGLE_DF,     QH_S,    QH_D,      QH_F                    ) \
  DO(l_mid_trpi,             EM_SPLIT_H,    QH_D,    QH_F,      QH_G                    ) \
  _______________________________________________________________________________________ \
  __(l_bot_rech_diag_up,     _____________, QH_A,    QB_X                               ) \
  __(l_bot_rech_diag_dn,     _____________, QH_S,    QB_Z                               ) \
  __(l_bot_outr_diag_up,     _____________, QH_S,    QB_C                               ) \
  __(l_bot_outr_diag_dn,     _____________, QH_D,    QB_X                               ) \
  __(l_bot_innr_diag_up,     _____________, QH_D,    QB_V                               ) \
  __(l_bot_innr_diag_dn,     _____________, QH_F,    QB_C                               ) \
  __(l_bot_curl_diag_up,     _____________, QH_F,    QB_B                               ) \
  __(l_bot_curl_diag_dn,     _____________, QH_F,    QB_C                               ) \
  _______________________________________________________________________________________ \
  __(l_bot_rech,             _____________, QB_Z,    QB_X                               ) \
  DO(l_bot_outr,             KC_ENT,        QB_X,    QB_C                               ) \
  DO(l_bot_innr,             SS_CD,         QB_C,    QB_V                               ) \
  __(l_bot_curl,             _____________, QB_V,    QB_B                               ) \
  __(l_bot_trpo,             _____________, QB_Z,    QB_X,      QB_C                    ) \
  __(l_bot_sprd,             _____________, QB_X,               QB_V                    ) \
  DO(l_bot_trpm,             TG(LN_MOUSE),  QB_X,    QB_C,      QB_V                    ) \
  __(l_bot_trpi,             _____________, QB_C,    QB_V,      QB_B                    ) \
  _______________________________________________________________________________________ \
  DO(r_top_trpi,             SS_SMILEY2,    QT_Y,    QT_U,      QT_I                    ) \
  DO(r_top_trpm,             EM_REVERT,     QT_U,    QT_I,      QT_O                    ) \
  DO(r_top_sprd,             SS_AND_AND,    QT_U,               QT_O                    ) \
  DO(r_top_trpo,             SS_SMILEY,     QT_I,    QT_O,      QT_P                    ) \
  DO(r_top_curl,             QK_LEAD,       QT_Y,    QT_U                               ) \
  DO(r_top_innr,             LALT(KC_X),    QT_U,    QT_I                               ) \
  DO(r_top_outr,             KC_ESC,        QT_I,    QT_O                               ) \
  DO(r_top_rech,             EM_LWRAP,      QT_O,    QT_P                               ) \
  _______________________________________________________________________________________ \
  DO(r_top_curl_diag_up,     KC_HOME,       QH_H,    QT_U                               ) \
  DO(r_top_curl_diag_dn,     SS_FULLSCR,    QH_J,    QT_Y                               ) \
  DO(r_top_innr_diag_up,     SS_LBRACK,     QH_J,    QT_I                               ) \
  DO(r_top_innr_diag_dn,     KC_END,        QH_K,    QT_U                               ) \
  DO(r_top_outr_diag_up,     LGUI(KC_MINS), QH_K,    QT_O                               ) \
  DO(r_top_outr_diag_dn,     SS_RBRACK,     QH_L,    QT_I                               ) \
  __(r_top_rech_diag_up,     _____________, QH_L,    QT_P                               ) \
  DO(r_top_rech_diag_dn,     LGUI(KC_EQL),  QH_QUOT, QT_O                               ) \
  _______________________________________________________________________________________ \
  DO(r_mid_trpi,             EM_PRV_BUF,    QH_H,    QH_J,       QH_K                   ) \
  DO(r_mid_trpm,             EM_DIRED,      QH_J,    QH_K,       QH_L                   ) \
  DO(r_mid_sprd,             TG(LN_MOUSE),  QH_J,                QH_L                   ) \
  DO(r_mid_trpo,             EM_ALL_BUF,    QH_K,    QH_L,       QH_QUOT                ) \
  DO(r_mid_curl,             KC_EQL,        QH_H,    QH_J                               ) \
  DO(r_mid_innr,             KC_ENT,        QH_J,    QH_K                               ) \
  DO(r_mid_outr,             KC_SCLN,       QH_K,    QH_L                               ) \
  DO(r_mid_rech,             LSFT(KC_SCLN), QH_L,    QH_QUOT                            ) \
  _______________________________________________________________________________________ \
  DO(r_bot_curl_diag_up,     KC_VOLD,       QH_J,    QB_N                               ) \
  __(r_bot_curl_diag_dn,     _____________, QH_H,    QB_M                               ) \
  DO(r_bot_innr_diag_up,     CLOSE_WIN,     QH_K,    QB_M                               ) \
  DO(r_bot_innr_diag_dn,     KC_VOLU,       QH_J,    QB_COMM                            ) \
  DO(r_bot_outr_diag_up,     SPOTLIGHT,     QH_L,    QB_COMM                            ) \
  DO(r_bot_outr_diag_dn,     NEW_TAB,       QH_K,    QB_DOT                             ) \
  DO(r_bot_rech_diag_up,     SPOTLIGHT,     QH_L,    QB_SLSH                            ) \
  __(r_bot_rech_diag_dn,     _____________, QH_QUOT, QB_DOT                             ) \
  _______________________________________________________________________________________ \
  DO(r_bot_trpi,             EM_CHG_BUFF,   QB_N,    QB_M,      QB_COMM                 ) \
  DO(r_bot_trpm,             EM_SHELL,      QB_M,    QB_COMM,   QB_DOT                  ) \
  DO(r_bot_sprd,             SS_DICT,       QB_M,               QB_DOT                  ) \
  DO(r_bot_trpo,             EM_KILL_BUFF,  QB_COMM, QB_DOT,    QB_SLSH                 ) \
  DO(r_bot_curl,             EM_LASTARG,    QB_N,    QB_M                               ) \
  DO(r_bot_innr,             KA_UNDO,       QB_M,    QB_COMM                            ) \
  DO(r_bot_outr,             SS_DIR,        QB_COMM, QB_DOT                             ) \
  DO(r_bot_rech,             SS_ARROW,      QB_DOT,  QB_SLSH                            ) \
  _______________________________________________________________________________________

//========================================================================================
// Define combo keys
//========================================================================================

#define DEFINE_COMBO_KEYS(name, ignored, ...)                                             \
  const uint16_t PROGMEM name[] = { __VA_ARGS__, COMBO_END };

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
  uint16_t      combo_index,
  combo_t *     combo,
  uint16_t      keycode,
  keyrecord_t * record) {
  return (false
          || (get_highest_layer(layer_state) < LN_MOUSE)
          // v this index will probably need frequent adjustment whenever left-hand combos are altered:
          || (((layer_state_is(LN_MOUSE)  && ((combo_index <= 20)))))
          || (((layer_state_is(LN_MOUSE)  && (true
                                              && (combo->keycode != KC_ENT)
                                              && (combo->keycode != KC_SCLN)
                                              && (combo->keycode != SS_LBRACK)
                                              && (combo->keycode != SS_RBRACK)))))
          || (((layer_state_is(LN_LOWER) || layer_state_is(LN_UPPER) || layer_state_is(LN_ARROWS))) &&
              (false
               || (combo->keycode == KC_ESC)
               // || (combo->keycode == KC_ENT)
               || (combo->keycode == KA_UNDO)
               || (combo->keycode == EM_BOL)
               || (combo->keycode == EM_EOL)
               || (combo->keycode == KC_VOLD)
               || (combo->keycode == KC_VOLU)
               || (combo->keycode == KC_HOME)
               || (combo->keycode == KC_END)))
          || false);
}

//========================================================================================

// =======================================================================================
// Undefine local macros
// =======================================================================================

#undef __
#undef ____________
#undef _______________________________________________________________________________________
#undef FOR_EACH_COMBO
