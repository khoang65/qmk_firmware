 /* Copyright 2022-2022 Kevin Hoang
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

// ** QMK VIM Implementation for Windows ** //
//  Based off ergodox_ez/keymaps/vim/
//  added more functions and modified to be more robust an work with Windows
#pragma once

#include QMK_KEYBOARD_H
#include "print.h"
#include "quantum.h"
#include "quantum_keycodes.h"

// ** VIM Definitions ** //
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
  VIM_YI, // = 32
};

uint16_t VIM_QUEUE = KC_NO;
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

void VIM_APPEND(void);
void VIM_APPEND_LINE(void);
void VIM_CHANGE_BACK(void);
void VIM_CHANGE_DOWN(void);
void VIM_CHANGE_END(void);
void VIM_CHANGE_INNER_WORD(void);
void VIM_CHANGE_LEFT(void);
void VIM_CHANGE_TO_EOL(void);
void VIM_CHANGE_RIGHT(void);
void VIM_CHANGE_UP(void);
void VIM_CHANGE_WHOLE_LINE(void);
void VIM_CHANGE_WORD(void);
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
void VIM_OPEN(void);
void VIM_OPEN_ABOVE(void);
void VIM_PUT_AFTER(void); 
void VIM_PUT_BEFORE(void);
void VIM_REPLACE(void);
void VIM_SUBSTITUTE(void);
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
void VIM_LEADER(uint16_t keycode) {
  VIM_QUEUE = keycode;
  switch(keycode) {
    case VIM_C: print("\e[32mc\e[0m"); break;
    case VIM_CI: print("\e[32mci\e[0m"); break;
    case VIM_D: print("\e[32md\e[0m"); break;
    case VIM_DI: print("\e[32mdi\e[0m"); break;
    case VIM_G: print("\e[32mg\e[0m"); break;
    case VIM_R: print("\e[32mr\e[0m"); break;
    case VIM_V: print("\e[32mv\e[0m"); break;
    case VIM_VI: print("\e[32mvi\e[0m"); break;
    case VIM_Y: print("\e[32my\e[0m"); break;
    case VIM_YI: print("\e[32myi\e[0m"); break;
    case KC_NO: print("❎"); break;
  }
}

/**
 * Keycode Helper Functions
 * Can help with function reability
 * @param keycode
 */
#define PRESS(keycode) register_code16(keycode)
#define RELEASE(keycode) unregister_code16(keycode)

void TAP(uint16_t keycode) {
  PRESS(keycode);
  RELEASE(keycode);
}

void CMD(uint16_t keycode) {
  PRESS(KC_LGUI);
    TAP(keycode);
  RELEASE(KC_LGUI);
}

void CTRL(uint16_t keycode) {
  PRESS(KC_LCTL);
    TAP(keycode);
  RELEASE(KC_LCTL);
}

void SHIFT(uint16_t keycode) {
  PRESS(KC_LSHIFT);
    TAP(keycode);
  RELEASE(KC_LSHIFT);
}

void ALT(uint16_t keycode) {
  PRESS(KC_LALT);
    TAP(keycode);
  RELEASE(KC_LALT);
}

/****
 *.##.....##.####.##.....##....########.##.....##.##....##..######..########.####..#######..##....##..######.
 *.##.....##..##..###...###....##.......##.....##.###...##.##....##....##.....##..##.....##.###...##.##....##
 *.##.....##..##..####.####....##.......##.....##.####..##.##..........##.....##..##.....##.####..##.##......
 *.##.....##..##..##.###.##....######...##.....##.##.##.##.##..........##.....##..##.....##.##.##.##..######.
 *..##...##...##..##.....##....##.......##.....##.##..####.##..........##.....##..##.....##.##..####.......##
 *...##.##....##..##.....##....##.......##.....##.##...###.##....##....##.....##..##.....##.##...###.##....##
 *....###....####.##.....##....##........#######..##....##..######.....##....####..#######..##....##..######.
 */
 // ** VIM Implementation ** //
