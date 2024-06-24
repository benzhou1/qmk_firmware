/* Copyright 2023 projectcain
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

// Tap Dance declarations
enum {
    TD_ENC,
};

typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t double_tap;
    uint16_t held;
} tap_dance_tap_hold_t;


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    TD(TD_ENC),    MO(1),    MO(2),    MO(3),
    KC_7,    KC_8,    KC_9,    _______,
    KC_6,    KC_5,    KC_4,    _______,
    KC_1,    KC_2,    KC_3,   _______
  ),

  [1] = LAYOUT(
    _______,    _______,    _______,    _______,
    _______,    _______,    _______,    _______,
    _______,    _______,    _______,    _______,
    _______,    _______,    _______,    _______
  ),

  [2] = LAYOUT(
    _______,    _______,    _______,    _______,
    _______,    _______,    _______,    _______,
    _______,    _______,    _______,    _______,
    _______,    _______,    _______,    _______
  ),

  [3] = LAYOUT(
    QK_BOOT,    _______,    _______,    _______,
    _______,    _______,    _______,    _______,
    _______,    _______,    _______,    _______,
    _______,    _______,    _______,    _______
  ),

};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] =   { ENCODER_CCW_CW(KC_VOLU, KC_VOLD),   ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [1] =  { ENCODER_CCW_CW(_______, _______),   ENCODER_CCW_CW(_______, _______) },
    [2] =  { ENCODER_CCW_CW(_______, _______),   ENCODER_CCW_CW(_______, _______) },
    [3] =  { ENCODER_CCW_CW(_______, _______),   ENCODER_CCW_CW(_______, _______) },
};
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    tap_dance_action_t *action;

    switch (keycode) {
        /* case TD(TD_ENC):  // list all tap dance keycodes with tap-hold configurations */
        /*     action = &tap_dance_actions[QK_TAP_DANCE_GET_INDEX(keycode)]; */
        /*     if (!record->event.pressed && action->state.count && !action->state.finished) { */
        /*         tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data; */
        /*         tap_code16(tap_hold->tap); */
        /*     } */
    }
    return true;
}

void tap_dance_tap_hold_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (state->count == 1) {
        if (state->interrupted || !state->pressed) {
            register_code16(tap_hold->tap);
        }
        else {
            register_code16(tap_hold->hold);
            tap_hold->held = tap_hold->hold;
        }
    } else if (state->count == 2) {
        if (state->interrupted || !state->pressed) {
            register_code16(tap_hold->double_tap);
        }
        /* else { */
        /*     register_code16(tap_hold->hold); */
        /*     tap_hold->held = tap_hold->hold; */
        /* } */
    }
}

void tap_dance_tap_hold_reset(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (tap_hold->held) {
        unregister_code16(tap_hold->held);
        tap_hold->held = 0;
    }
}

typedef struct {
    uint16_t kc1;
    uint16_t kc2;
    uint16_t kc3;
} tap_dance_pair_hold_t;

void tap_dance_pair_on_each_tap_hold(tap_dance_state_t *state, void *user_data) {
    tap_dance_pair_hold_t *pair = (tap_dance_pair_hold_t *)user_data;

    if (state->count == 2) {
        if (state->interrupted || !state->pressed) {
            register_code16(pair->kc2);
            state->finished = true;
        }
    }
}

void tap_dance_pair_hold_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_pair_hold_t *pair = (tap_dance_pair_hold_t *)user_data;

    if (state->interrupted || !state->pressed) {
        register_code16(pair->kc1);
    } else {
        register_code16(pair->kc3);
    }
}

void tap_dance_pair_hold_reset(tap_dance_state_t *state, void *user_data) {
    tap_dance_pair_hold_t *pair = (tap_dance_pair_hold_t *)user_data;

    if (state->count == 1) {
        wait_ms(TAP_CODE_DELAY);
        unregister_code16(pair->kc1);
        /* unregister_code16(pair->kc3); */
    } else if (state->count == 2) {
        unregister_code16(pair->kc2);
    }
}


#define ACTION_TAP_DANCE_TAP_HOLD_DOUBLETAP(tap, hold, double_tap) \
{ .fn = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, double_tap, 0}), }

#define ACTION_TAP_DANCE_DOUBLE_HOLD(kc1, kc2, kc3) \
{ .fn = {tap_dance_pair_on_each_tap_hold, tap_dance_pair_hold_finished, tap_dance_pair_hold_reset, NULL}, .user_data = (void *)&((tap_dance_pair_hold_t){kc1, kc2, kc3}), }

tap_dance_action_t tap_dance_actions[] = {
    [TD_ENC] = ACTION_TAP_DANCE_DOUBLE_HOLD(KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK, KC_MUTE),
};
