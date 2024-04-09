#pragma once

#include "faker_layout.h"

#ifndef EXIT_MOUSE_MODE
#define EXIT_MOUSE_MODE TG(2)
#endif
#define KC_EXMM EXIT_MOUSE_MODE

// clang-format off

#define MOUSE_LAYER                                                                                                                                                   \
    LAYOUT_faker(                                                                                                                                                     \
        KC_EXMM, MCKC_R4K1, MCKC_R4K2, MCKC_R4K3, MCKC_R4K4, MCKC_R4K5, MCKC_R4K6, MCKC_R4K7, MCKC_R4K8, MCKC_R4K9, MCKC_R4K10, _______, _______, _______, _______,   \
        _______, MCKC_R3K1, MCKC_R3K2, MCKC_R3K3, MCKC_R3K4, MCKC_R3K5, MCKC_R3K6, MCKC_R3K7, MCKC_R3K8, MCKC_R3K9, MCKC_R3K10, _______, _______,          _______,   \
        _______, MCKC_R2K1, MCKC_R2K2, MCKC_R2K3, MCKC_R2K4, MCKC_R2K5, MCKC_R2K6, MCKC_R2K7, MCKC_R2K8, MCKC_R2K9, MCKC_R2K10, _______, _______,          _______,   \
        _______, _______, MCKC_R1K1, MCKC_R1K2, MCKC_R1K3, MCKC_R1K4, MCKC_R1K5, MCKC_R1K6, MCKC_R1K7, MCKC_R1K8, MCKC_R1K9, MCKC_R1K10,          _______, _______,   \
        _______, _______, _______,                       _______,                                _______,                       _______, _______, _______, _______    \
    )

// clang-format on
