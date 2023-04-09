#include QMK_KEYBOARD_H
#include "print.h"

void keyboard_post_init_kb(void) {
//  debug_enable=true;
  oled_init(OLED_ROTATION_0);
}

void matrix_init_kb(void) {
}

