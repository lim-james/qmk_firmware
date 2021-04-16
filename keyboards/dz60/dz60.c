#include "dz60.h"

int rgb_index = 0;
int h = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        ++rgb_index;
        if (rgb_index >= RGBLED_NUM) 
            rgb_index = 0;

        //rgblight_sethsv_noeeprom(255, 255, 0);
        rgblight_sethsv_at(h, 255, 255, rgb_index);
    }
    return true;
}

void housekeeping_task_user() {
    ++h;
    if (h > 255) 
        h = 0;

    rgblight_sethsv_at(h, 255, 255, rgb_index);
}
