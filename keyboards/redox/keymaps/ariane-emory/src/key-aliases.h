#pragma once

//==============================================================================
// Key alias macros
//==============================================================================

//==============================================================================
// HRM Assignments
//==============================================================================
#define LHRM_4(x) LSFT_T(x) // LT(13,x)
#define LHRM_3(x) LGUI_T(x)
#define LHRM_2(x) LALT_T(x)
#define LHRM_1(x) LCTL_T(x)
#define RHRM_1(x) RCTL_T(x)
#define RHRM_2(x) RALT_T(x)
#define RHRM_3(x) RGUI_T(x)
#define RHRM_4(x) LSFT_T(x) // LT(13,x)

//==============================================================================
// Top row
//==============================================================================
#define QT_TAB  LT(10,KC_TAB)
#define QT_Q    KC_Q
#define QT_W    KC_W
#define QT_E    KC_E
#define QT_R    KC_R
#define QT_T    KC_T
#define QT_Y    KC_Y
#define QT_U    KC_U
#define QT_I    KC_I
#define QT_O    KC_O
#define QT_P    KC_P
#define QT_BSLS LT(11,KC_BSLS)
//------------------------------------------------------------------------------
#define MT_Q    KC_Q // M layout is Workman.
#define MT_W    KC_W
#define MT_E    KC_D
#define MT_R    KC_F
#define MT_T    KC_G
#define MT_Y    KC_J
#define MT_U    KC_U
#define MT_I    KC_K
#define MT_O    KC_L
#define MT_P    KC_P
//------------------------------------------------------------------------------
#ifdef COLEMAK_DH
#  define CT_Q    KC_Q
#  define CT_W    KC_W
#  define CT_F    KC_F
#  define CT_P    KC_P
#  define CT_G    KC_B
#  define CT_J    KC_J
#  define CT_L    KC_L
#  define CT_U    KC_U
#  define CT_O    KC_O
#  define CT_Y    KC_Y
#else
#  define CT_Q    KC_Q
#  define CT_W    KC_W
#  define CT_F    KC_F
#  define CT_P    KC_P
#  define CT_G    KC_G
#  define CT_J    KC_J
#  define CT_L    KC_L
#  define CT_U    KC_U
#  define CT_O    KC_O
#  define CT_Y    KC_Y
#endif
//==============================================================================

//==============================================================================
// Middle row
//==============================================================================
#define QH_A    LHRM_4(KC_A)
#define QH_S    LHRM_3(KC_S)
#define QH_D    LHRM_2(KC_D)
#define QH_F    LHRM_1(KC_F)
#define QH_G    LSFT_T(KC_G)
#define QH_H    RSFT_T(KC_H)
#define QH_J    RHRM_1(KC_J)
#define QH_K    RHRM_2(KC_K)
#define QH_L    RHRM_3(KC_L)
#define QH_QUOT RHRM_4(KC_QUOT)
//------------------------------------------------------------------------------
#define MH_A    LHRM_4(KC_A)
#define MH_S    LHRM_3(KC_S)
#define MH_D    LHRM_2(KC_E)
#define MH_F    LHRM_1(KC_R)
#define MH_G    LSFT_T(KC_T)
#define MH_H    RSFT_T(KC_H)
#define MH_J    RHRM_1(KC_N)
#define MH_K    RHRM_2(KC_I)
#define MH_L    RHRM_3(KC_O)
#define MH_QUOT RHRM_4(KC_QUOT)
//------------------------------------------------------------------------------
#ifdef COLEMAK_DH
#  define CH_A    LHRM_4(KC_A)
#  define CH_R    LHRM_3(KC_R)
#  define CH_S    LHRM_2(KC_S)
#  define CH_T    LHRM_1(KC_T)
#  define CH_D    LSFT_T(KC_G)
#  define CH_H    RSFT_T(KC_M)
#  define CH_N    RHRM_1(KC_N)
#  define CH_E    RHRM_2(KC_E)
#  define CH_I    RHRM_3(KC_I)
#  define CH_QUOT RHRM_4(KC_QUOT)
#else
#  define CH_A    RHRM_4(KC_A)
#  define CH_R    LHRM_3(KC_R)
#  define CH_S    LHRM_2(KC_S)
#  define CH_T    LHRM_1(KC_T)
#  define CH_D    LSFT_T(KC_D)
#  define CH_H    RSFT_T(KC_H)
#  define CH_N    RHRM_1(KC_N)
#  define CH_E    RHRM_2(KC_E)
#  define CH_I    RHRM_3(KC_I)
#  define CH_QUOT RHRM_4(KC_QUOT)
#endif
//==============================================================================

