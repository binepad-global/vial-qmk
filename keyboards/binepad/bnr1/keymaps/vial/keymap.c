/* Copyright 2022 Binepad (@binpad) */
/* SPDX-License-Identifier: GPL-2.0-or-later */

#include QMK_KEYBOARD_H

#ifndef VIAL_PROTOCOL_VERSION
#    error "Hey! This is for Vial only! Stop it. Get some help."
#endif

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ortho_1x1(
        LT(1, KC_SPC)
    ),

    [1] = LAYOUT_ortho_1x1(
        _______
    )
};
// clang-format on

#if defined(ENCODER_MAP_ENABLE)

// clang-format off
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_DOWN, KC_UP) },
    [1] = { ENCODER_CCW_CW(KC_RGHT, KC_LEFT) }
};
// clang-format on

#endif
