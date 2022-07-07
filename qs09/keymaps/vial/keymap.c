#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
         KC_7,    KC_8,     KC_9,
         KC_4,    KC_5,     KC_6,
         KC_1,    KC_2,     KC_3
    ),
    [1] = LAYOUT(
         _______, _______, _______,
         _______, _______, _______,
         _______, _______, _______
    ),
    [2] = LAYOUT(
         _______, _______, _______,
         _______, _______, _______,
         _______, _______, _______
    ),
    [3] = LAYOUT(
         _______, _______, _______,
         _______, _______, _______,
         _______, _______, _______
    )
};
