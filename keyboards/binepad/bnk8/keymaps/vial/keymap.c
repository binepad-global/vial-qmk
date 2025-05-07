// Copyright 2023 Binepad (@binpad)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "double_tap.h"

#ifndef VIAL_PROTOCOL_VERSION
#    error "This keymap is only intended for VIAL. Please use VIAL-QMK."
#endif

#ifndef DOUBLE_TAP_TERM
#    ifdef TAPPING_TERM
#        define DOUBLE_TAP_TERM TAPPING_TERM
#    else
#        define DOUBLE_TAP_TERM 200
#    endif
#endif

dt_keycodes_t double_tap_keycodes[] = {
    {.kcc = QK_KB_0,
     .kc1 = KC_MUTE,
     .kc2 = KC_MPLY}
};

/* --- User overriden functions --- */

void matrix_init_user(void) {
    matrix_init_double_tap();
}

void matrix_scan_user(void) {
    matrix_scan_double_tap();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QK_KB_0:
            return process_double_tap(keycode, record);
            break;
    }
    return true; // Process all other keycodes normally
}
