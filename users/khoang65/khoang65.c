#include "khoang65.h"

// Future flag for Mac use
bool onMac = false;

bool isShiftPressed = false; 
bool isCtrlPressed = false;  

// Overloaded function for indivual keymaps if they need something extra/keyboard specific
__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }

// Defines actions for my custom keycodes.
// Then runs the _keymap's record handler if not processed here,
// And use "NEWPLACEHOLDER" for new safe range
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return process_record_keymap(keycode, record);
}

// ************************************************ //
// *********** KEYBOARD PRE/POST INIT ************* //
// ************************************************ //
__attribute__((weak)) void keyboard_pre_init_keymap(void) {}
__attribute__((weak)) void keyboard_post_init_keymap(void) {}

void keyboard_pre_init_user(void) {
  keyboard_pre_init_keymap();
}

void keyboard_post_init_user(void) {
  numlock_on();
  #ifdef RGBLIGHT_ENABLE
  rgblight_disable_noeeprom();
  #endif // !RGBLIGHT_ENABLE

  keyboard_post_init_keymap();
}

// Numlock on boot <https://github.com/qmk/qmk_firmware/issues/10890#issuecomment-927222187>
void numlock_on(void) {
  led_t led_state = host_keyboard_led_state();
  bool isNumlock = led_state.num_lock;
  if (!isNumlock) {
      register_code(KC_NUMLOCK);
      unregister_code(KC_NUMLOCK);
  }
}

// ************************************************ //
// ******** DYNAMIC TAP HOLD CONFIGURATION ******** //
// ************************************************ //
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case FNT_PSCR:
      return TAPPING_TERM + 40;
    default:
      return TAPPING_TERM;
  }
}
bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case CS_F14:
      return true;
    case FNT_PSCR:
      return true;
    case FNT_BSLS:
      return true;
    default:
      return false;
  }
}

// ************************************************ //
// ************* LAYER RGB INDICATORS ************* //
// ************************************************ //
#ifdef RGB_MATRIX_ENABLE
/* Leader Key per-key LED  */
/*
void rgb_matrix_indicators_user(void) { 
    if (isLeader) {
        rgb_matrix_set_color_hsv(14, 999, 999, 999, 1); // CONFIG
        rgb_matrix_set_color_hsv(30, 999, 999, 999, 1); // CONFIG
    } else {
        rgb_matrix_set_color_hsv(14, 999, 999, 999, led_dim_ratio); // CONFIG
    }  
}
*/
#endif // !RGB_MATRIX_ENABLE

#ifdef RGBLIGHT_ENABLE
/* WIP Code for layer state LED underglow */
/*
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _BASE:
        rgblight_sethsv_noeeprom(HSV_GOLD);
        break;
    case _ADJUST:
        rgblight_sethsv_noeeprom(HSV_RED);
        break;
    default: //  for any other layers, or the default layer
        rgblight_sethsv_noeeprom(HSV_OFF);
        break;
    }
  return state;
}
*/
#endif // !RGBLIGHT_ENABLE