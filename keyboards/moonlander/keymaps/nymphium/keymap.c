/* Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Christopher Courtney <drashna@live.com> (@drashna)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_jp.h"


#define _BASE 0 // default layer
#define _LOWER 1
#define _SHIFT 2
#define _LSHIFT 3
#define _WHEEL 4
#define _XF86 5

#define ___ _______
#define WAIT_PRESSING(record) \
  while (timer_elapsed(record->event.time) <= TAPPING_TERM) {}

enum layers {
  EPRM = SAFE_RANGE,
  LOWER,
  LSHIFT,
  MIDDLE,
  XF86
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_moonlander(
        XF86,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,                         KC_MS_U,  KC_6,     KC_7,    KC_8,    KC_9,  KC_0,   ___,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    ___,                          KC_MS_U,  KC_MS_R,  KC_Y,    KC_U,    KC_I,  KC_O,   KC_P,
        KC_ENT,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_Y,                         KC_MS_L,  KC_MS_D,  KC_H,    KC_J,    KC_K,  KC_L,   KC_MHEN,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                            KC_B,     KC_N,    KC_M,    ___,   ___,    ___,
        KC_LCTRL,KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,         KC_LGUI,                      ___,                KC_BSPC, KC_LCTRL,___,   ___,    ___,
                                                     KC_LALT, LOWER, KC_SPC,       KC_BTN1, MIDDLE,  KC_BTN2
    ),
    [_LOWER] = LAYOUT_moonlander(
        ___, KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,   ___,                       ___,     ___,     KC_F7,     JP_LBRC,  JP_RBRC,  KC_F12,   ___,
        ___, JP_AT,    JP_PLUS,  KC_ESC,   KC_SCLN,  JP_CIRC, KC_6,                      ___,     ___,     ___,       KC_DOT,   KC_COMMA, KC_HOME,  KC_END,
        ___, KC_MINS,  KC_PERC,  JP_BSLS,  KC_SLSH,  JP_QUOT, KC_6,                       ___,     ___,     KC_LEFT,   KC_DOWN,  KC_UP,    KC_RIGHT, KC_HENK,
        ___, KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,                                      KC_F11,  KC_PGUP,   KC_PGDN,  ___,      _______,  ___,
        ___, _______, _______,   ___,      ___,               ___,                       _______,          KC_DELETE, ___,      ___,      _______,  ___,
                                                     ___,     ___, _______,     _______, _______, ___
    ),
    [_SHIFT] = LAYOUT_moonlander(
        ___,___,___, ___, _______, _______, _______,           _______, _______, _______, _______, _______, JP_QUES, ___,
        _______, _______, _______, ___, _______, _______, _______,           _______, _______, _______, _______, _______, ___, ___,
        _______, _______, ___, ___, ___, _______, _______,           _______, _______, _______, _______, _______, _______, ___,
        _______, _______, _______, _______, _______, _______,                             _______, _______, ___, ___, _______, _______,
        _______, _______, _______, ___, ___,         _______,            _______,          ___, ___, ___, _______, _______,
                                            _______, _______, _______,           _______, _______, _______
    ),
    [_LSHIFT] = LAYOUT_moonlander(
        ___,_______,_______, _______, _______, _______, _______,           _______, _______, JP_LCBR, JP_RCBR, _______, _______, ___,
        _______, JP_GRV, JP_ASTR, ___,     JP_COLN, JP_TILD, KC_7,           _______, _______, ___,KC_LT, KC_GT, _______, _______,
        _______, JP_EQL, ___,     JP_UNDS, JP_PIPE,  JP_AMPR,  ___,         _______, _______, ___,_______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                             ___,_______, _______, ___, ___, _______,
        _______, _______, _______, ___, ___,         _______,            _______,          ___, ___, ___, _______, _______,
                                            _______, _______, _______,           _______, _______, _______
    ),
    [_WHEEL] = LAYOUT_moonlander(
        ___,_______,_______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, ___,
        _______, _______, _______, ___, _______, _______, _______,           KC_WH_U, KC_WH_R, _______, _______, _______, _______, _______,
        _______, _______, ___, ___, ___, _______, _______,           KC_WH_L, KC_WH_D, _______, _______, _______, _______, ___,
        _______, _______, _______, _______, _______, _______,                             _______, _______, ___, ___, ___, ___,
        _______, _______, _______, ___, ___,         _______,            _______,          ___, ___, ___, ___, ___,
                                            _______, _______, _______,           _______, _______, _______
    ),
    [_XF86] = LAYOUT_moonlander(
        ___,KC_MUTE,KC_VOLD, KC_VOLU, _______, _______, _______,         ___,  _______, _______, _______, _______, _______, KC_PSCR,
        _______, _______, _______, ___, _______, _______, _______,           _______, _______, _______, _______, _______, KC_BRID, KC_BRIU,
        _______, _______, ___, ___, ___, _______, _______,           _______, _______, _______, _______, _______, _______, ___,
        _______, _______, _______, _______, _______, _______,                             _______, _______, ___, ___, _______, _______,
        _______, _______, _______, ___, ___,         _______,            _______,          ___, ___, ___, _______, _______,
                                            _______, _______, _______,           _______, _______, _______
    ),
};

// state flags {{{
static bool henkan;
static bool shift;
static bool modkeyed = false;
// }}}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // shift (+ MOD) + key workaround {{{
    case KC_LGUI:
    case KC_LALT:
    case KC_LCTRL:
      if (record->event.pressed) {
        register_code(keycode);
        modkeyed = true;
      } else {
        unregister_code(keycode);
        modkeyed = false;
      }
      return false;

    case JP_COLN:
      if (record->event.pressed) {
        unregister_code(KC_LSFT);
        /* register_code(keycode); */
      } else {
        if (shift) register_code(KC_LSFT);
        unregister_code(keycode);
      }
      return true;

    case KC_LSFT:
      if (record->event.pressed) {
        register_code(KC_LSFT);

        if (!modkeyed) {
          shift = true;
          layer_on(_SHIFT);
          update_tri_layer(_LOWER, _SHIFT, _LSHIFT);
        }
      } else {
        if (shift) {
          shift = false;
          layer_off(_SHIFT);
          update_tri_layer(_LOWER, _SHIFT, _LSHIFT);
        }
        unregister_code(KC_LSFT);
      }
      return false;
    // }}}

    case XF86: // {{{
      if(record->event.pressed) {
        layer_on(_XF86);
      } else {
        layer_off(_XF86);
      }
      return false;
    /// }}}

    case LOWER: // {{{
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _SHIFT, _LSHIFT);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _SHIFT, _LSHIFT);
      }
      return false;
    // }}}

    case MIDDLE: // {{{
      if (record->event.pressed) {
        register_code(KC_BTN3);

        WAIT_PRESSING(record);

        unregister_code(KC_BTN3);
        layer_on(_WHEEL);
      } else {
        layer_off(_WHEEL);
      }
      return false;
    // }}}

    // 変換/無変換 {{{
    case KC_MHEN:
      if (record->event.pressed) {
        henkan = false;
        register_code(keycode);
      } else {
        unregister_code(keycode);
      }
      return false;

    case KC_HENK:
      if (record->event.pressed) {
        henkan = true;
        register_code(keycode);
      } else {
        unregister_code(keycode);
      }
      return false;
    // }}}
  }

  return true;
}


