#pragma once

#undef  RGBLED_NUM
#undef  USE_CIE1931_CURVE
#undef  EEPROM_DRIVER
#undef  EEPROM_ENABLE
#undef  LOCKING_RESYNC_ENABLE
#undef  LOCKING_SUPPORT_ENABLE

#define MASTER_LEFT

#define AUTO_SHIFT_REPEAT
#define AUTO_SHIFT_TIMEOUT                   180
#define NO_AUTO_SHIFT_ALPHA
#define NO_AUTO_SHIFT_SPECIAL

#define COMBO_ONLY_FROM_LAYER                0
#define COMBO_SHOULD_TRIGGER
#define COMBO_TERM                           40

#define DYNAMIC_MACRO_DELAY                  15

#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

#define MOUSEKEY_DELAY                       0
#define MOUSEKEY_INTERVAL                    24
#define MOUSEKEY_MAX_SPEED                   10
#define MOUSEKEY_MOVE_DELTA                  8
#define MOUSEKEY_TIME_TO_MAX                 75
#define MOUSEKEY_WHEEL_DELAY                 0
#define MOUSEKEY_WHEEL_INTERVAL              85
#define MOUSEKEY_WHEEL_MAX_SPEED             13
#define MOUSEKEY_WHEEL_TIME_TO_MAX           52

#define MY_RGB_LAYERS
#define MY_RGB_DEFAULT                       RGB_MAGENTA
#define MY_RGB_LOWER_LAYER_ON                RGB_CYAN
#define MY_RGB_UPPER_LAYER_ON                RGB_BLUE
#define MY_RGB_ADJUST_LAYER_ON               RGB_RED
#define MY_RGB_RECORDING_MACRO               RGB_ORANGE
#define MY_RGB_TOGGLED_LAYER_ON              RGB_CHARTREUSE

#define NO_ACTION_ONESHOT

#define ONESHOT_TIMEOUT                      1000
#define PERMISSIVE_HOLD_PER_KEY

#define RGBLIGHT_HUE_STEP                    8
#define RGBLIGHT_SAT_STEP                    8
#define RGBLIGHT_VAL_STEP                    8

#define CRGB_FADER_NO_STRINGS

#define TAPPING_TERM                         200

#define TOGGLED_LAYER                        6
#define TOGGLED_LAYER_TIMEOUT                30000

#define TRI_LAYER_ADJUST_LAYER               13
#define TRI_LAYER_LOWER_LAYER                7
#define TRI_LAYER_UPPER_LAYER                8

// #define HOME_SHIFT_LEFT
// #define HOME_SHIFT_RIGHT
#define HOME_ARROWS_LEFT
#define HOME_ARROWS_RIGHT
#define BOTTOM_SHIFT
#define HOME_ROW_MODS

// #define FLIP_THUMBS
#define SPREAD_THUMBS
// #define SPREAD_THUMBS_WIDE
#define RGB_ONE_HAND
#define DIM_RGBS                             1

#ifdef RGB_ONE_HAND
#  define RGBLED_NUM                         8 // one LED on right half.
#else
#  define RGBLED_NUM                         14
#endif

