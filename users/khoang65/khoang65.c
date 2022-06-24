// Copyright 2022 Kevin Hoang (@khoang65) <khoang65@gmail.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#include "khoang65.h"

// Future feature flag to toggle for Mac functionality
bool onMac = false;

// Flags to determine if the key is currently physically pressed
bool isShiftPressed = false; 
bool isCtrlPressed = false;  

// Overloaded function for indivual keymaps if they need something extra/keyboard specific
__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }

// Defines actions for my custom keycodes.
// Then runs the _keymap's record handler if not processed here,
// And use "NEWPLACEHOLDER" for new safe range
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  /** if you want the _keymap to run first, uncomment following line and remove call at bottom of function **/
  // if(!process_record_keymap(keycode, record)) return false;

  switch (keycode) {
    case KC_LSHIFT:
      if (record->event.pressed) {
        isShiftPressed = true;
      } else {
        isShiftPressed = false;
      }
      return true; // Let QMK process the keycode as usual
    
    case KC_RSHIFT:
      if (record->event.pressed) {
        isShiftPressed = true;
      } else {
        isShiftPressed = false;
      }
      return true;
      
    case KC_LCTL:
      if (record->event.pressed) {
        isCtrlPressed = true;
      } else {
        isCtrlPressed = false;
      }
      return true;
    
    case KC_RCTL:
      if (record->event.pressed) {
        isCtrlPressed = true;
      } else {
        isCtrlPressed = false;
      }
      return true;
  }
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
// ************** Leader Key Macros *************** //
// ************************************************ //
#ifdef LEADER_ENABLE
/** (▌) PARENTHESIS **/
void ldr_send_parenthesis_cursor_wrap(void) {
    SEND_STRING("()" SS_TAP(X_LEFT));
}
/** [▌] SQUARE BRACKET **/
void ldr_send_bracket_cursor_wrap(void) {
    SEND_STRING("[]" SS_TAP(X_LEFT));
}
/** '▌' SINGLE QUOTE **/
void ldr_send_quotesingle_cursor_wrap(void) {
    SEND_STRING("''" SS_TAP(X_LEFT));
}
/** "▌" DOUBLE QUOTE **/
void ldr_send_quotedouble_cursor_wrap(void) {
    SEND_STRING("\"\"" SS_TAP(X_LEFT));
}
/** {▌} CURLY BRACE **/
void ldr_send_curly_brace_cursor_wrap(void) {
    SEND_STRING("{}" SS_TAP(X_LEFT));
}
/** [▌] SQUARE BRACKET **/
void ldr_send_squarebracket_cursor_wrap(void) {
    SEND_STRING("[]" SS_TAP(X_LEFT));
}
/** <▌> ANGLE BRACKET **/
void ldr_send_angle_bracket_cursor_wrap(void) {
    SEND_STRING("<>" SS_TAP(X_LEFT));
}
/** `▌` GRAVE **/
void ldr_send_grave_cursor_wrap(void) {
    SEND_STRING("``" SS_TAP(X_LEFT));
}
/** /▌/ FORWARD SLASH **/
void ldr_send_forward_slash_cursor_wrap(void) {
    SEND_STRING("//" SS_TAP(X_LEFT));
}
/** *▌* ASTERISK **/
void ldr_send_asterisk_cursor_wrap(void) {
    SEND_STRING("**" SS_TAP(X_LEFT));
}
/** @▌@ AT **/
void ldr_send_at_cursor_wrap(void) {
    SEND_STRING("@@" SS_TAP(X_LEFT));
}
/** %▌% PERCENT **/
void ldr_send_percent_cursor_wrap(void) {
    SEND_STRING("%%" SS_TAP(X_LEFT));
}
#endif // LEADER_ENABLE


// ************************************************ //
// ************* LAYER RGB INDICATORS ************* //
// ************************************************ //
#ifdef RGB_MATRIX_ENABLE
/** Leader Key per-key LED  **/
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
/** WIP Code for layer state LED underglow **/
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
