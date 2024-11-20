// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layer_names {
    _BL,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BL] = LAYOUT(
        KC_B,
        KC_D,   KC_F,   KC_J,   KC_K,
        KC_N,           KC_M
)
};

// 全局变量来跟踪鼠标移动的步进和加速
static int8_t mouse_speed = 1;
static int8_t max_speed = 10;

bool encoder_update_user(uint8_t index, bool clockwise) {
    // 如果有多个编码器，你可以用 index 来区分
    if (index == 0) {
        if (clockwise) {
            if (mouse_speed < 5) {
                mouse_speed = 5;  // 慢速旋转时，设置为较大速度以防止丢失
            } else {
                mouse_speed = max_speed;  // 快速旋转时，设置为最大速度
            }
            tap_code16(QK_MOUSE_CURSOR_RIGHT);
        } else {
            if (mouse_speed < 5) {
                mouse_speed = 5;  // 慢速旋转时，设置为较大速度以防止丢失
            } else {
                mouse_speed = max_speed;  // 快速旋转时，设置为最大速度
            }
            tap_code16(QK_MOUSE_CURSOR_LEFT);
        }
    } else if (index == 1) {
        if (clockwise) {
            if (mouse_speed < 5) {
                mouse_speed = 5;  // 慢速旋转时，设置为较大速度以防止丢失
            } else {
                mouse_speed = max_speed;  // 快速旋转时，设置为最大速度
            }
            tap_code16(QK_MOUSE_CURSOR_DOWN);
        } else {
            if (mouse_speed < 5) {
                mouse_speed = 5;  // 慢速旋转时，设置为较大速度以防止丢失
            } else {
                mouse_speed = max_speed;  // 快速旋转时，设置为最大速度
            }
            tap_code16(QK_MOUSE_CURSOR_UP);
        }
    }
    wait_ms(100 / mouse_speed);  // 根据速度控制移动的间隔时间，速度越高间隔越短
    return true;
}

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BL] = { ENCODER_CCW_CW(QK_MOUSE_CURSOR_UP, QK_MOUSE_CURSOR_DOWN),  ENCODER_CCW_CW(QK_MOUSE_CURSOR_LEFT, QK_MOUSE_CURSOR_RIGHT)  },
};
#endif
