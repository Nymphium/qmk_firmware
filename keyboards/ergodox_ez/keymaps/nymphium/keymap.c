#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_japanese.h"
#include "config.h"

#define _BASE 0 // default layer
#define _LOWER 1
#define _SHIFT 2
#define _LSHIFT 3
#define _WHEEL 5
#define _XF86 7

#define ___ _______

#define TMP_MODE(MODE)               \
    case MODE:                       \
        if (record->event.pressed) { \
            layer_on(_##MODE);       \
        } else {                     \
            layer_off(_##MODE);      \
        }                            \
        return false;                \
        break;

#define WAIT_PRESSING(record)                                   \
    while (timer_elapsed(record->event.time) <= TAPPING_TERM) { \
    }

#define led_on(x) ergodox_right_led_##x##_on()
#define led_off(x) ergodox_right_led_##x##_off()

enum custom_keycodes { EPRM = SAFE_RANGE, LOWER, LSHIFT, MIDDLE, XF86, RESET };

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [_BASE] = LAYOUT_ergodox_pretty(
   XF86,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,        KC_6,     ___,     KC_6,    KC_7,    KC_8,    KC_9,     KC_0, ___,
   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,     KC_MS_U, KC_MS_R, KC_Y,    KC_U,    KC_I,     KC_O, KC_P,
   KC_ENT,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                           KC_MS_D, KC_H,    KC_J,    KC_K,     KC_L, JP_MHEN,
   KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_H,     KC_MS_L, KC_B,    KC_N,    KC_M,    KC_HOME,  KC_UP,KC_END,
            KC_LCTL, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,    KC_BSPC, KC_LCTL,  KC_LEFT, KC_DOWN, KC_RIGHT,
                                       KC_LGUI, KC_UP,       KC_MS_U, KC_MS_R,
                                                KC_DOWN,     KC_MS_D,
                            KC_LALT, LOWER,     KC_SPC,      KC_BTN1,MIDDLE,  KC_BTN2
)

,[_LOWER] = LAYOUT_ergodox_pretty( // {{{
  // left hand
  ___,  KC_F1,   KC_F2,    KC_F3,    KC_F4,   KC_F5,   KC_F6,      ___,       KC_F6,   KC_F7,   JP_LBRC,  JP_RBRC,  KC_F12,   RESET,
  ___,  JP_AT,   JP_PLUS,  KC_ESC,   KC_SCLN, JP_CIRC, KC_6,       ___,       ___,     ___,     KC_DOT,   KC_COMMA, KC_HOME,  KC_END,
  ___,  KC_MINS, KC_PERC,  JP_BSLS,  KC_SLSH, JP_QUOT,                        ___,     KC_LEFT, KC_DOWN,  KC_UP,    KC_RIGHT, JP_HENK,
  ___,  KC_F6,   KC_F7,    KC_F8,    KC_F9,   KC_F10,  ___,        ___,       KC_F11,  ___,     KC_PGUP,  KC_PGDN,  ___,      ___,
                  ___,     ___,      ___,     ___,     ___,        KC_DELETE, ___,     ___,     ___,      ___,
                                              ___,     ___,        ___, ___,
                                                       ___,        ___,
                                     ___,    ___,      ___,        ___, ___,      ___
) // }}}

,[_SHIFT] = LAYOUT_ergodox_pretty( // {{{
  ___,  ___,   ___,  ___,  ___, ___,  ___,              ___, ___, ___, ___, ___,JP_QUES,___,
  ___,  ___,   ___,  ___,  ___,  ___,  ___,             ___, ___, ___, ___, ___,___,    ___,
  ___,  ___,   ___,  ___,  ___,  ___,                        ___, ___, ___, ___,___,    ___,
  ___,  ___,   ___,  ___,  ___,  ___,  ___,             ___, ___, ___, ___, ___,___,    ___,
  ___,  ___,   ___,  ___,  ___,                         ___, ___, ___, ___, ___,
                                    ___, ___,           ___, ___,
                                         ___,           ___,
                               ___, ___, ___,           ___, ___, ___

) // }}}

,[_LSHIFT] = LAYOUT_ergodox_pretty( // {{{
  ___,    ___,    ___,     ___,     ___,      ___,      ___,          ___, ___, ___,     ___, ___,  ___,  ___,
  ___,    JP_GRV, JP_ASTR, ___,     JP_COLN,  JP_TILD,  KC_7,         ___, ___, ___,     KC_COMMA,   KC_DOT,  ___,  ___,
  ___,    JP_EQL, ___,     JP_UNDS, JP_PIPE,  JP_AMPR,                     ___, ___,     ___,     ___,  ___,  ___,
  ___,    ___,    ___,     ___,     ___,      ___,      KC_7,         ___, ___, ___,     ___,     ___,  ___,  ___,
  ___,    ___,    ___,     ___,     ___,                              ___, ___, ___,     ___,     ___,
                                    ___, ___,                         ___, ___,
                                         ___,                         ___,
                               ___, ___, ___,                         ___, ___, ___
) // }}}

,[_WHEEL] = LAYOUT_ergodox_pretty(
  // left hand
  ___,    ___,   ___,  ___,  ___,  ___,  ___,        ___, ___,  ___, ___, ___,  ___,  ___,
  ___,    ___,   ___,  ___,  ___,  ___,  ___,        KC_WH_U, KC_WH_R,  ___, ___, ___,  ___,  ___,
  ___,    ___,   ___,  ___,  ___,  ___,                  KC_WH_D, ___, ___, ___,  ___,  ___,
  ___,    ___,   ___,  ___,  ___,  ___,  ___,        KC_WH_L, ___,  ___, ___, ___,  ___,  ___,
  ___,    ___,   ___,  ___,  ___,                               ___,  ___,  ___, ___, ___,
                                    ___, ___,        ___, ___,
                                         ___,        ___,
                               ___, ___, ___,        ___, ___, ___
) // }}}

,[_XF86] = LAYOUT_ergodox_pretty( // {{{
  ___,   KC_MUTE,  KC_VOLD,  KC_VOLU,  ___, ___,  ___,     ___, ___,  ___, ___, ___,  ___,  ___,
  ___,    ___,   ___,     ___,  ___,  ___,  ___,           ___, ___,  ___, ___, ___, KC_BRID, KC_BRIU,
  ___,    ___,   ___,     ___,  ___,  ___,                      ___, ___, ___, ___,  ___,  ___,
  ___,    ___,   ___,     ___,  ___,  ___,  ___,           ___, ___,  ___, ___, ___,  ___,  ___,
  ___,    ___,   ___,     ___,  ___,                            ___, KC_PSCR,  ___, ___, ___,
                                    ___, ___,              ___, ___,
                                         ___,              ___,
                               ___, ___, ___,              ___, ___, ___
) // }}}
};
// clang-format on

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
        case KC_LCTL:
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
        case JP_MHEN:
            if (record->event.pressed) {
                if (henkan) led_off(2);
                henkan = false;
                register_code(keycode);
            } else {
                unregister_code(keycode);
            }
            return false;

        case JP_HENK:
            if (record->event.pressed) {
                henkan = true;
                led_on(2);
                register_code(keycode);
            } else {
                led_on(2);
                unregister_code(keycode);
            }
            return false;
            // }}}

        case RESET: // {{{
            if (record->event.pressed) {
                led_on(1);
                led_on(2);
                led_on(3);
            } else {
                reset_keyboard();
            }
            return false;
            // }}}

        case XF86:
            if (record->event.pressed) {
                layer_on(_XF86);
            } else {
                layer_off(_XF86);
            }
            return false;
            break;
    }

    return true;
}

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

layer_state_t layer_state_set_user(layer_state_t state) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    uint8_t layer = get_highest_layer(state);
    switch (layer) {
        case _BASE:
        case _SHIFT:
        case _LSHIFT:
        case _LOWER:
            if (henkan) {
                ergodox_right_led_2_on();
            } else {
                ergodox_right_led_2_off();
            }
            break;

        case _WHEEL:
            ergodox_right_led_3_off();
            ergodox_right_led_1_on();
            break;

        default:
            break;
    }

    return state;
};
