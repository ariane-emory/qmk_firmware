#include "tap_number.h"

void tap_number(uint16_t num) {
  static const uint8_t max_digits   = 3;
  /*  */ const uint8_t current_mods = get_mods();

  clear_mods();
  send_keyboard_report();

  uint16_t buf[max_digits];
  uint8_t  ix = max_digits - 1;

  while (num) {
    const uint8_t modulo = num % 10;    

    num -= modulo;
    num /= 10;
    buf[ix] = (modulo == KC_0)
      ? KC_0
      : KC_1 + modulo - 1;

    if (num)
      ix--;
  }
  
  for (; ix < max_digits; ix++)
    tap_code16(LSFT(buf[ix]));
  
  set_mods(current_mods);
}

