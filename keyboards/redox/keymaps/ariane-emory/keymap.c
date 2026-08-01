// -*- c-backslash-column: 100; c-backslash-max-column: 100 ; fill-column: 100; eval: (display-fill-column-indicator-mode 1); eval: (aggressive-indent-mode -1); -*-

#include QMK_KEYBOARD_H 
#include <quantum/mousekey.h>
#include <stdbool.h>

#include "src/key-aliases.h"
#include "src/layouts.h"
#include "src/secrets.h" // #define AE_PIN1 and AE_PIN2 in this file.

#ifdef USE_ACHORDION
#  include "src/achordion.h"
#endif

#ifdef RGBLIGHT_ENABLE
#  include "src/rgb_led_fader.h"
rgb_led_fader_t rgb_led_fader;
#endif

#if CONSOLE_ENABLE
#  include "print.h"
#endif

#include "src/util.h"
// #include "src/tap_number.h"

// ==============================================================================
// Define local macros
// ==============================================================================

#define DIM_RGB_LED_T(x) (x >> DIM_RGBS)

#define RGB_SETRGB_FROM_FADER(f)                                                                                                                 \
rgblight_setrgb(                                                                                                                                 \
DIM_RGB_LED_T((f)->current.r),                                                                                                                   \
DIM_RGB_LED_T((f)->current.g),                                                                                                                   \
DIM_RGB_LED_T((f)->current.b));                                                                                                            

#define KEYRECORD_FUN(type_and_name) type_and_name(uint16_t keycode, keyrecord_t * record)
#define CONST_KEYRECORD_FUN(type_and_name) type_and_name(uint16_t keycode, keyrecord_t const * const record)

#ifdef SEND_STRING_ENABLE
#  define MY_SS_DELAY 10
#  define SEND_STRING_WITHOUT_MODS(string) send_string_without_mods(string)
#  define SEND_STRING_WITHOUT_MODS_P(string) send_string_without_mods_P(string)
void send_string_without_mods(const char * const string) {
  const uint8_t current_mods = get_mods();

  clear_oneshot_mods();
  clear_mods();
  send_keyboard_report();
  send_string_with_delay(string, MY_SS_DELAY);
  set_mods(current_mods);
}
void send_string_without_mods_P(const char * const string) {
  const uint8_t current_mods = get_mods();

  clear_oneshot_mods();
  clear_mods();
  send_keyboard_report();
  send_string_with_delay_P(string, MY_SS_DELAY);
  set_mods(current_mods);
}
#else
#  define SEND_STRING_WITHOUT_MODS(str) (((void)0))
#  define SEND_STRING_WITHOUT_MODS_P(str) (((void)0))
#endif

#define SEND_PSTR(str) SEND_STRING_WITHOUT_MODS_P(PSTR(str))

// ==============================================================================
// Init
// ==============================================================================

void keyboard_post_init_user(void) {
#if CONSOLE_ENABLE
  debug_enable   = false;
  debug_matrix   = false;
  debug_keyboard = false;
  debug_mouse    = false;
#endif

#ifdef RGBLIGHT_ENABLE
  rgblight_enable_noeeprom();

  init_rgb_led_fader(&rgb_led_fader, MY_RGB_BOOT);

  RGB_SETRGB_FROM_FADER(&rgb_led_fader);
#endif
  }

// ==============================================================================
// Send string keycodes (string macros)
// ==============================================================================

#define S_END(_)               SS_TAP(X_END)
#define S_DELSEL()             SS_LCTL(SS_TAP(X_BSPC))
#define S_CLEAR(_)             SS_LGUI("a") S_DELSEL() S_CR()
#define S_CR(_)                SS_TAP(X_ENT)
#define DD                     150
#define S_DD()                 SS_DELAY(DD * 2)
#define S_ESC()                SS_TAP(X_ESC)
#define S_LL(_)                SS_TAP(X_LEFT)
#define S_RR(_)                SS_TAP(X_RIGHT)
#define S_SCR_L()              SS_LCTL(SS_TAP(X_F13))
#define S_SCR_R()              SS_LCTL(SS_TAP(X_F14))
#define S_SPC()                SS_TAP(X_SPC)
#define S_TB(_)                SS_TAP(X_TAB)
#define S_UU(_)                SS_TAP(X_UP) 
#define S_GUI_CLICK(_)         SS_DOWN(X_LGUI) SS_TAP(X_BTN1) SS_DELAY(10) SS_UP(X_LGUI)
#define S_GUI_CLICK_AND_TAB(_) S_GUI_CLICK() SS_LCTL(SS_TAP(X_TAB))

// #define S_REPEAT_SHELL_CMD(_)  SS_DOWN(X_LGUI) TAP(X_A) SS_UP(X_LGUI) TAP(X_BSPC) TAP(X_ENT) "!!" S_CR() TAP(X_HOME)
// #define S_REPEAT_SHELL_CMD(_)  SS_DOWN(X_LGUI) TAP(X_A) SS_UP(X_LGUI) TAP(X_BSPC) TAP(X_ENT) "!!" S_CR()
// #define S_REPEAT_SHELL_CMD(_)  SS_DOWN(X_LGUI) TAP(X_A) SS_UP(X_LGUI) SS_DOWN(X_LALT) SS_LGUI("d") SS_UP(X_LALT) TAP(X_ENT) "!!" S_CR()
#define S_REPEAT_SHELL_CMD(_)  SS_LGUI("a") SS_LCTL("x") S_DELSEL() SS_TAP(X_ENT) "!!" S_CR()
// #define S_REPEAT_SHELL_CMD(_)  SS_DOWN(X_LGUI) TAP(X_A) SS_UP(X_LGUI) S_CR() TAP(X_ENT) "!!" S_CR() 

/* #define S_TELEPORT(_)                                                                                                                        */
/*   S_GUI_CLICK() S_DD() SS_LCTL(TAP(X_TAB)) S_DD() SS_LGUI("l") S_DD() SS_LGUI("a") S_DD() SS_LGUI("x") S_DD() SS_LGUI("w") S_DD()            */
/*   SS_LGUI("`") S_DD() S_SCR_R() SS_DELAY(200) TAP(X_BTN1) S_DD() S_ESC() S_DD()                                                              */
/*   SS_LGUI("l") S_DD() SS_LGUI("a") S_DD() SS_LGUI("v") S_DD() TAP(X_ENT) SS_DELAY(2500)                                                      */
/*                                                                          TAP(X_F) S_DD() S_RR() S_DD() S_RR() S_DD()                         */
/*                                                                                   SS_LGUI("`") S_DD() S_SCR_L() */
#define S_TELEPORT(_)                                                                                                              \
S_GUI_CLICK() S_DD() SS_LCTL(SS_TAP(X_TAB)) S_DD() SS_LGUI("l") S_DD() SS_LGUI("a") S_DD() SS_LGUI("x") S_DD() SS_LGUI("w") S_DD() \
SS_LGUI("`") S_DD() S_SCR_R() SS_DELAY(200) SS_TAP(X_BTN1) S_DD() S_ESC() S_DD()                                                   \
SS_LGUI("l") S_DD() SS_LGUI("a") S_DD() SS_LGUI("v") SS_DELAY(DD * 4) SS_TAP(X_ENT) SS_DELAY(DD * 24)                              \
SS_TAP(X_F) S_DD()                                                                                                                 \
SS_LGUI("`") S_DD() S_SCR_L()

