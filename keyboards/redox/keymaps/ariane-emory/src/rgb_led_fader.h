// -*- c-backslash-column: 100; c-backslash-max-column: 100 ; fill-column: 100; eval: (display-fill-column-indicator-mode 1); -*-
#pragma once

#include <stdint.h>
#include <stdbool.h>
#include "rgb_led_functions.h"
#include "color.h"

// =================================================================================================
// RGB fader class
// ======================+++++++++++++==============================================================

typedef struct rgb_led_fader_t {
  rgb_led_t   initial;
  rgb_led_t   current;
  rgb_led_t   target;
  uint8_t     step;

#ifndef CRGB_FADER_NO_STRINGS
  char        c_str[8];
#endif
} rgb_led_fader_t;

void init_rgb_led_fader               (rgb_led_fader_t * const this,
                                       const uint8_t r,
                                       const uint8_t g,
                                       const uint8_t b);
void set_rgb_led_fader_target         (rgb_led_fader_t * const this,
                                       const uint8_t r,
                                       const uint8_t g,
                                       const uint8_t b);
bool rgb_led_fader_is_changing        (const rgb_led_fader_t * const this);
void step_rgb_led_fader               (      rgb_led_fader_t * const this);
void stop_rgb_led_fader               (      rgb_led_fader_t * const this);

#define set_rgb_led_fader_target_from_rgb(rgb_led_fader_p, rgb_p)                                   \
  set_rgb_led_fader_target(rgb_led_fader_p, ((rgb_p)->r), ((rgb_p)->g), ((rgb_p)->b))

#define init_rgb_led_fader_from_rgb(rgb_led_fader_p, rgb_p)                                         \
  init_rgb_led_fader(rgb_led_fader_p, ((rgb_p)->r), ((rgb_p)->g), ((rgb_p)->b))

#ifndef CRGB_FADER_NO_STRINGS
bool init_rgb_led_fader_from_str      (      rgb_led_fader_t * const this, const char * const str);
bool set_rgb_led_fader_target_from_str(      rgb_led_fader_t * const this, const char * const str);
void printf_rgb_led_fader             (const rgb_led_fader_t * const this);
void describe_rgb_led_fader           (const rgb_led_fader_t * const this);
#endif

