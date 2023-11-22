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
#define LHRM_4(x) LSFT_T(x) // LT(LN_ARROWS,x)
#define LHRM_3(x) LGUI_T(x)
#define LHRM_2(x) LALT_T(x)
#define LHRM_1(x) LCTL_T(x)
#define LHRM_0(x) LSFT_T(x)
//------------------------------------------------------------------------------
#define RHRM_0(x) RSFT_T(x)
#define RHRM_1(x) RCTL_T(x)
#define RHRM_2(x) RALT_T(x)
#define RHRM_3(x) RGUI_T(x)
#define RHRM_4(x) LSFT_T(x) // LT(LN_ARROWS,x)
//------------------------------------------------------------------------------
#define LBRM_4(x) LT(LN_ARROWS, x)
#define RBRM_4(x) LT(LN_ARROWS, x)
//==============================================================================


//==============================================================================
// Qwerty
//==============================================================================
#define QT_TAB  LT(LN_UTIL,KC_TAB)
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
#define QT_BSLS LT(LN_UTIL,KC_BSLS)
//------------------------------------------------------------------------------
#define QH_A    LHRM_4(KC_A)
#define QH_S    LHRM_3(KC_S)
#define QH_D    LHRM_2(KC_D)
#define QH_F    LHRM_1(KC_F)
#define QH_G    LHRM_0(KC_G)
#define QH_H    RHRM_0(KC_H)
#define QH_J    RHRM_1(KC_J)
#define QH_K    RHRM_2(KC_K)
#define QH_L    RHRM_3(KC_L)
#ifdef DQUOTE_LEFT
#  define DEF_QUOT KC_DQUO
#  define QH_QUOT  RHRM_4(KC_DQUO_TAP)
#  define QH_ENTR  RCTL_SQUO
#else
#  define DEF_QUOT KC_QUOT
#  define QH_QUOT  RHRM_4(KC_QUOT)
#  define QH_ENTR  RCTL_DQUO
#endif
//------------------------------------------------------------------------------
#define QB_Z    LBRM_4(KC_Z)
#define QB_X    KC_X
#define QB_C    KC_C
#define QB_V    KC_V
#define QB_B    KC_B
#define QB_N    KC_N
#define QB_M    KC_M
#define QB_COMM KC_COMM
#define QB_DOT  KC_DOT
#define QB_SLSH LBRM_4(KC_SLSH)
//==============================================================================


#ifdef BOTTOM_O
# define RIGHT_OUTER_H KC_QUOT
# define RIGHT_OUTER_B KC_O
#else
# define RIGHT_OUTER_H KC_O
# define RIGHT_OUTER_B KC_QUOT
#endif

#ifdef BOTTOM_V
# define LEFT_INNER_T KC_B
# define LEFT_INNER_B KC_V
#else
# define LEFT_INNER_T KC_V
# define LEFT_INNER_B KC_B
#endif

//==============================================================================
// Colemak-like, ARTS
//==============================================================================
#  define AT_Q    KC_Q
#  define AT_W    KC_W
#  define AT_E    KC_D
#  define AT_R    KC_C
#  define AT_T    LEFT_INNER_T
#  define AT_Y    KC_J
#  define AT_U    KC_L
#  define AT_I    KC_U
#  define AT_O    KC_Y
#  define AT_P    KC_SLSH
//------------------------------------------------------------------------------
#  define AH_A    LHRM_4(KC_A)
#  define AH_S    LHRM_3(KC_R)
#  define AH_D    LHRM_2(KC_T)
#  define AH_F    LHRM_1(KC_S)
#  define AH_G    LHRM_0(KC_G)
#  define AH_H    RHRM_0(KC_M)
#  define AH_J    RHRM_1(KC_H)
#  define AH_K    RHRM_2(KC_E)
#  define AH_L    RHRM_3(KC_I)
#  define AH_QUOT RHRM_4(RIGHT_OUTER_H)
//------------------------------------------------------------------------------
#  define AB_Z    LBRM_4(KC_Z)
#  define AB_X    KC_X
#  define AB_C    KC_P
#  define AB_V    KC_F
#  define AB_B    LEFT_INNER_B
#  define AB_N    KC_K
#  define AB_M    KC_N
#  define AB_COMM KC_COMM
#  define AB_DOT  KC_DOT
#  define AB_SLSH RBRM_4(RIGHT_OUTER_B)
//==============================================================================