// ==============================================================================
// Send string keycodes (the main X-macro table)
// ==============================================================================

#  define FOR_EACH_BASIC_SEND_STRING_KEYCODE(DO)                    \
DO(SS_TELEPORT,          (S_TELEPORT())                           ) \
DO(SS_FULLSCR,           (SS_DOWN(X_F24) SS_TAP(X_F) SS_UP(X_F24))) \
DO(SS_KILL_WHOLE_LINE,   (SS_LCTL("a") SS_LCTL("k"))              ) \
DO(EM_SHELL,             (SS_LCTL("x") SS_LCTL("t"))              ) \
DO(EM_ALL_BUFF,          (SS_LCTL("x") SS_LCTL("b"))              ) \
DO(EM_DIRED,             (SS_LCTL("x") SS_LCTL("j"))              ) \
DO(EM_KILL_BUFF,         (SS_LCTL("x") SS_LCTL("k"))              ) \
DO(EM_LWRAP,             (SS_LCTL("x") SS_LCTL("l"))              ) \
DO(EM_PRV_BUFF,          (SS_LCTL("x") "p")                       ) \
DO(EM_SPLIT_V,           (SS_LCTL("x") "2")                       ) \
DO(EM_SPLIT_H,           (SS_LCTL("x") "3")                       ) \
DO(EM_MAC_BGN,           (SS_LCTL("x") "(")                       ) \
DO(EM_MAC_END,           (SS_LCTL("x") ")")                       ) \
DO(EM_MAC_RPT,           (SS_LCTL("x") "e")                       ) \
DO(EM_CHG_BUFF,          (SS_LCTL("x") "b")                       ) \
DO(OTHER_WIN,            (SS_LCTL("x") "o")                       ) \
DO(SS_0X,                ("0x")                                   ) \
DO(SS_THAT,              ("that ")                                )
//                       NO MODS                                 

// Disabled:
// DO(SS_DICT2,             (SS_TAP(X_F24) SS_TAP(X_F24))            ) 

#define S_EVAL_SEXP (SS_LCTL("x") SS_LCTL("e"))
//#define S_PP_EVAL_SEXP (SS_LCTL("x") SS_LCTL(" "))
#define S_PP_EVAL_SEXP (SS_LCTL("c") SS_LCTL(SS_TAP(X_BSPC)))

#  define FOR_EACH_MODDABLE_SEND_STRING_KEYCODE(DO)                                                                                       \
DO(SS_CD,                ("cd "),                 ("cd ~/"),               ("cd .."),              ("cd -"))                              \
DO(SS_SMILEY2,           (" :)"),                 (" :P"),                 (" :D"),                (" :tada: "))                          \
DO(SS_AND_AND,           (" && "),                (" || "),                (" 2>&1 "),             (" >/dev/null "))                      \
DO(SS_SMILEY,            (" ;)") ,                (" :-/"),                (" >_>"),               (" :laughing: "))                      \
DO(SS_LBRACK,            ("("),                   ("{"),                   ("["),                  ("<"))                                 \
DO(SS_RBRACK,            (")"),                   ("}"),                   ("]"),                  (">"))                                 \
DO(EM_LASTARG,           (S_EVAL_SEXP),           (S_PP_EVAL_SEXP),        (" " SS_LCTL("c") "."), ("c -" S_CR()))                        \
DO(SS_DIR,               ("~/"),                  ("../"),                 ("./"),                 ("` + `" S_LL() S_CR() S_TB() S_RR())) \
DO(SS_ARROW,             (" => "),                ("${}" S_LL()),          ("``" S_LL()),          ("->"))                                \
DO(SS_GUI_CLICK,         (S_GUI_CLICK()),         (S_GUI_CLICK_AND_TAB()), (""),                   (S_GUI_CLICK_AND_TAB()))               \
DO(SS_PIN1,              (AE_PIN1),               (AE_PIN2),               (ROUTER_PWD),           (AE_FPWD))                             
//                       NO MODS                  CTRL                     ALT                     SHIFT

// Disabled
// DO(SS_DICT,              (SS_TAP(X_F24) SS_TAP(X_F24)), (SS_DOWN(X_F24) SS_TAP(X_S) SS_UP(X_F24)),   (""),               ("")) 

// ==================================================================================================
// Send string keycodes (initialize the strings)
// ==================================================================================================
#define enum_item(kc, ...)                                                                     kc,
#define define_tagged_progmem_string(tag, kc, str, ...)                                        static const char tag##_str_##kc[] PROGMEM = str;
#define define_nomods_progmem_string(kc, nomods_str, ...)                                      define_tagged_progmem_string(nomods, kc, nomods_str, __VA_ARGS__)
#define define_ctrled_progmem_string(kc, nomods_str, ctrled_str, ...)                          define_tagged_progmem_string(ctrled, kc, ctrled_str, __VA_ARGS__)
#define define_alted_progmem_string(kc, nomods_str, ctrled_str, alted_str, ...)                define_tagged_progmem_string(alted, kc, alted_str, __VA_ARGS__)
#define define_shifted_progmem_string(kc, nomods_str, ctrled_str, alted_str, shifted_str, ...) define_tagged_progmem_string(shifted, kc, shifted_str, __VA_ARGS__)
#define define_basic_progmem_string(kc, nomods_str)                                            define_tagged_progmem_string(nomods, kc, nomods_str)

FOR_EACH_BASIC_SEND_STRING_KEYCODE(define_basic_progmem_string);
FOR_EACH_MODDABLE_SEND_STRING_KEYCODE(define_nomods_progmem_string);
FOR_EACH_MODDABLE_SEND_STRING_KEYCODE(define_alted_progmem_string);
FOR_EACH_MODDABLE_SEND_STRING_KEYCODE(define_ctrled_progmem_string);
FOR_EACH_MODDABLE_SEND_STRING_KEYCODE(define_shifted_progmem_string);

// ==================================================================================================
// Custom keycodes (incl. send string keycodes)
// ==================================================================================================

enum arianes_custom_keycodes {
  KC_DUMMY = SAFE_RANGE,
  //SS_0X,
  EM_CX,
  EM_CC,
  //OTHER_WIN,
  CLOSE_WIN,
  TYPE_LAYOUT,
  KC_SQUO_TAP,
  KC_DQUO_TAP,
  HOLD_GUI,
#ifdef INSERT_UPP_ENABLED
  INSERT_UPP,
#endif // INSERT_UPP_ENABLED
  VD_LEFT_ALT,
  VD_RIGHT_ALT,
  MY_BOOT,
  DISCORD_MUTE,
  TOGGLE_DF,
  FOR_EACH_MODDABLE_SEND_STRING_KEYCODE(enum_item)
    FOR_EACH_BASIC_SEND_STRING_KEYCODE(enum_item)
};

// ==============================================================================
// Send string keycodes (build the moddable array)
// ==============================================================================

