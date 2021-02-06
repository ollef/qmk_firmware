#include QMK_KEYBOARD_H

const keypos_t hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
    /* Left hand, matrix positions */
    {{5, 6}, {4, 6}, {3, 6}, {2, 6}, {1, 6}, {0, 6}},
    {{5, 7}, {4, 7}, {3, 7}, {2, 7}, {1, 7}, {0, 7}},
    {{5, 8}, {4, 8}, {3, 8}, {2, 8}, {1, 8}, {0, 8}},
    {{5, 9}, {4, 9}, {3, 9}, {2, 9}, {1, 9}, {0, 9}},
    {{5, 10}, {4, 10}, {3, 10}, {2, 10}, {1, 10}, {0, 10}},
    {{5, 11}, {4, 11}, {3, 11}, {2, 11}, {1, 11}, {0, 11}},
    /* Right hand, matrix positions */
    {{5, 0}, {4, 0}, {3, 0}, {2, 0}, {1, 0}, {0, 0}},
    {{5, 1}, {4, 1}, {3, 1}, {2, 1}, {1, 1}, {0, 1}},
    {{5, 2}, {4, 2}, {3, 2}, {2, 2}, {1, 2}, {0, 2}},
    {{5, 3}, {4, 3}, {3, 3}, {2, 3}, {1, 3}, {0, 3}},
    {{5, 4}, {4, 4}, {3, 4}, {2, 4}, {1, 4}, {0, 4}},
    {{5, 5}, {4, 5}, {3, 5}, {2, 5}, {1, 5}, {0, 5}}
};

enum custom_keycodes {
    BSPC_DEL = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case BSPC_DEL: {
            static uint16_t pressed_keycode = KC_NO;
            if (record->event.pressed) {
                uint8_t mods = get_mods();
                pressed_keycode = KC_BSPC;
                if (mods & (MOD_MASK_SHIFT | MOD_MASK_CTRL)) {
                    clear_mods();
                    pressed_keycode = KC_DEL;
                }
                register_code(pressed_keycode);
                set_mods(mods);
            }
            else {
                unregister_code(pressed_keycode);
            }
            return false;
        }
    }
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_5x6_5(
        KC_GRV,          KC_1,      KC_2,           KC_3,    KC_4,  KC_5,                KC_6,   KC_7,   KC_8,     KC_9,            KC_0,    KC_MINS,
        KC_TAB,          KC_Q,      KC_W,           KC_E,    KC_R,  KC_T,                KC_Y,   KC_U,   KC_I,     KC_O,            KC_P,    KC_LBRC,
        KC_ESC,          KC_A,      KC_S,           KC_D,    KC_F,  KC_G,                KC_H,   KC_J,   KC_K,     KC_L,            KC_SCLN, KC_QUOT,
        KC_LSPO,         KC_Z,      KC_X,           KC_C,    KC_V,  KC_B,                KC_N,   KC_M,   KC_COMM,  KC_DOT,          KC_SLSH, KC_RSPC,
                         LALT_T(KC_LBRC), KC_BSLASH, KC_APPLICATION, KC_LCTL, MO(1),     BSPC_DEL,  KC_SPC, KC_ENT, KC_EQUAL, RALT_T(KC_RBRC),
                                                               KC_LGUI, SH_OS,           SH_OS,  KC_RGUI

  ),
    [1] = LAYOUT_5x6_5(
        KC_F12, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
        _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______,
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5,                     KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS,
        _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______,
                                            _______, _______,     _______, _______
    )
};
