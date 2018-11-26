#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _DEFAULT 0
#define _LOWER 2
#define _SHIFT 3
#define _LSHIFT 4
#define _MOUSE 5
#define _OMOUSE 6
#define _WHEEL 7

enum custom_keycodes {
  DEFAULT = SAFE_RANGE,
  WDEFAULT,
  LOWER,
  MOUSE,
  OMOUSE,
  WHEEL,
  XHENK,
  XMHEN,
};

#define LSpr KC_LGUI
#define KC_ASTR LSFT(KC_8)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* DEFAULT
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |  P   |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |Enter |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |Muhen |      |
 * |------+------+------+------+------+------|  Y    |    |   B   |------+------+------+------+------+------|
 * |LShift       |   Z  |   X  |   C  |   V  |-------|    |-------|   N  |   M  |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |Super | LAlt |LOWER | / Space /       \ BSPC \  | Ctrl |MOUSE |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_DEFAULT] = LAYOUT( \
  KC_ESC,  KC_1, KC_2, KC_3, KC_4,    KC_5,                    KC_6,     KC_7,   KC_8,    KC_9,    KC_0,    _______, \
  KC_TAB,  KC_Q, KC_W, KC_E, KC_R,    KC_T,                    KC_Y,     KC_U,   KC_I,    KC_O,    KC_P,    _______, \
  KC_ENT,  KC_A, KC_S, KC_D, KC_F,    KC_G,                    KC_H,     KC_J,   KC_K,    KC_L,    XMHEN, _______, \
  KC_LSFT, KC_Z, KC_X, KC_C, KC_V,    KC_B,  KC_Y,    KC_B,    KC_N,     KC_M,   _______, _______, _______, TG(_OMOUSE), \
                       LSpr, KC_LALT, LOWER, KC_SPC,  KC_BSPC, KC_RCTRL, MOUSE,  WDEFAULT \
),

/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      | F1  |  F2  |  F3  |  F4  |  F5   |                    |      |      |  [   |   ]  | F12  |      |
 * |------+-----+------+------+------+-------|                    |------+------+------+------+------+------|
 * |      |  @  |  +   | ESC  |  ;   |  ^    |                    |      |      |  .   |  ,   | HOME | END  |
 * |------+-----+------+------+------+-------|                    |------+------+------+------+------+------|
 * |      |  -  |   %  |  \   |  /   |  '    |-------.    ,-------|      | Left | Down |  Up  |Right |Henkan|
 * |------+-----+------+------+------+-------|  F10  |    |       |------+------+------+------+------+------|
 * |      |     |  F6  |  F7  |  F8  |  F9   |-------|    |-------|      | F11  | PgDn | PgUp |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |Delete|      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT( \
   _______, KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,                        _______,  KC_LBRC, KC_RBRC,  KC_F12,   _______, _______,\
   _______, KC_AT,    KC_PLUS, KC_ESC,  KC_SCLN, KC_CIRC,                      KC_6,     KC_DOT,  KC_COMMA, KC_HOME,  KC_END,  _______,    \
   _______, KC_MINUS, KC_PERC, KC_BSLS, KC_SLSH, KC_QUOT,                      KC_LEFT,  KC_DOWN, KC_UP,    KC_RIGHT, XHENK, _______,    \
   _______, KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,  _______,   KC_F11,   KC_PGUP, KC_PGDN,  _______, _______,  _______,    \
                               _______, _______, _______, _______,  KC_DELETE, _______, _______,  _______ \
),

// shift key modification
[_SHIFT] = LAYOUT( \
  _______, _______, KC_DQT,  KC_HASH, KC_DLR,  _______,                    _______, KC_LPRN, KC_RPRN, KC_QUES, _______, _______, \
  _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, \
                             _______, _______, _______, _______,  _______, _______, _______, _______ \
),

// LOWER + SHIFT = LSHIFT
/* _LSHIFT
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |   {  |  }   |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  `   |  *   |      |   :  |   ~  |                    |      |      |  <   |  >   |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  =   |      |  _   |  |   |  &   |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_LSHIFT] = LAYOUT( \
  _______, _______, _______, _______,  _______,  _______,                    _______, KC_LCBR, KC_RCBR, _______, _______, _______, \
  _______, KC_GRV,  KC_ASTR,   _______,  KC_COLON, KC_TILDE,                   _______, KC_LT,   KC_GT,   _______, _______, _______, \
  _______, KC_EQL, _______, KC_UNDS,  KC_PIPE,  KC_AMPR,                    _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______,  _______,  _______, _______,  _______, _______, _______, _______, _______, _______, _______, \
                             _______, _______, _______, _______,  _______, _______, _______, _______ \
),

[_MOUSE] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,                   KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
                             KC_BTN1, KC_BTN3, KC_BTN2, WHEEL,   _______, _______, _______, _______ \
),

[_OMOUSE] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,                   KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
                             _______, _______, _______, _______,  WHEEL,  KC_BTN1, KC_BTN3, KC_BTN2 \
),

[_WHEEL] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,                    KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, \
                             _______, _______, _______, _______,  _______, _______, _______, _______ \
)
};

bool wdefault = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case DEFAULT:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DEFAULT);
      }
      return false;
      break;

    case WDEFAULT:
      if (record->event.pressed) {
        if (!wdefault) {
          wdefault = true;
        } else {
          wdefault = false;
        }
      }
      return false;
      break;

    case MOUSE:
      if (record->event.pressed) {
        layer_on(_MOUSE);
      } else {
        layer_off(_MOUSE);
      }
      return false;
      break;

    case WHEEL:
      if (record->event.pressed) {
        layer_on(_WHEEL);
      } else {
        layer_off(_WHEEL);
      }
      return false;
      break;

    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _SHIFT, _LSHIFT);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _SHIFT, _LSHIFT);
      }
      return false;
      break;

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
      break;

    case XMHEN:
      if (wdefault) {
        if (record->event.pressed) {
          register_code(KC_INS);
        } else {
          unregister_code(KC_INS);
        }
      } else {
        if (record->event.pressed) {
          register_code(KC_MHEN);
        } else {
          unregister_code(KC_MHEN);
        }
      }
      return true;
      break;

    case XHENK:
      if (wdefault) {
        if (record->event.pressed) {
          register_code(KC_LSFT);
          register_code(KC_INS);
        } else {
          unregister_code(KC_LSFT);
          unregister_code(KC_INS);
        }
      } else {
        if (record->event.pressed) {
          register_code(KC_HENK);
        } else {
          unregister_code(KC_HENK);
        }
      }

      return true;
      break;

    case KC_GRV:
    case KC_EQL:
    case KC_ASTR:
      unregister_code(KC_LSFT);
      return true;
  }

  return true;
}

