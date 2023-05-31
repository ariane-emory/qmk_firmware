#pragma once

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

#ifdef HOME_ROW_MODS
#  ifdef STAGGERED_SHIFT
#    define QH_A    KC_A
#  else // STAGGERED_SHIFT
#    define QH_A    LSFT_T(KC_A)
#  endif // STAGGERED_SHIFT
#define QH_S    LGUI_T(KC_S)
#define QH_D    LALT_T(KC_D)
#define QH_F    LCTL_T(KC_F)
#define QH_G    KC_G
#define QH_H    KC_H
#define QH_J    RCTL_T(KC_J)
#define QH_K    RALT_T(KC_K)
#define QH_L    RGUI_T(KC_L)

#  ifdef STAGGERED_SHIFT
#    define QH_QUOT KC_QUOT
#  else // STAGGERED_SHIFT
#    define QH_QUOT RSFT_T(KC_QUOT)
#  endif // STAGGERED_SHIFT

#define CH_A    LSFT_T(KC_A)
#define CH_R    LGUI_T(KC_R)
#define CH_S    LALT_T(KC_S)
#define CH_T    LCTL_T(KC_T)
#define CH_D    KC_D
#define CH_H    KC_H
#define CH_N    RCTL_T(KC_N)
#define CH_E    RALT_T(KC_E)
#define CH_I    RGUI_T(KC_I)
#define CH_QUOT RSFT_T(KC_QUOT)

#else // HOME_ROW_MODS

#define QH_A    KC_A
#define QH_S    KC_S
#define QH_D    KC_D
#define QH_F    KC_F
#define QH_G    KC_G
#define QH_H    KC_H
#define QH_J    KC_J
#define QH_K    KC_K
#define QH_L    KC_L
#define QH_QUOT KC_QUOT
#define CH_A    KC_A
#define CH_R    KC_R
#define CH_S    KC_S
#define CH_T    KC_T
#define CH_D    KC_D
#define CH_H    KC_H
#define CH_N    KC_N
#define CH_E    KC_E
#define CH_I    KC_I
#define CH_QUOT KC_QUOT
#endif // HOME_ROW_MODS

#ifdef BOTTOM_ROW_MODS
#define QB_Z    LCTL_T(KC_Z)
#define QB_X    LALT_T(KC_X)
#define QB_C    LGUI_T(KC_C)
#define QB_V    LSFT_T(KC_V)
#define QB_B    KC_B
#define QB_N    KC_N
#define QB_M    RSFT_T(KC_M)
#define QB_COMM RGUI_T(KC_COMM)
#define QB_DOT  RALT_T(KC_DOT)
#define QB_SLSH RCTL_T(KC_SLSH)
#define CB_Z    LCTL_T(KC_Z)
#define CB_X    LALT_T(KC_X)
#define CB_C    LGUI_T(KC_C)
#define CB_V    LSFT_T(KC_V)
#define CB_B    KC_B
#define CB_K    KC_K
#define CB_M    RSFT_T(KC_M)
#define CB_COMM RGUI_T(KC_COMM)
#define CB_DOT  RALT_T(KC_DOT)
#define CB_SLSH RCTL_T(KC_SLSH)

#else // BOTTOM_ROW_MODS

#  ifdef STAGGERED_SHIFT
#    define QB_Z    LSFT_T(KC_Z)
#  else // STAGGERED_SHIFT
#    define QB_Z   KC_Z
#  endif // STAGGERED_SHIFT

#define QB_X    KC_X
#define QB_C    KC_C
#define QB_V    KC_V
#define QB_B    KC_B
#define QB_N    KC_N
#define QB_M    KC_M
#define QB_COMM KC_COMM
#define QB_DOT  KC_DOT

#  ifdef STAGGERED_SHIFT
#    define QB_SLSH RSFT_T(KC_SLSH)j
#  else // STAGGERED_SHIFT
#    define QB_SLSH KC_SLSH
#  endif // STAGGERED_SHIFT

#define CB_Z    KC_Z
#define CB_X    KC_X
#define CB_C    KC_C
#define CB_V    KC_V
#define CB_B    KC_B
#define CB_K    KC_K
#define CB_M    KC_M
#define CB_COMM KC_COMM
#define CB_DOT  KC_DOT
#define CB_SLSH KC_SLSH
#endif // BOTTOM_ROW_MODS

#ifdef TRI_LAYER_ENABLE
#  define TH_LFT QK_TRI_LAYER_LOWER
#  define TH_RGT QK_TRI_LAYER_UPPER
#else // TRI_LAYER_ENABLE
#  define TH_LFT MO(TRI_LAYER_LOWER_LAYER)
#  define TH_RGT MO(TRI_LAYER_UPPER_LAYER)
#endif // TRI_LAYER_ENABLE

#define EM_SHELL    LALT(LGUI(KC_S))
#define KA_UNDO     LGUI(KC_Z)
#define EM_ALL_BUF  LALT(LGUI(KC_A))
#define EM_PRV_BUF  LALT(LGUI(KC_V))
#define EM_DIRED    LALT(LGUI(KC_D))
#define EM_LWRAP    LALT(LGUI(KC_L))
#define EM_BGN_MAC  LALT(LGUI(KC_W))
#define EM_RPT_MAC  LALT(LGUI(KC_E))
#define EM_END_MAC  LALT(LGUI(KC_R))
#define EM_CTL_X    LCTL(KC_X)
#define EM_CTL_C    LCTL(KC_C)
#define RCTL_DQUO   RCTL_T(KC_DQUO)
