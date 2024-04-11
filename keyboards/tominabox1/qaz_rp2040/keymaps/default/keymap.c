#include QMK_KEYBOARD_H

enum layers_enums {
    BASE,
    LY_PUNC,
    LY_NAV,
    LY_NUM,
    LY_F
};

enum keys {
    KEY_Q, KEY_W, KEY_E, KEY_R, KEY_T, KEY_Y, KEY_U, KEY_I, KEY_O, KEY_P,
    KEY_A, KEY_S, KEY_D, KEY_F , KEY_G, KEY_H, KEY_J, KEY_K, KEY_L, KEY_SEMICOLON,
    KEY_Z, KEY_X, KEY_C, KEY_V , KEY_B, KEY_N, KEY_M, KEY_COMMA, KEY_DOT,
    KEY_LCTRL, KEY_LGUI, KEY_LALT, KEY_SPACE1, KEY_SPACE2, KEY_RALT, KEY_RGUI, KEY_RCTRL
};

#define CREATE_LAYOUT(layer_keys) LAYOUT(layer_keys[KEY_Q],layer_keys[KEY_W],layer_keys[KEY_E],layer_keys[KEY_R],layer_keys[KEY_T],layer_keys[KEY_Y],layer_keys[KEY_U],layer_keys[KEY_I],layer_keys[KEY_O],layer_keys[KEY_P],layer_keys[KEY_A],layer_keys[KEY_S],layer_keys[KEY_D],layer_keys[KEY_F],layer_keys[KEY_G],layer_keys[KEY_H],layer_keys[KEY_J],layer_keys[KEY_K],layer_keys[KEY_L],layer_keys[KEY_SEMICOLON],layer_keys[KEY_Z],layer_keys[KEY_X],layer_keys[KEY_C],layer_keys[KEY_V],layer_keys[KEY_B],layer_keys[KEY_N],layer_keys[KEY_M],layer_keys[KEY_COMMA],layer_keys[KEY_DOT],layer_keys[KEY_LCTRL],layer_keys[KEY_LGUI],layer_keys[KEY_LALT],layer_keys[KEY_SPACE1],layer_keys[KEY_SPACE2],layer_keys[KEY_RALT],layer_keys[KEY_RGUI],layer_keys[KEY_RCTRL])

const uint16_t base_layer[MATRIX_ROWS * MATRIX_COLS] = {
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

    [KEY_A] = KC_A,
    [KEY_S] = KC_S,
    [KEY_D] = KC_D,
    [KEY_F] = KC_F,
    [KEY_G] = KC_G,
    [KEY_H] = KC_H,
    [KEY_J] = KC_J,
    [KEY_K] = KC_K,
    [KEY_L] = KC_L,
    [KEY_SEMICOLON] = KC_SCLN,

    [KEY_Z] = LSFT_T(KC_Z),
    [KEY_X] = KC_X,
    [KEY_C] = KC_C,
    [KEY_V] = KC_V,
    [KEY_B] = KC_B,
    [KEY_N] = KC_N,
    [KEY_M] = KC_M,
    [KEY_COMMA] = KC_COMM,
    [KEY_DOT] = RSFT_T(KC_DOT),

    [KEY_LCTRL] = KC_LCTL,
    [KEY_LGUI] = KC_LGUI,
    [KEY_LALT] = KC_LALT,
    [KEY_SPACE1] = KC_HYPR,
    [KEY_SPACE2] = KC_SPC,
    [KEY_RALT] = KC_RALT,
    [KEY_RGUI] = KC_RGUI,
    [KEY_RCTRL] = KC_RCTL,
};

const uint16_t punc_layer[MATRIX_ROWS * MATRIX_COLS] = {
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

    [KEY_Z] = KC_LSFT,
    [KEY_X] = KC_GRAVE,
    [KEY_C] = KC_QUES,
    [KEY_V] = KC_AMPERSAND,
    [KEY_B] = KC_PIPE,
    [KEY_N] = KC_ASTERISK,
    [KEY_M] = KC_LEFT_CURLY_BRACE,
    [KEY_COMMA] = KC_RIGHT_CURLY_BRACE,
    [KEY_DOT] = KC_SLSH,

    [KEY_LCTRL] = _______,
    [KEY_LGUI] = _______,
    [KEY_LALT] = _______,
    [KEY_SPACE1] = _______,
    [KEY_SPACE2] = _______,
    [KEY_RALT] = _______,
    [KEY_RGUI] = _______,
    [KEY_RCTRL] = _______,
};

