#include QMK_KEYBOARD_H

#define _ KC_NO
#define ____ KC_NO
#define xxxx KC_TRNS

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
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Shift |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |  ]   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Ctrl/↼|  GUI | Alt  |      |Esc/M2|   Space/M1  | Enter| EN(*)| RU(+)|      |  Del |
 * `-----------------------------------------------------------------------------------'
 */
[DEFAULT] = LAYOUT(
    KC_GRV,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RBRC,
    LCTL_BS, KC_LGUI, ____,    KC_LALT, ESC_MOD, SPC_MOD, ____,    KC_ENT,  KC_PAST, KC_PPLS, KC_BSLS, KC_DEL
),

/* MOD1
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  1-8 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   -  |   [  |   ]  |   @  |   #  |   &  |   !  |   🠜  |   🠟  |   🠝  |   🠞  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   (  |   {  |   }  |   $  |   %  |   ^  |   =  |   _  |   +  |   .  |   *  |   )  |
 * |-----------------------------------------------------------------------------------|
 * | xxxx |   🔉 |   🔊 |   🔇 |   ■  |   xxxxxxx   |   ⏮  |   ►  |   ⏭  | Mail | Home |
 * `-----------------------------------------------------------------------------------'
 */

[MOD1] = LAYOUT(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    MACRO_1_8,
    KC_MINS, KC_LBRC, KC_RBRC, KC_AT,   KC_HASH, KC_AMPR, KC_EXLM, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, ____,
    KC_LPRN, KC_LCBR, KC_RCBR, KC_DLR,  KC_PERC, KC_CIRC, KC_EQL,  KC_UNDS, KC_PLUS, xxxx,    KC_ASTR, KC_RPRN,
    xxxx,    KC_VOLD, KC_VOLU, KC_MUTE, KC_MSTP, xxxx,    xxxx,    KC_MPRV, KC_MPLY, KC_MNXT, KC_MAIL, KC_WHOM
),

/* MOD2
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | Home | PgDn | PgUp |  End | Pause|
 * |-----------------------------------------------------------------------------------|
 * |PrntSc|      |      |      |      |      |      |      |      |      |      |      |
 * |-----------------------------------------------------------------------------------|
 * |      |      |      |      | xxxx |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

[MOD2] = LAYOUT(
    KC_F1,   KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8,   KC_F9,   KC_F10,  KC_F11, KC_F12,
    ____,    ____,  ____,  ____,  ____,  ____,  ____,  KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_PAUS,
    KC_PSCR, ____,  ____,  ____,  ____,  ____,  ____,  ____,    ____,    ____,    ____,   ____,
    ____,    ____,  RESET, ____,  xxxx,  ____,  ____,  ____,    ____,    ____,    ____,   ____
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
