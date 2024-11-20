#include QMK_KEYBOARD_H

// 定义层
enum layer_names {
    BASE,
    FN
};

// 定义自定义键码
enum custom_keycodes {
    CUSTOM_1 = SAFE_RANGE,
    CUSTOM_2
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = LAYOUT_60_ansi(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT, MO(FN),  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, KC_RGUI, KC_APP,  KC_RCTL
),
[FN] = LAYOUT_60_ansi(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        _______, KC_MPLY, KC_MPRV, KC_MNXT, KC_CALC, _______, _______, _______, KC_INS,  KC_HOME, KC_PGUP, KC_PSCR, _______, KC_PAUS,
        _______, KC_VOLD, KC_VOLU, KC_MUTE, CUSTOM_1,CUSTOM_2,_______, _______, _______, KC_END,  KC_PGDN, _______,          _______,
        _______, _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______,          _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______
)
};

led_config_t g_led_config = { {
                                      // 键矩阵到LED索引的映射
    { 0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13 },
    { 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27 },
    { 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, NO_LED, 40 },
    { 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, NO_LED, 53 },
    { 54, 55, 56, NO_LED, NO_LED, 57, NO_LED, NO_LED, 58, 59, 60, 61 }
    }, {
    // LED索引到物理位置的映射
    {  0,  0 }, { 16,  0 }, { 32,  0 }, { 48,  0 }, { 64,  0 }, { 80,  0 }, { 96,   0 }, { 112,  0 }, { 128,  0 }, { 144,  0 }, { 160,  0 }, { 176,  0 }, { 192,  0 }, { 208,  0 },
    {  0, 16 }, { 16, 16 }, { 32, 16 }, { 48, 16 }, { 64, 16 }, { 80, 16 }, { 96,  16 }, { 112, 16 }, { 128, 16 }, { 144, 16 }, { 160, 16 }, { 176, 16 }, { 192, 16 }, { 208, 16 },
    {  0, 32 }, { 16, 32 }, { 32, 32 }, { 48, 32 }, { 64, 32 }, { 80, 32 }, { 96,  32 }, { 112, 32 }, { 128, 32 }, { 144, 32 }, { 160, 32 }, { 176, 32 }, { 208, 32 },
    {  0, 48 }, { 16, 48 }, { 32, 48 }, { 48, 48 }, { 64, 48 }, { 80, 48 }, { 96,  48 }, { 112, 48 }, { 128, 48 }, { 144, 48 }, { 160, 48 }, { 176, 48 }, { 208, 48 },
    {  0, 64 }, { 16, 64 }, { 32, 64 }, { 96, 64 }, { 160, 64 }, { 176, 64 }, { 192, 64 }, { 208, 64 }
    }, {
    // LED索引到标志的映射
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,    4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,    4,
    4, 4, 4,          4,          4, 4, 4, 4
} };

// 可以在这里添加其他自定义函数或配置

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CUSTOM_1:
            if (record->event.pressed) {
                // 当CUSTOM_1被按下时执行的代码
            }
            return false;
        case CUSTOM_2:
            if (record->event.pressed) {
                // 当CUSTOM_2被按下时执行的代码
            }
            return false;
        default:
            return true;
    }
}
