#include "khoang65.h"

// Future flag for Mac use
bool onMac = false;

bool isShiftPressed = false; 
bool isCtrlPressed = false;  

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }

// Defines actions tor my global custom keycodes. Defined in drashna.h file
// Then runs the _keymap's recod handier if not processed here,
// And use "NEWPLACEHOLDER" for new safe range
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    return process_record_keymap(keycode, record);
}