#include QMK_KEYBOARD_H
#include "version.h"

#define BASE 0 // default layer
#define _LOWER 1
#define _SHIFT 2
#define _LSHIFT 3
#define _MOUSE 4
#define _WHEEL 5
#define _OMOUSE 6

#define ___ _______

#define TMP_MODE(MODE) \
    case MODE: \
      if (record->event.pressed) { \
        layer_on(_##MODE); \
      } else { \
        layer_off(_##MODE); \
      } \
      return false; \
      break;


#define led_on(x) ergodox_right_led_##x##_on()
#define led_off(x) ergodox_right_led_##x##_off()

enum custom_keycodes {
  EPRM = SAFE_RANGE,
  LOWER,
  SHIFT,
  LSHIFT,
  MOUSE,
  WHEEL,
  OMOUSE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  L1  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BkSp   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|' / Cmd |
 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|  '"  |AltShf| Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
 *                                 |      |ace   | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */

 [BASE] = LAYOUT_ergodox(
  // left hand
  //,-----------------------------------------------------------------------------.
  /*|*/ KC_ESC, /*|*/KC_1,/*|*/KC_2,/*|*/KC_3,   /*|*/KC_4, /*|*/KC_5,/*|*/KC_6,//|
  //|-------------+---------+---------+------------+----------+---------+---------|
  /*|*/ KC_TAB, /*|*/KC_Q,/*|*/KC_W,/*|*/KC_E,   /*|*/KC_R, /*|*/KC_T,/*|*/KC_Y,//|
  //|-------------+---------+---------+------------+----------+---------+---------|
  /*|*/ KC_ENT, /*|*/KC_A,/*|*/KC_S,/*|*/KC_D,   /*|*/KC_F, /*|*/KC_G,//          |
  //|-------------+---------+---------+------------+----------+---------+---------|
  /*|*/ KC_LSFT,/*|*/KC_Z,/*|*/KC_X,/*|*/KC_C,   /*|*/KC_V, /*|*/KC_B,/*|*/___, //|
  //`-------------+---------+---------+------------+----------+-------------------'
  /*  |*/ ___,  /*|*/___, /*|*/___, /*|*/KC_LALT,/*|*/LOWER,//|
  //  `-------------------------------------------------------'

                                                     // left thumb
                                         //            ,--------------------------.
                                         /*            |*/KC_LEFT,/*|*/KC_UP,   //|
                                         //,-----------|------------+-------------|
                                         /*|           |            |*/KC_DOWN, //|
                                         //|           |            |-------------|
                                         /*|*/KC_SPC,/*|*/ LOWER, /*|*/KC_RIGHT,//|
                                         //`--------------------------------------'

  // right hand
  //,-----------------------------------------------------------------------------------.
  /*|*/RESET,/*|*/KC_7,/*|*/KC_8, /*|*/KC_9,/*|*/KC_0,/*|*/___,    /*|*/___,          //|
  //|----------+---------+----------+---------+---------+------------+------------------|
  /*|*/KC_Y, /*|*/KC_Y,/*|*/KC_U, /*|*/KC_I,/*|*/KC_O,/*|*/KC_P,   /*|*/KC_BSLS,      //|
  //|----------+---------+----------+---------+---------+------------+------------------|
  /*|*/      /*|*/KC_H,/*|*/KC_J, /*|*/KC_K,/*|*/KC_L,/*|*/KC_MHEN,/*|*/___,          //|
  //|----------+---------+----------+---------+---------+------------+------------------|
  /*|*/KC_B, /*|*/KC_N,/*|*/KC_M, /*|*/___, /*|*/___, /*|*/___,    /*|*/___,          //|
  //`--------------------+----------+---------+---------+------------+------------------'
  /*                     |*/MOUSE,/*|*/___, /*|*/___, /*|*/___,    /*|*/TG(_OMOUSE),//|
  //                     `------------------------------------------------------------'

  // right thumb
  //,-------------------------.
  /*|*/KC_MS_U,/*|*/KC_MS_R,//|
  //|------------+------------|-----------.
  /*|*/KC_MS_D,//|            |           |
  //|------------|            |           |
  /*|*/KC_MS_L,/*|*/KC_BSPC,/*|*/KC_LCTL//|
  //`-------------------------------------'
)

,[_LOWER] = LAYOUT_ergodox(
  // left hand
  ___,         KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,   ___,
  ___,         KC_AT,    KC_PLUS,  KC_ESC,   KC_SCLN,  KC_CIRC, KC_6,
  ___,         KC_MINS,  KC_PERC,  KC_BSLS,  KC_SLSH,  KC_QUOT,
  ___,         KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,  ___,
  ___,         ___,      ___,      ___,      ___,

                                                       ___,     ___,
                                                                ___,
                                               ___,    ___,     ___,

  // right hand
  ___,         KC_F7,    KC_LBRC,  KC_RBRC,  KC_F12,   ___,     ___,
  ___,         ___,      KC_DOT,   KC_COMMA, KC_HOME,  KC_END,  ___,
               KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT, KC_HENK, ___,
  ___,         KC_F11,   KC_PGUP,  KC_PGDN,  ___,      ___,     ___,
  ___,         KC_DOT,   KC_0,     KC_EQL,   ___,

  ___,      ___,
  ___,
  ___,      KC_DELETE,  ___
)

,[_SHIFT] = LAYOUT_ergodox(
  // left hand
  ___,    ___,   KC_DQT,  KC_HASH, KC_DLR, ___,  ___,
  ___,    ___,   ___,     ___,  ___,  ___,  ___,
  ___,    ___,   ___,     ___,  ___,  ___,
  ___,    ___,   ___,     ___,  ___,  ___,  ___,
  ___,    ___,   ___,     ___,  ___,

                                    ___, ___,
                                         ___,
                               ___, ___, ___,

  // right hand
  ___, ___, KC_LPRN, KC_RPRN, KC_QUES,  ___,  ___,
  ___, ___,  ___, ___, ___,  ___,  ___,
       ___, ___, ___, ___,  ___,  ___,
  ___, ___,  ___, ___, ___,  ___,  ___,
  ___, ___,  ___, ___, ___,

  ___, ___,
  ___,
  ___, ___, ___
)

,[_LSHIFT] = LAYOUT_ergodox(
  // left hand
  ___,    ___,   ___,  ___, ___, ___,  ___,
  ___,    KC_GRV,   KC_ASTR,     ___, KC_COLON,  KC_TILDE,  KC_7,
  ___,    KC_EQL,   ___,     KC_UNDS,  KC_PIPE,  KC_AMPR,
  ___,    ___,   ___,     ___,  ___,  ___,  ___,
  ___,    ___,   ___,     ___,  ___,
                              // left thumb
                                    ___, ___,
                                         ___,
                               ___, ___, ___,

  // right hand
  ___, ___, KC_LCBR, KC_RCBR, ___,  ___,  ___,
  ___, ___, KC_LT, KC_GT, ___,  ___,  ___,
       ___, ___, ___, ___,  ___,  ___,
  ___, ___,  ___, ___, ___,  ___,  ___,
  ___, ___,  ___, ___, ___,

  ___, ___,
  ___,
  ___, ___, ___
)

,[_MOUSE] = LAYOUT_ergodox(
  // left hand
  ___,    ___,   ___,  ___,  ___,  ___,  ___,
  ___,    ___,   ___,  ___,  ___,  ___,  ___,
  ___,    ___,   ___,  ___,  ___,  WHEEL,
  ___,    ___,   ___,  ___,  ___,  ___,  ___,
  ___,    ___,   KC_BTN1, KC_BTN3, KC_BTN2,

                                    ___, ___,
                                         ___,
                               ___, ___, ___,

  // right hand
  ___, ___,  ___, ___, ___,  ___,  ___,
  ___, ___,  ___, ___, ___,  ___,  ___,
       KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,  ___,  ___,
  ___, ___,  ___, ___, ___,  ___,  ___,
  ___, ___,  ___, ___, ___,

  ___, ___,
  ___,
  ___, ___, ___
)

,[_OMOUSE] = LAYOUT_ergodox(
  // left hand
  ___,    ___,   ___,  ___,  ___,  ___,  ___,
  ___,    ___,   ___,  ___,  ___,  ___,  ___,
  ___,    ___,   ___,  ___,  ___,  ___,
  ___,    ___,   ___,  ___,  ___,  ___,  ___,
  ___,    ___,   ___,  ___,  ___,

                                    ___, ___,
                                         ___,
                               ___, ___, ___,

  // right hand
  ___, ___,     ___,     ___,     ___,     ___, ___,
  ___, ___,     ___,     ___,     ___,     ___, ___,
       KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, ___, ___,
  ___, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R,  ___, ___,
                KC_BTN2, ___,     ___,     ___, ___,

  ___, ___,
  ___,
  ___, WHEEL, KC_BTN1
)

,[_WHEEL] = LAYOUT_ergodox(
  // left hand
  ___,    ___,   ___,  ___,  ___,  ___,  ___,
  ___,    ___,   ___,  ___,  ___,  ___,  ___,
  ___,    ___,   ___,  ___,  ___,  ___,
  ___,    ___,   ___,  ___,  ___,  ___,  ___,
  ___,    ___,   ___,  ___,  ___,

                                    ___, ___,
                                         ___,
                               ___, ___, ___,

  // right hand
  ___, ___,  ___, ___, ___,  ___,  ___,
  ___, ___,  ___, ___, ___,  ___,  ___,
      KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R,  ___,  ___,
  ___, ___,  ___, ___, ___,  ___,  ___,
             ___,  ___,  ___, ___, ___,

  ___, ___,
  ___,
  ___, ___, ___
)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    TMP_MODE(MOUSE);
    TMP_MODE(WHEEL);

    case KC_GRV:
    case KC_EQL:
    case KC_ASTR:
    case KC_7:
      unregister_code(KC_LSFT);

      return true;

    case KC_LSFT:
      if (record->event.pressed) {
        register_code(KC_LSFT);
        layer_on(_SHIFT);
        update_tri_layer(_LOWER, _SHIFT, _LSHIFT);
      } else {
        layer_off(_SHIFT);
        update_tri_layer(_LOWER, _SHIFT, _LSHIFT);
        unregister_code(KC_LSFT);
      }
      return false;

    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _SHIFT, _LSHIFT);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _SHIFT, _LSHIFT);
      }
      return false;

    case RESET:
      if (record->event.pressed) {
        led_on(1);
        led_on(2);
        led_on(3);
      } else {
        reset_keyboard();
      }

      return false;
  }

  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  led_off(1);
  led_off(2);
  led_off(3);

  uint8_t layer = biton32(state);
  switch (layer) {
    case _OMOUSE:
      led_on(3);
      #ifdef RGBLIGHT_COLOR_LAYER_0
        rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
      #endif
      break;

    case _WHEEL:
      led_on(1);
      break;
    }
  return state;
}

