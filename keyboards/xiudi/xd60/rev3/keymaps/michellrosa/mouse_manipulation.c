#include "custom_keycodes.h"
#include "digitizer.h"
#include <stdint.h>

#ifdef CONSOLE_ENABLE
#include "print.h"
#endif

// #define CENTER_IN_SLOT // uncomment to center position in between slots.

const int max_col_count = 10; // TODO depends on keymap.
const int max_row_count = 4; // TODO depends on keymap.

static float screen_init_x = 0.0f;
static float screen_end_x = 1.0f;
static float current_x = 0.5f;
static float screen_init_y = 0.0f;
static float screen_end_y = 1.0f;
static float current_y = 0.5f;

static int current_zoom_level = 0;

#ifdef CONSOLE_ENABLE
static bool printConfig(uint16_t keycode) {
    if (keycode == MCKC_INFO) {
        print("Mouse man. info:\n");
        uint16_t x_int = current_x;
        uint16_t x_dec = (uint8_t)(current_x * 100) % 100;
        uint16_t y_int = current_y;
        uint16_t y_dec = (uint8_t)(current_y * 100) % 100;
        uprintf("Current X,Y: (%u.%02u, %u.%02u)\n", x_int, x_dec, y_int, y_dec);
        x_int = screen_init_x;
        x_dec = (uint8_t)(screen_init_x * 100) % 100;
        y_int = screen_init_y;
        y_dec = (uint8_t)(screen_init_y * 100) % 100;
        uprintf("Screen X,Y: (%u.%02u, %u.%02u), ", x_int, x_dec, y_int, y_dec);
        x_int = screen_end_x;
        x_dec = (uint8_t)(screen_end_x * 100) % 100;
        y_int = screen_end_y;
        y_dec = (uint8_t)(screen_end_y * 100) % 100;
        uprintf("(%u.%02u, %u.%02u)\n", x_int, x_dec, y_int, y_dec);
        return true;
    }
    return false;
}
#endif

static bool setSWcorner(uint16_t keycode) {
    if (keycode == MCKC_SW) {
        screen_init_x = current_x;
        screen_init_y = current_y;
        return true;
    }
    return false;
}

static bool setNEcorner(uint16_t keycode) {
    if (keycode == MCKC_NE) {
        screen_end_x = current_x;
        screen_end_y = current_y;
        return true;
    }
    return false;
}

/// slot: starts in 1.
/// init_pos: must be less than end_pos.
static float getPosition(int slot, float init_pos, float end_pos, int slotCount) {
    float pos = init_pos;

    // move to the selected slot.
    float slot_size = (end_pos - init_pos) / slotCount;
    pos += (slot_size * (slot - 1));

#ifdef CENTER_IN_SLOT
    // center in between current and next slots.
    float center_offset = slot_size / 2;
    pos += center_offset;
#endif

    return pos;
}

static int getRow(uint16_t keycode) {
    if ((keycode >= MCKC_R1) && (keycode < MCKC_R2)) {
        return 1;
    } else if ((keycode >= MCKC_R2) && (keycode < MCKC_R3)) {
        return 2;
    } else if ((keycode >= MCKC_R3) && (keycode < MCKC_R4)) {
        return 3;
    } else if ((keycode >= MCKC_R4) && (keycode < MCKC_END)) {
        return 4;
    } else {
        return 0;
    }
}

/// Y 1.0 = bottom (init), 0.0 = top (end).
static bool updateYposition(uint16_t keycode, float *y_pos, int zoom_level) {
    int row = getRow(keycode);
    if (row > 0) {
        float init_y = screen_init_y;
        float end_y = screen_end_y;
        if (zoom_level > 0) {
            float line_height = (screen_end_y - screen_init_y) / max_row_count;
            line_height /= (zoom_level + 1);
#ifdef CENTER_IN_SLOT
            float center_offset = line_height / 2;
#else
            float center_offset = 0;
#endif
            init_y = *y_pos - center_offset; // new bottom position
            end_y = *y_pos + center_offset; // new top position
        }
        *y_pos = getPosition(row, init_y, end_y, max_row_count);
        return true;
    }
    return false;
}

