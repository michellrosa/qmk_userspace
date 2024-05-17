#pragma once

#include QMK_KEYBOARD_H

// clang-format off

// Shift on Hold, Enter on Tap
#define FK_SENT SC_SENT // SFT_T(KC_ENT)

#define FKBR_QUOT       KC_QUOT         // '"
#define FKBR_LBRC       KC_LBRC         // [{
#define FKBR_RBRC       KC_RBRC         // ]}
#define FKBR_BSLS       KC_BSLS         // \|
#define FKBR_SCLN       KC_SLSH         // ;:

// #define FKBR_6          KC_6            // 6¨
#define FKBR_ACUT       ALGR(KC_QUOT)   // ´`
#define FKBR_CCED       ALGR(KC_COMM)   // çÇ
#define FKBR_TILD       LSFT(KC_GRV)    // ~^
// Shifted versions:
#define FKBR_6_S          SAGR(KC_QUOT) // 6¨ // TODO only when BR layer is active.
#define FKBR_ACUT_S       KC_GRV        // ´`
#define FKBR_CCED_S       SAGR(KC_COMM) // çÇ
#define FKBR_TILD_S       LSFT(KC_6)    // ~^

// RALT(kc) 	ROPT(kc), ALGR(kc) 	Hold Right Alt (AltGr) and press kc
// RSA(kc) 	SAGR(kc) 	Hold Right Shift and Right Alt (AltGr) and press kc

#include "features/custom_shift_keys.h"

// const custom_shift_key_t fk_custom_shift_keys[] = {
//     {FKBR_6, FKBR_6_S},              // Shift 6 is ¨ (FKBR_6)
//     {FKBR_ACUT, FKBR_ACUT_S},        // Shift ´ is ` (FKBR_ACUT)
//     //{FKBR_CCED, FKBR_CCED_S},      // Shift ç is Ç (FKBR_CCED)
//     {FKBR_TILD, FKBR_TILD_S},        // Shift ~ is ^ (FKBR_TILD)
// };
// uint8_t NUM_CUSTOM_SHIFT_KEYS = sizeof(fk_custom_shift_keys) / sizeof(custom_shift_key_t);

/// Custom keycodes
enum custom_keycodes {
    CUSTOM_KEYCODE_START = SAFE_RANGE,

    #include "custom_mouse_keycodes"

    FKBR_6,

    CUSTOM_KEYCODE_END
};

// clang-format on
