#pragma once

#include QMK_KEYBOARD_H

// clang-format off

// Shift on Hold, Enter on Tap
#define FK_SENT SC_SENT // SFT_T(KC_ENT)

#include "abnt2_keycodes.h"

/// Custom keycodes
enum custom_keycodes {
    CUSTOM_KEYCODE_START = SAFE_RANGE,

    #include "custom_mouse_keycodes"

    FKBR_6,

    CUSTOM_KEYCODE_END
};

// clang-format on
