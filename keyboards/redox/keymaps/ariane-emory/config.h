/*
Copyright 2018 Mattia Dal Ben <matthewdibi@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

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
#define RGBLED_NUM 14
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8

// #define AUTO_SHIFT_MODIFIERS
#define AUTO_SHIFT_REPEAT
#define AUTO_SHIFT_TIMEOUT 150
#define AUTO_SHIFT_TIMEOUT_PER_KEY
// #define NO_AUTO_SHIFT_ALPHA
#define RETRO_SHIFT

#define COMBO_ONLY_FROM_LAYER 0
#define COMBO_SHOULD_TRIGGER
#define COMBO_TERM 50

#define MOUSEKEY_DELAY 0
#define MOUSEKEY_INTERVAL 20
#define MOUSEKEY_MAX_SPEED 9
#define MOUSEKEY_MOVE_DELTA 8
#define MOUSEKEY_TIME_TO_MAX 38
#define MOUSEKEY_WHEEL_DELAY 0
#define MOUSEKEY_WHEEL_INTERVAL 85
#define MOUSEKEY_WHEEL_MAX_SPEED 14
#define MOUSEKEY_WHEEL_TIME_TO_MAX 45

#define ONESHOT_TIMEOUT 1000

#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
//#define HOLD_ON_OTHER_KEY_PRESS
#define IGNORE_MOD_TAP_INTERRUPT
//#define PERMISSIVE_HOLD
#define PERMISSIVE_HOLD_PER_KEY

#define TAPPING_TERM 225
#define TAPPING_TERM_PER_KEY

#define TOGGLED_LAYER 6
#define TOGGLED_LAYER_TIMEOUT 20000
#define RGB_TIMEOUT 40000

#define TRI_LAYER_ADJUST_LAYER 13
#define TRI_LAYER_LOWER_LAYER 7
#define TRI_LAYER_UPPER_LAYER 8