/***
 *       ####  #    # ######     ####  #    #  ####  ##### 
 *      #    # ##   # #         #      #    # #    #   #   
 *      #    # # #  # #####      ####  ###### #    #   #   
 *      #    # #  # # #              # #    # #    #   #   
 *      #    # #   ## #         #    # #    # #    #   #   
 *       ####  #    # ######     ####  #    #  ####    #   
 */
 
/**
 * Vim-like `append` command.
 * Works by sending →
 */
void VIM_APPEND(void) {
  print("\e[31ma\e[0m");
  TAP(KC_RIGHT);
  layer_move(_BASE);
}

/**
 * Vim-like `beginning` command
 * Simulates vim's `b` command by sending ^←
 */
void VIM_BEGINNING(void) {
  print("\e[31mb\e[0m");
  CTRL(KC_LEFT);
}

/**
 * Vim-like `cut` command
 * Simulates vim's `x` command by sending ⇧→ then ^X
 */
void VIM_CUT(void) {
  print("\e[31mx\e[0m");
  SHIFT(KC_RIGHT);
  CTRL(KC_X);
}

/**
 * Vim-like `down` command
 * Sends ↓
 */
void VIM_DOWN(void) {
  print("\e[31mj\e[0m");
  TAP(KC_DOWN);
}

/**
 * Vim-like `end` command
 * Simulates vim's `e` command by sending ^→
 */
void VIM_END(void) {
  print("\e[31me\e[0m");
  CTRL(KC_RIGHT);
}

/**
 * Vim-like `left` command
 * Sends ←
 */
void VIM_LEFT(void) {
  print("\e[31mh\e[0m");
  VIM_LEADER(KC_NO);
  TAP(KC_LEFT);
}

/**
 * Vim-like `open` command.
 * Works by sending `End` to move to the end of the line, `Enter` to open a new line,
 * then switching to insert mode.
 */
void VIM_OPEN(void) {
  print("\e[31mo\e[0m");
  VIM_LEADER(KC_NO);
  TAP(KC_END);
  TAP(KC_ENTER);
  layer_move(_BASE);
}

/**
 * Vim-like `put after` command
 * Simulates vim's `p` command by sending ^V
 */
void VIM_PUT_AFTER(void) {
  print("\e[31mp\e[0m");
  VIM_LEADER(KC_NO);
  VIM_RIGHT();
  CTRL(KC_V);
}

/**
 * Vim-like `put before` command
 * Simulates vim's `P` command by sending ↑, ^←, then ^V
 */
void VIM_PUT_BEFORE(void) {
  print("\e[31mP\e[0m");
  VIM_LEADER(KC_NO);
  CTRL(KC_V);
}

/**
 * Vim-like `replace`
 * Simulates vim's `r` command
 * ↑→
 */
void VIM_REPLACE(void){
  print("\e[31mr\e[0m");
  SHIFT(KC_RIGHT);
}

/**
 * Vim-like `right` command
 * Sends →
 */
void VIM_RIGHT(void) {
  print("\e[31ml\e[0m");
  VIM_LEADER(KC_NO);
  TAP(KC_RIGHT);
}

 /**
 * Vim-like `start of line` command.
 * Simulates vim's `0` command by sending Home, Home
 */
 void VIM_START_OF_LINE(void) {
  print("\e[31m0\e[0m");
  TAP(KC_HOME);
  TAP(KC_HOME);
 }

/**
 * Vim-like `substitute` command
 * Simulates vim's `s` command by sending ⇧→ to select the next character, then
 * ^X to cut it, then entering insert mode.
 */
void VIM_SUBSTITUTE(void) {
  print("\e[31ms\e[0m");
  VIM_LEADER(KC_NO);
  SHIFT(KC_RIGHT);
  CTRL(KC_X);
  layer_move(_BASE);
}

/**
 * Vim-like `undo` command
 * Simulates vim's `u` command by sending ^Z
 */
