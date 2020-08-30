/* Gustavo Cruz
 *
 * Keyboard: id80
 * Last Upd: 27-08-2020
 * 
 */
 
#include QMK_KEYBOARD_H

enum {
	MACRO_1 = SAFE_RANGE,
	MACRO_2,
	MACRO_3,
	MACRO_4,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ESC,  KC_F1, KC_F2, KC_F3, KC_F4,  KC_F5, KC_F6, KC_F7, KC_F8,  KC_F9, KC_F10, KC_F11, KC_F12,	KC_PSCR,  KC_DEL,
        KC_GRV,  KC_1,  KC_2,  KC_3,  KC_4,  KC_5,  KC_6,  KC_7,  KC_8,  KC_9,  KC_0,  KC_MINS,  KC_EQL,	KC_BSPC, KC_HOME,
        KC_TAB,  KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,  KC_Y,  KC_U,  KC_I,  KC_O,  KC_P,  KC_LBRC, KC_RBRC, KC_BSLS,    KC_END,
        LCTL_T(KC_CAPS),KC_A,  KC_S,  KC_D,  KC_F,  KC_G,  KC_H,  KC_J,  KC_K,  KC_L,  KC_SCLN, KC_QUOT, 	KC_ENT,
        KC_LSFT, KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,  KC_N,  KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,       KC_UP,
        MO(1),   KC_LGUI,   KC_LALT,                KC_SPC,              KC_RALT,     KC_RCTL,     KC_LEFT, KC_DOWN, KC_RGHT
    ),               
    [1] = LAYOUT(
        RESET,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD,   RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD,   BL_DEC, BL_TOGG, BL_INC, BL_STEP,   NK_TOGG,   KC_MUTE,
        RALT(KC_RBRC), RSFT(KC_1), RALT(KC_Q), RSFT(KC_3), RSFT(KC_4), RSFT(KC_5), RALT(KC_QUOT), RSFT(KC_6), RSFT(KC_RBRC), RSFT(KC_8), RSFT(KC_9), RSFT(KC_SLSH), RSFT(KC_0), _______, KC_PGUP,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_QUOT, KC_BSLS, RALT(KC_MINS), KC_PGDN,
        _______, _______, _______, _______, _______, _______, _______, MACRO_1, MACRO_2, MACRO_3, MACRO_4, _______, 		 _______,
        _______, _______, _______, _______, _______, _______, _______, KC_APP, KC_NUBS, RSFT(KC_NUBS), RSFT(KC_7), _______, _______,
        _______,  _______,  _______, 						_______, 							_______, 	_______,    _______, _______, 	_______
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	if (record->event.pressed) {
		switch(keycode) {
			case MACRO_1:
				SEND_STRING("select "SS_RSFT("]")"\n from ");
				return false;break;
			case MACRO_2:
				SEND_STRING("cd "SS_LSFT("7")"siebel"SS_LSFT("7")"siebsrvr"SS_LSFT("7")"objects"SS_LSFT("7")"esn");
				return false;break;
			case MACRO_3:
				SEND_STRING("source "SS_LSFT("7")"siebel"SS_LSFT("7")"siebsrvr"SS_LSFT("7")"siebenv.sh");
				return false;break;
			case MACRO_4:
				SEND_STRING(SS_TAP(X_HOME)SS_TAP(X_MINS)SS_TAP(X_END)SS_TAP(X_MINS)SS_TAP(X_COMM)SS_TAP(X_RGHT));
				return false;break;
		}
	}
	return true;
};