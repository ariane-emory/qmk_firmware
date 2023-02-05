#include QMK_KEYBOARD_H

const uint16_t PROGMEM double_space_combo [] = {KC_SPC, RGUI_T(KC_BSPC), COMBO_END};
const uint16_t PROGMEM double_tucky_combo [] = {OSL(3), OSL(4), COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
};

#include "keymap.inl"

