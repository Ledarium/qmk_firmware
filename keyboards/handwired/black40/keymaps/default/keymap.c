#include QMK_KEYBOARD_H

#define _ KC_NO
#define ____ KC_NO

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

/* Default
 * ,-----------------------------------------------------------------------------------.
 * | `    |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  [   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[DEFAULT] = LAYOUT(
    KC_GRV,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    KC_LCTL, KC_LGUI, KC_LALT, RESET,   KC_ESC,  KC_SPC,  KC_SPC,  KC_SPC,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Numpad
 * ,-----------------------------------------------------------------------------------.
 * | Num  |   /  |   *  |   =  |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  _   |   7  |   8  |   9  |Backsp|      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  +   |   4  |   5  |   6  |Backsp|      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Enter|   1  |   2  |   3  |   .  |      0      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[NUMPAD] = LAYOUT(
    KC_NLCK, KC_PSLS, KC_ASTR, KC_PEQL, ____,    ____,    ____,    ____,    ____,    ____,    ____,    ____,
    KC_PMNS, KC_P7,   KC_P8,   KC_P9,   KC_BSPC, ____,    ____,    ____,    ____,    ____,    ____,    ____,
    KC_PLUS, KC_P4,   KC_P5,   KC_P6,   KC_BSPC, ____,    ____,    ____,    ____,    ____,    ____,    ____,
    KC_PENT, KC_P1,   KC_P2,   KC_P3,   KC_PDOT, ____,    ____,    ____,    ____,    ____,    ____,    ____
    )
};
