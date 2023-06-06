#pragma once

#include <stdint.h>
#include <stdbool.h>
#include "rgb.h"

typedef struct rgb_fader_t {
  rgb_t   initial;
  rgb_t   current;
  rgb_t   target;
  uint8_t step;
#ifndef RGB_FADER_NO_STRINGS
  char    c_str[8];
#endif
} rgb_fader_t;

void rgb_fader_init               (rgb_fader_t * const this, uint8_t r, uint8_t g, uint8_t b);
bool rgb_fader_is_changing        (const rgb_fader_t * const this);
void rgb_fader_set_target         (rgb_fader_t * const this, uint8_t r, uint8_t g, uint8_t b);
void rgb_fader_step               (rgb_fader_t * const this);
void rgb_fader_stop               (rgb_fader_t * const this);

#define rgb_fader_set_target_from_rgb(rgb_fader_p, rgb_p)                       \
  rgb_fader_set_target(rgb_fader_p, ((rgb_p)->r), ((rgb_p)->g), ((rgb_p)->b))

#define rgb_fader_init_from_rgb(rgb_fader_p, rgb_p)                             \
  rgb_fader_init(rgb_fader_p, ((rgb_p)->r), ((rgb_p)->g), ((rgb_p)->b))

#ifndef RGB_FADER_NO_STRINGS
bool rgb_fader_init_from_str      (rgb_fader_t * const this, const char * const str);
bool rgb_fader_set_target_from_str(rgb_fader_t * const this, const char * const str);
void rgb_fader_printf             (const rgb_fader_t * const this);
void rgb_fader_describe           (const rgb_fader_t * const this);
#endif

