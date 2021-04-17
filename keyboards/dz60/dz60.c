#include "dz60.h"

float h = 0.f;
float v = 0.001f;     // velocity
float min_v = 0.f;     // velocity
float a = 0.005f;    // acceleration
float f = 0.000075f;   // friction

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    v += a; 
    return true;
}

void housekeeping_task_user() {
    h += v;
    if (h > 255.f) 
        h = 0.f;

    v = fmax(min_v, v - f);

    rgblight_sethsv_noeeprom((int)h, 255, 255);
}
