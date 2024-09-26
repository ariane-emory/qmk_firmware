// -*- c-backslash-column: 80; c-backslash-max-column: 80 ; fill-column: 80; eval: (display-fill-column-indicator-mode 1); -*-
#pragma once

//==============================================================================
// Key alias macros
//==============================================================================

//==============================================================================
// Layer names
//==============================================================================
#define LN_MOUSE  9
#define LN_LOWER  10
#define LN_UPPER  11
#define LN_FLIPL  12
#define LN_FLIPR  13
#define LN_ARROWS 14
#define LN_UTIL   15
//==============================================================================


//==============================================================================
// HRM Assignments
//==============================================================================
#ifdef TRM_SWAP
  #define LTRM_2(x) LT(LN_ARROWS, x)
  #define LTRM_1(x) LSFT_T(x)
  #define RTRM_1(x) LSFT_T(x)
  #define RTRM_2(x) LT(LN_ARROWS, x)
#else
  #define LTRM_2(x) LSFT_T(x)
  #define LTRM_1(x) LT(LN_ARROWS, x)
  #define RTRM_1(x) LT(LN_ARROWS, x)
  #define RTRM_2(x) LSFT_T(x)
#endif
//==============================================================================
#define LHRM_4(x) LSFT_T(x) // LGUI_T(x)  
#define LHRM_3(x) LGUI_T(x) // LALT_T(x) 
#define LHRM_2(x) LALT_T(x) // LCTL_T(x) 
#define LHRM_1(x) LCTL_T(x) // LSFT_T(x) 
#define LHRM_0(x) LSFT_T(x) // LCTL_T(x) 
//------------------------------------------------------------------------------
#define RHRM_0(x) RSFT_T(x) // RCTL_T(x) 
#define RHRM_1(x) RCTL_T(x) // RSFT_T(x) 
#define RHRM_2(x) RALT_T(x) // RCTL_T(x) 
#define RHRM_3(x) RGUI_T(x) // RALT_T(x) 
#define RHRM_4(x) RSFT_T(x) // RGUI_T(x) 
//------------------------------------------------------------------------------
#define LBRM_4(x) LT(LN_ARROWS, x) // LSFT_T(x) 
#define LBRM_1(x) LT(LN_ARROWS, x)
#define RBRM_1(x) LT(LN_ARROWS, x)
#define RBRM_4(x) LT(LN_ARROWS, x) // RSFT_T(x) 
//==============================================================================


//==============================================================================
// Shift keys
//==============================================================================
#define QB_LSFT LSFT_T(KC_MINS)
#define QB_RSFT RSFT_T(KC_MINS)
//==============================================================================


//==============================================================================
// Number row
//==============================================================================
#define NUM_1       KC_1
#define NUM_2       KC_2
#define NUM_3       KC_3
#define NUM_4       KC_4
#define NUM_5       KC_5
#define NUM_6       KC_6
#define NUM_7       KC_7
#define NUM_8       KC_8
#define NUM_9       KC_9
#define NUM_0       KC_0
//==============================================================================


//==============================================================================
// Numpad keys
//==============================================================================
#define NUMP_0      LSFT(KC_0)
#define NUMP_1      LSFT(KC_1)
#define NUMP_2      LSFT(KC_2)
#define NUMP_3      LSFT(KC_3)
#define NUMP_4      LSFT(KC_4)
#define NUMP_5      LSFT(KC_5)
#define NUMP_6      LSFT(KC_6)
#define NUMP_7      LSFT(KC_7)
#define NUMP_8      LSFT(KC_8)
#define NUMP_9      LSFT(KC_9)
#define NUMP_0      LSFT(KC_0)
//==============================================================================


//==============================================================================
// Virtual desktops
//==============================================================================
#define VD_LEFT     LALT(LCTL(KC_S))
#define VD_RIGHT    LALT(LCTL(KC_D))
#define VD_ALL      LALT(LCTL(LGUI(KC_TAB)))
//==============================================================================


//==============================================================================
// Misc special functions
//==============================================================================
#define BRT_DN         KC_F19
#define BRT_UP         KC_F20
#define CAPS_WORD      QK_CAPS_WORD_TOGGLE
/* #define EM_MAC_BGN     LALT(LGUI(KC_W)) */
/* #define EM_MAC_END     LALT(LGUI(KC_E)) */
/* #define EM_MAC_RPT     LALT(LGUI(KC_R)) */
#define EM_BOL         LCTL(KC_A)
#define EM_EOL         LCTL(KC_E)
#define KA_UNDO        LGUI(KC_Z)
#define LCTL_ESC       LCTL_T(KC_ESC)
#define LCTL_OPEN      LCTL_T(RGUI(KC_O))
#define LOCAL_CAPS     LGUI(LALT(KC_C))
#define LUTIL_OR_CMD_W LT(LN_UTIL,RGUI(KC_W))
#define NEW_TAB        LGUI(KC_T)
#define RCTL_DQUO      RCTL_T(KC_DQUO_TAP)
#define RCTL_SQUO      RCTL_T(KC_SQUO_TAP)
#define SPOTLIGHT      LGUI(KC_SPC)
#define TG_MOUSE       TG(LN_MOUSE)
#define OTHER_WIN2     LGUI(KC_GRV)
//==============================================================================


//==============================================================================
// Tri layer keys
//==============================================================================
#define KC_LOWER       MO(LN_LOWER)
#define KC_UPPER       MO(LN_UPPER)
//==============================================================================


//==============================================================================
// Thumb key aliases
//==============================================================================
#define FLIPL_OR_DASH      LT(LN_FLIPL,    KC_MINS)
#define FLIPL_OR_TAB       LT(LN_FLIPL,    KC_TAB)
#define LALT_OR_SPC        MT(MOD_LALT,    KC_SPC)
#define LGUI_OR_BSPC       MT(MOD_RGUI,    KC_BSPC)
#define FLIPR_OR_DASH      LT(LN_FLIPR,    KC_MINS)
#define FLIPR_OR_BTN2      LT(LN_FLIPR,    KC_BTN2)
#define LOWER_OR_SPC       LT(LN_LOWER,    KC_SPC)
#define UPPER_OR_BSPC      LT(LN_UPPER,    KC_BSPC)
#define LARROWS_OR_TAB     LT(LN_ARROWS,   KC_TAB)
#define LARROWS_OR_USCORE  LT(LN_ARROWS,   KC_MINS)
#define FLIPR_OR_USCORE    LT(LN_FLIPR,    KC_MINS)
//==============================================================================


//==============================================================================
// Thumb key assignments
//==============================================================================
#define CRL_LFT FLIPL_OR_TAB
#define THU_LFT KC_LOWER
#define STR_LFT LALT_OR_SPC
//------------------------------------------------------------------------------
#define STR_RGT LGUI_OR_BSPC
#define THU_RGT KC_UPPER
#define CRL_RGT FLIPR_OR_USCORE
//------------------------------------------------------------------------------
#define STR_MS  KC_BTN1
#define THU_MS  KC_TRNS
// #define CRL_MS  FLIPR_OR_BTN2
#define CRL_MS  KC_BTN2
//==============================================================================

