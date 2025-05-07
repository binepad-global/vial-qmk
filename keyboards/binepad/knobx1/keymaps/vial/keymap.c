// (c) 2024 Binepad (@binpad)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "knobx1.h" // need layer selection key
#include "double_tap.h"

#ifndef VIAL_PROTOCOL_VERSION
#    error "This keymap is only intended for Vial. Please use Vial-QMK."
#endif

enum {
    X1_MUTE = QK_KB_0, // Mute / Play (double tap)
    X1_LAYJ,           // Layer Jump Up / Down (double tap)
    X1_LAYU,           // Layer Up
    X1_LAYD            // Layer Down
} custom_keycodes_t;

// clang-format off
dt_keycodes_t double_tap_keycodes[] = {
    {.kcc = X1_MUTE, .kc1 = KC_MUTE, .kc2 = KC_MPLY},
    {.kcc = X1_LAYJ, .kc1 = X1_LYRU, .kc2 = X1_LYRD}
};
// clang-format on

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┐
     * │ L │ K │
     * └───┴───┘
     */
    [0] = LAYOUT(
        X1_LAYJ, X1_MUTE
    ),
    [1] = LAYOUT(
        _______, _______
    ),
    [2] = LAYOUT(
        _______, _______
    ),
    [3] = LAYOUT(
        _______, _______
    )
};
// clang-format on

#if defined(ENCODER_MAP_ENABLE)

// clang-format off
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [1] = { ENCODER_CCW_CW(_______, _______) },
    [2] = { ENCODER_CCW_CW(_______, _______) },
    [3] = { ENCODER_CCW_CW(_______, _______) }
};
// clang-format on

#endif

/* --- User overriden functions --- */

void matrix_init_user(void) {
    matrix_init_double_tap();
}

void matrix_scan_user(void) {
    matrix_scan_double_tap();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case X1_MUTE:
        case X1_LAYJ:
            return process_double_tap(keycode, record);

        case X1_LAYU:
            tap_code16(X1_LAYER_SELECTOR_UP);
            return false;

        case X1_LAYD:
            tap_code16(X1_LAYER_SELECTOR_DOWN);
            return false;
    }
    return true; // Process all other keycodes normally
}