#define moddable_send_string_keycodes_row(kc, ...) { kc, nomods_str_##kc, ctrled_str_##kc, alted_str_##kc, shifted_str_##kc },

typedef struct moddable_send_string_keycodes_t {
  uint16_t     kc;
  const char * str;
  const char * ctrled_str;
  const char * alted_str;
  const char * shifted_str;
} moddable_send_string_keycodes_t;

static const moddable_send_string_keycodes_t moddable_send_string_keycodes[] = {
  FOR_EACH_MODDABLE_SEND_STRING_KEYCODE(moddable_send_string_keycodes_row)
};

// ==============================================================================
// Send string keycodes (build the basic array)
// ==============================================================================

#define basic_send_string_keycodes_row(kc, ...) { kc, nomods_str_##kc },

typedef struct basic_send_string_keycodes_t {
  uint16_t     kc;
  const char * str;
} basic_send_string_keycodes_t;

static const basic_send_string_keycodes_t basic_send_string_keycodes[] = {
  FOR_EACH_BASIC_SEND_STRING_KEYCODE(basic_send_string_keycodes_row)
};

// ==============================================================================
// Send string keycodes (the moddable process function)
// ==============================================================================

CONST_KEYRECORD_FUN(bool process_moddable_send_string) {
  for (uint8_t ix = 0; ix < ARRAY_SIZE(moddable_send_string_keycodes); ix++) {
    if (moddable_send_string_keycodes[ix].kc == keycode) {      
      if (record->event.pressed)  {
        if      ((get_mods() & MOD_MASK_CTRL)) {
          SEND_STRING_WITHOUT_MODS_P(moddable_send_string_keycodes[ix].ctrled_str);
        }
        else if ((get_mods() & MOD_MASK_ALT)) {
          SEND_STRING_WITHOUT_MODS_P(moddable_send_string_keycodes[ix].alted_str);
        }
        else if ((get_mods() & MOD_MASK_SHIFT)) {
          SEND_STRING_WITHOUT_MODS_P(moddable_send_string_keycodes[ix].shifted_str);
        }
        else {
          SEND_STRING_WITHOUT_MODS_P(moddable_send_string_keycodes[ix].str);
        }
      }
      return false;
    }
  }
  return true;
}

// ==============================================================================
// Send string keycodes (the basic process function)
// ==============================================================================

CONST_KEYRECORD_FUN(bool process_basic_send_string) {
  for (uint8_t ix = 0; ix < ARRAY_SIZE(basic_send_string_keycodes); ix++) {
    if (basic_send_string_keycodes[ix].kc == keycode) {      
      if (record->event.pressed)
        SEND_STRING_WITHOUT_MODS_P(basic_send_string_keycodes[ix].str);

      return false;
    }
  }
  return true;
}

// ==============================================================================
// Callback-based handlers: the callbacks
// ==============================================================================

#ifdef DYNAMIC_MACRO_HANDLERS
CONST_KEYRECORD_FUN(bool dynamic_macros_handler) {
#ifdef   DYNAMIC_MACRO_ENABLE
  if (record->event.pressed)
    dynamic_macro_stop_recording();
#endif // DYNAMIC_MACRO_ENABLE

return true;
}
#endif // DYNAMIC_MACRO_HANDLERS

CONST_KEYRECORD_FUN(bool discord_mute_handler) {
  if (record->event.pressed) {
    // tap_code16(LGUI(LSFT(KC_D)));
    register_code16(LGUI(LSFT(KC_D)));
    wait_ms(4);
    unregister_code16(LGUI(LSFT(KC_D)));
  }

  return false;
}

CONST_KEYRECORD_FUN(bool cx_handler) {
  if (record->event.pressed) {
    layer_off(LN_MOUSE);
    tap_code16(LCTL(KC_X));
    add_oneshot_mods(MOD_LCTL);
    return false;
  }
  return true;
  
}

CONST_KEYRECORD_FUN(bool cc_handler) {
  if (record->event.pressed) {
    layer_off(LN_MOUSE);
    tap_code16(LCTL(KC_C));
    add_oneshot_mods(MOD_LCTL);
    return false;
  }
  return true;
}

/* CONST_KEYRECORD_FUN(bool other_win_handler) { */
/*   if (record->event.pressed) { */
/*     tap_code16(LGUI(KC_GRV)); */
/*   } */

/*   return false; */
/* } */
              
CONST_KEYRECORD_FUN(bool close_win_handler) {
  if (record->event.pressed) {
    tap_code16(LGUI(KC_W));
  }

  return false;
}

void tap_half_row_by_matrix_pos(uint8_t row, uint8_t start_column, uint8_t end_column, int8_t col_incr, uint8_t row_offset) {
  for (uint8_t column = start_column; column != end_column + col_incr; column += col_incr) {
    tap_code(keymap_key_to_keycode(get_highest_layer(default_layer_state), (keypos_t){column, row + row_offset}));
    tap_code(KC_SPC);
  }
}

CONST_KEYRECORD_FUN(bool type_layout_handler) {
  return false; // Disable the function here!
  if (! record->event.pressed)
    return false;
  
  const uint8_t outermost_typed_column = 1;
  const uint8_t innermost_typed_column = 5;
    
#define TAP_HALF_ROW_BY_MATRIX_POS(row, start_column, end_column, col_incr, row_offset)                                                          \
for (uint8_t column = start_column;                                                                                                            \
  column != end_column + col_incr;                                                                                                          \
  column += col_incr) {                                                                                                                     \
  tap_code(keymap_key_to_keycode(get_highest_layer(default_layer_state), (keypos_t){column, row + row_offset}));                               \
  tap_code(KC_SPC);                                                                                                                            \
  }

  for (uint8_t row = 1; row <= 3; ++row) {
    TAP_HALF_ROW_BY_MATRIX_POS(row, outermost_typed_column, innermost_typed_column, +1, 0); // left side of split
    tap_code(KC_SPC);
    TAP_HALF_ROW_BY_MATRIX_POS(row, innermost_typed_column, outermost_typed_column, -1, 5); // right side of split
    tap_code(KC_BSPC);
    tap_code(KC_ENT);
  }
    
  tap_code(KC_ENT);

  return false;
}

CONST_KEYRECORD_FUN(bool my_boot_handler) {
  init_rgb_led_fader(&rgb_led_fader, MY_RGB_BOOT);

  RGB_SETRGB_FROM_FADER(&rgb_led_fader);
  
  reset_keyboard();
  
  return false;
}

#ifdef INSERT_UPP_ENABLED
CONST_KEYRECORD_FUN(bool insert_upp_handler) {
  if (record->event.pressed) {
    for (uint8_t ix = 0; ix < 6; ix++) {
      static const uint16_t hex_keycodes[] = {
        KC_2, KC_3, KC_4, KC_5, KC_6, KC_7,
        KC_8, KC_9, KC_A, KC_B, QB_C,
      };

      const uint8_t roll    = ((rand() % 6) + 1) + ((rand() % 6) + 1);
      const uint16_t hex_kc = LSFT(hex_keycodes[roll - 2]);

      tap_code16(hex_kc);
    }
    
    tap_code(KC_ENTER);
  }

  return false;
}
#endif // INSERT_UPP_ENABLED

