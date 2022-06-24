#pragma once

#include QMK_KEYBOARD_H

// Initialize variable holding the binary
// representation of active modifiers.
uint8_t mod_state;

// Flags to determine if the key is currently physically pressed
//   used so modifiers can be held to send repeated modifier'd actions
extern bool isShiftPressed; 
extern bool isCtrlPressed;  

enum layer_names {
    _BASE = 0,
    _FN,   // = 1
    _VIMTOGGLE, // = 2
    _NUM,  // = 3
    _VIM,  // = 4
    _SYM,  // = 5
    _ADJUST// = 6
};

// My Abbreviated Quantum Keycodes
#define ALL_      ALL_T(KC_NO)
#define MEH_F13   MEH_T(KC_F13)
#define CS_F14    C_S_T(KC_F14)
#define FNT_PSCR  LT(_FN,KC_PSCR)
#define FNT_BSLS  LT(_FN,KC_BSLS)
#define CTLC    LCTL(KC_C)
#define CTLX    LCTL(KC_X)
#define CTLF    LCTL(KC_F)

// Function for turning on numlock on startup
void numlock_on(void);

// Leader Key function Declaration
#ifdef LEADER_ENABLE
// Cursor Wrap Functions
void ldr_send_parenthesis_cursor_wrap(void);
void ldr_send_bracket_cursor_wrap(void);
void ldr_send_quotesingle_cursor_wrap(void);
void ldr_send_quotedouble_cursor_wrap(void);
void ldr_send_curly_brace_cursor_wrap(void);
void ldr_send_squarebracket_cursor_wrap(void);
void ldr_send_angle_bracket_cursor_wrap(void);
void ldr_send_grave_cursor_wrap(void);
void ldr_send_forward_slash_cursor_wrap(void);
void ldr_send_asterisk_cursor_wrap(void);
void ldr_send_at_cursor_wrap(void);
void ldr_send_percent_cursor_wrap(void);
#endif // LEADER_ENABLE


