#pragma once

#include <stdint.h>
#include <stdbool.h>
#include "color.h"

void rgb_init         (cRGB * const this, uint8_t r, uint8_t g, uint8_t b);
void rgb_copy         (cRGB * const this, const cRGB * const that);
bool rgb_equal        (const cRGB * const this, const cRGB * const that);

#ifndef RGB_FADER_NO_STRINGS
bool rgb_init_from_str(cRGB * const this, const char * const str);
void rgb_sprintf      (const cRGB * const this, char * const str);
#endif

