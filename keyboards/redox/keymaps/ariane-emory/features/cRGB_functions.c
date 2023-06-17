#include <string.h>
#include <stdio.h>
#include "cRGB_functions.h"

#define COLORS                                                                  \
  C(r)                                                                          \
  C(g)                                                                          \
  C(b)

void cRGB_init(cRGB * const this, uint8_t r, uint8_t g, uint8_t b) {
#define C(n) this->n = n;
  COLORS;
#undef C
}

void cRGB_copy(cRGB * const this, const cRGB * const that) {
#define C(n) this->n = that->n;
  COLORS;
#undef C
}

bool cRGB_equal(const cRGB * const this, const cRGB * const that) {
  return ((this->r == that->r) &&
          (this->g == that->g) &&
          (this->b == that->b));
}

#ifndef RGB_FADER_NO_STRINGS
bool cRGB_init_from_str(cRGB * const this, const char * const str) {
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

void cRGB_sprintf(const cRGB * const this, char * const str) {
  snprintf(str, 8, "#%02X%02X%02X", this->r, this->g, this->b);
}
#endif

#undef COLORS