//==============================================================================
// Colemak-like, ARST
//==============================================================================
#define KT_Q    KC_Q
#define KT_W    KC_W
#define KT_E    KC_F
#define KT_R    KC_P
#define KT_T    LEFT_INNER_T
#define KT_Y    KC_J
#define KT_U    KC_L
#define KT_I    KC_U
#define KT_O    KC_Y
#define KT_P    KC_SLSH
//------------------------------------------------------------------------------
#define KH_A    LHRM_4(KC_A)
#define KH_S    LHRM_3(KC_R)
#define KH_D    LHRM_2(KC_S)
#define KH_F    LHRM_1(KC_T)
#define KH_G    LHRM_0(KC_G)
#define KH_H    RHRM_0(KC_M)
#define KH_J    RHRM_1(KC_H)
#define KH_K    RHRM_2(KC_E)
#define KH_L    RHRM_3(KC_I)
#define KH_QUOT RHRM_4(RIGHT_OUTER_H)
//------------------------------------------------------------------------------
#define KB_Z    LBRM_4(KC_Z)
#define KB_X    KC_X
#define KB_C    KC_C
#define KB_V    KC_D
#define KB_B    LEFT_INNER_B
#define KB_N    KC_K
#define KB_M    KC_N
#define KB_COMM KC_COMM
#define KB_DOT  KC_DOT
#define KB_SLSH RBRM_4(RIGHT_OUTER_B)
//==============================================================================


//==============================================================================
// Colemak-DH
//==============================================================================
#define CT_Q    KC_Q
#define CT_W    KC_W
#define CT_E    KC_F
#define CT_R    KC_P
#define CT_T    LEFT_INNER_T
#define CT_Y    KC_J
#define CT_U    KC_L
#define CT_I    KC_U
#define CT_O    KC_Y
#define CT_P    KC_SLSH
//------------------------------------------------------------------------------
#define CH_A    LHRM_4(KC_A)
#define CH_S    LHRM_3(KC_R)
#define CH_D    LHRM_2(KC_S)
#define CH_F    LHRM_1(KC_T)
#define CH_G    LHRM_0(KC_G)
#define CH_H    RHRM_0(KC_M)
#define CH_J    RHRM_1(KC_N)
#define CH_K    RHRM_2(KC_E)
#define CH_L    RHRM_3(KC_I)
#define CH_QUOT RHRM_4(RIGHT_OUTER_H)
//------------------------------------------------------------------------------
#define CB_Z    LBRM_4(KC_Z)
#define CB_X    KC_X
#define CB_C    KC_C
#define CB_V    KC_D
#define CB_B    LEFT_INNER_B
#define CB_N    KC_H
#define CB_M    KC_N
#define CB_COMM KC_COMM
#define CB_DOT  KC_DOT
#define CB_SLSH RBRM_4(RIGHT_OUTER_B)
//==============================================================================


