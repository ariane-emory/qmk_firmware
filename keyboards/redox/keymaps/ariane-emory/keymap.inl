const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(LT(6,KC_GRV), KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, LT(12,KC_BSLS), KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_VOLU, KC_PGUP, KC_Y, KC_U, KC_I, KC_O, KC_P, LT(11,KC_QUOT), LCTL_T(KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_VOLD, KC_PGDN, KC_H, KC_J, KC_K, KC_L, KC_SCLN, RCTL_T(KC_ESC), LSFT_T(KC_MINS), KC_Z, KC_X, KC_C, KC_V, KC_B, KC_F21, KC_F22, RGUI(KC_Z), TG(2), KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, RSFT_T(KC_MINS), KC_F23, KC_F24, KC_NO, OSM(MOD_RGUI), OSL(3), TD(0), LT(5,KC_ENT), LT(9,KC_ENT), RGUI_T(KC_BSPC), OSL(4), KC_LEFT, KC_DOWN, KC_UP, KC_RGHT),
	[1] = LAYOUT(LT(7,KC_GRV), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_Q, KC_W, KC_J, KC_R, KC_T, KC_TRNS, KC_TRNS, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_TRNS, KC_TRNS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_TRNS, KC_TRNS, KC_H, KC_N, KC_E, KC_L, KC_SCLN, KC_TRNS, KC_TRNS, KC_Z, KC_X, KC_C, KC_V, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
	[2] = LAYOUT(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGUI(KC_T), RSG(KC_T), RGUI(KC_W), RGUI(KC_MINS), RGUI(KC_EQL), MO(8), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP, KC_WH_R, KC_MS_U, KC_WH_L, RGUI(KC_R), MO(11), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGDN, KC_MS_L, KC_MS_D, KC_MS_R, KC_RGUI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LCA(KC_X), KC_TRNS, KC_RGUI, KC_WH_U, KC_WH_D, KC_F21, KC_F22, RSFT_T(KC_F23), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN2, KC_BTN1, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
	[3] = LAYOUT(RCS(KC_TAB), KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, RGUI(KC_T), RSG(KC_T), RGUI(KC_W), RGUI(KC_MINS), RGUI(KC_EQL), MO(8), LCTL(KC_TAB), LSA(KC_LCBR), LSA(KC_RCBR), RCS(KC_TAB), LCTL(KC_TAB), KC_PGUP, KC_HOME, KC_HOME, KC_PGUP, KC_WH_R, KC_MS_U, KC_WH_L, RGUI(KC_R), MO(11), LALT(KC_TAB), KC_NO, KC_NO, LALT(KC_B), LALT(KC_F), KC_PGDN, KC_END, KC_END, KC_PGDN, KC_MS_L, KC_MS_D, KC_MS_R, KC_RGUI, KC_TRNS, LSFT_T(KC_F23), KC_F21, KC_F22, LCTL(KC_A), LCTL(KC_E), KC_MUTE, KC_TRNS, KC_TRNS, LCA(KC_X), KC_TRNS, KC_RGUI, KC_WH_U, KC_WH_D, KC_F21, KC_F22, RSFT_T(KC_F23), KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN2, KC_BTN1, LM(10, MOD_LGUI | MOD_LALT), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
	[4] = LAYOUT(RCS(KC_TAB), KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, RGUI(KC_T), RSG(KC_T), RGUI(KC_W), RGUI(KC_MINS), RGUI(KC_EQL), KC_F24, LCTL(KC_TAB), LSA(KC_LCBR), LSA(KC_RCBR), RCS(KC_TAB), LCTL(KC_TAB), KC_PGUP, KC_HOME, KC_HOME, KC_PGUP, RCS(KC_TAB), RCTL(KC_TAB), RGUI(KC_LBRC), RGUI(KC_RBRC), KC_SPC, LALT(KC_TAB), KC_NO, KC_NO, LALT(KC_B), LALT(KC_F), KC_PGDN, KC_END, KC_END, KC_PGDN, RCTL(KC_X), RCTL(KC_C), KC_NO, KC_NO, KC_ENT, LSFT_T(KC_F23), KC_F21, KC_F22, LCTL(KC_A), LCTL(KC_E), KC_MUTE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, RALT(KC_X), KC_NO, KC_F21, KC_F22, RSFT_T(KC_F23), KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, LM(10, MOD_LGUI | MOD_LALT), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, QK_BOOT, QK_REBOOT),
	[5] = LAYOUT(QK_BOOT, RGB_TOG, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F13, KC_F14, KC_F15, KC_F16, RSA(KC_DLR), QK_REBOOT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F20, KC_F20, KC_NO, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, KC_CAPS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F19, KC_F19, KC_NO, KC_F5, KC_F6, KC_F7, KC_F8, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_HOME, KC_END, KC_NO, KC_F1, KC_F2, KC_F3, KC_F4, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_INS, KC_DEL, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO),
	[6] = LAYOUT(KC_TRNS, DF(1), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
	[7] = LAYOUT(KC_TRNS, DF(0), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
	[8] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RSA(KC_C), RSA(KC_X), RSA(KC_Z), KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_VOLU, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_VOLD, KC_MPLY, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MUTE, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
	[9] = LAYOUT(KC_NO, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, RGUI(KC_T), RSG(KC_T), RGUI(KC_W), RGUI(KC_MINS), RGUI(KC_EQL), KC_TRNS, KC_NO, KC_PSLS, LSFT(KC_7), LSFT(KC_8), LSFT(KC_9), KC_PMNS, KC_TRNS, KC_HOME, KC_HOME, RSA(KC_LCBR), KC_UP, RSA(KC_RCBR), KC_LBRC, KC_RBRC, KC_NO, KC_PAST, LSFT(KC_4), LSFT(KC_5), LSFT(KC_6), KC_PPLS, KC_TRNS, KC_END, KC_END, KC_LEFT, KC_DOWN, KC_RGHT, KC_LCBR, KC_RCBR, KC_NO, KC_PEQL, LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), KC_PEQL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RCTL(KC_A), RALT(KC_B), RALT(KC_F), RCTL(KC_E), RSFT(KC_COMM), RSFT(KC_SLSH), KC_NO, KC_NO, KC_PCMM, KC_PDOT, LSFT(KC_0), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
	[10] = LAYOUT(KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSLS, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_NO, KC_NO, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_QUOT, KC_SPC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_NO, KC_NO, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_ESC, LSFT_T(KC_MINS), KC_Z, KC_X, KC_C, KC_V, KC_B, KC_NO, KC_NO, KC_NO, KC_NO, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, RSFT_T(KC_MINS), KC_NO, KC_NO, KC_NO, KC_NO, LM(10, MOD_LGUI | MOD_LALT), KC_SPC, KC_ENT, KC_ENT, KC_BSPC, LM(10, MOD_LGUI | MOD_LALT), KC_LEFT, KC_DOWN, KC_UP, KC_RGHT),
	[11] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_PMNS, KC_PPLS, KC_PEQL, KC_NO, KC_PSLS, LSFT(KC_7), LSFT(KC_8), LSFT(KC_9), KC_PMNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_LBRC, KC_RBRC, KC_TRNS, KC_NO, KC_PAST, LSFT(KC_4), LSFT(KC_5), LSFT(KC_6), KC_PPLS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_LCBR, KC_RCBR, KC_TRNS, KC_NO, KC_PEQL, LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), KC_PEQL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, RSFT(KC_COMM), RSFT(KC_DOT), KC_TRNS, KC_NO, KC_NO, KC_LCTL, KC_PDOT, LSFT(KC_0), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
	[12] = LAYOUT(KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RSA(KC_C), RSA(KC_X), RSA(KC_Z), KC_TRNS, KC_TRNS, KC_C, KC_D, KC_E, KC_F, KC_NO, KC_TRNS, KC_VOLU, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, LSFT(KC_8), LSFT(KC_9), KC_A, KC_B, KC_NO, KC_TRNS, KC_VOLD, KC_MPLY, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, LSFT(KC_4), LSFT(KC_5), LSFT(KC_6), LSFT(KC_7), KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MUTE, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, LSFT(KC_0), LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)
};
