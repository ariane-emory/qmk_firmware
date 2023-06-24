#include <string.h>
#include <stdio.h>

#include "cRGB_functions.h"

// ==============================================================================
// cRGB functions
// ==============================================================================

#define COLORS                                                                  \
  C(r)                                                                          \
  C(g)                                                                          \
  C(b)

void cRGB_init(cRGB * const this, const uint8_t r, const uint8_t g, const uint8_t b) {
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
#  define C(n) this->n = n & 0xff;
    COLORS;
#  undef C
    
    return true;
  }
  
  return false;
}

void cRGB_sprintf(const cRGB * const this, char * const str) {
  snprintf(str, 8, "#%02X%02X%02X", this->r, this->g, this->b);
}
#endif

#undef COLORS

void cRGB_dim_to_1_quarter(cRGB * const this) {
  this->r = this->r >> 2;
  this->g = this->g >> 2;
  this->b = this->b >> 2;
}

void cRGB_dim_to_half(cRGB * const this) {
  this->r = this->r >> 1;
  this->g = this->g >> 1;
  this->b = this->b >> 1;
}