CONST_KEYRECORD_FUN(bool disable_mouse_layer_handler) {
  if ((! record->tap.count) && (! record->event.pressed))
    layer_off(LN_MOUSE);
  
  return true;
};

static bool toggle_df_flag = false;

CONST_KEYRECORD_FUN(bool toggle_df_handler) {  
  if (record->event.pressed) {
    toggle_df_flag = ! toggle_df_flag;

    layer_off(LN_MOUSE);
    
    default_layer_set((layer_state_t)1 << (toggle_df_flag ? 2 : 0)); // 2 is canary.
  }
  
  return false;
};

static bool double_quote_is_primed = false;

CONST_KEYRECORD_FUN(bool double_quote_handler) {
  if (record->event.pressed) {
    if (double_quote_is_primed) {
      tap_code(KC_BSPC);
      tap_code16(S(KC_QUOT));

      double_quote_is_primed = false;

      return false;
    }
    else {
      double_quote_is_primed = true;

      return true;
    }
  }
  
  return true;
};

// ==============================================================================
// Callback-based handlers: the callback table
// ==============================================================================

typedef bool(*keycode_handler_fun_t)(const uint16_t keycode, const keyrecord_t * const record);

static const struct { uint16_t keycode; keycode_handler_fun_t handler; } keycode_handlers[] PROGMEM = {
  { EM_CC,                       cc_handler                  },
  { EM_CX,                       cx_handler                  },
  { DISCORD_MUTE,                discord_mute_handler        },
  { MY_BOOT,                     my_boot_handler             },
  { CLOSE_WIN,                   close_win_handler           },
  // { NEW_TAB,                     new_tab_handler             },
  // { REOPEN_TAB,                  reopen_tab_handler          },
  // { OTHER_WIN,                   other_win_handler           },
  { TOGGLE_DF,                   toggle_df_handler           },
  { TYPE_LAYOUT,                 type_layout_handler         },
  { STR_LFT,                     disable_mouse_layer_handler },
  { THU_LFT,                     disable_mouse_layer_handler },
  { CRL_LFT,                     disable_mouse_layer_handler },
  // { CRL_MS,                      disable_mouse_layer_handler },

  { KC_QUOT,                     double_quote_handler },
  { RHRM_4(KC_QUOT),             double_quote_handler },
  
  #ifdef DYNAMIC_MACRO_HANDLERS
  { QK_DYNAMIC_MACRO_PLAY_1,     dynamic_macros_handler      },
  { QK_DYNAMIC_MACRO_PLAY_2,     dynamic_macros_handler      },
  #endif // DYNAMIC_MACRO_HANDLERS

    #ifdef    HOLD_GUI_ENABLED
  { HOLD_GUI,                    hold_gui_handler            },
  #endif    // HOLD_GUI_ENABLED

    #ifdef    INSERT_UPP_ENABLED
  { INSERT_UPP,                  insert_upp_handler          },
  #endif // INSERT_UPP_ENABLED
};

// ==============================================================================
// Tap handling
// ==============================================================================

static const struct { uint16_t matched; uint16_t tapped; } tap_cases[] PROGMEM = {
  { LT(15, LGUI(KC_W)),          LGUI(KC_W)     },
  { RHRM_4(KC_DQUO_TAP),         KC_DQUO        },

  { LCTL_SQUO,                   KC_QUOT        },
  { LCTL_DQUO,                   KC_DQUO        },

  { LCTL_OPEN,                   LGUI(KC_O)     },
  // { ARROWS_OPEN,                 LGUI(KC_O)     },
  
  { LHRM_1(VD_RIGHT_ALT),        VD_RIGHT       },
  { LHRM_2(VD_LEFT_ALT),         VD_LEFT        },

  { LHRM_4(LCA(KC_B)),           LCA(KC_B)      },
  { LHRM_3(LCA(KC_F)),           LCA(KC_F)      }, 

  { LT(14, LSA(KC_LBRC)),        LSA(KC_LBRC)   },

  { FLIPR_OR_USCORE,             LSFT(KC_MINS)  },

  { LTRM_1(C(KC_TAB)),           C(KC_TAB)      },
  { LTRM_2(RCS(KC_TAB)),         RCS(KC_TAB)    },
};

bool process_tap_case(uint16_t keycode, keyrecord_t const * const record)  {
  for (uint8_t ix = 0; ix < ARRAY_SIZE(tap_cases); ix++) {
    if (pgm_read_word(&tap_cases[ix].matched) == keycode) {
      if (record->tap.count && record->event.pressed) {
        tap_code16(pgm_read_word(&tap_cases[ix].tapped));

        return false;
      }

      return true;
    }
  }

  return true;
}

// ==============================================================================
// Mouse key overlap fixer function
// ==============================================================================

KEYRECORD_FUN(bool process_mouse_keys) {
  {
    static bool m_l, m_r, m_u, m_d = false;
  
    switch (keycode) {
    case KC_MS_L:
      if (record->event.pressed) {
        m_l = true;
      }
      else {
        if (m_r)
          mousekey_on(KC_MS_R);

        m_l = false;
      }

      return true;

    case KC_MS_R:
      if (record->event.pressed) {
        m_r = true;
      }
      else {
        if (m_l)
          mousekey_on(KC_MS_L);

        m_r = false;
      }

      return true;

    case KC_MS_U:
      if (record->event.pressed) {
        m_u = true;
      }
      else {
        if (m_d)
          mousekey_on(KC_MS_D);

        m_u = false;
      }

      return true;

    case KC_MS_D:
      if (record->event.pressed) {
        m_d = true;
      }
      else {
        if (m_u)
          mousekey_on(KC_MS_U);

        m_d = false;
      }

      return true;

    default:
      return false;
    }
  }
}

// ==============================================================================
// process_record_user and co.
// ==============================================================================

static uint16_t idle_timer = 0;

KEYRECORD_FUN(bool process_record_user) {
  idle_timer = timer_read();

// Unprime double quoting when other key is struck. This should probably be
// moved to some sort of cleanup function.
if (record->event.pressed && (((uint8_t)keycode) != ((uint8_t)KC_QUOT)))
  double_quote_is_primed = false;
  
#ifdef USE_ACHORDION
if (! process_achordion(keycode, record)) return false;
#endif // USE_ACHORDION
  
if (! process_basic_send_string(keycode, record)) return false;
if (! process_moddable_send_string(keycode, record)) return false;
if (! process_tap_case(keycode, record)) return false;
if (process_mouse_keys(keycode, record)) return true;
    
for (uint8_t ix = 0; ix < ARRAY_SIZE(keycode_handlers); ix++) {
  if (pgm_read_word(&keycode_handlers[ix].keycode) == keycode) {
    keycode_handler_fun_t handler = (keycode_handler_fun_t)(pgm_read_ptr(&keycode_handlers[ix].handler));

    return (*handler)(keycode, record);
  }
}
return true;
}

// ==============================================================================
// Dynamic macro related
// ==============================================================================

#ifdef DYNAMIC_MACRO_HANDLERS
static bool currently_recording_macro = false;

