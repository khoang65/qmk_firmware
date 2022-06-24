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

#include "quantum.h"
#include "khoang65.h" // included for the is<ModPressed> flags
#include "custom_keycode.h"

// ** Tap Dance Definitions ** //
enum tapdance_index {
  TD_PLACEHOLDER = SAFE_RANGE+1000,
  TD_yy = SAFE_RANGE+1001,
  TD_dd = SAFE_RANGE+1002,
};

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_DOUBLE_TAP,
    TD_TRIPLE_TAP
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

enum custom_tapdance_actions{
    VIM_d,
    VIM_y,
};

td_state_t cur_dance(qk_tap_dance_state_t *state);

void d_finished(qk_tap_dance_state_t *state, void *user_data);
void d_reset(qk_tap_dance_state_t *state, void *user_data); 
void y_finished(qk_tap_dance_state_t *state, void *user_data);
void y_reset(qk_tap_dance_state_t *state, void *user_data);


/****
 *.########....###....########.....########.....###....##....##..######..########
 *....##......##.##...##.....##....##.....##...##.##...###...##.##....##.##......
 *....##.....##...##..##.....##....##.....##..##...##..####..##.##.......##......
 *....##....##.....##.########.....##.....##.##.....##.##.##.##.##.......######..
 *....##....#########.##...........##.....##.#########.##..####.##.......##......
 *....##....##.....##.##...........##.....##.##.....##.##...###.##....##.##......
 *....##....##.....##.##...........########..##.....##.##....##..######..########
 */
  // ** Tap Dance Implementation ** //
td_state_t cur_dance(qk_tap_dance_state_t *state) {
  if (state->count == 1) return TD_SINGLE_TAP;
  else if (state->count == 2) return TD_DOUBLE_TAP;
  else return TD_UNKNOWN;
}

td_tap_t dtap_state = {
  .is_press_action = true,
  .state = TD_NONE
};

void d_finished(qk_tap_dance_state_t *state, void *user_data) {
  dtap_state.state = cur_dance(state);
  switch (dtap_state.state) {
    case TD_SINGLE_TAP:
      if (isCtrlPressed) {
        del_mods(MOD_MASK_CTRL);
        //VIM_SCROLL_HALF_DOWN();
        set_mods(mod_state);
      } else {
        register_code16(CTLX);
      }
      break;
    case TD_DOUBLE_TAP:
      register_custom_keycode(TD_dd, 12, 5);
      break;
    default: break;
  }
}

void d_reset(qk_tap_dance_state_t *state, void *user_data) {
  switch (dtap_state.state) {
    case TD_SINGLE_TAP:
      if (!isCtrlPressed) {
        unregister_code16(CTLX); 
      }
      break;
    case TD_DOUBLE_TAP:
      unregister_custom_keycode(TD_dd, 12, 5);
      break;
    default: break;
  }
  dtap_state.state = TD_NONE;
}

td_tap_t ytap_state = {
  .is_press_action = true,
  .state = TD_NONE
};

void y_finished(qk_tap_dance_state_t *state, void *user_data) {
  dtap_state.state = cur_dance(state);
  switch (dtap_state.state) {
    case TD_SINGLE_TAP:
      register_code16(CTLC);
      break;
    case TD_DOUBLE_TAP:
      register_custom_keycode(TD_yy, 12 ,5);
      break;
    default: break;
  }
}

void y_reset(qk_tap_dance_state_t *state, void *user_data) {
  switch (dtap_state.state) {
    case TD_SINGLE_TAP:
      unregister_code16(CTLC); 
      break;
    case TD_DOUBLE_TAP: 
      unregister_custom_keycode(TD_yy, 12, 5);
      break;
    default: break;
  }
  dtap_state.state = TD_NONE;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [VIM_d] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, d_finished, d_reset, 175),
    [VIM_y] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, y_finished, y_reset, 175),
};

