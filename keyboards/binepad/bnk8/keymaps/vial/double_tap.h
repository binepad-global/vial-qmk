// Copyright 2025 Silvino R. (@silvinor)
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include "quantum.h"
#include "keycodes.h"

// clang-format off
typedef struct {
    uint16_t kcc;
    uint16_t kc1;
    uint16_t kc2;
    uint8_t tap_count;
    timer_t tap_time;
    bool active : 1;
} dt_keycodes_t;
// clang-format on

extern dt_keycodes_t double_tap_keycodes[];

void matrix_init_double_tap(void);
void matrix_scan_double_tap(void);
bool process_double_tap(uint16_t keycode, keyrecord_t *record);
