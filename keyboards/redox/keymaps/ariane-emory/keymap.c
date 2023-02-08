#include QMK_KEYBOARD_H

/* const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, RGUI_T(KC_BSPC), KC_DEL); */

/* const key_override_t delete_key_override_2 = { */
/*   .trigger                = RGUI_T(KC_BSPC), */
/*   .trigger_mods           = MOD_MASK_SHIFT, */
/*   .layers                 = (1 << 0), */
/*   .suppressed_mods        = MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT), */
/*   .options                = ko_option_no_reregister_trigger, */
/*   .negative_mod_mask      = 0, */
/*   .custom_action          = NULL, */
/*   .context                = NULL, */
/*   .replacement            = KC_DEL, */
/*   .enabled                = NULL}; */

/* // This globally defines all key overrides to be used */
/* const key_override_t **key_overrides = (const key_override_t *[]){ */
/*   &delete_key_override_2, */
/*   NULL // Null terminate the array of overrides! */
/* }; */

enum td_events {
  TD_SPC_LALT,
  TD_OSL3_LGUI,
};
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_SPC_LALT]  = ACTION_TAP_DANCE_DOUBLE(KC_SPC, KC_LALT),
  [TD_OSL3_LGUI] = ACTION_TAP_DANCE_DOUBLE(OSL(3), KC_LGUI),
  };

enum combo_events {
  DBL_SPC,
  DBL_LT5_LT9,
  // DBL_OSL3_OSL4,
  COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH; // remove the COMBO_COUNT define and use this instead!

const uint16_t PROGMEM dbl_spc_combo[] = {LALT_T(KC_SPC), RGUI_T(KC_BSPC), COMBO_END};
const uint16_t PROGMEM dbl_lt5_lt9_combo[] = {LT(5, KC_ENT), LT(9, KC_ENT), COMBO_END};
// const uint16_t PROGMEM dbl_osl3_osl4_combo[] = {OSL(3), OSL(4), COMBO_END};

combo_t key_combos[] = {
  [DBL_SPC]       = COMBO(dbl_spc_combo, RCTL(KC_SPC)),
  [DBL_LT5_LT9]   = COMBO(dbl_lt5_lt9_combo, KC_LCTL),
  // [DBL_OSL3_OSL4] = COMBO(dbl_osl3_osl4_combo, KC_LCTL),
};

#include "keymap.inl"

