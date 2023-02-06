#include QMK_KEYBOARD_H

enum combo_events {
  EM_EMAIL,
  BSPC_LSFT_CLEAR,
  COMBO_LENGTH
};

uint16_t COMBO_LEN = COMBO_LENGTH; // remove the COMBO_COUNT define and use this instead!

const uint16_t PROGMEM email_combo[] = {KC_E, KC_M, COMBO_END};
const uint16_t PROGMEM clear_line_combo[] = {KC_BSPC, KC_LSFT, COMBO_END};

combo_t key_combos[] = {
  [EM_EMAIL] = COMBO_ACTION(email_combo),
  [BSPC_LSFT_CLEAR] = COMBO_ACTION(clear_line_combo),
  };
/* COMBO_ACTION(x) is same as COMBO(x, KC_NO) */

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
  case EM_EMAIL:
    if (pressed) {
      SEND_STRING("john.doe@example.com");
    }
    break;
  case BSPC_LSFT_CLEAR:
    if (pressed) {
      tap_code16(KC_END);
      tap_code16(S(KC_HOME));
      tap_code16(KC_BSPC);
    }
    break;
  }
}

#include "keymap.inl"

