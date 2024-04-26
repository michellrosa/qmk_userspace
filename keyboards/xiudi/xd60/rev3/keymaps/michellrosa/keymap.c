#include QMK_KEYBOARD_H

#include "custom_keycodes.h"
#include "custom_mouse_keymap.h"
#include "faker_layout.h"
#include "mouse_manipulation.h"
#include "keymap_brazilian_abnt2.h"

// Shift on Hold, Enter on Tap
#define FK_SENT SFT_T(KC_ENT) // SC_SENT

enum keyboard_layers {
  _USL = 0, // Base Layer Ansii
  _BRL,     // Base Layer ABNT2
  _FL,       // Function Layer
  _ML,       // Mouse Layer
};

#define _BL _USL

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
#if 0
    [_USL] = LAYOUT_faker(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_DEL,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,          KC_BSLS,
        CW_TOGG, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,           KC_ENT,
        KC_LSFT, FK_SENT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_INS,
        KC_LCTL, KC_LGUI, KC_LALT,        LT(_FL, KC_SPC),           LT(_FL, KC_SPC),             KC_RALT, KC_APP,           KC_RCTL, KC_RGUI
    ),
#else
    [_USL] = LAYOUT_60_ansi_split_bs_rshift_space(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_DEL,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,          KC_BSLS,
        CW_TOGG, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,           KC_ENT,
        KC_LSFT, FK_SENT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, XXXXXXX, KC_RSFT, KC_INS,
        KC_LCTL, KC_LGUI, KC_LALT,        LT(_FL, KC_SPC),           LT(_FL, KC_SPC),    XXXXXXX, KC_RALT, KC_APP,  XXXXXXX, KC_RCTL, KC_RGUI
    ),
#endif
    [_BRL] = LAYOUT_60_ansi_split_bs_rshift_space(
        _______, BR_1,    BR_2,    BR_3,    BR_4,    BR_5,    BR_6,    BR_7,    BR_8,    BR_9,    BR_0,    BR_MINS, BR_EQL,  _______, _______,
        _______, BR_Q,    BR_W,    BR_E,    BR_R,    BR_T,    BR_Y,    BR_U,    BR_I,    BR_O,    BR_P,    BR_ACUT, BR_LBRC,          BR_BSLS,
        _______, BR_A,    BR_S,    BR_D,    BR_F,    BR_G,    BR_H,    BR_J,    BR_K,    BR_L,    BR_CCED, BR_TILD, BR_RBRC,          _______,
        _______, _______, BR_Z,    BR_X,    BR_C,    BR_V,    BR_B,    BR_N,    BR_M,    BR_COMM, BR_DOT,  BR_SCLN, _______, _______, _______,
        _______, _______, _______,        _______,                   _______,            _______, _______, _______, _______, _______, _______
    ),
    [_FL] = LAYOUT_faker(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______,
        _______, _______, KC_UP,   _______, KC_PGUP, _______, _______, KC_HOME, KC_END,  _______, _______, _______, _______,          _______,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, _______,          _______,
        _______, _______, _______, KC_DEL,  _______, _______, _______, _______, _______, _______, _______, _______,          _______, TG(_ML),
        _______, _______, _______,          _______,                   _______,                   _______, _______,          _______, TG(_BRL)
    ),
    [_ML] = LAYOUT_mouse_layer(),
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
    if (layer_state_is(_ML)) { // Restrict processing for layer 2 active.
        return process_record_user_mouse_manipulation(keycode, record);
    }
    return true; // Process keycodes normally
}
