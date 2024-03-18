// -*- c-backslash-column: 115; c-backslash-max-column: 115 ; fill-column: 115; eval: (display-fill-column-indicator-mode 1); -*-
#pragma once

#include <stdint.h>
#include <stdbool.h>

#include "color.h"

// ================================================================================================================
// rgb_led_t functions
// ================================================================================================================

void init_rgb_led_t            (      rgb_led_t * const this, const uint8_t r,  const uint8_t g, const uint8_t b);
void copy_rgb_led_t            (      rgb_led_t * const this, const rgb_led_t * const that);
bool equal_rgb_led_t           (const rgb_led_t * const this, const rgb_led_t * const that);

#ifndef RGB_FADER_NO_STRINGS
bool init_rgb_led_t_from_str   (      rgb_led_t * const this, const char * const str);
void sprintf_rgb_led_t         (const rgb_led_t * const this,       char * const str);
#endif

