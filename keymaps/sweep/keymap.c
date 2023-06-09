// qmk flash -c -kb ferris/sweep -km iron -e CONVERT_TO=blok -bl uf2-split-<left|right>
// TODO: create combos for brackets with arrow back
// TODO: create tri-layer for osms and system controls

#include QMK_KEYBOARD_H
#include <stdio.h>

enum user_layers {
    _BSE,
    _EXT,
    _SYM,
    _NUM,
    _FNC,
    _MSE,
    _MED
};

enum custom_keycodes {
    DBPRN = SAFE_RANGE, // double parenthesis with arrow back
    ALT_TAB
};

enum combos {};

// defining any key combo greater than seven characters?

// one shot mods
#define OSC OSM(MOD_LCTL)
#define OSS OSM(MOD_LSFT)
#define OSG OSM(MOD_LGUI)
#define OSA OSM(MOD_LALT)


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) { // This will do most of the grunt work with the keycodes.
    case ALT_TAB:
      if (record->event.pressed) {
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          register_code(KC_LALT);
        }
        alt_tab_timer = timer_read();
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
      }
      break;

    case DBPRN:
      if (record->event.pressed) {

      } else {

      }
      break;
  }
  return true;
};

void matrix_scan_user(void) { // The very important timer.
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 1000) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    //base
  [_BSE] = LAYOUT(
  //,--------------------------------------------.                    ,--------------------------------------------.
         KC_F,    KC_L,    KC_H,    KC_V,    KC_Z,                      KC_QUOT,    KC_W,    KC_U,    KC_O,    KC_Y,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
         KC_S,    KC_R,    KC_N,    KC_T,    KC_K,                         KC_C,    KC_D,    KC_E,    KC_A,    KC_I,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
         KC_X,    KC_J,    KC_B,    KC_M,    KC_Q,                         KC_P,    KC_G, KC_COMM,  KC_DOT,   TT(3),
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                            TT(2),  KC_SPC,      TT(1),     OSS
                                      //`-----------------'  `-----------------'

  ),
    //extension
  [_EXT] = LAYOUT(
  //,-------------------------------------------.                    ,--------------------------------------------.
     XXXXXXX, KC_LGUI, CW_TOGG,   TO(6), XXXXXXX,                      XXXXXXX, KC_HOME,   KC_UP,  KC_END, XXXXXXX,
  //|-------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_ESC, KC_DEL,C(KC_BSPC),KC_BSPC, XXXXXXX,                      XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT,  KC_TAB,
  //|-------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
         OSA,     OSG,     OSS,     OSC, XXXXXXX,                      C(KC_S), C(KC_V), C(KC_C), C(KC_X), C(KC_Z),
  //|-------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                           TO(5),  KC_ENT,      TO(0), _______
                                      //`----------------'  `-----------------'
  ),
    //symbol
  [_SYM] = LAYOUT(
  //,--------------------------------------------.                    ,--------------------------------------------.
      KC_LABK, KC_RABK, KC_LCBR, KC_RCBR, XXXXXXX,                       KC_GRV, KC_AMPR, KC_ASTR, KC_MINS, KC_PLUS,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_BSLS, KC_SLSH, KC_LPRN, KC_RPRN, KC_PIPE,                      KC_TILD, KC_COLN, KC_SCLN, KC_QUES, KC_EXLM,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_UNDS,  KC_EQL, KC_LBRC, KC_RBRC, XXXXXXX,                        KC_AT, KC_CIRC, KC_PERC,  KC_DLR, KC_HASH,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                              OSS,  KC_SPC,      TO(0), _______
                                      //`-----------------'  `-----------------'
  ),
    //numpad
  [_NUM] = LAYOUT(
  //,--------------------------------------------.                    ,--------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,    KC_7,    KC_8,    KC_9,  KC_DOT,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,    KC_4,    KC_5,    KC_6,  KC_ENT,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,    KC_1,    KC_2,    KC_3, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                            MO(4), _______,      TO(0),    KC_0
                                      //`-----------------'  `-----------------'
  ),
    //function
  [_FNC] = LAYOUT(
  //,--------------------------------------------.                    ,--------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,   KC_F7,   KC_F8,   KC_F9,  KC_F12,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, QK_MAKE, QK_BOOT, XXXXXXX,                      XXXXXXX,   KC_F4,   KC_F5,   KC_F6,  KC_F11,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,   KC_F1,   KC_F2,   KC_F3,  KC_F10,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                          _______, XXXXXXX,    XXXXXXX, XXXXXXX
                                      //`-----------------'  `-----------------'
  ),
    //mouse
  [_MSE] = LAYOUT(
  //,--------------------------------------------.                    ,--------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_WH_L, KC_WH_R, C(KC_V), C(KC_C),
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX,      TO(0), XXXXXXX
                                      //`-----------------'  `-----------------'
  ),
    //media
  [_MED] = LAYOUT(
  //,--------------------------------------------.                    ,--------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_MSTP, KC_MPRV, KC_MNXT, KC_MPLY, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX,      TO(0), XXXXXXX
                                      //`-----------------'  `-----------------'
  )
};
