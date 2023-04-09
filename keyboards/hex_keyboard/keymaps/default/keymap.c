// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include <stdint.h>
#include QMK_KEYBOARD_H
#include "print.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
      [0] = LAYOUT_5x4(
              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
      ),
      [1] = LAYOUT_5x4(
              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
      ),
      [2] = LAYOUT_5x4(
              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
      ),
      [3] = LAYOUT_5x4(
              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
      )
};

const char layer[] = {0x09, 0x00};
uint16_t latest_keycode = 0x0000;

void render(void) {
  uint16_t keycode = latest_keycode;

  oled_set_cursor(1, 0);
  oled_write_P(layer, true);

  switch (get_highest_layer(layer_state)) {
      case 0:
          oled_write_P(PSTR("PAINT"), true);
          break;
      case 1:
          oled_write_P(PSTR("GAME"), true);
          break;
      case 2:
          oled_write_P(PSTR("MOUSE"), true);
          break;
      case 3:
          oled_write_P(PSTR("MISC"), true);
          break;
      default:
          oled_write_P(PSTR("Undefined"), true);
  }

  oled_write_P(PSTR("\n"), true);
  oled_write_P(PSTR("\n"), false);
  oled_set_cursor(1, 2);

  if (keycode != 0x0000) {
    char str[5];

    switch (keycode) {
      case KC_SPACE:
        oled_write_P(PSTR("MOVE"), false);
        break;
      case KC_P:
        oled_write_P(PSTR("BRUSH"), false);
        break;
      case KC_I:
        oled_write_P(PSTR("SPUIT"), false);
        break;
      case KC_M:
        oled_write_P(PSTR("SELECT"), false);
        break;
      case KC_KB_VOLUME_UP:
        oled_write_P(PSTR("VOL+"), false);
        break;
      case KC_KB_VOLUME_DOWN:
        oled_write_P(PSTR("VOL-"), false);
        break;
      case KC_COMMA:
        oled_write_P(PSTR("SUBTOOL-"), false);
        break;
      case KC_DOT:
        oled_write_P(PSTR("SUBTOOL+"), false);
        break;
      case 0x770B: // MACRO11
        oled_write_P(PSTR("MIRROR"), false);
        break;
      case 0x770D: // MACRO13
        oled_write_P(PSTR("UNDO"), false);
        break;
      case 0x770E: // MACRO14
        oled_write_P(PSTR("REDO"), false);
        break;
      case 0x7706: // MACRO6
        oled_write_P(PSTR("ROTATION 0"), false);
        break;
      case 0x7707: // MACRO7
        oled_write_P(PSTR("ZOOM 0"), false);
        break;
      case 0x7708: // MACRO8
        oled_write_P(PSTR("SMOOTH-"), false);
        break;
      case 0x7709: // MACRO9
        oled_write_P(PSTR("SMOOTH+"), false);
        break;
      case KC_LEFT_BRACKET:
        oled_write_P(PSTR("SIZE-"), false);
        break;
      case KC_RIGHT_BRACKET:
        oled_write_P(PSTR("SIZE+"), false);
        break;
      case KC_LEFT_CTRL:
        oled_write_P(PSTR("ZOOM"), false);
        break;
      case KC_LEFT_SHIFT:
        oled_write_P(PSTR("ROTATE"), false);
        break;
      case KC_MS_UP:
        oled_write_P(PSTR("MOUSE UP"), false);
        break;
      case KC_MS_DOWN:
        oled_write_P(PSTR("MOUSE DOWN"), false);
        break;
      case KC_MS_LEFT:
        oled_write_P(PSTR("MOUSE LEFT"), false);
        break;
      case KC_MS_RIGHT:
        oled_write_P(PSTR("MOUSE RIGHT"), false);
        break;
      case KC_MS_BTN1:
        oled_write_P(PSTR("CLICK"), false);
        break;
      case KC_MS_BTN2:
        oled_write_P(PSTR("SUB CLICK"), false);
        break;
      case KC_MS_BTN3:
        oled_write_P(PSTR("MID CLICK"), false);
        break;
      case KC_MS_BTN4:
        oled_write_P(PSTR("BACK"), false);
        break;
      case KC_MS_BTN5:
        oled_write_P(PSTR("FORWARD"), false);
        break;
      case KC_MS_WH_UP:
        oled_write_P(PSTR("WHEEL UP"), false);
        break;
      case KC_MS_WH_DOWN:
        oled_write_P(PSTR("WHEEL DOWN"), false);
        break;
      case KC_MS_WH_LEFT:
        oled_write_P(PSTR("WHEEL LEFT"), false);
        break;
      case KC_MS_WH_RIGHT:
        oled_write_P(PSTR("WHEEL RIGHT"), false);
        break;
      // Layer Keys
      case 0x5200:
      case 0x5201:
      case 0x5202:
        break;
      default:
        if (0x0004 <= keycode && keycode <= 0x001D) {
          str[0] = keycode - 0x0004 + 'A';
          str[1] = '\0';
          oled_write_P(PSTR(str), false);
        } else {
          sprintf(str, "%04X", keycode);
          oled_write_P(PSTR(str), false);
        }
        break;
    }
  }

  oled_write_P(PSTR("\n"), false);
  oled_set_cursor(1, 3);
  oled_write_P(PSTR("\n"), false);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  latest_keycode = keycode;

  return true;
}

bool oled_task_user(void) {
  render();

  return false;
}
