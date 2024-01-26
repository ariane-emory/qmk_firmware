#pragma once

#include <stdint.h>
#include <stdbool.h>

#include "color.h"

// ==============================================================================
// rgb_led_t functions
// ==============================================================================

void rgb_led_t_init            (      rgb_led_t * const this, const uint8_t r,  const uint8_t g, const uint8_t b);
void rgb_led_t_copy            (      rgb_led_t * const this, const rgb_led_t * const that);
bool rgb_led_t_equal           (const rgb_led_t * const this, const rgb_led_t * const that);

#ifndef RGB_FADER_NO_STRINGS
bool rgb_led_t_init_from_str   (rgb_led_t * const this, const char * const str);
void rgb_led_t_sprintf         (const rgb_led_t * const this, char * const str);
#endif