void dynamic_macro_record_start_user(int8_t direction) {
  currently_recording_macro = true;
}

void dynamic_macro_record_end_user(int8_t direction) {
  currently_recording_macro = false;
}
#endif // DYNAMIC_MACRO_HANDLERS

// ==============================================================================
// RGB fades
// ==============================================================================

#ifdef RGBLIGHT_ENABLE
#  ifdef DYNAMIC_MACRO_HANDLERS
  bool set_rgb_led_fader_target_if_recording_macro(rgb_led_fader_t * const this) {
    if (! currently_recording_macro)
      return false;

    set_rgb_led_fader_target(this, MY_RGB_RECORDING_MACRO);

    return true;
  }
#  endif //  DYNAMIC_MACRO_HANDLERS

typedef struct layer_to_rgb_t {
  uint8_t layer;
  uint8_t r;
  uint8_t g;
  uint8_t b;
} layer_to_rgb_t;
  
static const layer_to_rgb_t layer_to_rgbs[] PROGMEM = {
  { 0,             MY_RGB_DEFAULT                 },
  { 0,             MY_RGB_WORKMAK                 },
  { 5,             MY_RGB_TOGGLED_ARROWS_LAYER_ON },
  { LN_ARROWS,     MY_RGB_ADJUST_LAYER_ON         },
  { LN_FLIPR,      MY_RGB_FLIP_LAYER_ON           },
  { LN_FLIPL,      MY_RGB_FLIP_LAYER_ON           },
  { LN_UPPER,      MY_RGB_UPPER_LAYER_ON          },
  { LN_LOWER,      MY_RGB_LOWER_LAYER_ON          },
  { LN_MOUSE,      MY_RGB_TOGGLED_LAYER_ON        },
};

void set_rgb_led_fader_target_by_layer(rgb_led_fader_t * const this) {
  const layer_to_rgb_t * row = &layer_to_rgbs[toggle_df_flag]; // ? 1 : 0];
  
  for (size_t ix = 2; ix < ARRAY_SIZE(layer_to_rgbs); ix++) {
    if (layer_state_is(pgm_read_byte(&layer_to_rgbs[ix].layer))) {
      row = &layer_to_rgbs[ix];

      break;
    }
  }

  set_rgb_led_fader_target(this,
                           pgm_read_byte(&row->r),
                           pgm_read_byte(&row->g),
                           pgm_read_byte(&row->b));
}
#endif

// ==============================================================================
// Toggled mouse layer management
// ==============================================================================

#ifdef TOGGLED_LAYER_TIMEOUT
void manage_toggled_layer_timeout(const uint8_t layer, const uint16_t idle_time_limit_ms, const uint16_t timer)
{
  if (layer_state_is(layer) && (timer_elapsed(timer) >= idle_time_limit_ms))
    layer_off(layer);
}
#endif

#ifdef DOUBLE_QUOTE_TIMEOUT
void manage_double_quote_timeout(const uint8_t layer, const uint16_t idle_time_limit_ms, const uint16_t timer)
{
  if (double_quote_is_primed && timer_elapsed(timer) >= idle_time_limit_ms)
    double_quote_is_primed = false;
}
#endif

// ==============================================================================
// Toggled mouse layer management
// ==============================================================================

void matrix_scan_user(void) {  
#ifdef USE_ACHORDION
  achordion_task();
#endif // USE_ACHORDION

#ifdef DOUBLE_QUOTE_TIMEOUT
  manage_double_quote_timeout(TOGGLED_LAYER, DOUBLE_QUOTE_TIMEOUT, idle_timer);
#endif // DOUBLE_QUOTE_TIMEOUT

#ifdef TOGGLED_LAYER_TIMEOUT
  manage_toggled_layer_timeout(TOGGLED_LAYER, TOGGLED_LAYER_TIMEOUT, idle_timer);
#endif // TOGGLED_LAYER_TIMEOUT
  
  #if defined(RGBLIGHT_ENABLE) && defined(MY_RGB_LAYERS)
  #  ifdef DYNAMIC_MACRO_HANDLERS
  if (!set_rgb_led_fader_target_if_recording_macro(&rgb_led_fader))
    #  endif // DYNAMIC_MACRO_HANDLERS
    set_rgb_led_fader_target_by_layer(&rgb_led_fader);
  
#  ifdef SLOW_RGBS
  static uint8_t ticker = 0;

  ticker++;
  ticker %= 3;
  
  if (ticker)
    #  endif
    step_rgb_led_fader(&rgb_led_fader);

  RGB_SETRGB_FROM_FADER(&rgb_led_fader);
#endif // defined(RGBLIGHT_ENABLE) && defined(MY_RGB_LAYERS)
  }

  // ==============================================================================
  // Achordion
  // ==============================================================================

#ifdef USE_ACHORDION
  static const uint16_t achordion_qwerty_bilat_keys[] PROGMEM = {
    QH_S, QH_D, QH_F,
    QH_J, QH_K, QH_L, QH_QUOT
  };

  static const uint16_t achordion_canary_bilat_keys[] PROGMEM = {
    NH_S, NH_D, NH_F,
    NH_J, NH_K, NH_L, NH_QUOT
  };

  static const keycode_pair_t achordion_exceptions[] PROGMEM = {
    // Left GUI
    { QH_S,    QT_R            }, // refresh
    { QH_S,    QT_T            }, // new tab
    { QH_S,   KC_ENT },

    // Left alt
    { QH_D,    KC_ENT          }, // M-<return>

    // Left Control
    { QH_F,    QH_A            }, // beginning of line
    { QH_F,    KC_ENT          }, // C-<return>
    { QH_F,    QT_E            }, // end of line
  
    // Right Control
    { QH_J,    QH_K            }, // kill line

    { QH_J,    QH_L            }, // recenter / address bar
    { QH_J,    QT_Y            }, // yank
    { QH_J,    QB_N            }, // next line
    { QH_J,    QT_I            }, // tab
    { QH_J,    QT_P            }, // prev line

    // Right Alt
    { QH_K,    QH_L            }, // address bar?
    { QH_K,    QT_P            }, // prev command
    { QH_K,    QB_N            }, // next command

  };

  bool achordion_chord(
                       uint16_t      tap_hold_keycode,
                       keyrecord_t * tap_hold_record,
                       uint16_t      other_keycode,
                       keyrecord_t * other_record) {
    /* // KC_TAB keycode is not subject to achordion: */
    /* if (other_keycode >= KC_TAB) */
    /*   return true; */

    // custom keycodes are not subject to achordion:
    if (other_keycode >= SAFE_RANGE)
      return true;

    // Allow same-hand holds when the other key is in the rows below the
    // alphas. I need the `% (MATRIX_ROWS / 2)` because my keyboard is split.
    //
    // NOTE-AE: This is probably unnecesary due to the following check.  //
    if (other_record->event.key.row % (MATRIX_ROWS / 2) >= 4)
      return true;

    // If it isn't a home row mod/shift, process normally.
    if (!array_contains_keycode_P(tap_hold_keycode,
                                  (toggle_df_flag
                                   ? achordion_canary_bilat_keys
                                   : achordion_qwerty_bilat_keys),
                                  (toggle_df_flag
                                   ? ARRAY_SIZE(achordion_canary_bilat_keys)
                                   : ARRAY_SIZE(achordion_qwerty_bilat_keys))))
      return true;
  
    // Exceptionally consider the following chords as holds, even though they
    // are on the same hand.
    if (array_contains_keycode_pair_P((keycode_pair_t){ tap_hold_keycode, other_keycode }, achordion_exceptions, ARRAY_SIZE(achordion_exceptions)))
      return true;
   
    return achordion_opposite_hands(tap_hold_record, other_record);
  }

  bool achordion_eager_mod(uint8_t mod) {
    return true;  // Eagerly apply all mods.
  }
