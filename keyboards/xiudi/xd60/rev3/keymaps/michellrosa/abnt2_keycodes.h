#pragma once

// clang-format off

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

// /// Custom keycodes
// enum custom_keycodes {
//     CUSTOM_KEYCODE_START = SAFE_RANGE,

//     FKBR_6,

//     CUSTOM_KEYCODE_END
// };

// clang-format on
