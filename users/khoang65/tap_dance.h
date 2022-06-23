#pragma once

#include "quantum.h"
#include "khoang65.h"
#include "vim_dows.h"
#include "custom_keycode.h"


// ** TAP DANCE Definitions ** //
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
        VIM_SCROLL_HALF_DOWN();
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

