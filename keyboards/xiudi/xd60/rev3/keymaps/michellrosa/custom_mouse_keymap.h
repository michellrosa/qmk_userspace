#pragma once

#include "faker_layout.h"

#ifndef EXIT_MOUSE_MODE
#define EXIT_MOUSE_MODE TG(_ML)
#endif
#define KC_EXMM EXIT_MOUSE_MODE

// clang-format off

#define MOUSE_CONTROL_KC_LAYOUT_ROW4 MCKC_R4K1, MCKC_R4K2, MCKC_R4K3, MCKC_R4K4, MCKC_R4K5, MCKC_R4K6, MCKC_R4K7, MCKC_R4K8, MCKC_R4K9, MCKC_R4K10
#define MOUSE_CONTROL_KC_LAYOUT_ROW3 MCKC_R3K1, MCKC_R3K2, MCKC_R3K3, MCKC_R3K4, MCKC_R3K5, MCKC_R3K6, MCKC_R3K7, MCKC_R3K8, MCKC_R3K9, MCKC_R3K10
#define MOUSE_CONTROL_KC_LAYOUT_ROW2 MCKC_R2K1, MCKC_R2K2, MCKC_R2K3, MCKC_R2K4, MCKC_R2K5, MCKC_R2K6, MCKC_R2K7, MCKC_R2K8, MCKC_R2K9, MCKC_R2K10
#define MOUSE_CONTROL_KC_LAYOUT_ROW1 MCKC_R1K1, MCKC_R1K2, MCKC_R1K3, MCKC_R1K4, MCKC_R1K5, MCKC_R1K6, MCKC_R1K7, MCKC_R1K8, MCKC_R1K9, MCKC_R1K10

#define LAYOUT_faker_wrapper(...) LAYOUT_faker(__VA_ARGS__)

#define LAYOUT_mouse_layer()                                                                                                                                          \
    LAYOUT_faker_wrapper(                                                                                                                                             \
        KC_EXMM, MOUSE_CONTROL_KC_LAYOUT_ROW4,                                                                                  _______, _______, _______, _______,   \
        _______, MOUSE_CONTROL_KC_LAYOUT_ROW3,                                                                                  _______, _______,          _______,   \
        _______, MOUSE_CONTROL_KC_LAYOUT_ROW2,                                                                                  _______, _______,          _______,   \
        _______, _______, MOUSE_CONTROL_KC_LAYOUT_ROW1,                                                                                           _______, MCKC_INFO, \
        _______, _______, _______,                       _______,                                _______,                       _______, _______, MCKC_SW, MCKC_NE    \
    )

// clang-format on
