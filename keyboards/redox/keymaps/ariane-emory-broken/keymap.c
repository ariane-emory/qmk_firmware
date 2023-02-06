#include QMK_KEYBOARD_H

enum combo_events {
  DBL_SPC,
  DBL_OSL,
  COMBO_LENGTH
};

uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM double_space_combo [] = {KC_SPC, RGUI_T(KC_BSPC), COMBO_END};
const uint16_t PROGMEM double_osl_combo   [] = {OSL(3), OSL(4), COMBO_END};

combo_t key_combos[] = {
  [DBL_SPC] = COMBO(double_space_combo, LCTL(KC_SPC)),
  [DBL_OSL] = COMBO(double_osl_combo, LM(10, MOD_LGUI | MOD_LALT)),
  };

#include "keymap.inl"

