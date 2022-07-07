#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
         KC_7,    KC_8,     KC_9,
         KC_4,    KC_5,     KC_6,
         KC_1,    KC_2,     KC_3
    ),
    [1] = LAYOUT(
         KC_TRANS, KC_TRANS, KC_TRANS,
         KC_TRANS, KC_TRANS, KC_TRANS,
         KC_TRANS, KC_TRANS, KC_TRANS
    ),
    [2] = LAYOUT(
         KC_TRANS, KC_TRANS, KC_TRANS,
         KC_TRANS, KC_TRANS, KC_TRANS,
         KC_TRANS, KC_TRANS, KC_TRANS
    ),
    [3] = LAYOUT(
         KC_TRANS, KC_TRANS, KC_TRANS,
         KC_TRANS, KC_TRANS, KC_TRANS,
         KC_TRANS, KC_TRANS, KC_TRANS
    )
};


bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) { /* Second encoder */
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return false;
}