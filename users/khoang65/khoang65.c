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