//==============================================================================
// Bottom row
//==============================================================================
#define QB_Z    LT(13, KC_Z) // LSFT_T(KC_Z)
#define QB_X    KC_X
#define QB_C    KC_C
#define QB_V    KC_V
#define QB_B    KC_B
#define QB_N    KC_N
#define QB_M    KC_M
#define QB_COMM KC_COMM
#define QB_DOT  KC_DOT
#define QB_SLSH LT(13, KC_SLSH) // RSFT_T(KC_SLSH)
//------------------------------------------------------------------------------
#define MB_Z    LSFT_T(KC_Z)
#define MB_X    KC_X
#define MB_C    KC_C
#define MB_V    KC_V
#define MB_B    KC_B
#define MB_N    KC_Y
#define MB_M    KC_M
#define MB_COMM KC_COMM
#define MB_DOT  KC_DOT
#define MB_SLSH RSFT_T(KC_SLSH)
//------------------------------------------------------------------------------
#ifdef COLEMAK_DH
#  define CB_Z    LSFT_T(KC_Z)
#  define CB_X    KC_X
#  define CB_C    KC_C
#  define CB_V    KC_D
#  define CB_B    KC_V
#  define CB_K    KC_K
#  define CB_M    KC_H
#  define CB_COMM KC_COMM
#  define CB_DOT  KC_DOT
#  define CB_SLSH RSFT_T(KC_SLSH)
#else
#  define CB_Z    LSFT_T(KC_Z)
#  define CB_X    KC_X
#  define CB_C    KC_C
#  define CB_V    KC_V
#  define CB_B    KC_B
#  define CB_K    KC_K
#  define CB_M    KC_M
#  define CB_COMM KC_COMM
#  define CB_DOT  KC_DOT
#  define CB_SLSH RSFT_T(KC_SLSH)
#endif
//------------------------------------------------------------------------------
#define   QB_LSFT LSFT_T(KC_MINS) // L13_OR_DASH
#define   QB_RSFT RSFT_T(KC_MINS) // L13_OR_DASH
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
#define VD_ALL      LALT(LCTL(KC_TAB))
//==============================================================================

//==============================================================================
// Misc special functions
//==============================================================================
#define LT11_OR_CMD_W  LT(11,RGUI(KC_W))
#define EM_SHELL    LALT(LGUI(KC_S))
#define KA_UNDO     LGUI(KC_Z)
#define EM_ALL_BUF  LALT(LGUI(KC_A))
#define EM_PRV_BUF  LALT(LGUI(KC_V))
#define EM_DIRED    LALT(LGUI(KC_D))
#define EM_LWRAP    LALT(LGUI(KC_L))
#define EM_BGN_MAC  LALT(LGUI(KC_W))
#define EM_RPT_MAC  LALT(LGUI(KC_R))
#define EM_END_MAC  LALT(LGUI(KC_E))
#define EM_CTL_X    LCTL(KC_X)
#define EM_CTL_C    LCTL(KC_C)
#define RCTL_DQUO   RCTL_T(KC_DUMMY)
#define LCTL_ESC    LCTL_T(KC_ESC)
#define BRTU        KC_VOLU
#define BRTD        KC_VOLD
#define VOLU        KC_F20
#define VOLD        KC_F19
//==============================================================================

//==============================================================================
// Tri layer keys
//==============================================================================
#ifdef TRI_LAYER_ENABLE
#  define KC_LOWER       QK_TRI_LAYER_LOWER
#  define KC_UPPER       QK_TRI_LAYER_UPPER
#else // TRI_LAYER_ENABLE
#  define KC_LOWER       MO(TRI_LAYER_LOWER_LAYER)
#  define KC_UPPER       MO(TRI_LAYER_UPPER_LAYER)
#endif // TRI_LAYER_ENABLE
//==============================================================================

//==============================================================================
// Thumb key aliases
//==============================================================================
#define L9_OR_DASH    LT(9,KC_MINS)
#define L9_OR_TAB     LT(9,KC_TAB)
#define LALT_OR_SPC   MT(MOD_LALT,KC_SPC)
#define LGUI_OR_BSPC  MT(MOD_RGUI,KC_BSPC)
#define L12_OR_DASH   LT(12,KC_MINS)
#define L13_OR_DASH   LT(13,KC_MINS)
#define L12_OR_BTN2   LT(12,KC_BTN2)
#define LOWER_OR_SPC  LT(TRI_LAYER_LOWER_LAYER,KC_SPC)
#define UPPER_OR_BSPC LT(TRI_LAYER_UPPER_LAYER,KC_BSPC)
#define L13_OR_TAB    LT(13, KC_TAB)
#define L13_OR_USCORE LT(13, KC_MINS)
#define L12_OR_USCORE LT(12, KC_MINS)
//==============================================================================

//==============================================================================
// Thumb key assignments
//==============================================================================
#define CRL_LFT        L9_OR_TAB
#define THU_LFT        KC_LOWER
#define STR_LFT        LALT_OR_SPC
//------------------------------------------------------------------------------
#define STR_RGT        LGUI_OR_BSPC
#define THU_RGT        KC_UPPER
#define CRL_RGT        L12_OR_USCORE
//------------------------------------------------------------------------------
#define STR_MS         KC_BTN1
#define THU_MS         KC_TRNS
#define CRL_MS         L12_OR_BTN2
//==============================================================================
