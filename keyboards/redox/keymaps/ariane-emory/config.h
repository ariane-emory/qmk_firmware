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
#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_EFFECT_SNAKE
#define RGBLIGHT_EFFECT_KNIGHT
#define RGBLIGHT_EFFECT_CHRISTMAS
#define RGBLIGHT_EFFECT_STATIC_GRADIENT
#define RGBLIGHT_EFFECT_RGB_TEST
#define RGBLIGHT_EFFECT_ALTERNATING
#define RGBLIGHT_EFFECT_TWINKLE
#define RGBLED_NUM 14
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8

#define TAPPING_TERM 275
#define AUTO_SHIFT_TIMEOUT 250
#define RETRO_SHIFT
#define ONESHOT_TIMEOUT 1000

#define MOUSEKEY_WHEEL_DELAY 0 // Delay between pressing a wheel key and wheel movement.
#define MOUSEKEY_INERTIA 1 //	Enable Inertia mode
#define MOUSEKEY_DELAY 0 //	Delay between pressing a movement key and cursor movement
#define MOUSEKEY_INTERVAL 16 //	Time between cursor movements in milliseconds (16 = 60fps)
#define MOUSEKEY_MAX_SPEED 48 //	Maximum cursor speed at which acceleration stops
#define MOUSEKEY_TIME_TO_MAX 20 //	Number of frames until maximum cursor speed is reached
#define MOUSEKEY_FRICTION 20 //	How quickly the cursor stops after releasing a key
#define MOUSEKEY_MOVE_DELTA 2 //	How much to move on first frame (1 strongly recommended)
