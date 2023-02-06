#include QMK_KEYBOARD_H

enum td_events {
  TD_SPC_LALT,
  TD_BSPC_RGUI
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_SPC_LALT]  = ACTION_TAP_DANCE_DOUBLE(KC_SPC, KC_LALT),
  [TD_BSPC_RGUI] = ACTION_TAP_DANCE_DOUBLE(KC_BSPC, KC_RGUI),
  };

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
  // COMBO(dbl_osm_combo, LM(10, MOD_LGUI | MOD_LALT)),
  // COMBO(dbl_osm_combo, OSM(MOD_LGUI | MOD_LALT)),
};

#include "keymap.inl"

