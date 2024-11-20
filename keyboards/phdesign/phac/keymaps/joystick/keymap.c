// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layer_names {
    _BL,
};

//QMK support HID controller,that's enough for SDVX
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BL] = LAYOUT(
                JS_8,  // Start button
    JS_0,   JS_1,   JS_2,   JS_3,  // A, B, X, Y buttons
        JS_4,           JS_5       // LB, RB buttons
    )
};

static int16_t x_axis_reg = 0;
static int16_t y_axis_reg = 0;

#ifndef ENCODER_STEPS
    #define ENCODER_STEPS 20
#endif

#ifndef AXIS_RANGE
    #define AXIS_RANGE 127
#endif

#define STEP_INCREMENT (2 * AXIS_RANGE / ENCODER_STEPS)

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder - Left side */
        if (clockwise) {
            x_axis_reg = x_axis_reg + STEP_INCREMENT;
            if (x_axis_reg > AXIS_RANGE) {
                x_axis_reg = -AXIS_RANGE; // Wrap around to the left
            }
            joystick_set_axis(0, x_axis_reg);
        } else {
            x_axis_reg = x_axis_reg - STEP_INCREMENT;
            if (x_axis_reg < -AXIS_RANGE) {
                x_axis_reg = AXIS_RANGE; // Wrap around to the right
            }
            joystick_set_axis(0, x_axis_reg);
        }
    } else if (index == 1) { /* Second encoder - Right side */
        if (clockwise) {
            y_axis_reg = y_axis_reg + STEP_INCREMENT;
            if (y_axis_reg > AXIS_RANGE) {
                y_axis_reg = -AXIS_RANGE; // Wrap around to the bottom
            }
            joystick_set_axis(1, y_axis_reg);
        } else {
            y_axis_reg = y_axis_reg - STEP_INCREMENT;
            if (y_axis_reg < -AXIS_RANGE) {
                y_axis_reg = AXIS_RANGE; // Wrap around to the top
            }
            joystick_set_axis(1, y_axis_reg);
        }
    }
    return false;
}

joystick_config_t joystick_axes[JOYSTICK_AXIS_COUNT] = {
        JOYSTICK_AXIS_VIRTUAL, // x
        JOYSTICK_AXIS_VIRTUAL  // y
};
