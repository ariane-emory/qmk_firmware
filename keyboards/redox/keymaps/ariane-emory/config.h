#pragma once

/* Select hand configuration */
#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#undef RGBLED_NUM
/* #define RGBLIGHT_EFFECT_BREATHING */
/* #define RGBLIGHT_EFFECT_RAINBOW_MOOD */
/* #define RGBLIGHT_EFFECT_RAINBOW_SWIRL */
/* #define RGBLIGHT_EFFECT_SNAKE */
/* #define RGBLIGHT_EFFECT_KNIGHT */
/* #define RGBLIGHT_EFFECT_CHRISTMAS */
/* #define RGBLIGHT_EFFECT_STATIC_GRADIENT */
/* #define RGBLIGHT_EFFECT_RGB_TEST */
/* #define RGBLIGHT_EFFECT_ALTERNATING */
/* #define RGBLIGHT_EFFECT_TWINKLE */
#define RGBLED_NUM                 14
#define RGBLIGHT_HUE_STEP          8
#define RGBLIGHT_SAT_STEP          8
#define RGBLIGHT_VAL_STEP          8

// #define AUTO_SHIFT_MODIFIERS
#define AUTO_SHIFT_REPEAT
#define AUTO_SHIFT_TIMEOUT         180
#define AUTO_SHIFT_TIMEOUT_PER_KEY
#define NO_AUTO_SHIFT_ALPHA
// #define RETRO_TAPPING

#define COMBO_ONLY_FROM_LAYER      0
#define COMBO_SHOULD_TRIGGER
#define COMBO_TERM                 40

#define MOUSEKEY_DELAY             0
#define MOUSEKEY_INTERVAL          21 // 20
#define MOUSEKEY_MAX_SPEED         7 // 9
#define MOUSEKEY_MOVE_DELTA        8
#define MOUSEKEY_TIME_TO_MAX       42 // 38
#define MOUSEKEY_WHEEL_DELAY       0
#define MOUSEKEY_WHEEL_INTERVAL    85
#define MOUSEKEY_WHEEL_MAX_SPEED   13
#define MOUSEKEY_WHEEL_TIME_TO_MAX 52

#define ONESHOT_TIMEOUT            1000

#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
//#define HOLD_ON_OTHER_KEY_PRESS
#define IGNORE_MOD_TAP_INTERRUPT
//#define PERMISSIVE_HOLD
#define PERMISSIVE_HOLD_PER_KEY

#define TAPPING_TERM               250
#define TAPPING_TERM_PER_KEY

#define TOGGLED_LAYER              6
#define TOGGLED_LAYER_TIMEOUT      30000

#define SLEEP_TIMEOUT              45000
#define HSV_ASLEEP                 HSV_BLACK
#define HSV_TOGGLED_LAYER_OFF      HSV_BLACK // HSV_RED
#define HSV_TOGGLED_LAYER_ON       HSV_CHARTREUSE
#define HSV_LOWER_LAYER_ON         HSV_PURPLE
#define HSV_UPPER_LAYER_ON         HSV_BLUE
#define HSV_ADJUST_LAYER_ON        HSV_CYAN

#define MY_LOWER_LAYER      7 
#define MY_UPPER_LAYER      8
#define TRI_LAYER_LOWER_LAYER      7 // MY_LOWER_LAYER
#define TRI_LAYER_UPPER_LAYER      8 // MY_UPPER_LAYER
#define TRI_LAYER_ADJUST_LAYER     13

// #define IGNORE_WAKING_KEY
// #define INSERT_UPP_ENABLED
#define HOME_ROW_MODS
// #define BOTTOM_ROW_MODS
