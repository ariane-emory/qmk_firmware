#include "rgb_led_fader.h"

#include <stdio.h>
#include <stdlib.h>

#ifndef CRGB_FADER_NO_STRINGS
#  include <string.h>
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

#ifndef CRGB_FADER_NO_STRINGS
void rgb_led_fader_update_c_str(rgb_led_fader_t * const this);
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
// Before
////////////////////////////////////////////////////////////////////////////////////////////////////

void rgb_led_fader_finish_init(rgb_led_fader_t * const this) {
#  ifndef CRGB_FADER_NO_STRINGS
  rgb_led_fader_update_c_str(this);
#  endif
  this->step = 0;
}

bool rgb_led_fader_before_set_target (rgb_led_fader_t * const this, const rgb_led_t * const rgb) {
  return ! equal_rgb_led_t(&this->target, rgb);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// Initializers
////////////////////////////////////////////////////////////////////////////////////////////////////

void init_rgb_led_fader(rgb_led_fader_t * const this, const uint8_t r, const uint8_t g, const uint8_t b) {
  rgb_led_t rgb;

  init_rgb_led_t(&rgb, r, g, b);

#define copy_rgb(r) copy_rgb_led_t(&this->r, &rgb);
  FOR_EACH_RGB(copy_rgb);
#undef copy_rgb

  rgb_led_fader_finish_init(this);
}

#ifndef CRGB_FADER_NO_STRINGS
bool init_rgb_led_fader_from_str(rgb_led_fader_t * const this, const char * const str) {
  rgb_led_t tmp;

  if (! init_rgb_led_t_from_str(&tmp, str))
    return false;

  init_rgb_led_fader(this, tmp.r, tmp.g, tmp.b);

  return true;
}
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
// String methods"
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef CRGB_FADER_NO_STRINGS
void rgb_led_fader_update_c_str(rgb_led_fader_t * const this) {
  sprintf_rgb_led_t(&this->current, this->c_str);
}
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
// Step
////////////////////////////////////////////////////////////////////////////////////////////////////

int max(int x, int y) {
  return x > y ? x : y;
}

void step_rgb_led_fader(rgb_led_fader_t * const this) {
  if (UINT8_MAX == this->step) {
    init_rgb_led_fader(this, this->target.r, this->target.g, this->target.b);
  }
  else {
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

#ifndef CRGB_FADER_NO_STRINGS
    rgb_led_fader_update_c_str(this);
#endif
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// Stop
////////////////////////////////////////////////////////////////////////////////////////////////////

void stop_rgb_led_fader(rgb_led_fader_t * const this) {
  init_rgb_led_fader(this, this->current.r, this->current.g, this->current.b);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// Print functions
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef CRGB_FADER_NO_STRINGS
void printf_rgb_led_fader(const rgb_led_fader_t * const this) {
  printf("%s\n", this->c_str);
}

void describe_rgb_led_fader(const rgb_led_fader_t * const this) {
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

////////////////////////////////////////////////////////////////////////////////////////////////////
// Is changing
////////////////////////////////////////////////////////////////////////////////////////////////////

bool rgb_led_fader_is_changing(const rgb_led_fader_t * const this) {
  return ! equal_rgb_led_t(&this->current, &this->target);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// Setters
////////////////////////////////////////////////////////////////////////////////////////////////////

void set_rgb_led_fader_target(rgb_led_fader_t * const this, const uint8_t r, const uint8_t g, const uint8_t b) {
  rgb_led_t rgb;

  init_rgb_led_t(&rgb, r, g, b);

  // if rgb_led_fader_before_set_target returns false, no change is needed and we
  // return success

  if (! rgb_led_fader_before_set_target(this, &rgb))
    return;

  stop_rgb_led_fader(this);
  copy_rgb_led_t(&this->target, &rgb);
}

#ifndef CRGB_FADER_NO_STRINGS
bool set_rgb_led_fader_target_from_str(rgb_led_fader_t * const this, const char * const str) {
  rgb_led_t rgb;

  return ! rgb_init_from_str(&rgb, str)
    ? false
    : set_rgb_led_fader_target_from_rgb(this, &rgb);
}
#endif

#undef FOR_EACH_COLOR
#undef FOR_EACH_RGB
