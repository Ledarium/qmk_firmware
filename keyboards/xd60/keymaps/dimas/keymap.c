#include QMK_KEYBOARD_H

#define _ KC_NO
#define ____ KC_NO
#define _______ KC_NO

enum {
    DEFAULT = 0,
    MOD,
    FKEYS,
    NUMPAD
};

enum {
    ESC_MOD = LT(1,KC_ESC),
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [DEFAULT] = LAYOUT_all(
            KC_GRV, KC_1,   KC_2,   KC_3,  KC_4,  KC_5,   KC_6,   KC_7,    KC_8,   KC_9,  KC_0,  KC_MINS,  KC_EQL,  KC_BSPC, KC_PSCR,
            KC_TAB,   KC_Q,   KC_W,   KC_E,  KC_R,  KC_T,   KC_Y,   KC_U,    KC_I,   KC_O,  KC_P,   KC_LBRC,   KC_RBRC,      KC_BSLS,
            ESC_MOD,    KC_A,   KC_S,   KC_D,  KC_F,  KC_G,   KC_H,   KC_J,   KC_K,    KC_L,   KC_SCLN,   KC_QUOT,   KC_ENT, KC_ENT,
            KC_LSFT, _,   KC_Z,   KC_X,   KC_C, KC_V,   KC_B,   KC_N,   KC_M,  KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT, KC_UP,   KC_DEL,
            KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                         TG(3),  OSL(2),   KC_LEFT, KC_DOWN, KC_RGHT
            ),
    [MOD] = LAYOUT_all(
            ____,    ____,    ____,    LALT(KC_F4), KC_END,     ____,    ____,       ____,       ____,     ____,    KC_HOME,    ____,   ____,    ____,    KC_PAUS,
            KC_ESC,  KC_LSFT, KC_LCTL, ____,        ____,       ____,    LCTL(KC_C), LCTL(KC_Z), ____,     ____,    LCTL(KC_V), ____,   ____,    ____,
            KC_TRNS, KC_PAST, KC_PPLS, LCTL(KC_X),  LCTL(KC_F), ____,    KC_LEFT,    KC_DOWN,    KC_UP,    KC_RGHT, ____,       ____,   ____,    ____,
            KC_TRNS, KC_TRNS, ____,    ____,        ____,       ____,    ____,       ____,       ____,     ____,    ____,       ____,   ____,    ____,    ____,
            KC_TRNS, KC_TRNS, KC_TRNS,                   KC_BSPC,                                                   ____,       ____,   ____,    ____,    ____
            ),
    [FKEYS] = LAYOUT_all(
            ____,    KC_F1,   KC_F2,   KC_F3,       KC_F4,      KC_F5,   KC_F6,      KC_F7,      KC_F8,    KC_F9,   KC_F10,     KC_F11, KC_F12,  ____,    ____,
            ____,    ____,    ____,    ____,        ____,       ____,    ____,       ____,       ____,     ____,    ____,       ____,   ____,    ____,
            ____,    ____,    ____,    ____,        ____,       ____,    ____,       ____,       ____,     ____,    ____,       ____,   ____,    ____,
            RESET,   RESET,   ____,    ____,        ____,       RGB_MOD, RGB_TOG,    RGB_VAD,    RGB_VAI,  BL_TOGG, BL_DEC,     BL_INC, KC_MUTE, KC_VOLU, KC_MPLY,
            ____,    ____,    ____,    ____,        ____,       KC_TRNS, KC_MPRV,    KC_VOLD,    KC_MNXT),
    [NUMPAD] = LAYOUT_all(
            KC_NLCK, KC_PSLS, KC_PAST, KC_PEQL,     ____,       ____,    ____,       ____,       ____,     ____,    ____,       ____,   ____,    KC_BSPC, ____,
            KC_PMNS, KC_P7,   KC_P8,   KC_P9,       KC_BSPC,    ____,    ____,       ____,       ____,     ____,    ____,       ____,   ____,    ____,
            KC_PPLS, KC_P4,   KC_P5,   KC_P6,       KC_BSPC,    ____,    ____,       ____,       ____,     ____,    ____,       ____,   ____,    ____,
            KC_PENT, KC_PENT, KC_P1,   KC_P2,       KC_P3,      KC_PDOT, ____,       ____,       ____,     ____,    ____,       ____,   ____,    ____,    ____,
            ____,    ____,    KC_PDOT, KC_P0,       KC_TRNS,    ____,    ____,       ____,       ____)
};

void matrix_init_user() {
    rgblight_setrgb(RGB_WHITE);
    rgblight_enable();
}

uint32_t layer_state_set_user(uint32_t state) {
    uint8_t layer = biton32(state);
    switch (layer) {
        case MOD:
            rgblight_setrgb(RGB_ORANGE);
            break;

        case FKEYS:
            rgblight_setrgb(RGB_RED);
            break;

        case NUMPAD:
            rgblight_setrgb(RGB_CYAN);
            break;

        default:
            rgblight_setrgb(RGB_WHITE);
            break;
    }
    return state;
}
