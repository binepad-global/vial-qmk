// (c) 2025 Binepad (@binpad)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "v3.h"

void matrix_init_kb(void) {
    // Direct PINS use; gpio -> switch -> ground.
    // Setting Row 0 to ground makes it work like a direct pin
    gpio_set_pin_output(ROW0_PIN); // Set Col0 as an output
    gpio_write_pin_low(ROW0_PIN);  // Set Col0 to low / ground

    matrix_init_user();
}
