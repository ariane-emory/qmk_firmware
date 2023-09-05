#include <string.h>
#include <stdio.h>

#include "rgb_led_t_functions.h"

// ==============================================================================
// rgb_led_t functions
// ==============================================================================

#define COLORS                                                                  \
  C(r)                                                                          \
  C(g)                                                                          \
  C(b)

void rgb_led_t_init(rgb_led_t * const this, const uint8_t r, const uint8_t g, const uint8_t b) {
#define C(n) this->n = n;
  COLORS;
#undef C
}

void rgb_led_t_copy(rgb_led_t * const this, const rgb_led_t * const that) {
#define C(n) this->n = that->n;
  COLORS;
#undef C
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
#  define C(n) this->n = n & 0xff;
    COLORS;
#  undef C
    
    return true;
  }
  
  return false;
}

void rgb_led_t_sprintf(const rgb_led_t * const this, char * const str) {
  snprintf(str, 8, "#%02X%02X%02X", this->r, this->g, this->b);
}
#endif

#undef COLORS
