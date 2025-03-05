// (c) 2024 Binepad (@binpad)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "x1.h"  // need layer selection key

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┐
     * │ L │ K │
     * └───┴───┘
     */
    [0] = LAYOUT(
        X1_LAYER, KC_MUTE
    ),
    [1] = LAYOUT(
        _______, _______
    ),
    [2] = LAYOUT(
        _______, _______
    ),
    [3] = LAYOUT(
        _______, _______
    ),
    [4] = LAYOUT(
        _______, _______
    )
};

#if defined(ENCODER_MAP_ENABLE)

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [1] = { ENCODER_CCW_CW(_______, _______) },
    [2] = { ENCODER_CCW_CW(_______, _______) },
    [3] = { ENCODER_CCW_CW(_______, _______) },
    [4] = { ENCODER_CCW_CW(_______, _______) }
};

#endif