void VIM_UNDO(void) {
  print("\e[31mu\e[0m");
  VIM_LEADER(KC_NO);
  CTRL(KC_Z);
}

/**
 * Vim-like `up` command
 * Sends ↑
 */
void VIM_UP(void) {
  print("\e[31mk\e[0m");
  VIM_LEADER(KC_NO);
  TAP(KC_UP);
}

/**
 * Vim-like `word` command
 * Simulates vim's `w` command by moving the cursor first to the
 * end of the current word, then to the end of the next word,
 * then to the beginning of that word.
 */
void VIM_WORD(void) {
  print("\e[31mw\e[0m");
  VIM_LEADER(KC_NO);
  PRESS(KC_LCTL);
    TAP(KC_RIGHT);
    TAP(KC_RIGHT);
    TAP(KC_LEFT);
  RELEASE(KC_LCTL);
}

/**
 * Vim-like `yank` command
 * Simulates vim's `y` command by sending ^C
 */
void VIM_YANK(void) {
  print("\e[31my\e[0m");
  VIM_LEADER(KC_NO);
  CTRL(KC_C);
}

/***
 *       ####  #    # # ###### ##### ###### #####  
 *      #      #    # # #        #   #      #    # 
 *       ####  ###### # #####    #   #####  #    # 
 *           # #    # # #        #   #      #    # 
 *      #    # #    # # #        #   #      #    # 
 *       ####  #    # # #        #   ###### ##### 
 */
/**
 * Vim-like `append to line` command
 * Simulates vim's `A` command by sending End, 
 * then switching to insert mode
 */
void VIM_APPEND_LINE(void) {
  print("\e[31mA\e[0m");
  VIM_LEADER(KC_NO);
  TAP(KC_END);
  layer_move(_BASE);
}

/**
 * Vim-like 'jump to beginning (non-blank) of line' command
 * Simulates vim's `^` command by sending End, then Home
 */
void VIM_BEGINNING_OF_LINE(void) {
  print("\e[31m^\e[0m");
  VIM_LEADER(KC_NO);
  TAP(KC_END);
  TAP(KC_HOME);
}

/**
 * Vim-like `change line` command
 * Simulates vim's `C` command by sending ⇧End, then ^X
 * then switching to insert mode
 */
void VIM_CHANGE_TO_EOL(void) {
  print("\e[31mC\e[0m");
  VIM_LEADER(KC_NO);
  VIM_DELETE_TO_EOL();
  layer_move(_BASE);
}

/**
 * Vim-like 'delete line' command
 * Simulates vim's `D` command by sending ⇧End, then ^X
 */
void VIM_DELETE_TO_EOL(void) {
  print("\e[31mD\e[0m");
  VIM_LEADER(KC_NO);
  PRESS(KC_LSFT);
    TAP(KC_END);
  RELEASE(KC_LSFT);
  CTRL(KC_X);
}

/**
 * Vim-like 'jump to end of line' command
 * Simulates vim's `$` command by sending End
 */
void VIM_END_OF_LINE(void) {
  print("\e[31m$\e[0m");
  VIM_LEADER(KC_NO);
  TAP(KC_END);
}


/**
 * Vim-like 'last line' command
 * Simulates vim's `G` command by sending ^End
 */
void VIM_LAST_LINE(void) {
  print("\e[31mG\e[0m");
  VIM_LEADER(KC_NO);
  CTRL(KC_END);
}

/**
 * Vim-like 'join lines' command
 * Simulates vim's `J` command by sending ^→ to go to the end of the line, then
 * DELETE to join the lines
 */
void VIM_JOIN(void) {
  print("\e[31mJ\e[0m");
  VIM_LEADER(KC_NO);
  TAP(KC_END);
  TAP(KC_DELETE);
  VIM_LEADER(KC_NO);
}

/**
 * Vim-like 'open above' command
 * Simulates vim's `O` command by sending `Home` to go to the start of the line,
 * `Enter` to move the line down, ↑ to move up to the new line, then switching to
 * insert mode.
 */
