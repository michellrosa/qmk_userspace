#include QMK_KEYBOARD_H

#include "custom_keycodes.h"
#include "custom_mouse_keymap.h"
#include "faker_layout.h"
#include "mouse_manipulation.h"

// Shift on Hold, Enter on Tap
#define SHENT SFT_T(KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
#if 0
    [0] = LAYOUT_faker(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_DEL,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,          KC_BSLS,
        CW_TOGG, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,           KC_ENT,
        KC_LSFT, SHENT,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_INS,
        KC_LCTL, KC_LGUI, KC_LALT,          LT(1, KC_SPC),             LT(1, KC_SPC),             KC_RALT, KC_APP,           KC_RCTL, KC_RGUI
    ),
#else
    [0] = LAYOUT_60_ansi_split_bs_rshift_space(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_DEL,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,          KC_BSLS,
        CW_TOGG, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,           KC_ENT,
        KC_LSFT, SHENT,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_NO,   KC_RSFT, KC_INS,
        KC_LCTL, KC_LGUI, KC_LALT,          LT(1, KC_SPC),             LT(1, KC_SPC),    KC_NO,   KC_RALT, KC_APP,  KC_NO,   KC_RCTL, KC_RGUI
    ),
#endif
    [1] = LAYOUT_faker(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______,
        _______, _______, KC_UP,   _______, KC_PGUP, _______, _______, KC_HOME, KC_END,  _______, _______, _______, _______,          _______,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, _______,          _______,
        _______, _______, _______, KC_DEL,  _______, _______, _______, _______, _______, _______, _______, _______,          _______, TG(2),
        _______, _______, _______,          _______,                   _______,                   _______, _______,          _______, _______
    ),
    [2] = MOUSE_LAYER,
#if 0
    [x] = LAYOUT_faker(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______, _______, _______,          _______,                   _______,                   _______, _______,          _______, _______
    ),
#endif
};

void keyboard_post_init_user(void) {
    rgblight_disable_noeeprom();
    // Customise these values to desired behaviour
    debug_enable=true;
    //debug_matrix=true;
    //debug_keyboard=true;
    //debug_mouse=true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (layer_state_is(2)) { // Restrict processing for layer 2 active.
        return process_record_user_mouse_manipulation(keycode, record);
    }
    return true; // Process keycodes normally
}