static int getColumn(uint16_t keycode) {
    switch (keycode) {
        case MCKC_R1K1:
        case MCKC_R2K1:
        case MCKC_R3K1:
        case MCKC_R4K1:
            return 1;
        case MCKC_R1K2:
        case MCKC_R2K2:
        case MCKC_R3K2:
        case MCKC_R4K2:
            return 2;
        case MCKC_R1K3:
        case MCKC_R2K3:
        case MCKC_R3K3:
        case MCKC_R4K3:
            return 3;
        case MCKC_R1K4:
        case MCKC_R2K4:
        case MCKC_R3K4:
        case MCKC_R4K4:
            return 4;
        case MCKC_R1K5:
        case MCKC_R2K5:
        case MCKC_R3K5:
        case MCKC_R4K5:
            return 5;
        case MCKC_R1K6:
        case MCKC_R2K6:
        case MCKC_R3K6:
        case MCKC_R4K6:
            return 6;
        case MCKC_R1K7:
        case MCKC_R2K7:
        case MCKC_R3K7:
        case MCKC_R4K7:
            return 7;
        case MCKC_R1K8:
        case MCKC_R2K8:
        case MCKC_R3K8:
        case MCKC_R4K8:
            return 8;
        case MCKC_R1K9:
        case MCKC_R2K9:
        case MCKC_R3K9:
        case MCKC_R4K9:
            return 9;
        case MCKC_R1K10:
        case MCKC_R2K10:
        case MCKC_R3K10:
        case MCKC_R4K10:
            return 10;
        case MCKC_R1K11:
        case MCKC_R2K11:
        case MCKC_R3K11:
        case MCKC_R4K11:
            return 11;
        case MCKC_R1K12:
        case MCKC_R2K12:
        case MCKC_R3K12:
        case MCKC_R4K12:
            return 12;
        case MCKC_R1K13:
        case MCKC_R2K13:
        case MCKC_R3K13:
        case MCKC_R4K13:
            return 13;
        case MCKC_R1K14:
        case MCKC_R2K14:
        case MCKC_R3K14:
        case MCKC_R4K14:
            return 14;
        case MCKC_R1K15:
        case MCKC_R2K15:
        case MCKC_R3K15:
        case MCKC_R4K15:
            return 15;
        default:
            return 0;
    }
}

/// X 0.0 = left (init), 1 = right (end).
static bool updateXposition(uint16_t keycode, float *x_pos, int zoom_level) {
    int col = getColumn(keycode);
    if (col > 0) {
        float init_x = screen_init_x;
        float end_x = screen_end_x;
        if (zoom_level > 0) {
            float col_width = (screen_end_x - screen_init_x) / max_col_count;
            col_width /= (zoom_level + 1);
#ifdef CENTER_IN_SLOT
            float center_offset = col_width / 2;
#else
            float center_offset = 0;
#endif
            init_x = *x_pos - center_offset; // new left position
            end_x = *x_pos + center_offset; // new right position
        }
        *x_pos = getPosition(col, init_x, end_x, max_col_count);
        return true;
    }
    return false;
}

bool process_record_user_mouse_manipulation(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
#ifdef CONSOLE_ENABLE
        if (printConfig(keycode)) {
           return false; // Skip all further processing of this key
        }
#endif
        if (setSWcorner(keycode)) {
           return false; // Skip all further processing of this key
        }
        if (setNEcorner(keycode)) {
           return false; // Skip all further processing of this key
        }

        uint8_t mod_state = get_mods();
        if (mod_state & MOD_MASK_SHIFT) {
            current_zoom_level = 1;
        } else {
            current_zoom_level = 0;
        }

        float x = current_x;
        float y = current_y;

        bool ismousekeypressed = false;
        ismousekeypressed = updateXposition(keycode, &x, current_zoom_level);
        if (!ismousekeypressed) {
            return true; // Process all other keycodes normally
        }
        ismousekeypressed = updateYposition(keycode, &y, current_zoom_level);
        if (!ismousekeypressed) {
            return true; // Process all other keycodes normally
        }

        current_x = x;
        current_y = y;

        digitizer_in_range_on();
        digitizer_set_position(current_x, (1 - current_y));

        return false; // Skip all further processing of this key
    }

    return true; // Process all other keycodes normally
}


//https://github.com/qmk/qmk_firmware/blob/master/docs/feature_pointing_device.md#automatic-mouse-layer-idpointing-device-auto-mouse
