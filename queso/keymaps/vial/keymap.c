/* SPDX-License-Identifier: GPL-2.0-or-later */

#include QMK_KEYBOARD_H

#include "print.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,      KC_INS,  KC_HOME, KC_PGUP,   KC_7, KC_8, KC_9,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_ENT,    KC_DEL,  KC_END,  KC_PGDN,   KC_4, KC_5, KC_6,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,             KC_BSLS, KC_UP,   KC_SLSH,   KC_1, KC_2, KC_3,
    KC_LCTL, KC_LALT,      MO(1),   KC_SPC,  KC_SPC,  KC_SPC,  MO(2),       KC_RGUI, MO(3),     KC_LEFT, KC_DOWN, KC_RGHT,   KC_0, KC_MINUS, KC_DOT
    ),

    [1] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,            KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [2] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,            KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [3] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,            KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS
    )

};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] =   { ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO) },
    [1] =   { ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO) },
    [2] =   { ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO) },
    [3] =   { ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO) }
};
#endif


// dynamic_keymap_set_encoder(uint8_t layer, uint8_t encoder_id, bool clockwise, uint16_t keycode);
// dynamic_keymap_set_keycode(uint8_t layer, uint8_t row, uint8_t column, uint16_t keycode);

bool a_enc;
bool b_enc;

void via_set_layout_options_kb(uint32_t value) {

    bool a_enc_new = (value & 0x30) == 0x10;
    bool b_enc_new = (value & 0xC) == 0x4;

    uprintf("A enc %d, A enc NEW %d, B enc %d, B enc NEW %d, layout %ld \n", a_enc, a_enc_new, b_enc, b_enc_new, value);

    for (int i = 0; i < dynamic_keymap_get_layer_count(); i++){
        if (a_enc != a_enc_new){
            a_enc = a_enc_new;
            if (a_enc){
                dynamic_keymap_set_encoder(i, 0, 0, dynamic_keymap_get_keycode(i, 6, 0));
                dynamic_keymap_set_encoder(i, 0, 1, dynamic_keymap_get_keycode(i, 6, 2));
                dynamic_keymap_set_keycode(i, 6, 0, KC_NO);
                dynamic_keymap_set_keycode(i, 6, 2, KC_NO);
                print("add encoder A \n");
            } else {
                dynamic_keymap_set_keycode(i, 6, 0, dynamic_keymap_get_encoder(i, 0, 0));
                dynamic_keymap_set_keycode(i, 6, 2, dynamic_keymap_get_encoder(i, 0, 1));
                dynamic_keymap_set_encoder(i, 0, 0, KC_NO);
                dynamic_keymap_set_encoder(i, 0, 1, KC_NO);
                print("rem encoder A \n");
            }
        }
        if (b_enc != b_enc_new){
            b_enc = b_enc_new;
            if (b_enc){
                dynamic_keymap_set_encoder(i, 1, 0, dynamic_keymap_get_keycode(i, 6, 3));
                dynamic_keymap_set_encoder(i, 1, 1, dynamic_keymap_get_keycode(i, 6, 5));
                dynamic_keymap_set_keycode(i, 6, 3, KC_NO);
                dynamic_keymap_set_keycode(i, 6, 5, KC_NO);
                print("add encoder B \n");
            } else {
                dynamic_keymap_set_keycode(i, 6, 3, dynamic_keymap_get_encoder(i, 1, 0));
                dynamic_keymap_set_keycode(i, 6, 5, dynamic_keymap_get_encoder(i, 1, 1));
                dynamic_keymap_set_encoder(i, 1, 0, KC_NO);
                dynamic_keymap_set_encoder(i, 1, 1, KC_NO);
                print("rem encoder B \n");
            }
        }
    }

}


void via_init_kb(void) {
    a_enc = (via_get_layout_options() & 0x30) == 0x10;
    b_enc = (via_get_layout_options() & 0xC) == 0x4;
    uprintf("A enc %d, B enc %d, layout %ld \n", a_enc, b_enc, via_get_layout_options());
}