void VIM_OPEN_ABOVE(void) {
  print("\e[31mO\e[0m");
  VIM_LEADER(KC_NO);
  TAP(KC_HOME);
  TAP(KC_ENTER);
  TAP(KC_UP);
  layer_move(_BASE);
}

/**
 * Vim-like 'change whole line' command
 * Simulates vim's `S` `cc` or `c$` commands by sending ⌘← to go to the start of the line,
 * ⌃K to kill the line, then switching to insert mode.
 */
void VIM_CHANGE_WHOLE_LINE(void) {
  print("\e[31mS\e[0m");
  VIM_LEADER(KC_NO);
  TAP(KC_HOME);
  TAP(KC_HOME);
  VIM_CHANGE_TO_EOL();
}

/**
 * Vim-like `yank to end of line` command
 * Simulates vim's `Y` command by sending ⇧^→, End, then ^C
 */
void VIM_YANK_TO_EOL(void) {
  print("\e[31mY\e[0m");
  VIM_LEADER(KC_NO);
  PRESS(KC_LSHIFT);
    TAP(KC_END);
  RELEASE(KC_LSHIFT);
  CTRL(KC_C);
  TAP(KC_LEFT);
}

/***
 *       ####  ##### #####  #      ###### #####  
 *      #    #   #   #    # #      #      #    # 
 *      #        #   #    # #      #####  #    # 
 *      #        #   #####  #      #      #    # 
 *      #    #   #   #   #  #      #      #    # 
 *       ####    #   #    # ###### ###### #####  
 */

/**
 * Vim-like `scroll down half page` 
 * Simulates vim's `Ctrl + d` command
 * Sends Mouse Scroll Down, Mouse Scroll Down
 */ 
void VIM_SCROLL_HALF_DOWN(void) {
  print("\e[31m^d\e[0m");
  VIM_LEADER(KC_NO);
  TAP(KC_MS_WH_DOWN);
  TAP(KC_MS_WH_DOWN);
} 

/**
 * Vim-like `scroll up half page` 
 * Simulates vim's `Ctrl + u` command
 * Sends Mouse Scroll Up, Mouse Scroll Up
 */ 
void VIM_SCROLL_HALF_UP(void) {
  print("\e[31m^u\e[0m");
  VIM_LEADER(KC_NO);
  TAP(KC_MS_WH_UP);
  TAP(KC_MS_WH_UP);
  }

/**
 * Vim-like `scroll forward full page` 
 * Simulates vim's `Ctrl + f` command
 * Sends Page Down
 */ 
void VIM_SCROLL_FULL_FORWARD(void) {
  print("\e[31m^f\e[0m");
  VIM_LEADER(KC_NO);
  TAP(KC_PGDOWN);
}

/**
 * Vim-like `scroll back full page` 
 * Simulates vim's `Ctrl + b` command
 * Sends Page Up
 */ 
void VIM_SCROLL_FULL_BACK(void) {
  print("\e[31m^b\e[0m");
  VIM_LEADER(KC_NO);
  TAP(KC_PGUP);
}
 
 /***
 *       ####     #####  #####  ###### ###### # #    # 
 *      #    #    #    # #    # #      #      #  #  #  
 *      #         #    # #    # #####  #####  #   ##   
 *      #  ###    #####  #####  #      #      #   ##   
 *      #    #    #      #   #  #      #      #  #  #  
 *       ####     #      #    # ###### #      # #    # 
 */

/**
 * Vim-like 'first line' command
 * Simulates vim's `gg` command by sending ^Home
 */
void VIM_FIRST_LINE(void) {
  print("\e[31mgg\e[0m");
  VIM_LEADER(KC_NO);
  CTRL(KC_HOME);
}

/***
 *      #   #    #####  #####  ###### ###### # #    # 
 *       # #     #    # #    # #      #      #  #  #  
 *        #      #    # #    # #####  #####  #   ##   
 *        #      #####  #####  #      #      #   ##   
 *        #      #      #   #  #      #      #  #  #  
 *        #      #      #    # ###### #      # #    # 
 */
