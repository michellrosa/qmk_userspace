#include "custom_keycodes.h"
// #include "keymap_brazilian_abnt2.h"
#include "features/custom_shift_keys.h"

const custom_shift_key_t custom_shift_keys[] = {
    {FKBR_6, FKBR_6_S},             // Shift 6 is ¨
    {FKBR_ACUT, FKBR_ACUT_S},       // Shift ´ is `
    //{FKBR_CCED, FKBR_CCED_S},     // Shift ç is Ç
    {FKBR_TILD, FKBR_TILD_S},       // Shift ~ is ^
};
uint8_t NUM_CUSTOM_SHIFT_KEYS = sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);

bool abnt2_process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_custom_shift_keys(keycode, record)) {
        return false;
    }

    switch (keycode) {
    case FKBR_6:
        if (record->event.pressed) {
            register_code(KC_6);
        } else {
            unregister_code(KC_6);
        }
        // return false;
        break;
    }

    return true; // Process keycodes normally
}
