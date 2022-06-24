 /* Copyright 2022 Kevin Hoang (@khoang65) <khoang65@gmail.com>
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

#pragma once

#include QMK_KEYBOARD_H
#include "print.h"
#include "quantum.h"
#include "quantum_keycodes.h"

// ** QMK VIM Implementation for Windows ** //
//  Based off ergodox_ez/keymaps/vim/
//  added more functions and modified to be more robust an work with Windows

// ** VIM Definitions ** //
int _VIM_INSERT_LAYER;

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE,
  VIM_ESC,
  LT_TO_VIM,
  VIM_0,
  VIM_4, // `$`
  VIM_6, // `^`  
  VIM_A,
  VIM_B,
  VIM_C,
  VIM_CI,
  VIM_D,
  VIM_DI,
  VIM_E,
  VIM_F,
  VIM_G,
  VIM_H,
  VIM_I,
  VIM_J,
  VIM_K,
  VIM_L,
  VIM_O,
  VIM_P,
  VIM_R,
  VIM_S,
  VIM_U,
  VIM_V,
  VIM_VI,
  VIM_W,
  VIM_X,
  VIM_Y,
  VIM_YI,
  NEWPLACEHOLDER, // SAFE_RANGE + 33
};

uint16_t VIM_QUEUE;
uint16_t LT_TO_VIM_TIMER;

void VIM_LEFT(void); 
void VIM_DOWN(void);
void VIM_UP(void);
void VIM_RIGHT(void); 
void VIM_BEGINNING(void);
void VIM_WORD(void);
void VIM_END(void);
void VIM_START_OF_LINE(void);
void VIM_BEGINNING_OF_LINE(void);
void VIM_END_OF_LINE(void);

void VIM_SCROLL_HALF_DOWN(void);
void VIM_SCROLL_HALF_UP(void);
void VIM_SCROLL_FULL_FORWARD(void);
void VIM_SCROLL_FULL_BACK(void);
void VIM_FIRST_LINE(void);
void VIM_LAST_LINE(void);

void VIM_APPEND(int insert_layer);
void VIM_APPEND_LINE(int insert_layer);
void VIM_CHANGE_BACK(int insert_layer);
void VIM_CHANGE_DOWN(int insert_layer);
void VIM_CHANGE_END(int insert_layer);
void VIM_CHANGE_INNER_WORD(int insert_layer);
void VIM_CHANGE_LEFT(int insert_layer);
void VIM_CHANGE_TO_EOL(int insert_layer);
void VIM_CHANGE_RIGHT(int insert_layer);
void VIM_CHANGE_UP(int insert_layer);
void VIM_CHANGE_WHOLE_LINE(int insert_layer);
void VIM_CHANGE_WORD(int insert_layer);
void VIM_CUT(void); 
void VIM_DELETE_BACK(void);
void VIM_DELETE_DOWN(void);
void VIM_DELETE_END(void);
void VIM_DELETE_INNER_WORD(void);
void VIM_DELETE_LEFT(void);
void VIM_DELETE_TO_EOL(void);
void VIM_DELETE_RIGHT(void);
void VIM_DELETE_UP(void);
void VIM_DELETE_WHOLE_LINE(void);
void VIM_DELETE_WORD(void);
void VIM_JOIN(void);
void VIM_OPEN(int insert_layer);
void VIM_OPEN_ABOVE(int insert_layer);
void VIM_PUT_AFTER(void); 
void VIM_PUT_BEFORE(void);
void VIM_REPLACE(void);
void VIM_SUBSTITUTE(int insert_layer);
void VIM_UNDO(void);
void VIM_VISUAL_BACK(void);
void VIM_VISUAL_DOWN(void);
void VIM_VISUAL_END(void);
void VIM_VISUAL_INNER_WORD(void);
void VIM_VISUAL_LEFT(void);
void VIM_VISUAL_RIGHT(void);
void VIM_VISUAL_UP(void);
void VIM_VISUAL_WORD(void);
void VIM_YANK(void);
void VIM_YANK_BACK(void);
void VIM_YANK_DOWN(void);
void VIM_YANK_END(void);
void VIM_YANK_INNER_WORD(void);
void VIM_YANK_LEFT(void);
void VIM_YANK_TO_EOL(void);
void VIM_YANK_RIGHT(void);
void VIM_YANK_UP(void);
void VIM_YANK_WHOLE_LINE(void);
void VIM_YANK_WORD(void);

/**
 * Sets the `VIM_QUEUE` variable to the incoming keycode.
 * Pass `KC_NO` to cancel the operation.
 * @param keycode
 */
void VIM_LEADER(uint16_t keycode);

/**
 * Keycode Helper Functions
 * Can help with function reability
 * @param keycode
 */
#define PRESS(keycode) register_code16(keycode)
#define RELEASE(keycode) unregister_code16(keycode)

void TAP(uint16_t keycode);

void CMD(uint16_t keycode);

void CTRL(uint16_t keycode);

void SHIFT(uint16_t keycode);

void ALT(uint16_t keycode);