//==============================================================================
// Colemak-like, ASRT
//==============================================================================
#define XT_Q    KC_Q
#define XT_W    KC_F
#define XT_E    KC_W
#define XT_R    KC_P
#define XT_T    LEFT_INNER_T
#define XT_Y    KC_J
#define XT_U    KC_L
#define XT_I    KC_U
#define XT_O    KC_Y
#define XT_P    KC_Z
//------------------------------------------------------------------------------
#define XH_A    LHRM_4(KC_A)
#define XH_S    LHRM_3(KC_S)
#define XH_D    LHRM_2(KC_R)
#define XH_F    LHRM_1(KC_T)
#define XH_G    LHRM_0(KC_G)
#define XH_H    RHRM_0(KC_M)
#define XH_J    RHRM_1(KC_H)
#define XH_K    RHRM_2(KC_E)
#define XH_L    RHRM_3(KC_I)
#define XH_QUOT RHRM_4(RIGHT_OUTER_H)
//------------------------------------------------------------------------------
#define XB_Z    LBRM_4(KC_SLSH)
#define XB_X    KC_X
#define XB_C    KC_C
#define XB_V    KC_D
#define XB_B    LEFT_INNER_B
#define XB_N    KC_K
#define XB_M    KC_N
#define XB_COMM KC_COMM
#define XB_DOT  KC_DOT
#define XB_SLSH RBRM_4(RIGHT_OUTER_B)
//==============================================================================


//==============================================================================
// Colemak-like, ASTR
//==============================================================================
#define WT_Q    KC_Q
#define WT_W    KC_F
#define WT_E    KC_D
#define WT_R    KC_C
#define WT_T    LEFT_INNER_T
#define WT_Y    KC_J
#define WT_U    KC_L
#define WT_I    KC_U
#define WT_O    KC_Y
#define WT_P    KC_Z
//------------------------------------------------------------------------------
#define WH_A    LHRM_4(KC_A)
#define WH_S    LHRM_3(KC_S)
#define WH_D    LHRM_2(KC_T)
#define WH_F    LHRM_1(KC_R)
#define WH_G    LHRM_0(KC_G)
#define WH_H    RHRM_0(KC_M)
#define WH_J    RHRM_1(KC_H)
#define WH_K    RHRM_2(KC_E)
#define WH_L    RHRM_3(KC_I)
#define WH_QUOT RHRM_4(RIGHT_OUTER_H)
//------------------------------------------------------------------------------
#define WB_Z    LBRM_4(KC_SLSH)
#define WB_X    KC_X
#define WB_C    KC_P
#define WB_V    KC_W
#define WB_B    LEFT_INNER_B
#define WB_N    KC_K
#define WB_M    KC_N
#define WB_COMM KC_COMM
#define WB_DOT  KC_DOT
#define WB_SLSH RBRM_4(RIGHT_OUTER_B)
//==============================================================================


//==============================================================================
// Minimak
//==============================================================================
#define MT_Q    KC_Q
#define MT_W    KC_W
#define MT_E    KC_D
#define MT_R    KC_R
#define MT_T    KC_K
#define MT_Y    KC_Y
#define MT_U    KC_U
#define MT_I    KC_I
#define MT_O    KC_O
#define MT_P    KC_P
//------------------------------------------------------------------------------
#define MH_A    LHRM_4(KC_A)
#define MH_S    LHRM_3(KC_S)
#define MH_D    LHRM_2(KC_T)
#define MH_F    LHRM_1(KC_F)
#define MH_G    LHRM_0(KC_G)
#define MH_H    LHRM_0(KC_H)
#define MH_J    RHRM_1(KC_J)
#define MH_K    RHRM_2(KC_E)
#define MH_L    RHRM_3(KC_L)
#define MH_QUOT QH_QUOT
//------------------------------------------------------------------------------
#define MB_Z    LBRM_4(KC_Z)
#define MB_X    KC_X
#define MB_C    KC_C
#define MB_V    KC_V
#define MB_B    KC_B
#define MB_N    KC_N
#define MB_M    KC_M
#define MB_COMM KC_COMM
#define MB_DOT  KC_DOT
#define MB_SLSH RBRM_4(KC_SLSH)
//==============================================================================


