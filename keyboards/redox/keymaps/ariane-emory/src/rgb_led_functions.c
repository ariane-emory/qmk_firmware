// -*- c-backslash-column: 90; c-backslash-max-column: 90 -*-

#include <string.h>
#include <stdio.h>

#include "rgb_led_functions.h"

// ========================================================================================
// rgb_led_t functions
// ========================================================================================

#define FOR_EACH_COLOR(DO)                                                                \
  DO(r)                                                                                   \
  DO(g)                                                                                   \
  DO(b)

void rgb_led_t_init(rgb_led_t * const this, const uint8_t r, const uint8_t g, const uint8_t b) {
#define set_color(n) this->n = n & 0xff;

  FOR_EACH_COLOR(set_color);

#undef set_color
}

void rgb_led_t_copy(rgb_led_t * const this, const rgb_led_t * const that) {
#define copy_color(n) this->n = that->n;
  
  FOR_EACH_COLOR(copy_color);
  
#undef copy_color
}

bool rgb_led_t_equal(const rgb_led_t * const this, const rgb_led_t * const that) {
  return ((this->r == that->r) &&
          (this->g == that->g) &&
          (this->b == that->b));
}

#ifndef RGB_FADER_NO_STRINGS
bool rgb_led_t_init_from_str(rgb_led_t * const this, const char * const str) {
  if (7 != strlen(str))
    return false;
  
  unsigned int r, g, b;

  if (3 == sscanf(str, "#%02x%02x%02x", &r, &g, &b)) {
#  define set_color(n) this->n = n & 0xff;
    
  FOR_EACH_COLOR(set_color);
  
#  undef set_color
    
    return true;
  }
  
  return false;
}

void rgb_led_t_sprintf(const rgb_led_t * const this, char * const str) {
  snprintf(str, 8, "#%02X%02X%02X", this->r, this->g, this->b);
}
#endif

#undef FOR_EACH_COLOR