/**
 * Vim-like `yank to end` 
 * Simulates vim's `ye` command
 * Sends ^⇧→ , ^C
 */
void VIM_YANK_END(void) {
  print("\e[31mye\e[0m");
  VIM_LEADER(KC_NO);
  PRESS(KC_LCTL);
    SHIFT(KC_RIGHT); // select to end of this word
  RELEASE(KC_LCTL);
  CTRL(KC_C);
  TAP(KC_LEFT); // return cursor
}

/**
 * Vim-like `yank whole line` 
 * Simulates vim's `yy` command 
 * Sends Home, Home, Shift End ^C
 */
void VIM_YANK_WHOLE_LINE(void) {
  print("\e[31myy\e[0m");
  VIM_LEADER(KC_NO);
  TAP(KC_HOME);
  TAP(KC_HOME);
  VIM_YANK_TO_EOL();
  // find a way to return cursor
}

/**
 * Vim-like `yank word` 
 * Simulates vim's `yw` command
 * Sends ^⇧→→←, ^C
 */
void VIM_YANK_WORD(void) {
  print("\e[31myw\e[0m");
  VIM_LEADER(KC_NO);
  PRESS(KC_LCTL);
    SHIFT(KC_RIGHT); // select to end of this word
    SHIFT(KC_RIGHT); // select to end of next word
    SHIFT(KC_LEFT); // select to start of next word
  RELEASE(KC_LCTL);
  CTRL(KC_C); // yank selection
  TAP(KC_LEFT); // return cursor
}

/**
 * Vim-like `yank back` 
 * Simulates vim's `yb` command 
 * Sends ^SHIFT LEFT DEL
 */
void VIM_YANK_BACK(void) {
  print("\e[31myb\e[0m");
  VIM_LEADER(KC_NO);
  PRESS(KC_LCTL);
    SHIFT(KC_LEFT); // select to start of word
    TAP(KC_C); // yank selection
  RELEASE(KC_LCTL);
  TAP(KC_RIGHT); // return cursor
}

/**
 * Vim-like `yank left` 
 * Simulates vim's `yh` command
 * Sends ⇧←, ^C
 */
void VIM_YANK_LEFT(void) {
  print("\e[31mh\e[0m");
  VIM_LEADER(KC_NO);
  SHIFT(KC_LEFT);
  CTRL(KC_C);
  TAP(KC_RIGHT); // return cursor
}

/**
 * Vim-like `yank right` 
 * Simulates vim's `yl` command 
 * Sends ⇧→, ^C
 */
void VIM_YANK_RIGHT(void) {
  print("\e[31ml\e[0m");
  VIM_LEADER(KC_NO);
  SHIFT(KC_RIGHT);
  CTRL(KC_C);
  TAP(KC_LEFT); // return cursor
}

/**
 * Vim-like `yank up` 
 * Simulates vim's `yk` command 
 * Sends ↑, ⇧^→ End, ^C
 */
void VIM_YANK_UP(void) {
  print("\e[31myk\e[0m");
  VIM_LEADER(KC_NO);
  SHIFT(KC_UP);
  TAP(KC_UP);
  VIM_YANK_TO_EOL();
}

/**
 * Vim-like `yank down` 
 * Simulates vim's `yj` command 
 * Sends ↓, ⇧^→ End, ^C
 */
void VIM_YANK_DOWN(void) {
  print("\e[31yj\e[0m");
  VIM_LEADER(KC_NO);
  TAP(KC_DOWN);
  VIM_YANK_TO_EOL();
}

/***
 *      #   # #    #####  #####  ###### ###### # #    # 
 *       # #  #    #    # #    # #      #      #  #  #  
 *        #   #    #    # #    # #####  #####  #   ##   
 *        #   #    #####  #####  #      #      #   ##   
 *        #   #    #      #   #  #      #      #  #  #  
 *        #   #    #      #    # ###### #      # #    # 
 *                                                      
 */
