#pragma once

#include QMK_KEYBOARD_H

bool isShiftPressed = false; // flags to determine if the key is currently held instead of registered 
bool isCtrlPressed = false;  //   used so modifiers can be held to send repeated modifier vim macros 
uint8_t mod_state;

enum layer_names {
    _BASE = 0,
    _FN,   // = 1
    _VIMTOGGLE, // = 2
    _NUM,  // = 3
    _VIM,  // = 4
    _SYM,  // = 5
    _ADJUST// = 6
};

#define ALL_      ALL_T(KC_NO) 
#define MEH_F13   MEH_T(KC_F13)
#define CS_F14    C_S_T(KC_F14)
#define FNT_PSCR  LT(_FN,KC_PSCR)
#define FNT_BSLS  LT(_FN,KC_BSLS)

#define CTLC    LCTL(KC_C)
#define CTLX    LCTL(KC_X)
#define CTLF    LCTL(KC_F)