//==============================================================================
// Semimak
//==============================================================================
#define ST_Q    KC_F
#define ST_W    KC_L
#define ST_E    KC_H
#define ST_R    KC_V
#define ST_T    KC_Z
#define ST_Y    KC_Q
#define ST_U    KC_W
#define ST_I    KC_U
#define ST_O    KC_O
#define ST_P    KC_Y
//------------------------------------------------------------------------------
#define SH_A    LHRM_4(KC_S)
#define SH_S    LHRM_3(KC_R)
#define SH_D    LHRM_2(KC_N)
#define SH_F    LHRM_1(KC_T)
#define SH_G    LHRM_0(KC_K)
#define SH_H    RHRM_0(KC_C)
#define SH_J    RHRM_1(KC_D)
#define SH_K    RHRM_2(KC_E)
#define SH_L    RHRM_3(KC_A)
#define SH_QUOT RHRM_4(KC_I)
//------------------------------------------------------------------------------
#define SB_Z    LBRM_4(KC_X)
#define SB_X    DEF_QUOT
#define SB_C    KC_B
#define SB_V    KC_M
#define SB_B    KC_J
#define SB_N    KC_P
#define SB_M    KC_G
#define SB_COMM KC_COMM
#define SB_DOT  KC_DOT
#define SB_SLSH RBRM_4(KC_SLSH)
//==============================================================================


//==============================================================================
// Norman
//==============================================================================
#define NT_Q    KC_Q
#define NT_W    KC_W
#define NT_E    KC_D
#define NT_R    KC_F
#define NT_T    KC_K
#define NT_Y    KC_J
#define NT_U    KC_U
#define NT_I    KC_R
#define NT_O    KC_L
#define NT_P    DEF_QUOT
//------------------------------------------------------------------------------
#define NH_A    LHRM_4(KC_A)
#define NH_S    LHRM_3(KC_S)
#define NH_D    LHRM_2(KC_E)
#define NH_F    LHRM_1(KC_T)
#define NH_G    LHRM_0(KC_G)
#define NH_H    RHRM_0(KC_Y)
#define NH_J    RHRM_1(KC_N)
#define NH_K    RHRM_2(KC_I)
#define NH_L    RHRM_3(KC_O)
#define NH_QUOT RHRM_4(KC_H)   
//------------------------------------------------------------------------------
#define NB_Z    LBRM_4(KC_Z)
#define NB_X    KC_X
#define NB_C    KC_C
#define NB_V    KC_V
#define NB_B    KC_B
#define NB_N    KC_P
#define NB_M    KC_M
#define NB_COMM KC_COMM
#define NB_DOT  KC_DOT
#define NB_SLSH LBRM_4(KC_SLSH)
//==============================================================================


//==============================================================================
// Shift keys
//==============================================================================
#define   QB_LSFT LSFT_T(KC_MINS)
#define   QB_RSFT RSFT_T(KC_MINS)
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
#define LUTIL_OR_CMD_W LT(LN_UTIL,RGUI(KC_W))
#define EM_SHELL       LALT(LGUI(KC_S))
#define KA_UNDO        LGUI(KC_Z)
#define EM_ALL_BUF     LALT(LGUI(KC_A))
#define EM_PRV_BUF     LALT(LGUI(KC_V))
#define EM_DIRED       LALT(LGUI(KC_D))
#define EM_LWRAP       LALT(LGUI(KC_L))
#define EM_BGN_MAC     LALT(LGUI(KC_W))
#define EM_RPT_MAC     LALT(LGUI(KC_R))
#define EM_END_MAC     LALT(LGUI(KC_E))
#define EM_CTL_X       LCTL(KC_X)
#define EM_CTL_C       LCTL(KC_C)
#define RCTL_SQUO      RCTL_T(KC_SQUO_TAP)
#define RCTL_DQUO      RCTL_T(KC_DQUO_TAP)
#define LCTL_ESC       LCTL_T(KC_ESC)
#define BRTU           KC_VOLU
#define BRTD           KC_VOLD
#define VOLU           KC_F20
#define VOLD           KC_F19
#define TG_MOUSE       TG(LN_MOUSE)
//==============================================================================


//==============================================================================
// Tri layer keys
//==============================================================================
#define KC_LOWER       MO(LN_LOWER)
#define KC_UPPER       MO(LN_UPPER)
//==============================================================================


//==============================================================================
// Thumr key aliases
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
#define CRL_MS  FLIPR_OR_BTN2
//==============================================================================