/**
 * Vim-like `yank inner word` 
 * Simulates vim's `yiw` command 
 * by moving back then copying to the end of the word.
 */
void VIM_YANK_INNER_WORD(void) {
  print("\e[31myiw\e[0m");
  VIM_LEADER(KC_NO);
  VIM_BEGINNING();
  VIM_YANK_END();
}

/***
*       #####      #####  #####  ###### ###### # #    # 
*       #    #     #    # #    # #      #      #  #  #  
*       #    #     #    # #    # #####  #####  #   ##   
*       #    #     #####  #####  #      #      #   ##   
*       #    #     #      #   #  #      #      #  #  #  
*       #####      #      #    # ###### #      # #    #
*/
/**
 * Vim-like `delete to end` command
 * Simulates vim's `de` command by sending ^⇧→ then ^X.
 */
void VIM_DELETE_END(void) {
  print("\e[31mde\e[0m");
  VIM_LEADER(KC_NO);
  PRESS(KC_LCTL);
    SHIFT(KC_RIGHT); // select to end of this word
  RELEASE(KC_LCTL);
  CTRL(KC_X);
}

/**
 * Vim-like `delete whole line` command
 * Simulates vim's `dd` command by sending `Home` to move to start of line,
 * selecting the whole line, then sending ^X to cut the line.
 */
void VIM_DELETE_WHOLE_LINE(void) {
  print("\e[31mdd\e[0m");
  VIM_LEADER(KC_NO);
  TAP(KC_HOME);
  TAP(KC_HOME);
  VIM_DELETE_TO_EOL(); 
}

/**
 * Vim-like `delete word` command
 * Simulates vim's `dw` command by sending ^⇧→→← then ^X to select to the start
 * of the next word then cut.
 */
void VIM_DELETE_WORD(void) {
  print("\e[31mdw\e[0m");
  VIM_LEADER(KC_NO);
  PRESS(KC_LCTL);
    SHIFT(KC_RIGHT); // select to end of this word
    SHIFT(KC_RIGHT); // select to end of next word
    SHIFT(KC_LEFT); // select to start of next word
  RELEASE(KC_LCTL);
  CTRL(KC_X); // delete selection
}

/**
 * Vim-like `delete back` command
 * Simulates vim's `db` command by selecting to the end of the word then cut.
 */
void VIM_DELETE_BACK(void) {
  print("\e[31mdb\e[0m");
  VIM_LEADER(KC_NO);
  PRESS(KC_LCTL);
    SHIFT(KC_LEFT); // select to start of word
    SHIFT(KC_DEL); // delete selection
  RELEASE(KC_LCTL);
}

/**
 * Vim-like `delete left` command
 * Simulates vim's `dh` command by sending ⇧← then ^X.
 */
void VIM_DELETE_LEFT(void) {
  print("\e[31mdh\e[0m");
  VIM_LEADER(KC_NO);
  SHIFT(KC_LEFT);
  CTRL(KC_X);
}

/**
 * Vim-like `delete right` command
 * Simulates vim's `dl` command by sending ⇧→ then ^X.
 */
void VIM_DELETE_RIGHT(void) {
  print("\e[31mdl\e[0m");
  VIM_LEADER(KC_NO);
  SHIFT(KC_RIGHT);
  CTRL(KC_X);
}

/**
 * Vim-like `delete up` command
 * Simulates vim's `dk` command by sending ↑ then deleting the line.
 */
void VIM_DELETE_UP(void) {
  print("\e[31mdk\e[0m");
  VIM_LEADER(KC_NO);
  TAP(KC_UP);
  VIM_DELETE_TO_EOL();
}

/**
 * Vim-like `delete down` command
 * Simulates vim's `dj` command by sending ↓ then deleting the line.
 */
