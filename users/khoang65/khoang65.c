#include "khoang65.h"

// ************************************************ //
// *********** KEYBOARD PRE/POST INIT ************* //
// ************************************************ //
void keyboard_pre_init_user(void) {
  // rgblight_disable_noeeprom(); // ideally disables RBG on startup, prevents LED flash on plugin; needs to be moved to POST
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

void keyboard_post_init_user() {
  numlock_on();
  #ifdef RGBLIGHT_ENABLE
  rgblight_disable_noeeprom();
  #endif // !RGBLIGHT_ENABLE
}