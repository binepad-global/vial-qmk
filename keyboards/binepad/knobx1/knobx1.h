/* (c) 2025 Binepad (@binpad) */
/* SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once

#include "quantum.h"

/*
 *      ╔═══════════╗
 *      ║ STM32F103 ║
 *  RGB ╢ PC13      ║
 *    × ╢ PC14      ║
 *    × ╢ PC15      ║
 *    × ╢ PB0   PA0 ╟ ×
 *    × ╢ PB1   PA1 ╟ ×
 *    × ╢ PB2   PA2 ╟ ×
 *    × ╢ PB3   PA3 ╟ ind4
 *    × ╢ PB4   PA4 ╟ ind3
 *    × ╢ PB5   PA5 ╟ ind2
 *    × ╢ PB6   PA6 ╟ ind1
 *    × ╢ PB7   PA7 ╟ col0 -> sw-push
 * row0 ╢ PB8   PA8 ╟ ×
 *    × ╢ PB9   PA9 ╟ ×
 *    × ╢ PB10 PA10 ╟ ×
 *    × ╢ PB11 PA11 ╟ usb D-
 * encA ╢ PB12 PA12 ╟ usb D+
 * encB ╢ PB13 PA13 ╟ swd
 *    × ╢ PB14 PA14 ╟ swc
 *    × ╢ PB15 PA15 ╟ col1 -> enc-sw
 *      ╚═══════════╝
 */

#define ROW0_PIN B8 // Building a 1x2 matrix makes no sense, setting the 1xCol to ground for direct pin access.

#define IND1_LED A6
#define IND2_LED A5
#define IND3_LED A4
#define IND4_LED A3

// clang-format off
enum x1_keycodes {
    X1_LAYER_SELECTOR = QK_KB_15
};
// clang-format on

#define X1_LAYER X1_LAYER_SELECTOR

// clang-format off
static inline void x1_led_1(bool on) { gpio_write_pin(IND1_LED, on); }
static inline void x1_led_2(bool on) { gpio_write_pin(IND2_LED, on); }
static inline void x1_led_3(bool on) { gpio_write_pin(IND3_LED, on); }
static inline void x1_led_4(bool on) { gpio_write_pin(IND4_LED, on); }
static inline void x1_led_1_on(void) { gpio_write_pin_high(IND1_LED); }
static inline void x1_led_2_on(void) { gpio_write_pin_high(IND2_LED); }
static inline void x1_led_3_on(void) { gpio_write_pin_high(IND3_LED); }
static inline void x1_led_4_on(void) { gpio_write_pin_high(IND4_LED); }
static inline void x1_led_1_off(void) { gpio_write_pin_low(IND1_LED); }
static inline void x1_led_2_off(void) { gpio_write_pin_low(IND2_LED); }
static inline void x1_led_3_off(void) { gpio_write_pin_low(IND3_LED); }
static inline void x1_led_4_off(void) { gpio_write_pin_low(IND4_LED); }
// clang-format on

static inline void x1_layer_led(uint8_t lyr) {
    gpio_write_pin(IND1_LED, lyr >= 0);
    gpio_write_pin(IND2_LED, lyr >= 1);
    gpio_write_pin(IND3_LED, lyr >= 2);
    gpio_write_pin(IND4_LED, lyr >= 3);
}
