#pragma once

#include <stdint.h>
#include <stdbool.h>

#include "color.h"

// ==============================================================================
// cRGB functions
// ==============================================================================

void cRGB_init            (      cRGB * const this, const uint8_t r, const uint8_t g, const uint8_t b);
void cRGB_copy            (      cRGB * const this, const cRGB * const that);
bool cRGB_equal           (const cRGB * const this, const cRGB * const that);
void cRGB_dim_to_1_quarter(      cRGB * const this                         );
void cRGB_dim_to_half     (      cRGB * const this                         );

#ifndef RGB_FADER_NO_STRINGS
bool cRGB_init_from_str   (cRGB * const this, const char * const str);
void cRGB_sprintf         (const cRGB * const this, char * const str);
#endif

