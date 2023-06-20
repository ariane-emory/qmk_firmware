#pragma once

#include <stdbool.h>
#include <stdint.h>

// ==============================================================================
// Utility functions
// ==============================================================================

typedef struct {
  uint16_t first;
  uint16_t second;
} keycode_pair_t;

bool array_contains_keycode(const uint16_t arr[], const uint8_t length, const uint16_t keycode);
bool array_contains_keycode_P(const uint16_t arr[], const uint8_t length, const uint16_t keycode);
bool array_contains_keycode_pair(const keycode_pair_t arr[], const uint8_t length, const keycode_pair_t pair);
bool array_contains_keycode_pair_P(const keycode_pair_t arr[], const uint8_t length, const keycode_pair_t pair);
