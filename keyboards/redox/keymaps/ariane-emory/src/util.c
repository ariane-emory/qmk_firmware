#include "util.h"

// ==============================================================================
// Utility functions
// ==============================================================================

bool array_contains_keycode(const uint16_t arr[], const uint8_t length, const uint16_t keycode) {
  for (uint8_t ix = 0; ix < length; ix++)
    if (arr[ix] == keycode)
      return true;
  return false;
}

bool array_contains_keycode_P(const uint16_t arr[], const uint8_t length, const uint16_t keycode) {
  for (uint8_t ix = 0; ix < length; ix++)
    if (pgm_read_word(&arr[ix]) == keycode)
      return true;
  return false;
}

bool array_contains_keycode_pair(const keycode_pair_t arr[], const uint8_t length, const keycode_pair_t pair) {
  for (uint8_t ix = 0; ix < length; ix++)
    if (arr[ix].first  == pair.first &&
        arr[ix].second == pair.second)
      return true;
  return false;
}

bool array_contains_keycode_pair_P(const keycode_pair_t arr[], const uint8_t length, const keycode_pair_t pair) {
  for (uint8_t ix = 0; ix < length; ix++)
    if (pgm_read_word(&arr[ix].first)  == pair.first &&
        pgm_read_word(&arr[ix].second) == pair.second)
      return true;
  return false;
}

