#include QMK_KEYBOARD_H
#include "keymap_jp.h"

extern keymap_config_t keymap_config;

#define _DEFAULT 0
#define _LOWER 1
#define _SHIFT 2
#define _LSHIFT 3
#define _MOUSE 4
#define _OMOUSE 5
#define _MIDDLE 6
#define _XF86 7

#define TMP_MODE(MODE)                                                         \
  case MODE:                                                                   \
    if (record->event.pressed) {                                               \
      layer_on(_##MODE);                                                       \
    } else {                                                                   \
      layer_off(_##MODE);                                                      \
    }                                                                          \
    return false;                                                              \
    break;

#define WAIT_PRESSING(record)                                                  \
  while (timer_elapsed(record->event.time) <= TAPPING_TERM) {                  \
  }


enum custom_keycodes {
  DEFAULT = SAFE_RANGE,
  WDEFAULT,
  LOWER,
  MOUSE,
  OMOUSE,
  MIDDLE,
  XF86
};

#define LSpr KC_LGUI
#define KC_ASTR LSFT(KC_8)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* DEFAULT
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   7  |   8  |   9  |   0  |      |  Fn  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |  P   |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |Enter |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |XMhen |      |
 * |------+------+------+------+------+------|  Y    |    |   B   |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |  B   |-------|    |-------|   N  |   M  |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |Super | LAlt |LOWER | / Space /       \ BSPC \  | Ctrl |MOUSE |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_DEFAULT] = LAYOUT( \
  KC_ESC,  KC_1, KC_2, KC_3, KC_4,    KC_5,                     KC_6,    KC_7,     KC_8,   KC_9,    KC_0,    _______,    \
  KC_TAB,  KC_Q, KC_W, KC_E, KC_R,    KC_T,                     KC_6,    KC_Y,     KC_U,   KC_I,    KC_O,    KC_P,    \
  KC_ENT,  KC_A, KC_S, KC_D, KC_F,    KC_G,                     _______, KC_H,     KC_J,   KC_K,    KC_L,    KC_MHEN,   \
  KC_LSFT, KC_Z, KC_X, KC_C, KC_V,    KC_B,  KC_Y,    _______,  KC_B,    KC_N,     KC_M,   _______, _______, TG(_OMOUSE), \
                       LSpr, KC_LALT, LOWER, KC_SPC,  MOUSE,    KC_BSPC, KC_RCTRL, WDEFAULT \
),

/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      | F1  |  F2  |  F3  |  F4  |  F5   |                    |      |  [   |   ]  | F12  |      |      |
 * |------+-----+------+------+------+-------|                    |------+------+------+------+------+------|
 * |      |  @  |  +   | ESC  |  ;   |  ^    |                    |      |  .   |  ,   | HOME | END  |      |
 * |------+-----+------+------+------+-------|                    |------+------+------+------+------+------|
 * |      |  -  |   %  |  \   |  /   |  '    |-------.    ,-------| Left | Down |  Up  |Right |XHenk |      |
 * |------+-----+------+------+------+-------|   6   |    |       |------+------+------+------+------+------|
 * |      | F6  |  F7  |  F8  |  F9  | F10   |-------|    |-------| F11  | PgDn | PgUp |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \Delete\  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT( \
  _______, KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,                       _______, _______, JP_LBRC, JP_RBRC,  KC_F12,   _______, \
  _______, JP_AT,    JP_PLUS, KC_ESC,  KC_SCLN, JP_CIRC,                     _______, _______, KC_DOT,  KC_COMMA, KC_HOME,  KC_END,  \
  _______, KC_MINUS, KC_PERC, JP_BSLS, KC_SLSH, JP_QUOT,                     _______, KC_LEFT, KC_DOWN, KC_UP,    KC_RIGHT, KC_HENK,   \
  _______, KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_6,     _______,  _______, KC_F11,  KC_PGUP, KC_PGDN,  _______,  _______, \
                              _______, _______, _______, XF86,     _______,  KC_DELETE, _______, _______ \
),

/* shift key modification
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |  "   |  #   |  $   |      |                    |      |  (   |  )   |   ?  |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_SHIFT] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, JP_QUES, _______, \
  _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, \
                             _______, _______, _______, _______,  _______, _______, _______, _______ \
),

// LOWER + SHIFT = LSHIFT
/* _LSHIFT
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |   {  |  }   |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  `   |  *   |      |   :  |   ~  |                    |      |  <   |  >   |      |      |      |
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
  _______, _______, _______, _______, _______,  _______,                    _______, _______, JP_LCBR, JP_RCBR, _______, _______, \
  _______, JP_GRV,  JP_ASTR, _______, JP_COLN,  JP_TILD,                    _______, _______, KC_LT,   KC_GT,   _______, _______, \
  _______, JP_EQL,  _______, JP_UNDS, JP_PIPE,  JP_AMPR,                    _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______,  _______, KC_7,     _______, _______, _______, _______, _______, _______, _______, \
                             _______, _______,  _______, _______,  _______, _______, _______, _______ \
),

// mouse emulation {{{
[_MOUSE] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,                    _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, \
  _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, \
                             KC_BTN1, MIDDLE, KC_BTN2,   _______,  _______, _______, _______, _______ \
),

[_OMOUSE] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______,  _______, _______, \
  _______, _______, _______, _______, _______, _______,                    _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, \
  _______, _______, _______, _______, _______, _______,                    _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,  _______, \
  _______, _______, _______, _______, _______, _______, _______,  _______, _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END,   _______, \
                             _______, _______, _______, _______,  KC_BTN1, MIDDLE, KC_BTN2,  _______ \
),

[_MIDDLE] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,                    _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______, \
  _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, \
                             _______, _______, _______, _______,  _______, _______, _______, _______ \
),
// }}}

// media keys
[_XF86] = LAYOUT( \
  KC_MUTE,  KC_VOLD, KC_VOLU, _______, _______, _______,                    _______, _______, _______, _______, KC_BRID,  KC_BRIU, \
  _______,  _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______,  _______, \
  _______,  _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______,  _______, \
  _______,  _______, _______, _______, _______, _______, _______,  KC_PSCR, _______, _______, _______, _______, _______,  _______, \
                              _______, _______, _______, _______,  _______, _______, _______, _______ \
)
};

static bool henkan;
static bool shift;
static bool modkeyed = false;
static bool omouse = false;

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
      register_code(keycode);
    } else {
      if (shift)
        register_code(KC_LSFT);
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

  case OMOUSE: // {{{
    if (record->event.pressed) {
      if (omouse) {
        omouse = false;
        layer_off(_OMOUSE);
      } else {
        omouse = true;
        layer_on(_OMOUSE);
      }
    }
    return false;
    // }}}

  case MIDDLE: // {{{
    if (record->event.pressed) {
      register_code(KC_BTN3);

      WAIT_PRESSING(record);

      unregister_code(KC_BTN3);
      if (omouse)
        layer_off(_OMOUSE);
      layer_on(_MIDDLE);
    } else {
      if (omouse)
        layer_on(_OMOUSE);
      layer_off(_MIDDLE);
    }
    return false;
  // }}}

  // 変換/無変換 {{{
  case KC_MHEN:
    if (record->event.pressed) {
      if (henkan) henkan = false;
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

    TMP_MODE(XF86);
    TMP_MODE(MOUSE);
  }

  return true;
}

