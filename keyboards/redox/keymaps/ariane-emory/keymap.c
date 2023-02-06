#include QMK_KEYBOARD_H

enum combo_events {
  DBL_SPC,
  DBL_OSM,
  COMBO_LENGTH
};

uint16_t COMBO_LEN = COMBO_LENGTH; // remove the COMBO_COUNT define and use this instead!

const uint16_t PROGMEM dbl_spc_combo[] = {KC_SPC, RGUI_T(KC_BSPC), COMBO_END};
const uint16_t PROGMEM dbl_osm_combo[] = {OSM(3), OSM(4), COMBO_END};

combo_t key_combos[] = {
  [DBL_SPC] = COMBO(dbl_spc_combo, RCTL(KC_SPC)),
  [DBL_OSM] = COMBO(dbl_osm_combo, RCTL(KC_SPC)),
  };

#include "keymap.inl"

