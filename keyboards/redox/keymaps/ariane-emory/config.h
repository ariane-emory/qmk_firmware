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
#define DYNAMIC_MACRO_SIZE                   64

#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

#define MOUSEKEY_DELAY                       0
#define MOUSEKEY_INTERVAL                    22
#define MOUSEKEY_MAX_SPEED                   14
#define MOUSEKEY_MOVE_DELTA                  8
#define MOUSEKEY_TIME_TO_MAX                 95

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

#define RGBLED_NUM                           14
#define RGBLIGHT_HUE_STEP                    8
#define RGBLIGHT_SAT_STEP                    8
#define RGBLIGHT_VAL_STEP                    8

#define TAPPING_TERM                         250

#define TOGGLED_LAYER                        6
#define TOGGLED_LAYER_TIMEOUT                30000

//==============================================================================

#define CRGB_FADER_NO_STRINGS
#define DIM_RGBS                             1

//==============================================================================

#ifndef DIM_RGBS
#  define DIM_RGBs                           0
#endif

#undef PRODUCT
#define PRODUCT "K's Redox"

#define DROP_O
// #define DQUOTE_LEFT

#define LEADER_TIMEOUT 666
#define LEADER_PER_KEY_TIMING

#define AE_NO_DIAGONAL_MOUSE_ACCEL_RESET

