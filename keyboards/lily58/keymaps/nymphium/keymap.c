#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _DEFAULT 0
#define _LOWER 1
/* #define _RAISE 2 */
#define _SHIFT 2
#define _LSHIFT 3
#define _ADJUST 16

enum custom_keycodes {
  DEFAULT = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

#define LSpr KC_LGUI

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* DEFAULT
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |Enter |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |Henkan|      |
 * |------+------+------+------+------+------| Space |    | Space |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      | LGUI |LAlt  | /LOWER  /       \BSPC  \  |RCTRL |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_DEFAULT] = LAYOUT( \
  _______,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                   SFT_T(KC_6),    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
   KC_TAB,  KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______, \
   KC_ENT,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                   KC_H,    KC_J,    KC_K,    KC_L,    KC_MHEN, _______, \
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_SPC,  KC_SPC,  KC_N,    KC_M,    _______, _______, _______, _______, \
                      _______, LSpr,  KC_LALT,  LOWER,        KC_BSPC,  KC_RCTRL,  _______, _______ \
                      /* _______, LSpr,  KC_LALT,  LOWER,        KC_BSPC,  KC_RCTRL,   KC_LSFT, LOWER \ */
),

/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   -  |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |   _  |   +  |   {  |   }  |   |  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT( \
  _______, _______, _______, _______, KC_CIRC, _______,                   KC_6, KC_LCBR, KC_RCBR, KC_F12, _______, _______,\
  KC_AT,  KC_PLUS, KC_ESC,  KC_F4,   KC_F5,   KC_F6,                     KC_DOT,  KC_COMMA,  KC_HOME,  KC_END,  KC_F11,  KC_F12, \
  KC_GRV, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_HENK, KC_TILD, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_F11, KC_PRIOR, KC_PGUP, _______, _______, _______, \
                             _______, _______, _______, _______, KC_DELETE, _______, _______, _______\
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |-------.    ,-------|      | Left | Down |  Up  |Right |      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |  F7  |  F8  |  F9  | F10  | F11  | F12  |-------|    |-------|   +  |   -  |   =  |   [  |   ]  |   \  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

/* [_RAISE] = LAYOUT( \ */
  /* _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______, \ */
  /* KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \ */
  /* KC_F1,  KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,                       XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, \ */
  /* KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,   _______, _______,  KC_PLUS, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \ */
                             /* _______, _______, _______,  _______, _______,  _______, _______, _______ \ */
/* ), */

[_SHIFT] = LAYOUT( \
_______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, KC_QUES, _______, \
_______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
_______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
                           _______, _______, _______, _______, _______, _______, _______, _______ \
),

[_LSHIFT] = LAYOUT( \
  _______, _______, _______, _______,  _______,  _______,                   _______, _______, _______, _______, _______, _______, \
  KC_GRV,  KC_PAST, _______, KC_COLON, KC_TILDE, KC_7,                    KC_LT,   KC_GT,   _______, _______, _______, _______, \
  _______, _______, _______, _______,  _______,  _______,                   _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, \
                               _______, _______, _______, _______, _______, _______, _______, _______ \
),

/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */ 
  [_ADJUST] = LAYOUT( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
                             _______, _______, _______, _______, _______,  _______, _______, _______ \
  )
};

bool layered = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case DEFAULT:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DEFAULT);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layered = true;
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _SHIFT, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _SHIFT, _ADJUST);
        layered = false;
      }
      return false;
      break;
    case KC_LSFT:
      if (record->event.pressed) {
        if (layered) {
          layer_on(_LSHIFT);
        } else {
          register_code(KC_LSFT);

          layer_on(_SHIFT);
          update_tri_layer(_LOWER, _SHIFT, _ADJUST);
        }
      } else {
        if (layered) {
          layer_off(_LSHIFT);
        } else {
          layer_off(_SHIFT);
          update_tri_layer(_LOWER, _SHIFT, _ADJUST);
          unregister_code(KC_LSFT);
        }
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }

  return true;
}

