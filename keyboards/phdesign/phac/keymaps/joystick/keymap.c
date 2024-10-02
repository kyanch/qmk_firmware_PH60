// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layer_names {
    _BL,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BL] = LAYOUT(
                    JS_8,
        JS_0,   JS_1,   JS_2,   JS_3,
            JS_4,           JS_5
    )
};

static int16_t x_axis_reg = 0;
static int16_t y_axis_reg = 0;

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            //global x_axis_reg;
            x_axis_reg = x_axis_reg - 8;
            if (x_axis_reg < -127) {
                x_axis_reg = 127;
            };
            joystick_set_axis(1, x_axis_reg);
        } else {
            //global x_axis_reg;
            x_axis_reg = x_axis_reg + 8;
            if (x_axis_reg > 127) {
                x_axis_reg = -127;
            };
            joystick_set_axis(1, x_axis_reg);
        }
    } else if (index == 1) { /* Second encoder */
        if (clockwise) {
            //global y_axis_reg;
            y_axis_reg = y_axis_reg - 8;
            if (y_axis_reg < -127) {
                y_axis_reg = 127;
            };
            joystick_set_axis(0, y_axis_reg);
        } else {
            //global y_axis_reg;
            y_axis_reg = y_axis_reg + 8;
            if (y_axis_reg > 127) {
                y_axis_reg = -127;
            };
            joystick_set_axis(0, y_axis_reg);
        }
    }
    return false;
};

joystick_config_t joystick_axes[JOYSTICK_AXIS_COUNT] = {
    JOYSTICK_AXIS_VIRTUAL, // x
    JOYSTICK_AXIS_VIRTUAL  // y
};