#include QMK_KEYBOARD_H

#define NUMPAD_LAYER 0
#define VIM_LAYER 1
#define VIM_HELP_LAYER 2
#define MACRO_LAYER 3

enum custom_keycodes {
    VIM_START_RECORD_A = SAFE_RANGE,
    VIM_PLAY_RECORD_A,
    VIM_END_RECORD,
    VIM_START_RECORD_B,
    VIM_PLAY_RECORD_B,
    VIM_REGISTER_C,
    VIM_REGISTER_D,
    VIM_REGISTER_E,
    VIM_REGISTER_F,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case VIM_END_RECORD:
            if (record->event.pressed) {
                SEND_STRING("\eq");
            } else {
            }
            break;

        case VIM_START_RECORD_A:
            if (record->event.pressed) {
                SEND_STRING("\eqa");
            } else {
            }
            break;

        case VIM_PLAY_RECORD_A:
            if (record->event.pressed) {
                SEND_STRING("\e@a");
            } else {
            }
            break;

        case VIM_START_RECORD_B:
            if (record->event.pressed) {
                SEND_STRING("\eqb");
            } else {
            }
            break;
        case VIM_PLAY_RECORD_B:
            if (record->event.pressed) {
                SEND_STRING("\e@b");
            } else {
            }
            break;

        case VIM_REGISTER_C:
            if (record->event.pressed) {
                SEND_STRING("\"c");
            } else {
            }
            break;
        case VIM_REGISTER_D:
            if (record->event.pressed) {
                SEND_STRING("\"d");
            } else {
            }
            break;
        case VIM_REGISTER_E:
            if (record->event.pressed) {
                SEND_STRING("\"e");
            } else {
            }
            break;
        case VIM_REGISTER_F:
            if (record->event.pressed) {
                SEND_STRING("\"f");
            } else {
            }
            break;
    }

    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [NUMPAD_LAYER] = LAYOUT_numpad_4x5(
    TG(VIM_LAYER), KC_PSLS,  KC_PAST, KC_PMNS,
    KC_P7,   KC_P8,   KC_P9,   
    KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
    KC_P1,   KC_P2,   KC_P3,   
        KC_P0,        KC_DOT,  KC_PENT
  ),
  [VIM_LAYER] = LAYOUT_numpad_4x5(
    TG(VIM_LAYER), KC_NUM, KC_NO,  KC_NO, 
    VIM_START_RECORD_A,   VIM_START_RECORD_B,   VIM_REGISTER_C,   
    VIM_PLAY_RECORD_A,   VIM_PLAY_RECORD_B,   VIM_REGISTER_D,   KC_NO,
    VIM_END_RECORD,   VIM_REGISTER_F,   VIM_REGISTER_E,   
        KC_NO,        KC_NO,  KC_NO
  ),
  // [VIM_HELP_LAYER] = LAYOUT_numpad_4x5(
  //   TG(NUMPAD_LAYER), KC_PSLS,  KC_PAST, KC_PMNS,
  //   KC_Q,   KC_W,   KC_E,   
  //   KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
  //   KC_P1,   KC_P2,   KC_P3,   
  //       KC_P0,        KC_DOT,  KC_PENT
  // ),
  // [MACRO_LAYER] = LAYOUT_numpad_4x5(
  //   TG(NUMPAD_LAYER), KC_PSLS,  KC_PAST, KC_PMNS,
  //   KC_Q,   KC_W,   KC_E,   
  //   KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
  //   KC_P1,   KC_P2,   KC_P3,   
  //       KC_P0,        KC_DOT,  KC_PENT
  // ),
};
