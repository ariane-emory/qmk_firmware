#include "rgb_fader.h"

#include <stdio.h>
#include <stdlib.h>

#ifndef RGB_FADER_NO_STRINGS
#include <string.h>
#endif

// ==============================================================================
// RGB fader class
// ==============================================================================

#define FOR_EACH_COLOR(DO)                                                      \
  DO(r)                                                                         \
  DO(g)                                                                         \
  DO(b)

#define FOR_EACH_RGB(DO)                                                        \
  DO(initial)                                                                   \
  DO(current)                                                                   \
  DO(target)

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

bool rgb_fader_before_set_target (rgb_fader_t * const this, const cRGB * const rgb) {
  return ! cRGB_equal(&this->target, rgb);
}

////////////////////////////////////////////////////////////////////////////////
// Initializers
////////////////////////////////////////////////////////////////////////////////

void rgb_fader_init(rgb_fader_t * const this, const uint8_t r, const uint8_t g, const uint8_t b) {
  cRGB rgb;
  cRGB_init(&rgb, r, g, b);
#define copy_rgb(r) cRGB_copy(&this->r, &rgb);
  FOR_EACH_RGB(copy_rgb);
#undef copy_rgb
  rgb_fader_finish_init(this);
}

#ifndef RGB_FADER_NO_STRINGS
bool rgb_fader_init_from_str(rgb_fader_t * const this, const char * const str) {
  cRGB tmp;
  if (! cRGB_init_from_str(&tmp, str))
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
  cRGB_sprintf(&this->current, this->c_str);
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
#define define_color_delta(color) const int color ## _delta = (this->target. color - this->initial. color);
    FOR_EACH_COLOR(define_color_delta);
#undef define_color_delta
    
    if (! (r_delta | g_delta | b_delta))
      return;
    
    this->step++;

#define fmuls8(n, m)  (((n * m) >> 8) & 0xff)
#define set_current_color(color) this->current. color = (uint8_t)(max(0, this->initial. color + fmuls8(color ## _delta, this->step)));
    FOR_EACH_COLOR(set_current_color);
#undef fmuls8
#undef set_current_color

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
#define print_rgb_info(rgb)                                                     \
  printf("------------------------------\n");                                   \
  printf(#rgb ".r   = %3d\n", this->rgb.r);                                     \
  printf(#rgb ".g   = %3d\n", this->rgb.g);                                     \
  printf(#rgb ".b   = %3d\n", this->rgb.b);                                     \
  FOR_EACH_RGB(print_rgb_info);
#undef print_rgb_info
  
  printf("------------------------------\n");
  printf("step  = %3d\n", this->step);
  printf("c_str = '%s'\n", this->c_str);
}
#endif

////////////////////////////////////////////////////////////////////////////////
// Is changing
////////////////////////////////////////////////////////////////////////////////

bool rgb_fader_is_changing(const rgb_fader_t * const this) {
  return ! cRGB_equal(&this->current, &this->target);
}

////////////////////////////////////////////////////////////////////////////////
// Setters
////////////////////////////////////////////////////////////////////////////////

void rgb_fader_set_target(rgb_fader_t * const this, const uint8_t r, const uint8_t g, const uint8_t b) {
  cRGB rgb;
  cRGB_init(&rgb, r, g, b);
  // if rgb_fader_before_set_target returns false, no change is needed and we
  // return success
  if (! rgb_fader_before_set_target(this, &rgb))
    return;
  rgb_fader_stop(this);
  cRGB_copy(&this->target, &rgb);
}

#ifndef RGB_FADER_NO_STRINGS
bool rgb_fader_set_target_from_str(rgb_fader_t * const this, const char * const str) {
  cRGB rgb;
  return ! rgb_init_from_str(&rgb, str)
    ? false
    : rgb_fader_set_target_from_rgb(this, &rgb);
}
#endif

#undef FOR_EACH_COLOR
#undef FOR_EACH_RGB
