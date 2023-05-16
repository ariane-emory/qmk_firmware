const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(LT(10,KC_GRV), KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, MO(11), KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_VOLU, KC_PGUP, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS, LCTL_T(KC_ESC), LSFT_T(KC_A), LGUI_T(KC_S), LALT_T(KC_D), LCTL_T(KC_F), KC_G, KC_VOLD, KC_PGDN, KC_H, RCTL_T(KC_J), RALT_T(KC_K), RGUI_T(KC_L), RSFT_T(KC_QUOT), RCTL_T(KC_DQUO), LSFT_T(KC_MINS), KC_Z, KC_X, KC_C, KC_V, KC_B, KC_F21, KC_F22, RGUI(KC_Z), TG(6), KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, RSFT_T(KC_MINS), KC_F23, KC_F24, TG(6), OSM(MOD_RGUI), QK_TRI_LAYER_LOWER, MT(MOD_LALT,KC_SPC), LT(9,KC_ENT), LT(12,KC_ENT), RGUI_T(KC_BSPC), QK_TRI_LAYER_UPPER, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT),
	[1] = LAYOUT(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_Q, KC_W, KC_F, KC_P, KC_G, KC_TRNS, KC_TRNS, KC_J, KC_L, KC_U, KC_O, KC_Y, KC_TRNS, KC_TRNS, LSFT_T(KC_A), LGUI_T(KC_R), LALT_T(KC_S), LCTL_T(KC_T), KC_D, KC_TRNS, KC_TRNS, KC_H, RCTL_T(KC_N), RALT_T(KC_E), RGUI_T(KC_I), RSFT_T(KC_QUOT), RCTL_T(KC_DQUO), KC_TRNS, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
	[2] = LAYOUT(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_Q, KC_D, KC_R, KC_W, KC_B, KC_TRNS, KC_TRNS, KC_J, KC_F, KC_U, KC_P, KC_QUOT, KC_TRNS, KC_TRNS, KC_A, KC_S, KC_H, KC_T, KC_G, KC_TRNS, KC_TRNS, KC_I, KC_N, KC_E, KC_O, KC_Y, RCTL_T(KC_QUOT), KC_TRNS, KC_Z, KC_X, KC_M, KC_C, KC_V, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_K, KC_L, KC_COMM, KC_DOT, KC_SLSH, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
	[3] = LAYOUT(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_Q, KC_C, KC_H, KC_M, KC_Z, KC_TRNS, KC_TRNS, KC_K, KC_Y, KC_O, KC_J, KC_QUOT, KC_TRNS, KC_TRNS, KC_R, KC_S, KC_N, KC_T, KC_G, KC_TRNS, KC_TRNS, KC_W, KC_U, KC_E, KC_I, KC_A, KC_TRNS, KC_TRNS, KC_X, KC_B, KC_L, KC_D, KC_P, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_V, KC_F, KC_COMM, KC_DOT, KC_SLSH, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
	[4] = LAYOUT(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
	[5] = LAYOUT(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
	[6] = LAYOUT(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGUI(KC_T), RSG(KC_T), RGUI(KC_W), RGUI(KC_MINS), RGUI(KC_EQL), LT(11,KC_HOME), KC_TRNS, KC_TRNS, KC_TRNS, KC_UP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP, KC_WH_R, KC_MS_U, KC_WH_L, RGUI(KC_R), KC_END, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGDN, KC_MS_L, KC_MS_D, KC_MS_R, KC_RGUI, RCTL_T(KC_ESC), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LCA(KC_X), KC_TRNS, KC_BSPC, KC_WH_U, KC_WH_D, KC_F21, KC_F22, RSFT_T(KC_F23), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN2, KC_BTN1, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
	[7] = LAYOUT(KC_NO, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, RGUI(KC_T), RSG(KC_T), RGUI(KC_W), RGUI(KC_MINS), RGUI(KC_EQL), LT(11,KC_HOME), KC_NO, LCTL(KC_A), LCTL(KC_E), RCS(KC_TAB), LCTL(KC_TAB), KC_PGUP, KC_HOME, KC_TRNS, KC_PGUP, KC_WH_R, KC_MS_U, KC_WH_L, RGUI(KC_R), KC_END, LALT(KC_TAB), LALT(KC_B), LALT(KC_F), KC_F21, KC_F22, KC_PGDN, KC_END, KC_TRNS, KC_PGDN, KC_MS_L, KC_MS_D, KC_MS_R, KC_RGUI, RCTL_T(KC_ESC), KC_TRNS, LSA(KC_LCBR), LSA(KC_RCBR), LCA(KC_B), LCA(KC_F), KC_F23, KC_TRNS, KC_TRNS, LCA(KC_X), KC_TRNS, KC_BSPC, KC_WH_U, KC_WH_D, KC_F21, KC_F22, RSFT_T(KC_F23), KC_TRNS, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN2, KC_BTN1, KC_TRNS, S(A(G(KC_A))), S(A(G(KC_E))), S(A(G(KC_R))), S(A(G(KC_S)))),
	[8] = LAYOUT(KC_NO, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, RGUI(KC_T), RSG(KC_T), RGUI(KC_W), RGUI(KC_MINS), RGUI(KC_EQL), LT(11,KC_HOME), KC_NO, LCTL(KC_A), LCTL(KC_E), RCS(KC_TAB), LCTL(KC_TAB), KC_PGUP, KC_TRNS, KC_VOLU, KC_PGUP, RCS(KC_TAB), RCTL(KC_TAB), RGUI(KC_LBRC), RGUI(KC_RBRC), KC_END, LALT(KC_TAB), LALT(KC_B), LALT(KC_F), KC_F21, KC_F22, KC_PGDN, KC_TRNS, KC_VOLD, KC_PGDN, KC_F21, KC_F22, KC_F23, KC_F24, KC_SPC, QK_CAPS_WORD_TOGGLE, LSA(KC_LCBR), LSA(KC_RCBR), LCA(KC_B), LCA(KC_F), KC_F23, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RALT(KC_X), RCTL(KC_X), RCTL(KC_C), KC_NO, KC_NO, QK_CAPS_WORD_TOGGLE, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_TRNS, LCTL(KC_SPC), LALT(KC_SPC), KC_TRNS, KC_TRNS, KC_TRNS, RALT(KC_LEFT), RCTL(KC_A), RCTL(KC_E), RALT(KC_RGHT)),
	[9] = LAYOUT(KC_NO, KC_0, KC_9, KC_8, KC_7, KC_6, KC_F13, KC_F14, KC_F15, KC_F16, KC_NO, RSA(KC_DLR), KC_BSLS, KC_P, KC_O, KC_I, KC_U, KC_Y, KC_NO, KC_VOLU, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO, KC_TRNS, RCTL_T(KC_DQUO), KC_QUOT, KC_L, KC_K, KC_J, KC_H, KC_BSPC, KC_VOLD, KC_F5, KC_F6, KC_F7, KC_F8, KC_NO, KC_TRNS, KC_TRNS, KC_SLSH, KC_DOT, KC_COMM, KC_M, KC_N, KC_BSPC, KC_NO, KC_NO, KC_NO, KC_F1, KC_F2, KC_F3, KC_F4, KC_NO, KC_TRNS, KC_LEFT, KC_UP, KC_DOWN, KC_RGHT, KC_NO, RGUI_T(KC_BSPC), KC_TRNS, KC_INS, KC_DEL, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO),
	[10] = LAYOUT(KC_TRNS, INSERT_UPP, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, EE_CLR, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_CAPS, RGB_TOG, QK_REBOOT, QK_BOOT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
	[11] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RSA(KC_C), RSA(KC_X), RSA(KC_Z), KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F20, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F19, KC_MPLY, RGB_SPI, RGB_VAI, RGB_SAI, RGB_HUI, RGB_MOD, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MUTE, RGB_SPD, RGB_VAD, RGB_SAD, RGB_HUD, RGB_RMOD, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, QK_BOOT, QK_REBOOT, SS_PIN1, SS_PIN2),
	[12] = LAYOUT(KC_NO, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_5, KC_4, KC_3, KC_2, KC_1, KC_GRV, KC_TRNS, KC_SLSH, LSFT(KC_7), LSFT(KC_8), LSFT(KC_9), KC_MINS, KC_PGUP, KC_NO, KC_T, KC_R, KC_E, KC_W, KC_Q, KC_TAB, KC_CAPS, KC_8, LSFT(KC_4), LSFT(KC_5), LSFT(KC_6), LSFT(KC_EQL), KC_PGDN, KC_SPC, KC_G, KC_F, KC_D, KC_S, KC_A, RCTL_T(KC_ESC), KC_TRNS, KC_EQL, LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), KC_EQL, KC_TRNS, KC_TRNS, KC_NO, KC_SPC, KC_B, KC_V, KC_C, KC_X, KC_Z, KC_TRNS, KC_NO, KC_NO, KC_PCMM, KC_PDOT, LSFT(KC_0), KC_TRNS, KC_TRNS, KC_TRNS, MT(MOD_LALT,KC_SPC), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
	[13] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_HOME, RCTL(KC_A), KC_UP, RCTL(KC_E), KC_PGUP, KC_NO, KC_NO, KC_PGUP, RCTL(KC_A), KC_UP, RCTL(KC_E), KC_HOME, KC_NO, KC_TRNS, KC_END, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_NO, KC_NO, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_END, KC_TRNS, KC_LSFT, KC_NO, LALT(KC_DEL), LALT(KC_LEFT), LALT(KC_RGHT), LALT(KC_BSPC), KC_NO, KC_NO, KC_NO, KC_NO, LALT(KC_BSPC), LALT(KC_LEFT), LALT(KC_RGHT), LALT(KC_DEL), KC_NO, KC_RSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO)
};
