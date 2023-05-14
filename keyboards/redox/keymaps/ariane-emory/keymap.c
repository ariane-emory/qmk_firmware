#include QMK_KEYBOARD_H

#include "features/achordion.h"

// #define AE_PIN1 and AE_PIN2 in this file:
#include "secrets.h"

// ==============================================================================
// Swap hands config
// ==============================================================================

#ifdef SWAP_HANDS_ENABLE
const keypos_t PROGMEM hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
  {{13, 0}, {12, 0}, {11, 0}, {10, 0}, {9, 0}, {8, 0}, {7, 0}, {6, 0}, {5, 0}, {4, 0}, {3, 0}, {2, 0}, {1, 0}, {0, 0}},
  {{13, 1}, {12, 1}, {11, 1}, {10, 1}, {9, 1}, {8, 1}, {7, 1}, {6, 1}, {5, 1}, {4, 1}, {3, 1}, {2, 1}, {1, 1}, {0, 1}},
  {{13, 2}, {12, 2}, {11, 2}, {10, 2}, {9, 2}, {8, 2}, {7, 2}, {6, 2}, {5, 2}, {4, 2}, {3, 2}, {2, 2}, {1, 2}, {0, 2}},
  {{13, 3}, {12, 3}, {11, 3}, {10, 3}, {9, 3}, {8, 3}, {7, 3}, {6, 3}, {5, 3}, {4, 3}, {3, 3}, {2, 3}, {1, 3}, {0, 3}},
  {{13, 4}, {12, 4}, {11, 4}, {10, 4}, {9, 4}, {8, 4}, {7, 4}, {6, 4}, {5, 4}, {4, 4}, {3, 4}, {2, 4}, {1, 4}, {0, 4}},
};
#endif

// ==============================================================================
// Init
// ==============================================================================

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  /* debug_enable=true; */
  /* debug_matrix=true; */
  /* debug_keyboard=true; */
  /* debug_mouse=true; */
  // rgblight_enable();
}

// ==============================================================================
// Define local macros
// ==============================================================================

#ifdef RGBLIGHT_ENABLE
#define RGBLIGHT_SETHSV(hsv) rgblight_sethsv_noeeprom(hsv)
#else
#define RGBLIGHT_SETHSV(hsv) (((void)0))
#endif

#define KEYRECORD_FUN(name, t)                                                  \
  t name(uint16_t keycode, keyrecord_t *record)

#define MANAGE_TOGGLED_LAYER_TIMEOUT(layer, idle_time_limit_ms, timer)          \
  {                                                                             \
    if (layer_state_is(layer) &&                                                \
        timer_elapsed(timer) >= idle_time_limit_ms)                             \
      layer_off(layer);                                                         \
  }                                                                             

#ifdef SEND_STRING_ENABLE
#define SEND_STRING_WITHOUT_MODS(str)                                           \
  {                                                                             \
    const uint8_t current_mods = get_mods();                                    \
    clear_mods();                                                               \
    SEND_STRING(str);                                                           \
    set_mods(current_mods);                                                     \
  }                                                                         
#else
#define SEND_STRING_WITHOUT_MODS(str) (((void)0))                                
#endif

#define KC_CASE(kc, blk)                                                        \
  case kc:                                                                      \
  if (record->event.pressed)                                                    \
  {                                                                             \
    blk;                                                                        \
  }                                                                             \
  return false;                                                                 

// ==============================================================================
// Custom keycodes
// ==============================================================================

enum arianes_keycodes {
  SS_PIN1 = SAFE_RANGE,
  SS_PIN2,
  SS_GRAV,
  SS_LPAR,
  SS_RPAR,
  SS_RPAR_SCLN,
  SS_TILD,
  SS_TILD_SLASH,
  SS_UPDIR,
  SS_LASTARG,
  SS_REPEAT,
  INSERT_UPP,
};

static uint16_t idle_timer = 0;
static bool     asleep     = false;
#ifdef IGNORE_WAKING_KEY
static uint16_t waking_key = KC_NO;
#endif

