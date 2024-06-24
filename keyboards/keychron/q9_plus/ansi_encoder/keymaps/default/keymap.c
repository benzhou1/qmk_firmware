/* Copyright 2023 @ Keychron (https://www.keychron.com)
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
#include "quantum.h"

enum layers_enums {
    MAC_BASE,
    LY_GAME,
    WIN_BASE,
    MAC_FN1,
    WIN_FN1,

    LY_PUNC,
    LY_NAV,
    LY_NUM,
    LY_F
};

enum custom_keycodes {
    UP_CHANGE_LAYER = SAFE_RANGE,
    DOWN_CHANGE_LAYER,
    LEFT_CHANGE_LAYER,
    RIGHT_CHANGE_LAYER,
};

enum keys {
    KEY_TAB, KEY_Q, KEY_W, KEY_E, KEY_R, KEY_T, KEY_Y, KEY_U, KEY_I, KEY_O, KEY_P, KEY_LBRACKET, KEY_RBRACKET, KEY_BACKSLASH, KEY_MUTE,
    KEY_CAPS, KEY_A, KEY_S, KEY_D, KEY_F , KEY_G, KEY_H, KEY_J, KEY_K, KEY_L, KEY_SEMICOLON, KEY_QUOTE, KEY_ENTER, KEY_WIN_FN2,
    KEY_LSHIFT, KEY_Z, KEY_X, KEY_C, KEY_V , KEY_B, KEY_N, KEY_M, KEY_COMMA, KEY_DOT, KEY_SLASH, KEY_RSHIFT, KEY_UP,
    KEY_FN, KEY_LCTRL, KEY_LGUI, KEY_LALT, KEY_SPACE1, KEY_SPACE2, KEY_RALT , KEY_RGUI, KEY_FN1, KEY_LEFT, KEY_DOWN, KEY_RIGHT,
};

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

#define CREATE_LAYOUT(layer_keys) LAYOUT_54_ansi(layer_keys[KEY_TAB],layer_keys[KEY_Q],layer_keys[KEY_W],layer_keys[KEY_E],layer_keys[KEY_R],layer_keys[KEY_T],layer_keys[KEY_Y],layer_keys[KEY_U],layer_keys[KEY_I],layer_keys[KEY_O],layer_keys[KEY_P],layer_keys[KEY_LBRACKET],layer_keys[KEY_RBRACKET],layer_keys[KEY_BACKSLASH],layer_keys[KEY_MUTE],layer_keys[KEY_CAPS],layer_keys[KEY_A],layer_keys[KEY_S],layer_keys[KEY_D],layer_keys[KEY_F],layer_keys[KEY_G],layer_keys[KEY_H],layer_keys[KEY_J],layer_keys[KEY_K],layer_keys[KEY_L],layer_keys[KEY_SEMICOLON],layer_keys[KEY_QUOTE],layer_keys[KEY_ENTER],layer_keys[KEY_WIN_FN2],layer_keys[KEY_LSHIFT],layer_keys[KEY_Z],layer_keys[KEY_X],layer_keys[KEY_C],layer_keys[KEY_V],layer_keys[KEY_B],layer_keys[KEY_N],layer_keys[KEY_M],layer_keys[KEY_COMMA],layer_keys[KEY_DOT],layer_keys[KEY_SLASH],layer_keys[KEY_RSHIFT],layer_keys[KEY_UP],layer_keys[KEY_FN],layer_keys[KEY_LCTRL],layer_keys[KEY_LGUI],layer_keys[KEY_LALT],layer_keys[KEY_SPACE1],layer_keys[KEY_SPACE2],layer_keys[KEY_RALT],layer_keys[KEY_RGUI],layer_keys[KEY_FN1],layer_keys[KEY_LEFT],layer_keys[KEY_DOWN],layer_keys[KEY_RIGHT])
#define KC_HOME_A LSFT_T(KC_A)
#define KC_HOME_S LGUI_T(KC_S)
#define KC_HOME_D LALT_T(KC_D)
#define KC_HOME_F LCTL_T(KC_F)
#define KC_HOME_J LCTL_T(KC_J)
#define KC_HOME_K LALT_T(KC_K)
#define KC_HOME_L LGUI_T(KC_L)
#define KC_HOME_SCLN LSFT_T(KC_SCLN)
#define KC_HOME_Z KC_Z
#define KC_HOME_DOT KC_DOT
#define KC_MOD_SPACE1 MO(LY_NUM)
#define KC_MOD_LALT MO(LY_F)

const uint16_t base_layer[MATRIX_ROWS * MATRIX_COLS] = {
    [KEY_TAB] = KC_TAB,
    [KEY_Q] = KC_Q,
    [KEY_W] = KC_W,
    [KEY_E] = KC_E,
    [KEY_R] = KC_R,
    [KEY_T] = KC_T,
    [KEY_Y] = KC_Y,
    [KEY_U] = KC_U,
    [KEY_I] = KC_I,
    [KEY_O] = KC_O,
    [KEY_P] = KC_P,
    [KEY_LBRACKET] = KC_LBRC,
    [KEY_RBRACKET] = KC_RBRC,
    [KEY_BACKSLASH] = KC_BACKSLASH,
    [KEY_MUTE] = LT(0, KC_MPLY),

    [KEY_CAPS] = KC_NO,
    [KEY_A] = KC_HOME_A,
    [KEY_S] = KC_HOME_S,
    [KEY_D] = KC_HOME_D,
    [KEY_F] = KC_HOME_F,
    [KEY_G] = KC_G,
    [KEY_H] = KC_H,
    [KEY_J] = KC_HOME_J,
    [KEY_K] = KC_HOME_K,
    [KEY_L] = KC_HOME_L,
    [KEY_SEMICOLON] = KC_HOME_SCLN,
    [KEY_QUOTE] = KC_QUOTE,
    [KEY_ENTER] = KC_ENT,
    [KEY_WIN_FN2] = MO(MAC_FN1),

    [KEY_LSHIFT] = KC_HOME_Z,
    [KEY_Z] = KC_HOME_Z,
    [KEY_X] = KC_X,
    [KEY_C] = KC_C,
    [KEY_V] = KC_V,
    [KEY_B] = KC_B,
    [KEY_N] = KC_N,
    [KEY_M] = KC_M,
    [KEY_COMMA] = KC_COMM,
    [KEY_DOT] = KC_HOME_DOT,
    [KEY_SLASH] = KC_HOME_DOT,
    [KEY_RSHIFT] = KC_RSFT,
    [KEY_UP] = KC_UP,

    [KEY_FN] = KC_NO,
    [KEY_LCTRL] = KC_LCTL,
    [KEY_LGUI] = KC_LGUI,
    [KEY_LALT] = KC_MOD_LALT,
    [KEY_SPACE1] = KC_MOD_SPACE1,
    [KEY_SPACE2] = KC_SPC,
    [KEY_RALT] = KC_RALT,
    [KEY_RGUI] = KC_RGUI,
    [KEY_FN1] = KC_RCTL,
    [KEY_LEFT] = KC_LEFT,
    [KEY_DOWN] = KC_DOWN,
    [KEY_RIGHT] = KC_RIGHT,
};

const uint16_t punc_layer[MATRIX_ROWS * MATRIX_COLS] = {
    [KEY_TAB] = _______,
    [KEY_Q] = KC_EXCLAIM,
    [KEY_W] = KC_AT,
    [KEY_E] = KC_HASH,
    [KEY_R] = KC_DOLLAR,
    [KEY_T] = KC_PERCENT,
    [KEY_Y] = KC_CIRCUMFLEX,
    [KEY_U] = KC_LBRC,
    [KEY_I] = KC_RBRC,
    [KEY_O] = KC_LEFT_PAREN,
    [KEY_P] = KC_RIGHT_PAREN,
    [KEY_LBRACKET] = _______,
    [KEY_RBRACKET] = _______,
    [KEY_BACKSLASH] = _______,
    [KEY_MUTE] = _______,

    [KEY_CAPS] = _______,
    [KEY_A] = KC_TAB,
    [KEY_S] = KC_MINUS,
    [KEY_D] = KC_UNDERSCORE,
    [KEY_F] = KC_PLUS,
    [KEY_G] = KC_TILDE,
    [KEY_H] = KC_EQUAL,
    [KEY_J] = KC_BACKSLASH,
    [KEY_K] = KC_QUOTE,
    [KEY_L] = KC_DOUBLE_QUOTE,
    [KEY_SEMICOLON] = KC_ENT,
    [KEY_QUOTE] = _______,
    [KEY_ENTER] = _______,
    [KEY_WIN_FN2] = _______,

    [KEY_LSHIFT] = KC_LSFT,
    [KEY_Z] = KC_LSFT,
    [KEY_X] = KC_GRAVE,
    [KEY_C] = KC_QUES,
    [KEY_V] = KC_AMPERSAND,
    [KEY_B] = KC_PIPE,
    [KEY_N] = KC_ASTERISK,
    [KEY_M] = KC_LEFT_CURLY_BRACE,
    [KEY_COMMA] = KC_RIGHT_CURLY_BRACE,
    [KEY_DOT] = KC_SLSH,
    [KEY_SLASH] = KC_SLSH,
    [KEY_RSHIFT] = _______,
    [KEY_UP] = _______,

    [KEY_FN] = _______,
    [KEY_LCTRL] = _______,
    [KEY_LGUI] = _______,
    [KEY_LALT] = _______,
    [KEY_SPACE1] = _______,
    [KEY_SPACE2] = _______,
    [KEY_RALT] = _______,
    [KEY_RGUI] = _______,
    [KEY_FN1] = _______,
    [KEY_LEFT] = _______,
    [KEY_DOWN] = _______,
    [KEY_RIGHT] = _______,
};

const uint16_t nav_layer[MATRIX_ROWS * MATRIX_COLS] = {
    [KEY_TAB] = _______,
    [KEY_Q] = _______,
    [KEY_W] = _______,
    [KEY_E] = _______,
    [KEY_R] = _______,
    [KEY_T] = _______,
    [KEY_Y] = _______,
    [KEY_U] = KC_0,
    [KEY_I] = KC_UP,
    [KEY_O] = KC_DOLLAR,
    [KEY_P] = _______,
    [KEY_LBRACKET] = _______,
    [KEY_RBRACKET] = _______,
    [KEY_BACKSLASH] = _______,
    [KEY_MUTE] = _______,

    [KEY_CAPS] = _______,
    [KEY_A] = _______,
    [KEY_S] = _______,
    [KEY_D] = _______,
    [KEY_F] = _______,
    [KEY_G] = _______,
    [KEY_H] = _______,
    [KEY_J] = KC_LEFT,
    [KEY_K] = KC_DOWN,
    [KEY_L] = KC_RIGHT,
    [KEY_SEMICOLON] = _______,
    [KEY_QUOTE] = _______,
    [KEY_ENTER] = _______,
    [KEY_WIN_FN2] = _______,

    [KEY_LSHIFT] = _______,
    [KEY_Z] = _______,
    [KEY_X] = _______,
    [KEY_C] = _______,
    [KEY_V] = _______,
    [KEY_B] = _______,
    [KEY_N] = _______,
    [KEY_M] = _______,
    [KEY_COMMA] = _______,
    [KEY_DOT] = _______,
    [KEY_SLASH] = _______,
    [KEY_RSHIFT] = _______,
    [KEY_UP] = _______,

    [KEY_FN] = _______,
    [KEY_LCTRL] = _______,
    [KEY_LGUI] = _______,
    [KEY_LALT] = _______,
    [KEY_SPACE1] = _______,
    [KEY_SPACE2] = _______,
    [KEY_RALT] = _______,
    [KEY_RGUI] = _______,
    [KEY_FN1] = _______,
    [KEY_LEFT] = _______,
    [KEY_DOWN] = _______,
    [KEY_RIGHT] = _______,
};

const uint16_t num_layer[MATRIX_ROWS * MATRIX_COLS] = {
    [KEY_TAB] = _______,
    [KEY_Q] = KC_1,
    [KEY_W] = KC_2,
    [KEY_E] = KC_3,
    [KEY_R] = KC_4,
    [KEY_T] = KC_5,
    [KEY_Y] = KC_6,
    [KEY_U] = KC_7,
    [KEY_I] = KC_8,
    [KEY_O] = KC_9,
    [KEY_P] = KC_0,
    [KEY_LBRACKET] = _______,
    [KEY_RBRACKET] = _______,
    [KEY_BACKSLASH] = _______,
    [KEY_MUTE] = _______,

    [KEY_CAPS] = _______,
    [KEY_A] = _______,
    [KEY_S] = _______,
    [KEY_D] = _______,
    [KEY_F] = _______,
    [KEY_G] = _______,
    [KEY_H] = KC_LEFT,
    [KEY_J] = KC_DOWN,
    [KEY_K] = KC_UP,
    [KEY_L] = KC_RIGHT,
    [KEY_SEMICOLON] = _______,
    [KEY_QUOTE] = _______,
    [KEY_ENTER] = _______,
    [KEY_WIN_FN2] = _______,

    [KEY_LSHIFT] = _______,
    [KEY_Z] = _______,
    [KEY_X] = _______,
    [KEY_C] = _______,
    [KEY_V] = _______,
    [KEY_B] = _______,
    [KEY_N] = _______,
    [KEY_M] = _______,
    [KEY_COMMA] = _______,
    [KEY_DOT] = _______,
    [KEY_SLASH] = _______,
    [KEY_RSHIFT] = _______,
    [KEY_UP] = _______,

    [KEY_FN] = _______,
    [KEY_LCTRL] = _______,
    [KEY_LGUI] = _______,
    [KEY_LALT] = _______,
    [KEY_SPACE1] = _______,
    [KEY_SPACE2] = _______,
    [KEY_RALT] = _______,
    [KEY_RGUI] = _______,
    [KEY_FN1] = _______,
    [KEY_LEFT] = _______,
    [KEY_DOWN] = _______,
    [KEY_RIGHT] = _______,
};

const uint16_t f_layer[MATRIX_ROWS * MATRIX_COLS] = {
    [KEY_TAB] = _______,
    [KEY_Q] = KC_F1,
    [KEY_W] = KC_F2,
    [KEY_E] = KC_F3,
    [KEY_R] = KC_F4,
    [KEY_T] = KC_F5,
    [KEY_Y] = KC_F6,
    [KEY_U] = KC_F7,
    [KEY_I] = KC_F8,
    [KEY_O] = KC_F9,
    [KEY_P] = KC_F10,
    [KEY_LBRACKET] = _______,
    [KEY_RBRACKET] = _______,
    [KEY_BACKSLASH] = _______,
    [KEY_MUTE] = _______,

    [KEY_CAPS] = _______,
    [KEY_A] = KC_BRIGHTNESS_DOWN,
    [KEY_S] = KC_BRIGHTNESS_UP,
    [KEY_D] = KC_MEDIA_PREV_TRACK,
    [KEY_F] = KC_MEDIA_PLAY_PAUSE,
    [KEY_G] = KC_MEDIA_NEXT_TRACK,
    [KEY_H] = KC_MUTE,
    [KEY_J] = KC_VOLD,
    [KEY_K] = KC_VOLU,
    [KEY_L] = KC_F11,
    [KEY_SEMICOLON] = KC_F12,
    [KEY_QUOTE] = _______,
    [KEY_ENTER] = _______,
    [KEY_WIN_FN2] = _______,

    [KEY_LSHIFT] = _______,
    [KEY_Z] = _______,
    [KEY_X] = _______,
    [KEY_C] = _______,
    [KEY_V] = _______,
    [KEY_B] = _______,
    [KEY_N] = _______,
    [KEY_M] = _______,
    [KEY_COMMA] = _______,
    [KEY_DOT] = _______,
    [KEY_SLASH] = _______,
    [KEY_RSHIFT] = _______,
    [KEY_UP] = _______,

    [KEY_FN] = _______,
    [KEY_LCTRL] = _______,
    [KEY_LGUI] = _______,
    [KEY_LALT] = _______,
    [KEY_SPACE1] = KC_MEDIA_NEXT_TRACK,
    [KEY_SPACE2] = KC_MEDIA_PLAY_PAUSE,
    [KEY_RALT] = _______,
    [KEY_RGUI] = _______,
    [KEY_FN1] = _______,
    [KEY_LEFT] = _______,
    [KEY_DOWN] = _______,
    [KEY_RIGHT] = _______,
};


const uint16_t fn_layer[MATRIX_ROWS * MATRIX_COLS] = {
    [KEY_TAB] = _______,
    [KEY_Q] = _______,
    [KEY_W] = _______,
    [KEY_E] = _______,
    [KEY_R] = _______,
    [KEY_T] = _______,
    [KEY_Y] = _______,
    [KEY_U] = _______,
    [KEY_I] = _______,
    [KEY_O] = _______,
    [KEY_P] = _______,
    [KEY_LBRACKET] = _______,
    [KEY_RBRACKET] = _______,
    [KEY_BACKSLASH] = _______,
    [KEY_MUTE] = RGB_TOG,

    [KEY_CAPS] = _______,
    [KEY_A] = RGB_VAI,
    [KEY_S] = RGB_VAD,
    [KEY_D] = RGB_HUI,
    [KEY_F] = RGB_HUD,
    [KEY_G] = RGB_SAI,
    [KEY_H] = RGB_SAD,
    [KEY_J] = RGB_SPI,
    [KEY_K] = RGB_SPD,
    [KEY_L] = _______,
    [KEY_SEMICOLON] = _______,
    [KEY_QUOTE] = _______,
    [KEY_ENTER] = TG(LY_GAME),
    [KEY_WIN_FN2] = _______,

    [KEY_LSHIFT] = _______,
    [KEY_Z] = _______,
    [KEY_X] = _______,
    [KEY_C] = _______,
    [KEY_V] = _______,
    [KEY_B] = _______,
    [KEY_N] = _______,
    [KEY_M] = _______,
    [KEY_COMMA] = _______,
    [KEY_DOT] = _______,
    [KEY_SLASH] = _______,
    [KEY_RSHIFT] = _______,
    [KEY_UP] = DT_UP,

    [KEY_FN] = _______,
    [KEY_LCTRL] = _______,
    [KEY_LGUI] = _______,
    [KEY_LALT] = _______,
    [KEY_SPACE1] = NK_TOGG,
    [KEY_SPACE2] = _______,
    [KEY_RALT] = _______,
    [KEY_RGUI] = _______,
    [KEY_FN1] = _______,
    [KEY_LEFT] = _______,
    [KEY_DOWN] = DT_DOWN,
    [KEY_RIGHT] = DT_PRNT,
};

const uint16_t game_layer[MATRIX_ROWS * MATRIX_COLS] = {
    [KEY_TAB] = KC_TAB,
    [KEY_Q] = KC_Q,
    [KEY_W] = KC_W,
    [KEY_E] = KC_E,
    [KEY_R] = KC_R,
    [KEY_T] = KC_T,
    [KEY_Y] = KC_Y,
    [KEY_U] = KC_U,
    [KEY_I] = KC_I,
    [KEY_O] = KC_O,
    [KEY_P] = KC_P,
    [KEY_LBRACKET] = KC_LBRC,
    [KEY_RBRACKET] = KC_RBRC,
    [KEY_BACKSLASH] = KC_BACKSLASH,
    [KEY_MUTE] = KC_MPLY,

    [KEY_CAPS] = KC_NO,
    [KEY_A] = KC_A,
    [KEY_S] = KC_S,
    [KEY_D] = KC_D,
    [KEY_F] = KC_F,
    [KEY_G] = KC_G,
    [KEY_H] = KC_H,
    [KEY_J] = KC_J,
    [KEY_K] = KC_K,
    [KEY_L] = KC_L,
    [KEY_SEMICOLON] = KC_HOME_SCLN,
    [KEY_QUOTE] = KC_QUOTE,
    [KEY_ENTER] = KC_ENT,
    [KEY_WIN_FN2] = MO(MAC_FN1),

    [KEY_LSHIFT] = KC_LSFT,
    [KEY_Z] = KC_Z,
    [KEY_X] = KC_X,
    [KEY_C] = KC_C,
    [KEY_V] = KC_V,
    [KEY_B] = KC_B,
    [KEY_N] = KC_N,
    [KEY_M] = KC_M,
    [KEY_COMMA] = KC_COMM,
    [KEY_DOT] = KC_DOT,
    [KEY_SLASH] = KC_SLSH,
    [KEY_RSHIFT] = KC_RSFT,
    [KEY_UP] = KC_UP,

    [KEY_FN] = KC_NO,
    [KEY_LCTRL] = KC_LCTL,
    [KEY_LGUI] = KC_LGUI,
    [KEY_LALT] = KC_LALT,
    [KEY_SPACE1] = LT(LY_NUM, KC_SPC),
    [KEY_SPACE2] = KC_SPC,
    [KEY_RALT] = KC_RALT,
    [KEY_RGUI] = KC_RGUI,
    [KEY_FN1] = KC_RCTL,
    [KEY_LEFT] = KC_LEFT,
    [KEY_DOWN] = KC_DOWN,
    [KEY_RIGHT] = KC_RIGHT,
};


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = CREATE_LAYOUT(base_layer),

    [WIN_BASE] = LAYOUT_54_ansi(
        KC_TAB,  KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,     KC_RBRC,  KC_BSLS,          KC_MUTE,
        KC_CAPS, KC_A,     KC_S,     KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,               KC_ENT,           KC_HOME,
        KC_LSFT,           KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,               KC_RSFT, KC_UP,
        KC_LCTL, KC_LWIN,  KC_LALT,  MO(WIN_FN1),      KC_SPC,                    KC_SPC,           KC_RALT,  MO(WIN_FN1), MO(WIN_FN1),  KC_LEFT, KC_DOWN, KC_RGHT),

    [MAC_FN1] = CREATE_LAYOUT(fn_layer),

    [WIN_FN1] = LAYOUT_54_ansi(
        KC_GRV,  KC_BRID,  KC_BRIU,  KC_TASK, KC_FLXP, RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE,  KC_VOLD,     KC_VOLU,  _______,          RGB_TOG,
        RGB_TOG, RGB_MOD,  RGB_VAI,  RGB_HUI, RGB_SAI, RGB_SPI, _______, _______, _______, _______, _______,  _______,               _______,          _______,
        _______,           RGB_RMOD, RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD, NK_TOGG, _______, _______, _______,  _______,               _______, _______,
        _______, _______,  _______,  _______,          _______,                   _______,          _______,  _______,     _______,  _______, _______, _______),

    [LY_PUNC] = CREATE_LAYOUT(punc_layer),
    [LY_NAV] = CREATE_LAYOUT(nav_layer),
    [LY_F] = CREATE_LAYOUT(f_layer),
    [LY_NUM] = CREATE_LAYOUT(num_layer),
    [LY_GAME] = CREATE_LAYOUT(game_layer),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [MAC_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [WIN_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [MAC_FN1] = {ENCODER_CCW_CW(RGB_MOD, RGB_RMOD)},
    [WIN_FN1] = {ENCODER_CCW_CW(RGB_MOD, RGB_RMOD)},
    [LY_PUNC] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [LY_NAV] = {ENCODER_CCW_CW(KC_PGDN, KC_PGUP)},
    [LY_NUM] = {ENCODER_CCW_CW(_______, _______)},
    [LY_F] = {ENCODER_CCW_CW(KC_BRID, KC_BRIU)},
    [LY_GAME] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
};
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case UP_CHANGE_LAYER:
            if (record->event.pressed) {
                tap_code(KC_UP);
                layer_on(LY_NAV);
            } else {
                // when keycode QMKBEST is released
                layer_off(LY_NAV);
            }
            break;
        case DOWN_CHANGE_LAYER:
            if (record->event.pressed) {
                tap_code(KC_DOWN);
                layer_on(LY_NAV);
            } else {
                // when keycode QMKBEST is released
                layer_off(LY_NAV);
            }
            break;
        case LEFT_CHANGE_LAYER:
            if (record->event.pressed) {
                tap_code(KC_LEFT);
                layer_on(LY_NAV);
            } else {
                // when keycode QMKBEST is released
                layer_off(LY_NAV);
            }
            break;
        case RIGHT_CHANGE_LAYER:
            if (record->event.pressed) {
                tap_code(KC_RIGHT);
                layer_on(LY_NAV);
            } else {
                // when keycode QMKBEST is released
                layer_off(LY_NAV);
            }
            break;
        case LT(0,KC_MPLY):
            if (record->tap.count && record->event.pressed) {
                tap_code16(C(KC_MPLY)); // Intercept tap function to send Ctrl-C
            } else if (record->event.pressed) {
                tap_code16(C(KC_MUTE)); // Intercept hold function to send Ctrl-V
            }
            return false;
    }
    return true;
}

#include "g/keymap_combo.h"


bool get_combo_must_tap(uint16_t index, combo_t *combo) {
    // If you want all combos to be tap-only, just uncomment the next line
    return true;
}

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    switch (combo_index) {
      case FA_TAB:
      case FD_LY_PUNC:
      case FW_AT:
      case FE_HASH:
      case FR_DOLLAR:
      case FY_CIRCUMFLEX:
      case FU_LBRC:
      case FI_RBRC:
      case FO_LEFT_PAREN:
      case FP_RIGHT_PAREN:
      case FS_MINUS:
      case FD_UNDERSCORE:
      case FH_EQUAL:
      case FX_GRAVE:
      case FB_PIPE:
      case FN_ASTERISK:
      case FM_LEFT_CURLY_BRACE:
      case FCOMM_RIGHT_CURLY_BRACE:
      case JQ_EXLM:
      case JW_AT:
      case JE_HASH:
      case JR_DOLLAR:
      case JT_PERCENT:
      case JG_TILDE:
      case JK_QUOTE:
      case JL_DOUBLE_QUOTE:
      case JC_QUES:
      case JV_AMPERSAND:
      case JB_PIPE:
      case JRSFT_DOT_SLSH:
      case CW_CAW:
      case DW_DAW:
      case VW_VAW:
      case YW_YAW:
      case VP_VAWP:
      case YP_YYP:
      case CJL_CADQUOTE:
      case DJL_DADQUOTE:
      case VJL_VADQUOTE:
      case YJL_YADQUOTE:
      case CJK_CAQUOTE:
      case DJK_DAQUOTE:
      case VJK_VAQUOTE:
      case YJK_YAQUOTE:
      case CFU_CALBRC:
      case DFU_DALBRC:
      case VFU_VALBRC:
      case YFU_YALBRC:
      case CFO_CALPAREN:
      case DFO_DALPAREN:
      case VFO_VALPAREN:
      case YFO_YALPAREN:
      case CFM_CALCURLY:
      case DFM_DALCURLY:
      case VFM_VALCURLY:
      case YFM_YALCURLY:
      case CAP_CAP:
      case DAP_DAP:
      case VAP_VAP:
      case YAP_YAP:
            if (!layer_state_is(MAC_BASE)) {
                return false;
            }
            return true;

        case JSCLN_ENT:
        case FQ_ESC:
        case JP_BSPC:
        case JO_DEL:
            if (!layer_state_is(MAC_BASE) && !layer_state_is(LY_NUM) && !layer_state_is(LY_GAME)) {
                return false;
            }
            return true;

        case DTAB_ESC:
            if (!layer_state_is(LY_GAME)) {
                return false;
            }
            return true;
    }

    return true;
}

