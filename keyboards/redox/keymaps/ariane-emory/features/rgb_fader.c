#include "rgb_fader.h"

#include <stdio.h>
#include <stdlib.h>
#ifndef RGB_FADER_NO_STRINGS
#include <string.h>
#endif

#define COLORS                                                                  \
  C(r)                                                                          \
  C(g)                                                                          \
  C(b)

#define RGBS                                                                    \
  R(initial)                                                                    \
  R(current)                                                                    \
  R(target)

#ifndef RGB_FADER_NO_STRINGS
void rgb_fader_update_c_str(rgb_fader_t * const this);
#endif

////////////////////////////////////////////////////////////////////////////////
// Before
////////////////////////////////////////////////////////////////////////////////

void rgb_fader_finish_init(rgb_fader_t * const this) {
#  ifndef RGB_FADER_NO_STRINGS
  rgb_fader_update_c_str(this);
#  endif
  this->step = 0;
}

bool rgb_fader_before_set_target (rgb_fader_t * const this, const rgb_t * const rgb) {
  if (rgb_equal(&this->target, rgb))
    return false; // return false, no change is needed.
  return true;
}

////////////////////////////////////////////////////////////////////////////////
// Initializers
////////////////////////////////////////////////////////////////////////////////

void rgb_fader_init(rgb_fader_t * const this, uint8_t r, uint8_t g, uint8_t b) {
  rgb_t rgb;
  rgb_init(&rgb, r, g, b);
#define R(rr) rgb_copy(&this->rr, &rgb);
  RGBS;
#undef R
  rgb_fader_finish_init(this);
}

#ifndef RGB_FADER_NO_STRINGS
bool rgb_fader_init_from_str(rgb_fader_t * const this, const char * const str) {
  rgb_t tmp;
  if (! rgb_init_from_str(&tmp, str))
    return false;
  rgb_fader_init(this, tmp.r, tmp.g, tmp.b);
  return true;
}
#endif

////////////////////////////////////////////////////////////////////////////////
// String methods"
////////////////////////////////////////////////////////////////////////////////

#ifndef RGB_FADER_NO_STRINGS
void rgb_fader_update_c_str(rgb_fader_t * const this) {
  rgb_sprintf(&this->current, this->c_str);
}
#endif

////////////////////////////////////////////////////////////////////////////////
// Step
////////////////////////////////////////////////////////////////////////////////

int max(int x, int y) {
  return x > y ? x : y;
}

void rgb_fader_step(rgb_fader_t * const this) {
  if (UINT8_MAX == this->step) {
    rgb_fader_init(this, this->target.r, this->target.g, this->target.b);
  } else {
#define C(color) const int color ## _delta = (this->target. color - this->initial. color);
    COLORS;
#undef C
    
    if (! (r_delta | g_delta | b_delta))
      return;
    
    this->step++;

#define FMULS8(n, m)  (((n * m) >> 8) & 0xff)
#define C(color) this->current. color = (uint8_t)(max(0, this->initial. color + FMULS8(color ## _delta, this->step)));
    COLORS;
#undef FMULS8
#undef C

#ifndef RGB_FADER_NO_STRINGS
    rgb_fader_update_c_str(this);
#endif
  }
}

////////////////////////////////////////////////////////////////////////////////
// Stop
////////////////////////////////////////////////////////////////////////////////

void rgb_fader_stop(rgb_fader_t * const this) {
  rgb_fader_init(this, this->current.r, this->current.g, this->current.b);
}

////////////////////////////////////////////////////////////////////////////////
// Print functions
////////////////////////////////////////////////////////////////////////////////

#ifndef RGB_FADER_NO_STRINGS
void rgb_fader_printf(const rgb_fader_t * const this) {
  printf("%s\n", this->c_str);
}

void rgb_fader_describe(const rgb_fader_t * const this) {
#define R(rgb)                                                                  \
  printf("------------------------------\n");                                   \
  printf(#rgb ".r   = %3d\n", this->rgb.r);                                     \
  printf(#rgb ".g   = %3d\n", this->rgb.g);                                     \
  printf(#rgb ".b   = %3d\n", this->rgb.b);                                     \
  RGBS;
#undef R
  
  printf("------------------------------\n");
  printf("step  = %3d\n", this->step);
  printf("c_str = '%s'\n", this->c_str);
}
#endif

////////////////////////////////////////////////////////////////////////////////
// Is changing
////////////////////////////////////////////////////////////////////////////////

bool rgb_fader_is_changing(const rgb_fader_t * const this) {
  return ! rgb_equal(&this->current, &this->target);
}

////////////////////////////////////////////////////////////////////////////////
// Setters
////////////////////////////////////////////////////////////////////////////////

bool rgb_fader_set_target(rgb_fader_t * const this, uint8_t r, uint8_t g, uint8_t b) {
  rgb_t rgb;
  rgb_init(&rgb, r, g, b);
  // if rgb_fader_before_set_target returns false, no change is needed and we
  // 'success
  if (! rgb_fader_before_set_target(this, &rgb))
    return true;
  rgb_fader_stop(this);
  rgb_copy(&this->target, &rgb);
  return true;
}

#ifndef RGB_FADER_NO_STRINGS
bool rgb_fader_set_target_from_str(rgb_fader_t * const this, const char * const str) {
  rgb_t rgb;
  if (! rgb_init_from_str(&rgb, str))
    return false;
  return rgb_fader_set_target_from_rgb(this, &rgb);
}
#endif

#undef COLORS
#undef RGBS