KEYRECORD_FUN(process_record_user, bool) {
  idle_timer = timer_read();

#ifdef IGNORE_WAKING_KEY
  if (asleep) {
    if (record->event.pressed && waking_key == KC_NO) {
      waking_key = keycode;
    }
    else if (keycode == waking_key) {
      asleep = false;
      waking_key = KC_NO;
    }
    return false;
  }
#else
  if (asleep)
    asleep = false;
#endif
  
  if (!process_achordion(keycode, record))
    return false;
  
  switch (keycode) {
    KC_CASE(SS_PIN1,       SEND_STRING_WITHOUT_MODS(AE_PIN1));
    KC_CASE(SS_PIN2,       SEND_STRING_WITHOUT_MODS(AE_PIN2));
    KC_CASE(SS_GRAV,       SEND_STRING_WITHOUT_MODS("`"));
    KC_CASE(SS_LPAR,       SEND_STRING_WITHOUT_MODS("9"));
    KC_CASE(SS_RPAR,       SEND_STRING_WITHOUT_MODS("0"));
    KC_CASE(SS_RPAR_SCLN,  SEND_STRING_WITHOUT_MODS("0;"));
    KC_CASE(SS_TILD,       SEND_STRING_WITHOUT_MODS("~"));
    KC_CASE(SS_TILD_SLASH, SEND_STRING_WITHOUT_MODS(" ~/"));
    KC_CASE(SS_UPDIR,      SEND_STRING_WITHOUT_MODS("../"));
    KC_CASE(SS_LASTARG,    SEND_STRING_WITHOUT_MODS(" "SS_LCTL("c")SS_DELAY(50)"."));
    KC_CASE(SS_REPEAT,     SEND_STRING_WITHOUT_MODS(SS_LCTL("x")SS_DELAY(50)"z"));
  case RSFT_T(KC_DQUO):
    if (record->tap.count && record->event.pressed) {
      tap_code16(KC_DQUO); // Send KC_DQUO on tap
      return false;        // Return false to ignore further processing of key
    }
    break;
  case INSERT_UPP:
#ifdef INSERT_UPP_ENABLED
    if (record->event.pressed) {
      for (uint8_t ix = 0; ix < 6; ix++) {
        static const uint16_t hex_keycodes[] = {
          KC_2, KC_3, KC_4, KC_5, KC_6, KC_7,
          KC_8, KC_9, KC_A, KC_B, KC_C, 
        };
        const uint8_t roll = ((rand() % 6) + 1) + ((rand() % 6) + 1);
        const uint16_t hex_kc = LSFT(hex_keycodes[roll - 2]);
        tap_code16(hex_kc);
      }
      tap_code(KC_ENTER);
    }
#endif
    return false;
  }

  return true;
}

void matrix_scan_user(void) {
  achordion_task();

  MANAGE_TOGGLED_LAYER_TIMEOUT(TOGGLED_LAYER, TOGGLED_LAYER_TIMEOUT, idle_timer);

  if (asleep || timer_elapsed(idle_timer) >= RGB_TIMEOUT)
  {
    asleep = true;
    RGBLIGHT_SETHSV(HSV_ASLEEP);
  }
  else if (IS_LAYER_ON(TRI_LAYER_ADJUST_LAYER)) {
    RGBLIGHT_SETHSV(HSV_ADJUST_LAYER_ON);
  }
  else if (IS_LAYER_ON(TRI_LAYER_UPPER_LAYER)) {
    RGBLIGHT_SETHSV(HSV_UPPER_LAYER_ON);
  }
  else if (IS_LAYER_ON(TRI_LAYER_LOWER_LAYER)) {
    RGBLIGHT_SETHSV(HSV_LOWER_LAYER_ON);
  }
  else if (IS_LAYER_ON(TOGGLED_LAYER)) {
    RGBLIGHT_SETHSV(HSV_TOGGLED_LAYER_ON);
  }
  else {
    RGBLIGHT_SETHSV(HSV_TOGGLED_LAYER_OFF);
  }
}

// ==============================================================================
// Achordion
// ==============================================================================