const uint16_t nav_layer[MATRIX_ROWS * MATRIX_COLS] = {
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

    [KEY_Z] = _______,
    [KEY_X] = _______,
    [KEY_C] = _______,
    [KEY_V] = _______,
    [KEY_B] = _______,
    [KEY_N] = _______,
    [KEY_M] = _______,
    [KEY_COMMA] = _______,
    [KEY_DOT] = _______,

    [KEY_LCTRL] = _______,
    [KEY_LGUI] = _______,
    [KEY_LALT] = _______,
    [KEY_SPACE1] = _______,
    [KEY_SPACE2] = _______,
    [KEY_RALT] = _______,
    [KEY_RGUI] = _______,
    [KEY_RCTRL] = _______,
};

const uint16_t num_layer[MATRIX_ROWS * MATRIX_COLS] = {
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

    [KEY_A] = _______,
    [KEY_S] = _______,
    [KEY_D] = _______,
    [KEY_F] = _______,
    [KEY_G] = _______,
    [KEY_H] = _______,
    [KEY_J] = _______,
    [KEY_K] = _______,
    [KEY_L] = _______,
    [KEY_SEMICOLON] = _______,

    [KEY_Z] = _______,
    [KEY_X] = _______,
    [KEY_C] = _______,
    [KEY_V] = _______,
    [KEY_B] = _______,
    [KEY_N] = _______,
    [KEY_M] = _______,
    [KEY_COMMA] = _______,
    [KEY_DOT] = _______,

    [KEY_LCTRL] = _______,
    [KEY_LGUI] = _______,
    [KEY_LALT] = _______,
    [KEY_SPACE1] = _______,
    [KEY_SPACE2] = _______,
    [KEY_RALT] = _______,
    [KEY_RGUI] = _______,
    [KEY_RCTRL] = _______,
};

const uint16_t f_layer[MATRIX_ROWS * MATRIX_COLS] = {
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

    [KEY_Z] = _______,
    [KEY_X] = _______,
    [KEY_C] = _______,
    [KEY_V] = _______,
    [KEY_B] = _______,
    [KEY_N] = _______,
    [KEY_M] = _______,
    [KEY_COMMA] = _______,
    [KEY_DOT] = _______,

    [KEY_LCTRL] = _______,
    [KEY_LGUI] = _______,
    [KEY_LALT] = _______,
    [KEY_SPACE1] = KC_MEDIA_NEXT_TRACK,
    [KEY_SPACE2] = KC_MEDIA_PLAY_PAUSE,
    [KEY_RALT] = _______,
    [KEY_RGUI] = _______,
    [KEY_RCTRL] = _______,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = CREATE_LAYOUT(base_layer),
    [LY_PUNC] = CREATE_LAYOUT(punc_layer),
    [LY_NAV] = CREATE_LAYOUT(nav_layer),
    [LY_NUM] = CREATE_LAYOUT(num_layer),
    [LY_F] = CREATE_LAYOUT(f_layer),
};

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_Z):
        case RSFT_T(KC_DOT):
            // Immediately select the hold action when another key is pressed.
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}


#include "g/keymap_combo.h"

bool get_combo_must_tap(uint16_t index, combo_t *combo) {
    // If you want all combos to be tap-only, just uncomment the next line
    return true;
}

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    switch (combo_index) {
          case FA_TAB:
          case JSCLN_ENT:
          case FD_LY_PUNC:
          case DK_LY_NAV:
          case DJ_LT_LYNAV_LEFT:
          case DI_LT_LYNAV_UP:
          case DK_LT_LYNAV_DOWN:
          case DL_LT_LYNAV_RIGHT:
          case SL_LY_NUM:
          case ASCLNLSFT_TGLY_F:
          case DK_LY_NUM:
          case FQ_ESC:
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
          case DU_0:
          case DO_DOLLAR:
          case LQ_1:
          case SQ_1:
          case LW_2:
          case SE_3:
          case LE_3:
          case SR_4:
          case LR_4:
          case ST_5:
          case LT_5:
          case SY_6:
          case LY_6:
          case SU_7:
          case LU_7:
          case SI_8:
          case LI_8:
          case SO_9:
          case SP_0:
          case LP_0:
          case AU_F7:
          case SCLNU_F7:
          case AI_F8:
          case SCLNI_F8:
          case AO_F9:
          case SCLNO_F9:
          case SP_F10:
          case SCLNP_F10:
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
            if (!layer_state_is(BASE)) {
                return false;
            }
            return true;

        case JP_BSPC:
        case JO_DEL:
            if (!layer_state_is(BASE) && !layer_state_is(LY_NUM)) {
                return false;
            }
            return true;
    }

    return true;
}
