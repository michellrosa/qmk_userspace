#pragma once

#include QMK_KEYBOARD_H

// clang-format off

/// Custom keycodes
enum userspace_custom_keycodes {
    CUSTOM_KEYCODE_START = SAFE_RANGE,

    #include "custom_mouse_keycodes"

    CUSTOM_KEYCODE_END
};

// clang-format on
