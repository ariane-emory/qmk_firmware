#pragma once

#define MASTER_LEFT

#undef  USE_CIE1931_CURVE

#undef  RGBLED_NUM
#define RGBLED_NUM                           14
#define RGBLIGHT_HUE_STEP                    8
#define RGBLIGHT_SAT_STEP                    8
#define RGBLIGHT_VAL_STEP                    8

#define AUTO_SHIFT_REPEAT
#define AUTO_SHIFT_TIMEOUT                   180
#define NO_AUTO_SHIFT_ALPHA
#define NO_AUTO_SHIFT_SPECIAL

#define COMBO_ONLY_FROM_LAYER                0
#define COMBO_SHOULD_TRIGGER
#define COMBO_TERM                           50

#define MOUSEKEY_DELAY                       0
#define MOUSEKEY_INTERVAL                    21 // 20
#define MOUSEKEY_MAX_SPEED                   7 // 9
#define MOUSEKEY_MOVE_DELTA                  8
#define MOUSEKEY_TIME_TO_MAX                 42 // 38
#define MOUSEKEY_WHEEL_DELAY                 0
#define MOUSEKEY_WHEEL_INTERVAL              85
#define MOUSEKEY_WHEEL_MAX_SPEED             13
#define MOUSEKEY_WHEEL_TIME_TO_MAX           52

#define ONESHOT_TIMEOUT                      1000

#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
#define PERMISSIVE_HOLD_PER_KEY

#define TAPPING_TERM                         250

#define TOGGLED_LAYER                        6
#define TOGGLED_LAYER_TIMEOUT                30000

#define MY_RGB_DEFAULT                       0xFF, 0x50, 0x8F
#define MY_RGB_RECORDING_MACRO               RGB_MAGENTA
#define MY_RGB_TOGGLED_LAYER_ON              RGB_CHARTREUSE
#define MY_RGB_LOWER_LAYER_ON                RGB_CYAN
#define MY_RGB_UPPER_LAYER_ON                RGB_BLUE
#define MY_RGB_ADJUST_LAYER_ON               RGB_PURPLE

#define TRI_LAYER_LOWER_LAYER                7
#define TRI_LAYER_UPPER_LAYER                8
#define TRI_LAYER_ADJUST_LAYER               13

#define HOME_ROW_MODS
#define MY_RGB_LAYERS

#define NO_ACTION_ONESHOT
#define RGB_FADER_NO_STRINGS
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

#undef EEPROM_ENABLE
#undef EEPROM_DRIVER

#define DYNAMIC_MACRO_DELAY              15

#define TOP_SHIFT
#define BOTTOM_SHIFT

#define MY_RGB_RECORDING_MACRO               RGB_MAGENTA
#define MY_RGB_TOGGLED_LAYER_ON              RGB_CHARTREUSE
#define MY_RGB_LOWER_LAYER_ON                RGB_CYAN
#define MY_RGB_UPPER_LAYER_ON                RGB_BLUE
#define MY_RGB_ADJUST_LAYER_ON               RGB_PURPLE

#define TRI_LAYER_LOWER_LAYER                7
#define TRI_LAYER_UPPER_LAYER                8
#define TRI_LAYER_ADJUST_LAYER               13

#define HOME_ROW_MODS
#define MY_RGB_LAYERS

#define NO_ACTION_ONESHOT
#define RGB_FADER_NO_STRINGS
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

#undef EEPROM_ENABLE
#undef EEPROM_DRIVER

#define DYNAMIC_MACRO_DELAY              15

#define TOP_SHIFT
#define BOTTOM_SHIFT
#define DYNAMIC_MACRO_DELAY              15

#define TOP_SHIFT
#define BOTTOM_SHIFT

#define USE_SEND_STRING_KEYCODES_TABLE
#define USE_TAP_CASE_TABLE
