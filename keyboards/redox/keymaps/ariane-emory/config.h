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

#define LEADER_TIMEOUT 666
#define LEADER_PER_KEY_TIMING

#define MOUSEKEY_DELAY                       0
#define MOUSEKEY_INTERVAL                    22
#define MOUSEKEY_MAX_SPEED                   14
#define MOUSEKEY_MOVE_DELTA                  8
#define MOUSEKEY_TIME_TO_MAX                 95

#define MOUSEKEY_WHEEL_DELAY                 0
#define MOUSEKEY_WHEEL_INTERVAL              85
#define MOUSEKEY_WHEEL_MAX_SPEED             13
#define MOUSEKEY_WHEEL_TIME_TO_MAX           52

/* #define RGB_AZURE       0x99, 0xF5, 0xFF */
/* #define RGB_BLACK       0x00, 0x00, 0x00 */
/* #define RGB_BLUE        0x00, 0x00, 0xFF */
/* #define RGB_CHARTREUSE  0x80, 0xFF, 0x00 */
/* #define RGB_CORAL       0xFF, 0x7C, 0x4D */
/* #define RGB_CYAN        0x00, 0xFF, 0xFF */
/* #define RGB_GOLD        0xFF, 0xD9, 0x00 */
/* #define RGB_GOLDENROD   0xD9, 0xA5, 0x21 */
/* #define RGB_GREEN       0x00, 0xFF, 0x00 */
/* #define RGB_MAGENTA     0xFF, 0x00, 0xFF */
/* #define RGB_ORANGE      0xFF, 0x80, 0x00 */
/* #define RGB_PINK        0xFF, 0x80, 0xBF */
/* #define RGB_PURPLE      0x7A, 0x00, 0xFF */
/* #define RGB_RED         0xFF, 0x00, 0x00 */
/* #define RGB_SPRINGGREEN 0x00, 0xFF, 0x80 */
/* #define RGB_TEAL        0x00, 0x80, 0x80 */
/* #define RGB_TURQUOISE   0x47, 0x6E, 0x6A */
/* #define RGB_WHITE       0xFF, 0xFF, 0xFF */
/* #define RGB_YELLOW      0xFF, 0xFF, 0x00 */

#define MY_RGB_LAYERS
#define MY_RGB_RECORDING_MACRO               RGB_ORANGE
#define MY_RGB_DEFAULT                       RGB_RED
#define MY_RGB_FLIP_LAYER_ON                 0x88, 0x00, 0xC0
#define MY_RGB_LOWER_LAYER_ON                0x00, 0x60, 0x13 // blue-ish green
#define MY_RGB_UPPER_LAYER_ON                0xFF, 0x00, 0x40 // magenta-ish
#define MY_RGB_ADJUST_LAYER_ON               0x10, 0x00, 0x80 // RGB_GOLD // 0x0,  0xFF, 0x20
#define MY_RGB_TOGGLED_LAYER_ON              0x10, 0x80, 0x00 // RGB_CHARTREUSE
#define MY_RGB_BOOT                          0xFF, 0x20, 0x00 // orange-ish

#define NO_ACTION_ONESHOT
#define ONESHOT_TIMEOUT                      1000
#define PERMISSIVE_HOLD_PER_KEY

#define RGBLED_NUM                           14
#define RGBLIGHT_HUE_STEP                    8
#define RGBLIGHT_SAT_STEP                    8
#define RGBLIGHT_VAL_STEP                    8

#define TAPPING_TERM                         275

#define TOGGLED_LAYER                        9
#define TOGGLED_LAYER_TIMEOUT                30000

//==============================================================================

#define CRGB_FADER_NO_STRINGS
#define DIM_RGBS                             0
#define SLOW_RGBS

#ifndef DIM_RGBS
#  define DIM_RGBS                           0
#endif

//==============================================================================

#undef PRODUCT
#define PRODUCT "K's Redox"

//#define ROTATE_RIGHT_COL

#define USE_ACHORDION
#define ACHORDION_STREAK

#define AE_NO_DIAGONAL_MOUSE_ACCEL_RESET