void VIM_DELETE_DOWN(void) {
  print("\e[31mdj\e[0m");
  VIM_LEADER(KC_NO);
  TAP(KC_DOWN);
  VIM_DELETE_TO_EOL();
}

/***
*       #####  #    #####  #####  ###### ###### # #    # 
*       #    # #    #    # #    # #      #      #  #  #  
*       #    # #    #    # #    # #####  #####  #   ##   
*       #    # #    #####  #####  #      #      #   ##   
*       #    # #    #      #   #  #      #      #  #  #  
*       #####  #    #      #    # ###### #      # #    #
*/
/**
 * Vim-like `delete inner word` command
 * Simulates vim's `diw` command by moving back then cutting to the end of the word.
 */
void VIM_DELETE_INNER_WORD(void) {
  print("\e[31mdiw\e[0m");
  VIM_LEADER(KC_NO);
  VIM_BEGINNING();
  VIM_DELETE_END();
}

/***
*        ####     #####  #####  ###### ###### # #    # 
*       #    #    #    # #    # #      #      #  #  #  
*       #         #    # #    # #####  #####  #   ##   
*       #         #####  #####  #      #      #   ##   
*       #    #    #      #   #  #      #      #  #  #  
*        ####     #      #    # ###### #      # #    # 
*/
/**
 * Vim-like `change back` command
 * Simulates vim's `cb` command by first deleting to the start of the word,
 * then switching to insert mode.
 */
void VIM_CHANGE_BACK(void) {
  print("\e[31mcb\e[0m");
  VIM_LEADER(KC_NO);
  VIM_DELETE_BACK();
  layer_move(_BASE);
}

/**
 * Vim-like `change down` command
 * Simulates vim's `cj` command by sending ↓ then changing the line.
 */
void VIM_CHANGE_DOWN(void) {
  print("\e[31mcj\e[0m");
  VIM_LEADER(KC_NO);
  VIM_DELETE_DOWN();
  layer_move(_BASE);
}

/**
 * Vim-like `change to end` command
 * Simulates vim's `ce` command by first deleting to the end of the word,
 * then switching to insert mode.
 */
void VIM_CHANGE_END(void) {
  print("\e[31mce\e[0m");
  VIM_LEADER(KC_NO);
  VIM_DELETE_END();
  layer_move(_BASE);
}

/**
 * Vim-like `change left` command
 * Simulates vim's `ch` command by deleting left then switching to insert mode.
 */
void VIM_CHANGE_LEFT(void) {
  print("\e[31mch\e[0m");
  VIM_LEADER(KC_NO);
  VIM_DELETE_LEFT();
  layer_move(_BASE);
}

/**
 * Vim-like `change right` command
 * Simulates vim's `cl` command by deleting right then switching to insert mode.
 */
void VIM_CHANGE_RIGHT(void) {
  print("\e[31mcl\e[0m");
  VIM_LEADER(KC_NO);//?  
  VIM_DELETE_RIGHT();
  layer_move(_BASE);
}

/**
 * Vim-like `change up` command
 * Simulates vim's `ck` command by deleting up then switching to insert mode.
 */
void VIM_CHANGE_UP(void) {
  print("\e[31mck\e[0m");
  VIM_LEADER(KC_NO);//?
  VIM_DELETE_UP();
  layer_move(_BASE);
}

/**
 * Vim-like `change word` command
 * Simulates vim's `cw` command by first deleting to the end of the word,
 * then switching to insert mode.
 */
void VIM_CHANGE_WORD(void) {
  print("\e[31mcw\e[0m");
  VIM_LEADER(KC_NO);
  VIM_DELETE_WORD();
  layer_move(_BASE);
}


/***
*        ####  #   #####  #####  ###### ###### # #    # 
*       #    # #   #    # #    # #      #      #  #  #  
*       #      #   #    # #    # #####  #####  #   ##   
*       #      #   #####  #####  #      #      #   ##   
*       #    # #   #      #   #  #      #      #  #  #  
*        ####  #   #      #    # ###### #      # #    # 
*/
/**
 * Vim-like `change inner word` command
 * Simulates vim's `ciw` command by deleting the inner word then switching to insert mode.
 */
