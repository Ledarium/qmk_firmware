#include QMK_KEYBOARD_H

#define _ KC_NO
#define ____ KC_NO

#define DEFAULT_RGB_MODE RGBLIGHT_MODE_RAINBOW_SWIRL+1

// Macro Declarations
enum {
    MACRO_1_8 = SAFE_RANGE+100,
};
// Macro Definitions
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    case MACRO_1_8: {
        if (record->event.pressed) {
            SEND_STRING("12345678");
        }
        break;
    }
  }
  return true;
};

enum {
    DEFAULT = 0,
    GAME,
    MOD1,
    MOD2,
    FKEYS,
    NUMPAD
};

enum {
    ESC_MOD = LT(MOD2,KC_ESC),
    SPC_MOD = LT(MOD1,KC_SPC),
    LCTL_BS = MT(MOD_LCTL, KC_BSPC)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [DEFAULT] = LAYOUT_all(
            KC_GRV, KC_1,    KC_2,   KC_3,  KC_4,  KC_5,   KC_6,   KC_7,    KC_8,   KC_9,    KC_0, KC_MINS, KC_EQL,  KC_BSPC,  KC_PSCR,
            KC_TAB,    KC_Q,   KC_W,   KC_E,  KC_R,  KC_T,   KC_Y,   KC_U,    KC_I,   KC_O,    KC_P,  KC_LBRC,  KC_RBRC,       KC_BSLS,
            ESC_MOD,      KC_A,   KC_S,   KC_D,  KC_F,  KC_G,   KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN,  KC_QUOT,        _, KC_ENT,
            KC_LSPO, _,      KC_Z,   KC_X,   KC_C, KC_V,   KC_B,   KC_N,   KC_M,  KC_COMM,  KC_DOT, KC_SLSH,  KC_RSPC, KC_UP,  KC_DEL,
            LCTL_BS, KC_LGUI, KC_LALT,                   SPC_MOD,                      TG(NUMPAD),OSL(FKEYS),KC_LEFT, KC_DOWN, KC_RGHT
            ),
    [GAME] = LAYOUT_all(
            KC_GRV, KC_1,   KC_2,   KC_3,  KC_4,  KC_5,   KC_6,   KC_7,    KC_8,   KC_9,    KC_0, KC_MINS, KC_EQL,  KC_BSPC, KC_PSCR,
            KC_TAB,   KC_Q,   KC_W,   KC_E,  KC_R,  KC_T,   KC_Y,   KC_U,    KC_I,   KC_O,    KC_P,  KC_LBRC,  KC_RBRC,      KC_BSLS,
            KC_ESC,     KC_A,   KC_S,   KC_D,  KC_F,  KC_G,   KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN,    KC_QUOT,   _,    KC_ENT,
            KC_LSFT, _,   KC_Z,   KC_X,   KC_C, KC_V,   KC_B,   KC_N,   KC_M,  KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT, KC_UP,   KC_DEL,
            KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                     TG(NUMPAD),OSL(FKEYS),KC_LEFT, KC_DOWN, KC_RGHT
            ),
    [MOD1] = LAYOUT_all(
            KC_GRV, KC_F1,  KC_F2,  KC_F3,    KC_F4,  KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, KC_F11, KC_F12,  ____, ____,
            KC_DOT, KC_1,   KC_2,    KC_3,    KC_4,    KC_5,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,      ____, ____, MACRO_1_8,
            KC_BSPC,  KC_LBRC, KC_RBRC, KC_AT,  KC_HASH, KC_AMPR, KC_EXLM, KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT,  KC_DLR, _,    ____,
            KC_TRNS,_, KC_LCBR, KC_RCBR, KC_DLR, KC_PERC, KC_CIRC, KC_EQL,  KC_UNDS, KC_PLUS, KC_MINS, KC_ASTR, ____, KC_PGUP, ____,
            KC_TRNS, KC_TRNS, KC_TRNS,                 KC_TRNS,                               ____, ____, KC_HOME, KC_PGDN, KC_END
            ),
    [MOD2] = LAYOUT_all(
            ____,    ____,    KC_F2,    LALT(KC_F4), KC_END,     ____, ____,    ____,    ____,    ____,   KC_HOME, ____, ____, ____,    KC_PAUS,
            KC_ESC,  ____,    ____,    ____,        ____,       ____, ____,    ____,    ____,    ____,    ____,    ____, ____, ____,
            KC_TRNS, KC_PAST, KC_PPLS, LCTL(KC_X),  LCTL(KC_F), ____, ____, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  ____,    _,    ____,
            KC_TRNS, _,    ____, ____,     ____,    ____,    ____,    ____,    ____,  ____,      ____,    ____, ____, KC_PGUP, ____,
            KC_TRNS, KC_TRNS, KC_TRNS,              KC_SPC,                                      ____, ____, KC_HOME, KC_PGDN, KC_END
            ),
    [FKEYS] = LAYOUT_all(
            ____,    KC_F1,  KC_F2,  KC_F3,    KC_F4,  KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, KC_F11, KC_F12,  ____,    ____,
            KC_ASTG, KC_F13, KC_F14, KC_F15,   KC_F16, KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_F21,  KC_F22, KC_F23, KC_F24,  ____,
            ____,    ____,   ____,   ____,     ____,   ____,    ____,    ____,    ____,    ____,    ____,   ____,   ____,    ____,
            RESET,   _,      ____,   ____,     ____,   RGB_MOD, RGB_TOG, RGB_VAD, RGB_VAI, BL_TOGG, BL_DEC, BL_INC, KC_MUTE, KC_VOLU, KC_MPLY,
            ____,    ____,   ____,   TG(GAME), ____,   KC_TRNS, KC_MPRV, KC_VOLD, KC_MNXT
            ),
    [NUMPAD] = LAYOUT_all(
            KC_NLCK, KC_PSLS, KC_ASTR, KC_PEQL,     ____,       ____,    ____,       ____,       ____,     ____,    ____,       ____,   ____,    KC_BSPC, ____,
            KC_PMNS, KC_P7,   KC_P8,   KC_P9,       KC_BSPC,    ____,    ____,       ____,       ____,     ____,    ____,       ____,   ____,    ____,
            KC_PLUS, KC_P4,   KC_P5,   KC_P6,       KC_BSPC,    ____,    ____,       ____,       ____,     ____,    ____,       ____,   ____,    ____,
            KC_PENT, _, KC_P1,   KC_P2,  KC_P3,     KC_PDOT,    ____,    ____,       ____,     ____,    ____,       ____,   ____,    ____,    ____,
            ____,    ____,    KC_PDOT, KC_P0,       KC_TRNS,    ____,    ____,       ____,       ____
            )
};

void keyboard_post_init_user() {
    // Call the post init code.
    rgblight_enable_noeeprom();
    rgblight_mode_noeeprom(DEFAULT_RGB_MODE);
}

uint32_t layer_state_set_user(uint32_t state) {
    uint8_t layer = biton32(state);
    autoshift_disable();

    switch (layer) {
        case MOD1:
            rgblight_setrgb(RGB_ORANGE);
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
            break;

        case MOD2:
            rgblight_setrgb(RGB_PINK);
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
            break;

        case FKEYS:
            rgblight_setrgb(RGB_GREEN);
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
            break;

        case NUMPAD:
            rgblight_setrgb(RGB_CYAN);
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
            break;

        case GAME:
            rgblight_setrgb(RGB_RED);
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
            break;

        default:
            autoshift_enable();
            rgblight_mode_noeeprom(DEFAULT_RGB_MODE);
            break;
    }
    return state;
}