bool achordion_chord(
  uint16_t tap_hold_keycode,
  keyrecord_t* tap_hold_record,
  uint16_t other_keycode,
  keyrecord_t* other_record) {
  if (
    (IS_LAYER_ON(0) && (
      tap_hold_keycode == LCTL_T(KC_F)    ||
      tap_hold_keycode == LALT_T(KC_D)    ||
      tap_hold_keycode == LGUI_T(KC_S)    ||
      tap_hold_keycode == LSFT_T(KC_A)    ||
      tap_hold_keycode == RCTL_T(KC_J)    ||
      tap_hold_keycode == RALT_T(KC_K)    ||
      tap_hold_keycode == RGUI_T(KC_L)    ||
      tap_hold_keycode == RSFT_T(KC_QUOT))) ||
    (IS_LAYER_ON(1) && (
      tap_hold_keycode == LCTL_T(KC_T)    ||
      tap_hold_keycode == LALT_T(KC_S)    ||
      tap_hold_keycode == LGUI_T(KC_R)    ||
      tap_hold_keycode == LSFT_T(KC_A)    ||
      tap_hold_keycode == RCTL_T(KC_N)    ||
      tap_hold_keycode == RALT_T(KC_E)    ||
      tap_hold_keycode == RGUI_T(KC_I)    ||
      tap_hold_keycode == RSFT_T(KC_QUOT)))
      )
  {
    // Also allow same-hand holds when the other key is in the rows below the
    // alphas. I need the `% (MATRIX_ROWS / 2)` because my keyboard is split.
    if (other_record->event.key.row % (MATRIX_ROWS / 2) >= 4)
      return true;

    // Require bilateral
    return achordion_opposite_hands(tap_hold_record, other_record);
  }

  // Process normally
  return true;
}

// ==============================================================================
// Include combos 
// ==============================================================================

#include "combos.inl"

// ==============================================================================
// Mod tap interrupt
// ==============================================================================

KEYRECORD_FUN(get_hold_on_other_key_press, bool) {
  switch (keycode) {
  case QK_MOD_TAP ... QK_MOD_TAP_MAX:
    if (keycode == LCTL_T(KC_ESC)  ||
        keycode == RCTL_T(KC_SCLN) ||
        keycode == LSFT_T(KC_MINS) ||
        keycode == RSFT_T(KC_MINS)) {
      return true;
    }
    else {
      return false;
    }
  default:
    return false;
  }
}

KEYRECORD_FUN(get_permissive_hold, bool) {
  switch (keycode) {
  case MT(MOD_LALT,KC_SPC):
  case LCTL_T(KC_F):
  case LALT_T(KC_D):
  case LGUI_T(KC_S):
  case LSFT_T(KC_A):
  case RCTL_T(KC_J):
  case RALT_T(KC_K):
  case RGUI_T(KC_L):
  case RSFT_T(KC_QUOT):
    // Do not select the hold action when another key is tapped.
    return false;
  default:
    // Immediately select the hold action when another key is tapped.
    return true;
  }
}

// ==============================================================================
// Autoshift
// ==============================================================================

#ifdef AUTO_SHIFT_ENABLE
KEYRECORD_FUN(get_autoshift_timeout, uint16_t) {
  switch(keycode) {
  case AUTO_SHIFT_ALPHA:
    return get_generic_autoshift_timeout() + 60;
  case AUTO_SHIFT_SPECIAL:
    return get_generic_autoshift_timeout() + 30;
  case AUTO_SHIFT_NUMERIC:
  default:
    return get_generic_autoshift_timeout();
  }
}
#endif

// ==============================================================================
// Tapping term
// ==============================================================================

KEYRECORD_FUN(get_tapping_term, uint16_t) {
  switch (keycode) {
  case MT(MOD_LALT,KC_SPC):
    return TAPPING_TERM + 60;
  default:
    return TAPPING_TERM;
  }
}

// ==============================================================================
// Undefine local macros
// ==============================================================================

#undef KC_CASE
#undef KEYRECORD_FUN
#undef MANAGE_TOGGLED_LAYER_TIMEOUT
#undef RGBLIGHT_SETHSV
#undef SEND_STRING_WITHOUT_MODS
  
// ==============================================================================
// Include keymap
// ==============================================================================

#include "keymap.inl"