void VIM_CHANGE_INNER_WORD(void) {
  print("\e[31mciw\e[0m");
  VIM_LEADER(KC_NO);//?
  VIM_DELETE_INNER_WORD();
  layer_move(_BASE);
}

/***
 *      #    #     #####  #####  ###### ###### # #    # 
 *      #    #     #    # #    # #      #      #  #  #  
 *      #    #     #    # #    # #####  #####  #   ##   
 *      #    #     #####  #####  #      #      #   ##   
 *       #  #      #      #   #  #      #      #  #  #  
 *        ##       #      #    # ###### #      # #    # 
 */
/**
 * Vim-like `visual select back` command
 * Simulates vim's `vb` command by selecting to the enc of the word.
 */
void VIM_VISUAL_BACK(void) {
  print("\e[31mvb\e[0m");
  VIM_LEADER(KC_NO);
  PRESS(KC_LCTL);
    SHIFT(KC_LEFT); // select to start of word
  RELEASE(KC_LCTL);
}

/**
 * Vim-like `visual select to end` command
 * Simulates vim's `ve` command by selecting to the end of the word.
 */
void VIM_VISUAL_END(void) {
  print("\e[31mve\e[0m");
  VIM_LEADER(KC_NO);
  PRESS(KC_LCTL);
    SHIFT(KC_RIGHT); // select to end of this word
  RELEASE(KC_LCTL);
}

/**
 * Vim-like `visual select word` command
 * Simulates vim's `vw` command by selecting to the end of the word.
 */
void VIM_VISUAL_WORD(void) {
  print("\e[31mvw\e[0m");
  VIM_LEADER(KC_NO);
  PRESS(KC_LCTL);
    SHIFT(KC_RIGHT); // select to end of this word
    SHIFT(KC_RIGHT); // select to end of next word
    SHIFT(KC_LEFT); // select to start of next word
  RELEASE(KC_LCTL);
}

/**
 * Vim-like `visual left` command
 * Simulates vim's `vh` command by sending ⇧←.
 */
void VIM_VISUAL_LEFT(void) {
  print("\e[31mvh\e[0m");
  VIM_LEADER(KC_NO);
  SHIFT(KC_LEFT);
}

/**
 * Vim-like `visual right` command
 * Simulates vim's `vl` command by sending ⇧→.
 */
void VIM_VISUAL_RIGHT(void) {
  print("\e[31mvl\e[0m");
  VIM_LEADER(KC_NO);
  SHIFT(KC_RIGHT);
}

/**
 * Vim-like `visual up` command
 * Simulates vim's `vk` command by sending ⇧↑.
 */
void VIM_VISUAL_UP(void) {
  print("\e[31mvk\e[0m");
  VIM_LEADER(KC_NO);
  SHIFT(KC_UP);
}

/**
 * Vim-like `visual down` command
 * Simulates vim's `vj` command by sending ⇧↓.
 */
void VIM_VISUAL_DOWN(void) {
  print("\e[31mdj\e[0m");
  VIM_LEADER(KC_NO);
  SHIFT(KC_DOWN);
}


/***
 *      #    # #    #####  #####  ###### ###### # #    # 
 *      #    # #    #    # #    # #      #      #  #  #  
 *      #    # #    #    # #    # #####  #####  #   ##   
 *      #    # #    #####  #####  #      #      #   ##   
 *       #  #  #    #      #   #  #      #      #  #  #  
 *        ##   #    #      #    # ###### #      # #    # 
 */
/**
 * Vim-like `visual inner word` command
 * Simulates vim's `viw` command by moving back then selecting to the end of the word.
 */
void VIM_VISUAL_INNER_WORD(void) {
  print("\e[31mviw\e[0m");
  VIM_LEADER(KC_NO);
  VIM_BEGINNING();
  VIM_VISUAL_END();
}
