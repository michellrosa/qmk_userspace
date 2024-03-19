#include "keycodes.h"

const int row_count = 4;

static float screen_init_x = 1.0f;
static float screen_end_x = 0.0f;
static float current_x = 1.0f;
static float screen_init_y = 1.0f;
static float screen_end_y = 0.0f;
static float current_y = 1.0f;

//static int zoom_level = 0;

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

/*static*/ bool getYposition(uint16_t keycode, float &y_pos, int zoom_level) {
    int row = getRow(keycode);
    if (row > 0) {
        float line_height = (screen_init_y - screen_end_y) / row_count;
        float center_offset = line_height / 2;

        float y = screen_init_y;
        if (zoom_level > 0) {
            y = *y_pos + center_offset; // new top position

            line_height = line_height / row_count;
            center_offset = line_height / 2;
        }

        y -= (line_height * row);
        y += center_offset;

        *y_pos = y;
        return true;
    }
    return false;
}
