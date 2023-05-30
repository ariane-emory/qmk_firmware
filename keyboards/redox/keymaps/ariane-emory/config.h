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

#define RGB_DEFAULT                RGB_BLACK
#define RGB_TOGGLED_LAYER_OFF      RGB_BLACK // RGB_RED
#define RGB_TOGGLED_LAYER_ON       RGB_CHARTREUSE
#define RGB_LOWER_LAYER_ON         RGB_PURPLE
#define RGB_UPPER_LAYER_ON         RGB_BLUE
#define RGB_ADJUST_LAYER_ON        RGB_CYAN

#define TRI_LAYER_LOWER_LAYER      7
#define TRI_LAYER_UPPER_LAYER      8
#define TRI_LAYER_ADJUST_LAYER     13

#define HOME_ROW_MODS
// #define BOTTOM_ROW_MODS
#define MY_RGB_LAYERS

#define NO_ACTION_ONESHOT
#define RGB_FADER_NO_STRINGS
#undef  LOCKING_SUPPORT_ENABLE
#undef  LOCKING_RESYNC_ENABLE

//#define PERMISSIVE_HOLD
#define PERMISSIVE_HOLD_PER_KEY

#define TAPPING_TERM               250
#define TAPPING_TERM_PER_KEY

#define TOGGLED_LAYER              6
#define TOGGLED_LAYER_TIMEOUT      30000

#define SLEEP_TIMEOUT              45000
#define RGB_DEFAULT                RGB_BLACK
#define RGB_TOGGLED_LAYER_OFF      RGB_BLACK // RGB_RED
#define RGB_TOGGLED_LAYER_ON       RGB_CHARTREUSE
#define RGB_LOWER_LAYER_ON         RGB_PURPLE
#define RGB_UPPER_LAYER_ON         RGB_BLUE
#define RGB_ADJUST_LAYER_ON        RGB_CYAN

#define TRI_LAYER_LOWER_LAYER      7
#define TRI_LAYER_UPPER_LAYER      8
#define TRI_LAYER_ADJUST_LAYER     13

#define HOME_ROW_MODS
// #define BOTTOM_ROW_MODS
#define MY_RGB_LAYERS

#define NO_ACTION_ONESHOT
#define RGB_FADER_NO_STRINGS
#undef  LOCKING_SUPPORT_ENABLE
#undef  LOCKING_RESYNC_ENABLE


#undef EEPROM_ENABLE
