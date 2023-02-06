#include QMK_KEYBOARD_H

const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, RGUI_T(KC_BSPC), KC_DEL);

const key_override_t delete_key_override_2 = {
  .trigger                = RGUI_T(KC_BSPC),
  .trigger_mods           = MOD_MASK_SHIFT,
  .layers                 = (1 << 0),
  .suppressed_mods        = MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT),
  .options                = ko_option_no_reregister_trigger,
  .negative_mod_mask      = 0,
  .custom_action          = NULL,
  .context                = NULL,
  .replacement            = KC_DEL,
  .enabled                = NULL};

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
  &delete_key_override_2,
  NULL // Null terminate the array of overrides!
};

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

const uint16_t PROGMEM dbl_spc_combo[] = {TD(0), RGUI_T(KC_BSPC), COMBO_END};
const uint16_t PROGMEM dbl_osm_combo[] = {OSM(3), OSM(4), COMBO_END};

combo_t key_combos[] = {
  [DBL_SPC] = COMBO(dbl_spc_combo, RCTL(KC_SPC)),
  [DBL_OSM] = COMBO(dbl_osm_combo, RCTL(KC_SPC)),
  // COMBO(dbl_osm_combo, LM(10, MOD_LGUI | MOD_LALT)),
  // COMBO(dbl_osm_combo, OSM(MOD_LGUI | MOD_LALT)),
};

#include "keymap.inl"

