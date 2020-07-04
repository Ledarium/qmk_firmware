#include QMK_KEYBOARD_H

#define _ KC_NO
#define ____ KC_NO
#define xxxx KC_TRNS

// Macro Declarations
enum my_keycodes {
    MACRO_1_8 = SAFE_RANGE,
};

enum {
    DEF = 0,
    MOD1,
    MOD2,
    MOD3,
    NUMPAD,
    GAME
};

enum {
    SPC_M1 = LT(MOD1, KC_SPC),
    ESC_M2 = LT(MOD2, KC_ESC),
    ENT_M3 = LT(MOD3, KC_ENT),
    LCTL_BS = MT(MOD_LCTL, KC_BSPC)
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
    case ESC_M2: {
      if (record->event.pressed) {
        tap_code16(C(KC_1));
      }
      break;
    }
    case KC_LALT: {
      if (record->event.pressed) {
        tap_code16(C(KC_1));
      }
      break;
    }
    default: return true;
  }
  return true;
};

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    switch (biton32(layer_state)) {
        case MOD1:
            clockwise ? tap_code(KC_TAB) : tap_code16(S(KC_TAB));
            break;
        case MOD2:
            clockwise ? tap_code(KC_DOWN) : tap_code16(KC_UP);
            break;
        case MOD3:
            if (keyboard_report->mods & MOD_BIT(KC_RSFT)) { // if rshift pressed
                clockwise ? tap_code(KC_MNXT) : tap_code(KC_MPRV);
            } else {
                clockwise ? tap_code(KC_VOLU) : tap_code(KC_VOLD);
            }
            break;
        default:
            clockwise ? tap_code(KC_PGDN) : tap_code(KC_PGUP);
            break;
    }
}
#endif // ENCODER_ENABLE

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[DEF] = LAYOUT(
KC_GRV,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,   KC_I,    KC_O,    KC_P,    KC_LBRC,
KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT,
KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC,
LCTL_BS, KC_LGUI, KC_DEL,  KC_LALT, ESC_M2,     SPC_M1, _,     ENT_M3, C(KC_2), KC_RBRC, KC_BSLS, KC_RCTL
),

[MOD1] = LAYOUT(
KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_RBRC,
KC_MINS, KC_LBRC, KC_RBRC, KC_AT,   KC_HASH, KC_AMPR, KC_EXLM, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, MACRO_1_8,
KC_LPRN, KC_LCBR, KC_RCBR, KC_DLR,  KC_PERC, KC_CIRC, KC_EQL,  KC_UNDS, KC_PLUS, xxxx,    KC_ASTR, KC_RPRN,
xxxx,    KC_LGUI, ____,    xxxx,    ____,    xxxx,    xxxx,    ____,    C(KC_1), ____,    ____,    KC_RCTL
),

[MOD2] = LAYOUT(
KC_F12,  KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7,   KC_F8,   KC_F9,   KC_F10, KC_F11,
____,    ____,  ____,  ____,  ____,  ____,  ____,  KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_PAUS,
KC_PSCR, ____,  ____,  ____,  ____,  ____,  ____,  ____,    ____,    ____,    ____,   ____,
xxxx,    ____,  RESET, ____,  xxxx,  ____,  ____,  ____,    ____,    ____,    ____,   KC_RCTL
),

[MOD3] = LAYOUT(
____,    G(KC_1), G(KC_2), G(KC_3), G(KC_4), ____,   ____,    ____,         ____, ____, ____,      ____,
____,    ____,    ____,    ____,    ____,    ____,   ____,    A(S(KC_TAB)), ____, ____, A(KC_TAB), ____,
____,    ____,    ____,    ____,    ____,    ____,   ____,    C(S(KC_TAB)), ____, ____, C(KC_TAB), ____,
xxxx,    ____,    ____,    ____,    ____,        ____, _,     xxxx,         TG(GAME), ____, ____,      KC_MUTE
),

[NUMPAD] = LAYOUT(
KC_NLCK, KC_PSLS, KC_ASTR, KC_PEQL, ____,    ____,    ____,    ____,    ____,    ____,    ____,    ____,
KC_PMNS, KC_P7,   KC_P8,   KC_P9,   KC_BSPC, ____,    ____,    ____,    ____,    ____,    ____,    ____,
KC_PLUS, KC_P4,   KC_P5,   KC_P6,   KC_BSPC, ____,    ____,    ____,    ____,    ____,    ____,    ____,
KC_PENT, KC_P1,   KC_P2,   KC_P3,   KC_PDOT, ____,    ____,    ____,    ____,    ____,    ____,    ____
),

[GAME] = LAYOUT(
KC_GRV,  KC_3,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
KC_TAB,  KC_4,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
KC_1,    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
KC_2,    KC_LCTL, KC_DEL,  KC_LALT, KC_ESC,    KC_SPC, _,      KC_ENT,  TG(GAME), KC_RBRC, KC_BSLS, KC_RCTL
)
};

