#include "rgb_fader.h"

#include <string.h>
#include <stdio.h>

#define COLORS                                                                  \
  C(r)                                                                          \
  C(g)                                                                          \
  C(b)

void rgb_init(rgb_t * const this, uint8_t r, uint8_t g, uint8_t b) {
#define C(n) this->n = n;
  COLORS;
#undef C
}

void rgb_copy(rgb_t * const this, const rgb_t * const that) {
#define C(n) this->n = that->n;
  COLORS;
#undef C
}

bool rgb_equal(const rgb_t * const this, const rgb_t * const that) {
  return ((this->r == that->r) &&
          (this->g == that->g) &&
          (this->b == that->b));
}

#ifndef RGB_FADER_NO_STRINGS
bool rgb_init_from_str(rgb_t * const this, const char * const str) {
  if (7 != strlen(str))
    return false;
  
  unsigned int r, g, b;

  if (3 == sscanf(str, "#%02x%02x%02x", &r, &g, &b)) {
#define C(n) this->n = n & 0xff;
    COLORS;
#undef C
    
    return true;
  }
  
  return false;
}

void rgb_sprintf(const rgb_t * const this, char * const str) {
  snprintf(str, 8, "#%02X%02X%02X", this->r, this->g, this->b);
}
#endif

#undef COLORS
