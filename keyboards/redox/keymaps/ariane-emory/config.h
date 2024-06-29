// -*- c-backslash-column: 80; c-backslash-max-column: 80; fill-column: 80; eval: (display-fill-column-indicator-mode 1); -*-
#pragma once

#undef RGBLIGHT_ANIMATIONS
#undef RGBLIGHT_EFFECT_BREATHING
#undef RGBLIGHT_EFFECT_RAINBOW_MOOD
#undef RGBLIGHT_EFFECT_RAINBOW_SWIRL
#undef RGBLIGHT_EFFECT_SNAKE
#undef RGBLIGHT_EFFECT_KNIGHT
#undef RGBLIGHT_EFFECT_CHRISTMAS
#undef RGBLIGHT_EFFECT_STATIC_GRADIENT
#undef RGBLIGHT_EFFECT_RGB_TEST
#undef RGBLIGHT_EFFECT_ALTERNATING
#undef RGBLIGHT_EFFECT_TWINKLE

//#undef  RGBLED_NUM
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
#define COMBO_TERM                           50

#define DYNAMIC_MACRO_DELAY                  15
#define DYNAMIC_MACRO_SIZE                   64

#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

#define LEADER_TIMEOUT 300
#define LEADER_PER_KEY_TIMING

#define MOUSEKEY_DELAY                       0
#define MOUSEKEY_INTERVAL                    19 // 22
#define MOUSEKEY_MAX_SPEED                   14
#define MOUSEKEY_MOVE_DELTA                  8
#define MOUSEKEY_TIME_TO_MAX                 93

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
#define MY_RGB_DEFAULT                       0xFF, 0x00, 0x00 // red
#define MY_RGB_FLIP_LAYER_ON                 0x88, 0x00, 0xC0 // violet-ish
#define MY_RGB_LOWER_LAYER_ON                0x00, 0x74, 0x1C // blue-ish green
#define MY_RGB_UPPER_LAYER_ON                0xFF, 0x00, 0x70 // magenta-ish
#define MY_RGB_ADJUST_LAYER_ON               0x00, 0x14, 0xC0 // blue 
#define MY_RGB_TOGGLED_LAYER_ON              0x10, 0x90, 0x00 // green
#define MY_RGB_BOOT                          0xFF, 0x28, 0x00 // orange-ish
#define MY_RGB_WORKMAK                       0xFF, 0x20, 0x10 // pink-ish

//#define NO_ACTION_ONESHOT
#define ONESHOT_TIMEOUT                      1250
#define PERMISSIVE_HOLD_PER_KEY

//#define RGBLED_NUM                           14
#define RGBLIGHT_HUE_STEP                    8
#define RGBLIGHT_SAT_STEP                    8
#define RGBLIGHT_VAL_STEP                    8

#define TAPPING_TERM                         300
// #define QUICK_TAP_TERM                       0

#define TOGGLED_LAYER                        9
#define TOGGLED_LAYER_TIMEOUT                30000
#define DOUBLE_QUOTE_TIMEOUT                 333

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

// #define ROTATE_OXEY

#define USE_ACHORDION
#define ACHORDION_STREAK

#define AE_NO_DIAGONAL_MOUSE_ACCEL_RESET

#define AE_FLIPPED_NUMS