#endif

  // ==============================================================================
  // Mod-tap interrupt
  // ==============================================================================

  static const uint16_t hold_on_other_keypress_keys[] PROGMEM = {
    LCTL_ESC,
    LCTL_DQUO,
    LSFT_T(KC_MINS),
    RSFT_T(KC_MINS),
  };

  KEYRECORD_FUN(bool get_hold_on_other_key_press) {
  return ((keycode >= QK_MOD_TAP) &&
          (keycode <= QK_MOD_TAP_MAX) &&
          array_contains_keycode_P(keycode, hold_on_other_keypress_keys, ARRAY_SIZE(hold_on_other_keypress_keys)));
}

  static const uint16_t layer0_permissive_hold_keys[] PROGMEM = {
    CRL_LFT,
    CRL_RGT,
    THU_LFT,
    THU_RGT,
    QH_A, QH_S, QH_D, QH_F, QH_G,
    QH_J, QH_K, QH_L, QH_QUOT,  
  };

  static const uint16_t layer9_permissive_hold_keys[] PROGMEM = {
    CRL_LFT,
    CRL_RGT,
    THU_LFT,
    THU_RGT,
    NH_A, NH_S, NH_D, NH_F, NH_G,
    NH_J, NH_K, NH_L, NH_QUOT,  
  };


  KEYRECORD_FUN(bool get_permissive_hold) {
  if ((IS_LAYER_ON(0) && array_contains_keycode_P(keycode, layer0_permissive_hold_keys, ARRAY_SIZE(layer0_permissive_hold_keys))) ||
      (IS_LAYER_ON(9) && array_contains_keycode_P(keycode, layer9_permissive_hold_keys, ARRAY_SIZE(layer9_permissive_hold_keys))))
    return false; // Do not select the hold action when another key is tapped.

  return true; // Select the hold action when another key is tapped.
}

  uint16_t keycode_config(uint16_t keycode) {
    return keycode;
  }

  // ==============================================================================
  // Leader key
  // ==============================================================================

