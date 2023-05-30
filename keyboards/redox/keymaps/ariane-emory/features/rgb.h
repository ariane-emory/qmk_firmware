#pragma once

#include <stdint.h>
#include <stdbool.h>

typedef struct {
  uint8_t r;
  uint8_t g;
  uint8_t b;
} rgb_t;

void rgb_init         (rgb_t * const this, uint8_t r, uint8_t g, uint8_t b);
void rgb_copy         (rgb_t * const this, const rgb_t * const that);
bool rgb_equal        (const rgb_t * const this, const rgb_t * const that);

#ifndef RGB_FADER_NO_STRINGS
bool rgb_init_from_str(rgb_t * const this, const char * const str);
void rgb_sprintf      (const rgb_t * const this, char * const str);
#endif

