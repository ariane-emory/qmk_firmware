#include QMK_KEYBOARD_H

const uint16_t PROGMEM dbl_spc_combo[] = {KC_SPC, RGUI_T(KC_BSPC), COMBO_END};
const uint16_t PROGMEM dbl_osl_combo[] = {OSL(3), OSL(4), COMBO_END};

#include "keymap.inl"