#ifdef LEADER_ENABLE

  void ss_ultrathink_bang_(void) {
    SEND_PSTR("Ultrathink! ");
  }

  void ss_diagnose_(void) {
    SEND_PSTR("Diagnose the root cause of this problem. ");
    // ss_ultrathink_bang_();
  }

  typedef enum {
    ARTICLE_A,
    ARTICLE_THE,
  } article_t;

  void ss_article_t_(article_t article) {
    switch (article) {
    case ARTICLE_A:
      SEND_PSTR("in a ");
      return;
    case ARTICLE_THE:
      SEND_PSTR("the plan in the ");
      return;
    }
  }

  void ss_in_article_t_plan_markdown_file_dot_(article_t article) {
    ss_article_t_(article);  
    SEND_PSTR("plan Markdown file. ");
  }

  typedef enum {
    PLAN_LOCATION_IN_THE_PLANMD_FILE,
    PLAN_LOCATION_THE_PLAN,
    PLAN_LOCATION_IN_THE_PLAN_MARKDOWN_FILE,
    PLAN_LOCATION_IN_A_PLAN_MARKDOWN_FILE,
  } plan_location_t;

  void ss_plan_location_t_dot_(plan_location_t plan_location) {
    switch(plan_location) {
    case PLAN_LOCATION_THE_PLAN:
      SEND_PSTR("the plan. ");
      break;
    case PLAN_LOCATION_IN_THE_PLANMD_FILE:
      SEND_PSTR("in the PLAN.md file. ");
      break;
    case PLAN_LOCATION_IN_A_PLAN_MARKDOWN_FILE:
      ss_in_article_t_plan_markdown_file_dot_(ARTICLE_A);
      return;
    case PLAN_LOCATION_IN_THE_PLAN_MARKDOWN_FILE:
      ss_in_article_t_plan_markdown_file_dot_(ARTICLE_THE);
      return;
    }
  }

  void ss_mark_completed_in_the_planmd_file_dot_(void) {
    SEND_PSTR("You MUST check off any steps you've completed ");
    ss_plan_location_t_dot_(PLAN_LOCATION_IN_THE_PLAN_MARKDOWN_FILE);
  }

  typedef enum {
    WHEN_AFTERWARDS,
    WHEN_AFTER_EACH_PHASE,
    WHEN_BEFORE_EDITING,
  } when_t;

  void ss_when_t_dot_(when_t when) {
    switch(when) {
    case WHEN_AFTERWARDS:
      SEND_PSTR("afterwards. ");
      return;
    case WHEN_AFTER_EACH_PHASE:
      SEND_PSTR("after each phase. ");
      return;
    case WHEN_BEFORE_EDITING:
      SEND_PSTR("before you start editing the code. ");
      return;
    }
  }

  void ss_must_build_and_pass_tests_dot_(when_t when) {
    SEND_PSTR("The code MUST build correctly and all tests MUST pass ");
    ss_when_t_dot_(when);
  }

  void ss_do_not_edit_any_code_yet_dot_(void) {
    SEND_PSTR("Do not edit any code yet. ");
  }

  void ss_detailed_step_by_step_plan_(void) {
    SEND_PSTR("detailed, step-by-step plan ");
  }

  void ss_submit_the_plan_for_approval_before_editing_dot_(void) {
    SEND_PSTR("Submit the plan for my approval ");
    ss_when_t_dot_(WHEN_BEFORE_EDITING);
  }

  void ss_do_not_add_new_files_(void) {
    SEND_PSTR("You MUST NOT add any new files. ");
  }

  void ss_post_check_dot_(when_t when) {
    ss_must_build_and_pass_tests_dot_(when);
  }

  void ss_group_phases_dot_(void) {
    SEND_PSTR("Group the plan's steps into \"phases\". ");
    ss_post_check_dot_(WHEN_AFTER_EACH_PHASE);
  }

  void ss_analyze_this_problem_(void) {
    SEND_PSTR("Analyze this problem");
  }

  void ss_write_the_plan_in_the_planmd_file_(void) {
    SEND_PSTR("Write the plan ");
    ss_plan_location_t_dot_(PLAN_LOCATION_IN_A_PLAN_MARKDOWN_FILE);
    /* ss_plan_locatio n_t_dot_(PLAN_LOCATION_IN_THE_PLANMD_FILE); */
  }
 
  typedef enum {
    SUBJECT_CHANGE,
    SUBJECT_FEATURE,
    SUBJECT_PROBLEM,
    SUBJECT_SOLUTION,
    SUBJECT_REFACTORING,
  } plan_subject_t;

  void ss_plan_subject_t(const plan_subject_t subject) {
    switch (subject) {
    case SUBJECT_CHANGE: SEND_PSTR("change"); return;
    case SUBJECT_FEATURE: SEND_PSTR("feature"); return;
    case SUBJECT_PROBLEM: SEND_PSTR("problem"); return;
    case SUBJECT_REFACTORING: SEND_PSTR("refactoring"); return;
    case SUBJECT_SOLUTION: SEND_PSTR("solution"); return;
    }
  }

  void ss_plan_dot_(plan_subject_t subject, plan_subject_t subject2) {
    SEND_PSTR("Think the ");
    ss_plan_subject_t(subject);
    SEND_PSTR(" through thoroughly and break the ");
    ss_plan_subject_t(subject2);
    SEND_PSTR(" down into small steps to produce a ");
    ss_detailed_step_by_step_plan_();
    SEND_PSTR("for implementing the ");
    ss_plan_subject_t(subject2);
    SEND_PSTR(". ");
    ss_group_phases_dot_();
    // ss_ultrathink_bang_();
  }

  void ss_analyze_smells_(void) {
    ss_do_not_edit_any_code_yet_dot_();
    SEND_PSTR("Analyze the code and find opportunities to refactor to improve its maintainability, or for other 'code smells' we could eliminate. ");
    ss_plan_dot_(SUBJECT_REFACTORING, SUBJECT_REFACTORING);
    ss_do_not_add_new_files_();
    ss_submit_the_plan_for_approval_before_editing_dot_();
    ss_write_the_plan_in_the_planmd_file_();
  }

  typedef enum {
    PHASE_DESCRIPTION_ALL_PHASES_OF,
    PHASE_DESCRIPTION_THE_NEXT_PHASE_OF,
  } phase_description_t;

  void ss_phase_description(phase_description_t phase_description) {
    switch (phase_description) {
    case PHASE_DESCRIPTION_THE_NEXT_PHASE_OF:
      SEND_PSTR("the next phase of ");
      break;
    case PHASE_DESCRIPTION_ALL_PHASES_OF:
      SEND_PSTR("all phases of ");
      break;
    }
  }

  void ss_proceed_with_implementing_plan_etc_dot_(phase_description_t phase_description,
                                                  plan_location_t plan_location) {
    SEND_PSTR("Proceed with the implemention of ");
 
    ss_phase_description(phase_description);
    ss_plan_location_t_dot_(plan_location);

    if (plan_location == PLAN_LOCATION_IN_THE_PLANMD_FILE) 
      ss_mark_completed_in_the_planmd_file_dot_();

    ss_post_check_dot_(WHEN_AFTERWARDS);
  }

  void ss_systematically_analyze_(void) {
    SEND_PSTR("Systematically analyze ");
  }

  void ss_dead_code_(void) {
    ss_systematically_analyze_();
    SEND_PSTR("the codebase for any dead or duplicated code and make a ");
    ss_detailed_step_by_step_plan_();
    SEND_PSTR("to eliminate it. ");
    ss_group_phases_dot_();
  }

  // =============================================================================
  // leader_end_user
  // =============================================================================
  void leader_end_user(void) {
    if      (leader_sequence_two_keys  (KC_B, KC_B)) {my_boot_handler(0, NULL);}
    else if (leader_sequence_one_key   (KC_H))       {SEND_PSTR(SS_LGUI("s"));}
    else if (leader_sequence_one_key   (KC_Q))       {SEND_PSTR(/*S_CLR()*/ "cdkm; qmkc" S_CR());}
    else if (leader_sequence_two_keys  (KC_Q, KC_W)) {SEND_PSTR(S_CLEAR() "cdkm; qmkupd" S_CR());}
    else if (leader_sequence_one_key   (KC_R))       {SEND_PSTR(S_REPEAT_SHELL_CMD(_));}
    else if (leader_sequence_one_key   (KC_S))       {SEND_PSTR(S_END() SS_LCTL(SS_TAP(X_A)) SS_LCTL(SS_TAP(X_K)) SS_DELAY(200) "shove" S_CR());}
    else if (leader_sequence_one_key   (QK_LEAD))    {SEND_PSTR(SS_LCTL(SS_TAP(X_ENT)));}
      /* prompt fragments: */
      /* else if (leader_sequence_one_key   (KC_A))       { /\* continue *\/ SEND_PSTR("Answer. ");} */
    else if (leader_sequence_one_key   (KC_C))       { /* continue */ SEND_PSTR("Carry on, continue. ");}
    else if (leader_sequence_one_key   (KC_M))       { /* minimal change */ SEND_PSTR("Make the minimal change needed to accomplish this. ");}
      /* else if (leader_sequence_one_key   (KC_T))       { /\* that *\/ SEND_PSTR("that ");} */
      /* else if (leader_sequence_two_keys  (KC_C, KC_E)) { /\* correct all errors *\/ SEND_PSTR("Correct ALL of the errors! ");} */
      // else if (leader_sequence_two_keys  (KC_C, KC_O)) { /* carry on */ SEND_PSTR("Carry on. ");}
    else if (leader_sequence_two_keys  (KC_C, KC_P)) { /* complete plan */ SEND_PSTR("You MUST complete the ENTIRE plan! ");}
      /* else if (leader_sequence_two_keys  (KC_D, KC_G)) { /\* don't get distracted *\/ SEND_PSTR("Don't get distracted. ");} */
    else if (leader_sequence_two_keys  (KC_D, KC_P)) { /* diagnose problem */ ss_diagnose_();}
      /* else if (leader_sequence_two_keys  (KC_D, KC_N)) { /\* do it now, no mistakes *\/ SEND_PSTR("Do it now, do it correctly, and make no mistakes. ");} */
    else if (leader_sequence_two_keys  (KC_E, KC_P)) { /* correct all errors */ SEND_PSTR("This error persists: ");}
      /* else if (leader_sequence_two_keys  (KC_G, KC_W)) { /\* great work *\/ SEND_PSTR("Great work! ");} */
      /* else if (leader_sequence_two_keys  (KC_K, KC_G)) { /\* keep going *\/ SEND_PSTR("Keep going. ");} */
      /* else if (leader_sequence_two_keys  (KC_K, KC_T)) { /\* keep trying *\/ SEND_PSTR("Keep trying. ");} */
    else if (leader_sequence_two_keys  (KC_N, KC_E)) { /* new errors */ SEND_PSTR("The changes introduced new errors: ");}
      /* else if (leader_sequence_two_keys  (KC_N, KC_M)) { /\* no mistakes *\/ SEND_PSTR("No mistakes! ");} */
      /* else if (leader_sequence_two_keys  (KC_N, KC_T)) { /\* new topic *\/ SEND_PSTR("Let's change topics: ");} */
      /* else if (leader_sequence_two_keys  (KC_P, KC_M)) { /\* ./plan.md *\/ SEND_PSTR("./PLAN..md"); } */
      /* else if (leader_sequence_two_keys  (KC_P, KC_S)) { /\* proceed systematically *\/ SEND_PSTR("Proceed systematically ");} */
    else if (leader_sequence_two_keys  (KC_R, KC_T)) { /* try again */ SEND_PSTR("Rethink it and then try again! "); /* ss_ultrathink_bang_(); */ }
    else if (leader_sequence_two_keys  (KC_S, KC_F)) { /* so far so good */ SEND_PSTR("So far, so good. ");}
    else if (leader_sequence_two_keys  (KC_S, KC_G)) { /* sounds good */ SEND_PSTR("Sounds good to me. ");}
      /* else if (leader_sequence_two_keys  (KC_T, KC_C)) { /\* testing comms *\/ SEND_PSTR("Testing communications, can you hear me? ");} */
      /* else if (leader_sequence_two_keys  (KC_T, KC_A)) { /\* try again *\/ SEND_PSTR("Try again. ");} */
      /* else if (leader_sequence_two_keys  (KC_T, KC_H)) { /\* think hard *\/ SEND_PSTR("Think hard! ");} */
    else if (leader_sequence_two_keys  (KC_T, KC_P)) { /* problem persists */ SEND_PSTR("The problem persists. "); }
      /* else if (leader_sequence_two_keys  (KC_T, KC_Y)) { /\* thank you *\/ SEND_PSTR("Thank you. ");} */
      /* else if (leader_sequence_one_key   (KC_U))       { /\* ultrathink *\/ ss_ultrathink_bang_(); } */
    else if (leader_sequence_one_key   (KC_Y))       { /* yes */ SEND_PSTR("Yes, please proceed. ");}
      /* else if (leader_sequence_one_key   (KC_X))       { /\* explain line *\/ SEND_PSTR("Explain this line in detail: " SS_DOWN(X_LSFT) S_CR() SS_UP(X_LSFT));} */
      /* SINGLE CALLS: */
      /* else if (leader_sequence_two_keys  (KC_A, KC_S)) { /\* analyze smells *\/ ss_analyze_smells_();} */
      /* else if (leader_sequence_two_keys  (KC_D, KC_C)) { /\* dead code *\/ ss_dead_code_();} */
    else if (leader_sequence_two_keys  (KC_S, KC_A)) { /* systematically analyze */ ss_systematically_analyze_();}
      /* else if (leader_sequence_two_keys  (KC_D, KC_E)) { /\* don't edit *\/ ss_do_not_edit_any_code_yet_dot_();} */
    else if (leader_sequence_two_keys  (KC_G, KC_P)) { /* group into phases */ ss_group_phases_dot_(); }
    else if (leader_sequence_two_keys  (KC_M, KC_B)) { /* must build after */ ss_must_build_and_pass_tests_dot_(WHEN_AFTERWARDS);}
      /* else if (leader_sequence_two_keys  (KC_M, KC_C)) { /\* mark completed *\/ ss_mark_completed_in_the_planmd_file_dot_();} */
      /* else if (leader_sequence_two_keys  (KC_N, KC_F)) { /\* no new files *\/ ss_do_not_add_new_files_();} */
    else if (leader_sequence_two_keys  (KC_S, KC_S)) { /* step-by-step plan */ ss_detailed_step_by_step_plan_();}
      /* else if (leader_sequence_two_keys  (KC_W, KC_P)) { /\* write plan *\/ ss_write_the_plan_in_the_planmd_file_();} */
    else if (leader_sequence_two_keys  (KC_S, KC_P)) { /* submit for approval */ ss_submit_the_plan_for_approval_before_editing_dot_();}
      /* QUESTIONS/: */
      /* else if (leader_sequence_two_keys  (KC_Q, KC_Q)) { /\* ask questions *\/ ss_do_not_edit_any_code_yet_dot_(); SEND_PSTR("\b\b, just answer questions. ");} */
      /* ANALYZE */
    else if (leader_sequence_two_keys  (KC_D, KC_F)) { /* analyze and fix */ ss_analyze_this_problem_(); SEND_PSTR(", diagnose its cause and fix it. ");}
    else if (leader_sequence_two_keys  (KC_A, KC_E)) { /* analyze and explain problem */ /* ss_do_not_edit_any_code_yet_dot_();  */ss_analyze_this_problem_(); SEND_PSTR(" and explain its cause: ");}
      /* PLAN: */
    else if (leader_sequence_two_keys  (KC_P, KC_C)) { /* plan change */ ss_plan_dot_(SUBJECT_CHANGE, SUBJECT_CHANGE);} 
    else if (leader_sequence_two_keys  (KC_P, KC_F)) { /* plan feature */ ss_plan_dot_(SUBJECT_FEATURE, SUBJECT_FEATURE);}
    else if (leader_sequence_two_keys  (KC_P, KC_P)) { /* plan problem */ ss_plan_dot_(SUBJECT_PROBLEM, SUBJECT_SOLUTION);}
    else if (leader_sequence_two_keys  (KC_P, KC_R)) { /* plan refactor */ ss_plan_dot_(SUBJECT_REFACTORING, SUBJECT_REFACTORING);}
      /* IMPLEMENT: */
    else if (leader_sequence_two_keys  (KC_I, KC_A)) { /* all of plan */ ss_proceed_with_implementing_plan_etc_dot_(PHASE_DESCRIPTION_ALL_PHASES_OF, PLAN_LOCATION_THE_PLAN);}
    /* else if (leader_sequence_two_keys  (KC_I, KC_N)) { /\* proceed w/ next in plan *\/ ss_proceed_with_implementing_plan_etc_dot_(PHASE_DESCRIPTION_THE_NEXT_PHASE_OF, PLAN_LOCATION_THE_PLAN);} */
    /* else if (leader_sequence_two_keys  (KC_F, KC_A)) { /\* all of PLAN.md *\/ ss_proceed_with_implementing_plan_etc_dot_(PHASE_DESCRIPTION_ALL_PHASES_OF, PLAN_LOCATION_IN_THE_PLANMD_FILE);} */
    /* else if (leader_sequence_two_keys  (KC_F, KC_N)) { /\* implement next in PLAN.md *\/ ss_proceed_with_implementing_plan_etc_dot_(PHASE_DESCRIPTION_THE_NEXT_PHASE_OF, PLAN_LOCATION_IN_THE_PLANMD_FILE);} */
    /* else if (leader_sequence_two_keys  (KC_F, KC_A)) { /\* implement all of Markdown *\/ ss_proceed_with_implementing_plan_etc_dot_(PHASE_DESCRIPTION_ALL_PHASES_OF, PLAN_LOCATION_IN_THE_PLAN_MARKDOWN_FILE);} */
    /* else if (leader_sequence_two_keys  (KC_F, KC_N)) { /\* implement next in Markdown *\/ ss_proceed_with_implementing_plan_etc_dot_(PHASE_DESCRIPTION_THE_NEXT_PHASE_OF, PLAN_LOCATION_IN_THE_PLAN_MARKDOWN_FILE);} */
  }
#endif // LEADER_ENABLE

  // ==============================================================================
  // Include combos 
  // ==============================================================================

#ifdef COMBO_ENABLE
#  include "src/combos.inc"
#endif

  // ==============================================================================
  // Include keymap
  // ==============================================================================

#include "src/keymap.inc"

