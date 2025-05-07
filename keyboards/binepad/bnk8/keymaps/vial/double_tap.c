// Copyright 2025 Silvino R. (@silvinor)
// SPDX-License-Identifier: GPL-3.0-or-later

#include "double_tap.h"

#ifndef DOUBLE_TAP_TERM
#    ifdef TAPPING_TERM
#        define DOUBLE_TAP_TERM TAPPING_TERM
#    else
#        define DOUBLE_TAP_TERM 200
#    endif
#endif

#ifndef DOUBLE_TAP_KEY_COUNT
#    error "Please define DOUBLE_TAP_KEY_COUNT in config.h"
#endif

void matrix_init_double_tap(void) {
    // make doubly sure the struct is zeroed. may not be needed?
    for (uint8_t i = 0; i < DOUBLE_TAP_KEY_COUNT; ++i) {
        dt_keycodes_t *current = &double_tap_keycodes[i];
        current->tap_count     = 0;
        current->tap_time      = 0;
        current->active        = false;
    }
}

void matrix_scan_double_tap(void) {
    for (uint8_t i = 0; i < DOUBLE_TAP_KEY_COUNT; ++i) {
        dt_keycodes_t *current = &double_tap_keycodes[i];

        if (current->active && (timer_elapsed(current->tap_time) > DOUBLE_TAP_TERM)) {
            if (current->tap_count == 1) {
                tap_code(current->kc1);
            } else if (current->tap_count >= 2) {
                tap_code(current->kc2);
            }
            current->active    = false;
            current->tap_count = 0;
        }
    }
}

bool process_double_tap(uint16_t keycode, keyrecord_t *record) {
    for (uint8_t i = 0; i < DOUBLE_TAP_KEY_COUNT; ++i) {
        dt_keycodes_t *current = &double_tap_keycodes[i];

        // is this the one we're interested in?
        if (keycode == current->kcc) {
            if (record->event.pressed) {
                // first press?
                if (!current->active) {
                    current->active    = true;
                    current->tap_count = 1;
                    current->tap_time  = timer_read();
                } else {
                    current->tap_count++;
                }
            }
            return true; // Matched & handled
        }
    }
    return false;
}
