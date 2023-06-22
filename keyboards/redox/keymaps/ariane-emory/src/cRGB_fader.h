#pragma once

#include <stdint.h>
#include <stdbool.h>
#include "cRGB_functions.h"
#include "color.h"

// ==============================================================================
// RGB fader class
// ==============================================================================

typedef struct cRGB_fader_t {
  cRGB   initial;
  cRGB   current;
  cRGB   target;
  uint8_t step;

#ifndef CRGB_FADER_NO_STRINGS
  char    c_str[8];
#endif
} cRGB_fader_t;

void cRGB_fader_init               (      cRGB_fader_t * const this, const uint8_t r, const uint8_t g, const uint8_t b);
void cRGB_fader_set_target         (      cRGB_fader_t * const this, const uint8_t r, const uint8_t g, const uint8_t b);
bool cRGB_fader_is_changing        (const cRGB_fader_t * const this);
void cRGB_fader_step               (      cRGB_fader_t * const this);
void cRGB_fader_stop               (      cRGB_fader_t * const this);

#define cRGB_fader_set_target_from_rgb(cRGB_fader_p, rgb_p)                                                                                   \
  cRGB_fader_set_target(cRGB_fader_p, ((rgb_p)->r), ((rgb_p)->g), ((rgb_p)->b))

#define cRGB_fader_init_from_rgb(cRGB_fader_p, rgb_p)                             \
  cRGB_fader_init(cRGB_fader_p, ((rgb_p)->r), ((rgb_p)->g), ((rgb_p)->b))

#ifndef CRGB_FADER_NO_STRINGS
bool cRGB_fader_init_from_str      (      cRGB_fader_t * const this, const char * const str);
bool cRGB_fader_set_target_from_str(      cRGB_fader_t * const this, const char * const str);
void cRGB_fader_printf             (const cRGB_fader_t * const this);
void cRGB_fader_describe           (const cRGB_fader_t * const this);
#endif

