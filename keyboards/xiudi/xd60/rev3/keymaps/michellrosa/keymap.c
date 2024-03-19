#include QMK_KEYBOARD_H

#include "digitizer.h"
#include "keycodes.h"
#include "custom_mouse_keymap.h"

// Shift on Hold, Enter on Tap
#define SHENT SFT_T(KC_ENT)

#define EXIT_MOUSE_MODE TG(2)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_60_ansi_split_bs_rshift_space(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_DEL,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,          KC_BSLS,
        CW_TOGG, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,           KC_ENT,
        KC_LSFT, SHENT,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_RSFT, KC_INS,
        KC_LCTL, KC_LGUI, KC_LALT,          LT(1, KC_SPC),             LT(1, KC_SPC),    KC_NO,   KC_RALT, KC_APP,  KC_NO,   KC_RCTL, KC_RGUI
    ),
    [1] = LAYOUT_60_ansi_split_bs_rshift_space(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______,
        _______, _______, KC_UP,   _______, KC_PGUP, _______, _______, KC_HOME, KC_END,  _______, _______, _______, _______,          _______,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, _______,          _______,
        _______, _______, _______, KC_DEL,  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_UP,   TG(2),
        _______, _______, _______,          _______,                   _______,          KC_NO  , _______, KC_LEFT, KC_NO  , KC_DOWN, KC_RGHT
    ),
#if 0
    [2] = LAYOUT_60_ansi_split_bs_rshift_space(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, TG(2),
        _______, _______, _______,          _______,                   _______,          KC_NO  , _______, _______, KC_NO  , _______, _______
    ),
#else
    [2] = MOUSE_LAYER,
#endif
#if 0
    [x] = LAYOUT_60_ansi_split_bs_rshift_space(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,          _______,                   _______,          KC_NO  , _______, _______, KC_NO  , _______, _______
    ),
#endif
};

void keyboard_post_init_user(void) {
    rgblight_disable_noeeprom();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (layer_state_is(2)) {
        float x = 1;
        float y = 0;
        switch (keycode) {
            case KC_Q:
            case KC_A:
            case KC_Z:
                x -= 0.1;
            case KC_W:
            case KC_S:
            case KC_X:
                x -= 0.1;
            case KC_E:
            case KC_D:
            case KC_C:
                x -= 0.1;
            case KC_R:
            case KC_F:
            case KC_V:
                x -= 0.1;
            case KC_T:
            case KC_G:
            case KC_B:
                x -= 0.1;
            case KC_Y:
            case KC_H:
            case KC_N:
                x -= 0.1;
            case KC_U:
            case KC_J:
            case KC_M:
                x -= 0.1;
            case KC_I:
            case KC_K:
            case KC_COMM:
                x -= 0.1;
            case KC_O:
            case KC_L:
            case KC_DOT:
                x -= 0.1;
            case KC_P:
            case KC_SCLN:
            case KC_SLSH:
                x -= 0.1;
                break;
            default:
                return true; // Process all other keycodes normally
        }
#if 1
        bool ismousekeypressed = getYposition(keycode, &y, 0);
        if (!ismousekeypressed) {
            return true; // Process all other keycodes normally
        }
#else
        switch (keycode) {
            case KC_Q:
            case KC_W:
            case KC_E:
            case KC_R:
            case KC_T:
            case KC_Y:
            case KC_U:
            case KC_I:
            case KC_O:
            case KC_P:
                y += 0.1;
            case KC_A:
            case KC_S:
            case KC_D:
            case KC_F:
            case KC_G:
            case KC_H:
            case KC_J:
            case KC_K:
            case KC_L:
            case KC_SCLN:
                y += 0.1;
            case KC_Z:
            case KC_X:
            case KC_C:
            case KC_V:
            case KC_B:
            case KC_N:
            case KC_M:
            case KC_COMM:
            case KC_DOT:
            case KC_SLSH:
                y += 0.1;
                break;
            default:
                return true; // Process all other keycodes normally
        }
#endif
        if (record->event.pressed) { // Do something when pressed
            digitizer_in_range_on();
            digitizer_set_position(x, y);
        }
        return false; // Skip all further processing of this key
    }
    return true; // Process keycodes normally
}
