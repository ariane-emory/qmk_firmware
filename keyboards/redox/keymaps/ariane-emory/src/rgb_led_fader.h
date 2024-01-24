#pragma once

#include <stdint.h>
#include <stdbool.h>
#include "rgb_led_functions.h"
#include "color.h"

// ==============================================================================
// RGB fader class
// ==============================================================================

typedef struct rgb_led_fader_t {
  rgb_led_t   initial;
  rgb_led_t   current;
  rgb_led_t   target;
  uint8_t     step;

#ifndef CRGB_FADER_NO_STRINGS
  char    c_str[8];
#endif
} rgb_led_fader_t;

void rgb_led_fader_init               (      rgb_led_fader_t * const this, const uint8_t r, const uint8_t g, const uint8_t b);
void rgb_led_fader_set_target         (      rgb_led_fader_t * const this, const uint8_t r, const uint8_t g, const uint8_t b);
bool rgb_led_fader_is_changing        (const rgb_led_fader_t * const this);
void rgb_led_fader_step               (      rgb_led_fader_t * const this);
void rgb_led_fader_stop               (      rgb_led_fader_t * const this);

#define rgb_led_fader_set_target_from_rgb(rgb_led_fader_p, rgb_p)                                                                                   \
  rgb_led_fader_set_target(rgb_led_fader_p, ((rgb_p)->r), ((rgb_p)->g), ((rgb_p)->b))

#define rgb_led_fader_init_from_rgb(rgb_led_fader_p, rgb_p)                             \
  rgb_led_fader_init(rgb_led_fader_p, ((rgb_p)->r), ((rgb_p)->g), ((rgb_p)->b))

#ifndef CRGB_FADER_NO_STRINGS
bool rgb_led_fader_init_from_str      (      rgb_led_fader_t * const this, const char * const str);
bool rgb_led_fader_set_target_from_str(      rgb_led_fader_t * const this, const char * const str);
void rgb_led_fader_printf             (const rgb_led_fader_t * const this);
void rgb_led_fader_describe           (const rgb_led_fader_t * const this);
#endif

