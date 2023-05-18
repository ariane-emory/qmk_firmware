#pragma once

#ifdef HOME_ROW_MODS
#define QH_A    LSFT_T(KC_A)
#define QH_S    LGUI_T(KC_S)
#define QH_D    LALT_T(KC_D)
#define QH_F    LCTL_T(KC_F)
#define QH_G    KC_G
#define QH_H    KC_H
#define QH_J    RCTL_T(KC_J)
#define QH_K    RALT_T(KC_K)
#define QH_L    RGUI_T(KC_L)
#define QH_QUOT RSFT_T(KC_QUOT)
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
#else
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
#endif

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
#else
#define QB_Z    KC_Z
#define QB_X    KC_X
#define QB_C    KC_C
#define QB_V    KC_V
#define QB_B    KC_B
#define QB_N    KC_N
#define QB_M    KC_M
#define QB_COMM KC_COMM
#define QB_DOT  KC_DOT
#define QB_SLSH KC_SLSH
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
#endif

#ifdef TRI_LAYER_ENABLE
#define TH_LFT QK_TRI_LAYER_LOWER
#define TH_RGT QK_TRI_LAYER_UPPER
#else
#define TH_LFT MO(MY_LOWER_LAYER)
#define TH_RGT MO(MY_UPPER_LAYER)
#endif
