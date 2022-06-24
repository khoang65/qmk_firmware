#include QMK_KEYBOARD_H
#include "khoang65.h"
#include "vimdows.h"
#include "tapdance.h"

bool isLeader = false;

/****
 *.##....##.########.##....##.##.....##....###....########.
 *.##...##..##........##..##..###...###...##.##...##.....##
 *.##..##...##.........####...####.####..##...##..##.....##
 *.#####....######......##....##.###.##.##.....##.########.
 *.##..##...##..........##....##.....##.#########.##.......
 *.##...##..##..........##....##.....##.##.....##.##.......
 *.##....##.########....##....##.....##.##.....##.##.......
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   /* Keymap 0: BASE layer
   * ,-----------------------------------------------------------.                              ,-----------------------------------------------------------.
   * | ESC     | !1      | @2      | #3      | $4      | %5      |---------.          ,---------| ^6      | &7      | *8      | (9      | )0      | _-      |
   * |---------+---------+---------+---------+---------+---------| {[      |          | }]      |---------+---------+---------+---------+---------+---------|
   * | Tab     | Q       | W       | E       | R       | T       |---------|          |---------| Y       | U       | I       | O       | P       | LEADER  |
   * |---------+---------+---------+---------+---------+---------| F4      |          | +=      |---------+---------+---------+---------+---------+---------|
   * | ~`      | A       | S       | D       | F       | G       |---------|          |---------| H       | J       | K       | L       | :;      | "'      | // SYM LAYER ACCESS ("')
   * |---------+---------+---------+---------+---------+---------|LT1(PSCR)|          | LT1(|\) |---------+---------+---------+---------+---------|---------|
   * | LShift  | Z       | X       | C       | V       | B       |---------'          `---------| N       | M       | <,      | >.      | ?/      | RShift  |
   * |---------+---------+---------+-----------------------------'                              `-----------------------------+---------+---------+---------|
   * | LCtrl   | Meh(F13)| OS      |  | LAlt    |      ,-------------------.          ,-------------------.      | All()   |  | F15     | F16     | TT(NUM) |
   * `-----------------------------'  `---------'      |         |         |          |         |         |      `---------'  `-----------------------------'
   *                                                   | Del     | CS(F14) |          |LT/TO VIM| Enter   |
   *                                         ,---------|         |         |          |         |         +---------.
   *                                         | Space   |         |         |          |         |         | BckSpc  |
   *                                         `-----------------------------'          `-----------------------------'                                      */
  [_BASE] = LAYOUT_4key_2u_inner(
      VIM_ESC,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_LBRC,             KC_RBRC,  KC_6,     KC_7,     KC_8,      KC_9,     KC_0,    KC_MINS, 
      KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_F4,               KC_EQL,   KC_Y,     KC_U,     KC_I,      KC_O,     KC_P,    KC_LEAD, 
      KC_GRV,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     FNT_PSCR,            FNT_BSLS, KC_H,     KC_J,     KC_K,      KC_L,     KC_SCLN, KC_QUOT,
      KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     XXXXXXX,             XXXXXXX,  KC_N,     KC_M,     KC_COMM,   KC_DOT,   KC_SLSH, KC_RSFT, 
      KC_LCTL,  MEH_F13,  KC_LGUI,  KC_LALT,  KC_SPC,   KC_DEL,   CS_F14,              LT_TO_VIM,KC_ENT,   KC_BSPC,  ALL_,      KC_F15,   KC_F16,  TT(_NUM)
      ),
  
  
   /* Keymap 1: FUNCTION layer
   * ,-----------------------------------------------------------.                              ,-----------------------------------------------------------.
   * | TRNS    | F1      | F2      | F3      | F4      | F5      |---------.          ,---------| F6      | F7      | F8      | F9      | F10     | TRNS    |
   * |---------+---------+---------+---------+---------+---------| F11     |          | F12     |---------+---------+---------+---------+---------+---------|
   * | TRNS    | TRNS    | TRNS    | TRNS    | TRNS    | TRNS    |---------|          |---------| TRNS    | TRNS    | TRNS    | TRNS    | TRNS    | TRNS    |
   * |---------+---------+---------+---------+---------+---------| TRNS    |          | TRNS    |---------+---------+---------+---------+---------+---------|
   * | TRNS    | TRNS    | TRNS    | TRNS    | TRNS    | TRNS    |---------|          |---------| TRNS    | TRNS    | TRNS    | TRNS    | TRNS    | TRNS    |
   * |---------+---------+---------+---------+---------+---------| PrtScr  |          | |\      |---------+---------+---------+---------+---------|---------|
   * | TRNS    | TRNS    | TRNS    | TRNS    | TRNS    | TRNS    |---------'          `---------| TRNS    | TRNS    | TRNS    | TRNS    | TRNS    | TRNS    |
   * |---------+---------+---------+-----------------------------'                              `-----------------------------+---------+---------+---------|
   * | TRNS    | TRNS    | TRNS    |  | TRNS    |      ,-------------------.          ,-------------------.      | TRNS    |  | TRNS    | TRNS    | TO(BASE)|
   * `-----------------------------'  `---------'      |         |         |          |         |         |      `---------'  `-----------------------------'
   *                                                   | TRNS    | TRNS    |          |         | TRNS    |        
   *                                         ,---------|         |         |          |         |         +---------.
   *                                         | TRNS    |         |         |          |         |         | TRNS    |
   *                                         `-----------------------------'          `-----------------------------'                                      */
	[_FN] = LAYOUT_4key_2u_inner(
      _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F11,              KC_F12,   KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,    _______, 
      _______,  _______,  _______,  _______,  _______,  _______,  _______,             _______,  _______,  _______,  _______,  _______,  _______,   _______, 
      _______,  _______,  _______,  _______,  _______,  _______,  KC_PSCR,             KC_BSLS,  _______,  _______,  _______,  _______,  KC_SCLN,   _______, 
      _______,  _______,  _______,  _______,  _______,  _______,  _______,             _______,  _______,  _______,  _______,  _______,  _______,   _______, 
      _______,  _______,  _______,  _______,  _______,  _______,  _______,             _______,  _______,  _______,  _______,  _______,  _______,   TO(_BASE)
      ),


   /* Keymap 2: VIM (Toggle) Layer
   * ,-----------------------------------------------------------.                              ,-----------------------------------------------------------.
   * | VIM_ESC |         |         |         | VIM 4   |         |---------.          ,---------| VIM_6   |         |         |         | VIM 0   |         |
   * |---------+---------+---------+---------+---------+---------|         |          |         |---------+---------+---------+---------+---------+---------|
   * | TRNS    |         | VIM W   | VIM E   | VIM R   |         |---------|          |---------|         | VIM U   | VIM I   | VIM O   | VIM P   | CAPSLK  |
   * |---------+---------+---------+---------+---------+---------|         |          |         |---------+---------+---------+---------+---------+---------|
   * |         | VIM A   | VIM S   | VIM D   | VIM F   | VIM G   |---------|          |---------| VIM H   | VIM J   | VIM K   | VIM L   | MO(NUM) |         |
   * |---------+---------+---------+---------+---------+---------|         |          |         |---------+---------+---------+---------+---------|---------|
   * | TRNS    |         | VIM X   | VIM C   | VIM V   | VIM B   |---------'          `---------|         |         |         |         | Ctrl+F  | TRNS    |
   * |---------+---------+---------+-----------------------------'                              `-----------------------------+---------+---------+---------|
   * | TRNS    | TRNS    | TRNS    |  | TRNS    |      ,-------------------.          ,-------------------.      |         |  |         |         | TO(BASE)|
   * `-----------------------------'  `---------'      |         | TRNS    |          | TRNS    |         |      `---------'  `-----------------------------'
   *                                                   | TRNS    |_________|          |_________| TRNS    |
   *                                         ,---------|         | TRNS    |          | TRNS    |         +---------.
   *                                         | TRNS    |         |         |          |         |         | TRNS    |
   *                                         `-----------------------------'          `-----------------------------'                                      */
  [_VIMTOGGLE] = LAYOUT_4key_2u_inner(
      VIM_ESC,  XXXXXXX,  XXXXXXX,  XXXXXXX,  VIM_4,    XXXXXXX,  XXXXXXX,             XXXXXXX,  VIM_6,    XXXXXXX,  XXXXXXX,  XXXXXXX,  VIM_0,     XXXXXXX, 
      _______,  XXXXXXX,  VIM_W,    VIM_E,    VIM_R,    XXXXXXX,  XXXXXXX,             XXXXXXX,  VIM_Y,    VIM_U,    VIM_I,    VIM_O,    VIM_P,     KC_CAPS, 
      XXXXXXX,  VIM_A,    VIM_S,    VIM_D,    VIM_F,    VIM_G,    KC_PSCR,             XXXXXXX,  VIM_H,    VIM_J,    VIM_K,    VIM_L,    MO(_NUM),  XXXXXXX,
      _______,  XXXXXXX,  VIM_X,    VIM_C,    VIM_V,    VIM_B,    _______,             _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  CTLF,      _______,
      _______,  _______,  _______,  _______,  _______,  _______,  _______,             MO(_VIM), _______,  _______,  XXXXXXX,  _______,  _______,   TO(_BASE)
      ),
     
     
   /* Keymap 3: NUMPAD Layer // LEFT HAND MOUSE?
   * ,-----------------------------------------------------------.                              ,-----------------------------------------------------------.
   * | TRNS    |  !      |  @      |  #      |  $      |  %      |---------.          ,---------|  ^      |  &      |  *      |  /      |  -      | TRNS    |
   * |---------+---------+---------+---------+---------+---------| {[      |          | }]      |---------+---------+---------+---------+---------+---------|
   * | TRNS    |         |         | PgUp    |         |         |---------|          |---------|  +      |  7      |  8      |  9      |  +      |         |
   * |---------+---------+---------+---------+---------+---------| TT(ADJ) |          | TRNS    |---------+---------+---------+---------+---------+---------|
   * | TRNS    |         | Home    | PgDn    | End     |         |---------|          |---------|  =      |  4      |  5      |  6      | TRNS    | "'      |
   * |---------+---------+---------+---------+---------+---------| PrtScr  |          | |\      |---------+---------+---------+---------+---------|---------|
   * | TRNS    |         |         |         |         |         |---------'          `---------| Calc    |  1      |  2      |  3      | TRNS    | TRNS    |
   * |---------+---------+---------+-----------------------------'                              `-----------------------------+---------+---------+---------|
   * | TRNS    | TRNS    | TRNS    |  | TRNS    |      ,-------------------.          ,-------------------.      | 0       |  | .       | TRNS    | TO(BASE)|
   * `-----------------------------'  `---------'      |         |         |          |         |         |      `---------'  `-----------------------------'
   *                                                   | TRNS    | TRNS    |          | MO(_VIM)| TRNS    |
   *                                         ,---------|         |         |          |         |         +---------.
   *                                         | TRNS    |         |         |          |         |         | TRNS    |
   *                                         `-----------------------------'          `-----------------------------'                                      */
	[_NUM] = LAYOUT_4key_2u_inner(
      _______,  KC_EXLM,   KC_AT,    KC_HASH,   KC_DLR,   KC_PERC, KC_LBRC,             KC_RBRC,  KC_CIRC,  KC_AMPR,  KC_PAST,  KC_PSLS,  KC_PMNS,  _______, 
      _______,  XXXXXXX,   XXXXXXX,  KC_PGUP,   XXXXXXX,  XXXXXXX, TT(_ADJUST),         _______,  KC_PPLS,  KC_P7,    KC_P8,    KC_P9,    KC_PPLS,  XXXXXXX, 
      _______,  XXXXXXX,   KC_HOME,  KC_PGDOWN, KC_END,   XXXXXXX, KC_PSCR,             KC_BSLS,  KC_PEQL,  KC_P4,    KC_P5,    KC_P6,    XXXXXXX,  KC_QUOT,
      _______,  XXXXXXX,   XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX, _______,             _______,  KC_CALC,  KC_P1,    KC_P2,    KC_P3,    XXXXXXX,  _______, 
      _______,  _______,   _______,  _______,   _______,  _______, _______,             MO(_VIM), _______,  _______,  KC_P0,    KC_PDOT,  _______,  TO(_BASE)
      ),


   /* Keymap 4: VIM/Media (Momentary) layer 
   * ,-----------------------------------------------------------.                              ,-----------------------------------------------------------.
   * | VIM_ESC |         |         |         | VIM 4   |         |---------.          ,---------| VIM 6   | Rewind  | Fastfwd |         | VIM 0   |         |
   * |---------+---------+---------+---------+---------+---------|         |          |         |---------+---------+---------+---------+---------+---------|
   * | TRNS    |         | VIM W   | VIM E   | VIM R   |         |---------|          |---------|TD(VIM_y)| VIM U   | VIM I   |         | VIM P   |         |
   * |---------+---------+---------+---------+---------+---------|         |          | Mute    |---------+---------+---------+---------+---------+---------|
   * |         |         |         |TD(VIM_d)| VIM F   | VIM G   |---------|          |---------| Left    | Down    | Up      | Right   |         |         |
   * |---------+---------+---------+---------+---------+---------| PrtScr  |          | Play    |---------+---------+---------+---------+---------|---------|
   * | TRNS    |         | VIM X   |         | VIM V   | VIM B   |---------'          `---------| Prev Tra| Vol -   | Vol +   | Next Tra| Ctrl+F  | TRNS    |
   * |---------+---------+---------+-----------------------------'                              `-----------------------------+---------+---------+---------|
   * | TRNS    | TRNS    | TRNS    |  | TRNS    |      ,-------------------.          ,-------------------.      |         |  | TRNS    | TRNS    | TO(BASE)|
   * `-----------------------------'  `---------'      |         | TRNS    |          | TRNS    |         |      `---------'  `-----------------------------'
   *                                                   | TRNS    |_________|          |_________| TRNS    |        
   *                                         ,---------|         | TRNS    |          | TRNS    |         +---------.
   *                                         | TRNS    |         |         |          |         |         | TRNS    |
   *                                         `-----------------------------'          `-----------------------------'                                      */
	[_VIM] = LAYOUT_4key_2u_inner(
      VIM_ESC,  XXXXXXX,  XXXXXXX,  XXXXXXX,  VIM_4,    XXXXXXX,  XXXXXXX,             XXXXXXX,  VIM_6,    KC_MRWD,  KC_MFFD,  XXXXXXX,   VIM_0,     XXXXXXX, 
      _______,  XXXXXXX,  VIM_W,    VIM_E,    VIM_R,    XXXXXXX,  XXXXXXX,             KC_MUTE,  TD(VIM_y),VIM_U,    VIM_I,    XXXXXXX,   VIM_P,     XXXXXXX, 
      XXXXXXX,  XXXXXXX,  XXXXXXX,  TD(VIM_d),VIM_F,    VIM_G,    KC_PSCR,             KC_MPLY,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT,  XXXXXXX,   XXXXXXX, 
      _______,  XXXXXXX,  VIM_X,    XXXXXXX,  VIM_V,    VIM_B,    _______,             _______,  KC_MPRV,  KC_VOLD,  KC_VOLU,  KC_MNXT,   CTLF,      _______, 
      _______,  _______,  _______,  _______,  _______,  _______,  _______,             _______,  _______,  _______,  XXXXXXX,  _______,   _______,   TO(_BASE)
      ),


   /* Keymap 5: SYMBOL Layer
   * ,-----------------------------------------------------------.                              ,-----------------------------------------------------------.
   * | VIM_ESC | !       | @       | #       | $       | %       |---------.          ,---------|         |         |         |         |         |         |
   * |---------+---------+---------+---------+---------+---------| [       |          |         |---------+---------+---------+---------+---------+---------|
   * |         | ^       | &       | *       | -       | _       |---------|          |---------|         |         |         |         |         |         |
   * |---------+---------+---------+---------+---------+---------| '       |          |         |---------+---------+---------+---------+---------+---------|
   * | ~       | "       | <       | {       | (       | `       |---------|          |---------|         |         |         |         |         |         |
   * |---------+---------+---------+---------+---------+---------| :       |          |         |---------+---------+---------+---------+---------|---------|
   * |         | .       | +       | =       | /       | \       |---------'          `---------|         |         |         |         |         |         |
   * |---------+---------+---------+-----------------------------'                              `-----------------------------+---------+---------+---------|
   * |         |         |         |  |         |      ,-------------------.          ,-------------------.      |         |  |         |         | TO(0)   |
   * `-----------------------------'  `---------'      |         | TRNS    |          |         |         |      `---------'  `-----------------------------'
   *                                                   |         |_________|          |_________|         |
   *                                         ,---------|         | TRNS    |          |         |         +---------.
   *                                         |         |         |         |          |         |         |         |
   *                                         `-----------------------------'          `-----------------------------'                                      */
  [_SYM] = LAYOUT_4key_2u_inner(
      VIM_ESC,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,  KC_LBRC,             XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, 
      XXXXXXX,  KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_MINS,  KC_UNDS,  KC_QUOT,             XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, 
      KC_TILD,  KC_DQUO,  KC_LT,    KC_LCBR,  KC_LPRN,  KC_DQUO,  KC_COLN,             XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, 
      XXXXXXX,  KC_PDOT,  KC_PLUS,  KC_EQL,   KC_PSLS,  KC_BSLS,  XXXXXXX,             XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, 
      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,             XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  TO(_BASE)
      ),


   /* Keymap 6: ADJUST Layer
   * ,-----------------------------------------------------------.                              ,-----------------------------------------------------------.
   * | VIM_ESC |         |         |         |         |         |---------.          ,---------|         |         |         |         |         |         |
   * |---------+---------+---------+---------+---------+---------|         |          | EEP_RST |---------+---------+---------+---------+---------+---------|
   * |         |         |         |         |         |         |---------|          |---------|         |         |         |         |         |         |
   * |---------+---------+---------+---------+---------+---------|         |          |         |---------+---------+---------+---------+---------+---------|
   * |         |         |         |         |         |         |---------|          |---------|         |         |         |         |         |         |
   * |---------+---------+---------+---------+---------+---------|         |          |         |---------+---------+---------+---------+---------|---------|
   * |         |         |         |         |         |         |---------'          `---------|         |         |         |         |         |         |
   * |---------+---------+---------+-----------------------------'                              `-----------------------------+---------+---------+---------|
   * |         |         |         |  |         |      ,-------------------.          ,-------------------.      |         |  |         |         | TO(0)   |
   * `-----------------------------'  `---------'      |         |         |          |         |         |      `---------'  `-----------------------------'
   *                                                   |         |_________|          |_________|         |
   *                                         ,---------|         | CS(F14) |          |         |         +---------.
   *                                         |         |         |         |          |         |         |         |
   *                                         `-----------------------------'          `-----------------------------'                                      */
  [_ADJUST] = LAYOUT_4key_2u_inner(
      VIM_ESC,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,             EEP_RST,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, 
      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,             XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, 
      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,             XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, 
      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,             XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, 
      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  CS_F14,              XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  TO(_BASE)
      )
};

/****
 *.##....##.########.##....##..######...#######..########..########..######.
 *.##...##..##........##..##..##....##.##.....##.##.....##.##.......##....##
 *.##..##...##.........####...##.......##.....##.##.....##.##.......##......
 *.#####....######......##....##.......##.....##.##.....##.######....######.
 *.##..##...##..........##....##.......##.....##.##.....##.##.............##
 *.##...##..##..........##....##....##.##.....##.##.....##.##.......##....##
 *.##....##.########....##.....######...#######..########..########..######.
 */
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {

  bool PRESSED = record->event.pressed;
  mod_state = get_mods();
  //bool SHIFTED = (keyboard_report->mods & MOD_BIT(KC_LSFT)) | (keyboard_report->mods & MOD_BIT(KC_RSFT));
  //bool CTRLED = (keyboard_report->mods & MOD_BIT(KC_LCTL)) | (keyboard_report->mods & MOD_BIT(KC_RCTL));

  switch (keycode) {
    
    case KC_LSHIFT:
      if (PRESSED) {
        isShiftPressed = true;
      } else {
        isShiftPressed = false;
      }
      return true; // Let QMK process the keycode as usual
    
    case KC_RSHIFT:
      if (PRESSED) {
        isShiftPressed = true;
      } else {
        isShiftPressed = false;
      }
      return true;
      
    case KC_LCTL:
      if (PRESSED) {
        isCtrlPressed = true;
      } else {
        isCtrlPressed = false;
      }
      return true;
    
    case KC_RCTL:
      if (PRESSED) {
        isCtrlPressed = true;
      } else {
        isCtrlPressed = false;
      }
      return true; 
    
    case VIM_ESC:
      if (PRESSED) {
        switch(VIM_QUEUE){
          case VIM_R: VIM_LEFT(); break;
          default: 
            PRESS(KC_ESC);
            caps_word_off();
            layer_move(_BASE);
            if(IS_HOST_LED_ON(USB_LED_CAPS_LOCK)) {
              TAP(KC_CAPS); // Turns off CAPS
            }
            VIM_LEADER(KC_NO);
          break;
        }
      } else { // Do something when key released; typically unregister code
        RELEASE(KC_ESC);
      }
      return false;

    case LT_TO_VIM:                                  
      if(PRESSED){
        LT_TO_VIM_TIMER = timer_read();
        layer_on(_VIM); // Needs transparent layer to see keypress release()?
      } else {
        layer_off(_VIM);
        if ((timer_elapsed(LT_TO_VIM_TIMER) < TAPPING_TERM) && layer_state_is(_BASE)) {  
          layer_move(_VIMTOGGLE); // same as TO(_VIMTOGGLE)
        }
      }
      return true; 

    case TD_dd:
      if(PRESSED) {
        TAP(KC_HOME);
        TAP(KC_HOME);
        SHIFT(KC_END);
        PRESS(KC_LCTL);
        CTRL(KC_X);
      }
      return false;

    case TD_yy:
      if (PRESSED) {
        TAP(KC_HOME);
        TAP(KC_HOME);
        PRESS(KC_LSFT);
          TAP(KC_END);
        RELEASE(KC_LSFT);
        CTRL(KC_C);
        TAP(KC_RIGHT);
      }
      return false;

    case VIM_0:
      if (PRESSED) {
        VIM_START_OF_LINE();
      }
      return false;
    
    case VIM_4:
      if (isShiftPressed && PRESSED) {
        // First temporarily canceling both shifts so that
        // shift isn't applied to the macro
        del_mods(MOD_MASK_SHIFT);
        VIM_END_OF_LINE();
        // Reapplying modifier state so that the held shift key(s)
        // still work even after VIM_END_OF_LINE() is run
        set_mods(mod_state);
      }
      return false;
    
    case VIM_6:
      if (isShiftPressed && PRESSED) {
        del_mods(MOD_MASK_SHIFT);
        VIM_BEGINNING_OF_LINE();
        set_mods(mod_state);
      }
      return false;
    
    case VIM_A:
      if (isShiftPressed && PRESSED) { 
        del_mods(MOD_MASK_SHIFT);
        VIM_APPEND_LINE(_BASE);
        set_mods(mod_state);      
      } else if (PRESSED) {
        VIM_APPEND(_BASE);
      }
      return false;

    case VIM_B:
      if (PRESSED) {
        switch(VIM_QUEUE) {
          case KC_NO: 
            if(isCtrlPressed) {
              del_mods(MOD_MASK_CTRL);
              PRESS(KC_PGUP);
              set_mods(mod_state);
            } else {
              PRESS(KC_LCTL); 
              PRESS(KC_LEFT);
            }
            break;
          case VIM_C: VIM_CHANGE_BACK(_BASE); break;
          case VIM_D: VIM_DELETE_BACK(); break;
          case VIM_V: VIM_VISUAL_BACK(); break;
        }
      } else {
        RELEASE(KC_PGUP);
        RELEASE(KC_LEFT);
        RELEASE(KC_LCTL);
      }
      return false;

    case VIM_C:
      if (PRESSED) {
        switch(VIM_QUEUE) {
          case KC_NO: 
            if(isShiftPressed) {
              del_mods(MOD_MASK_SHIFT);
              VIM_CHANGE_TO_EOL(_BASE);
              set_mods(mod_state);
            } else {
              VIM_LEADER(VIM_C);
            }
            break;
          case VIM_C: VIM_CHANGE_WHOLE_LINE(_BASE); break;
        }
      }
      return false;

    case VIM_D:
      if (PRESSED) {
        switch(VIM_QUEUE) {
          case KC_NO: 
            if (isShiftPressed) {
              del_mods(MOD_MASK_SHIFT);
              VIM_DELETE_TO_EOL();
              set_mods(mod_state);
            } else if (isCtrlPressed) {
              del_mods(MOD_MASK_CTRL);
              //VIM_SCROLL_HALF_DOWN();
              set_mods(mod_state);
            } else {
              VIM_LEADER(VIM_D);
            }
            break;
          case VIM_D: VIM_DELETE_WHOLE_LINE(); break;
        }
      }
      return false;

    case VIM_E:
      if (PRESSED) {
        switch (VIM_QUEUE) {
          case KC_NO: PRESS(KC_LCTL); PRESS(KC_RIGHT); break;
          case VIM_C: VIM_CHANGE_END(_BASE); break;
          case VIM_D: VIM_DELETE_END(); break;
          case VIM_V: VIM_VISUAL_END(); break;
          case VIM_Y: VIM_YANK_END(); break;
        }
      } else {
        RELEASE(KC_RIGHT);
        RELEASE(KC_LCTL);
      }
      return false;
    
    case VIM_F:
      if (isCtrlPressed && PRESSED) {
        del_mods(MOD_MASK_CTRL);
        PRESS(KC_PGDOWN);
        set_mods(mod_state);
      } else {
        RELEASE(KC_PGDOWN);
      }
      return false;
    
    case VIM_G:
      if (PRESSED) {
        switch (VIM_QUEUE) {
          case KC_NO: 
            if (isShiftPressed) {
              del_mods(MOD_MASK_SHIFT);
              VIM_LAST_LINE();
              set_mods(mod_state);
            } else {
              VIM_LEADER(VIM_G);
            }
            break;
          case VIM_G: VIM_FIRST_LINE(); break;
        }
      }
      return false;
    
    case VIM_H:
      if (PRESSED) {
        switch (VIM_QUEUE) {
          case KC_NO: PRESS(KC_LEFT); break;
          case VIM_C: VIM_CHANGE_LEFT(_BASE); break;
          case VIM_D: VIM_DELETE_LEFT(); break;
          case VIM_V: VIM_VISUAL_LEFT(); break;
          case VIM_Y: VIM_YANK_LEFT(); break;
        }
      } else {
        RELEASE(KC_LEFT);
      }
      return false;

    case VIM_I:
      if (PRESSED) {
        switch (VIM_QUEUE) {
          case KC_NO: layer_move(_BASE); break;
          case VIM_C: VIM_LEADER(VIM_CI); break;
          case VIM_D: VIM_LEADER(VIM_DI); break;
          case VIM_V: VIM_LEADER(VIM_VI); break;
          case VIM_Y: VIM_LEADER(VIM_YI); break;
        }
      }
      return false;

    case VIM_J:
      if (PRESSED) {
        switch (VIM_QUEUE) {
          case KC_NO: 
            if (isShiftPressed) {
              del_mods(MOD_MASK_SHIFT);
              VIM_JOIN();
              set_mods(mod_state);
            } else {
              PRESS(KC_DOWN);
            }
            break;
          case VIM_C: VIM_CHANGE_DOWN(_BASE); break;
          case VIM_D: VIM_DELETE_DOWN(); break;
          case VIM_V: VIM_VISUAL_DOWN(); break;
          case VIM_Y: VIM_YANK_DOWN(); break;
        }
      } else {
        RELEASE(KC_DOWN);
      }
      return false;

    case VIM_K:
      if (PRESSED) {
        switch (VIM_QUEUE) {
          case KC_NO: PRESS(KC_UP); break;
          case VIM_C: VIM_CHANGE_UP(_BASE); break;
          case VIM_D: VIM_DELETE_UP(); break;
          case VIM_V: VIM_VISUAL_UP(); break;
          case VIM_Y: VIM_YANK_UP(); break;
        }
      } else {
        RELEASE(KC_UP);
      }
      return false;

    case VIM_L:
      if (PRESSED) {
        switch (VIM_QUEUE) {
          case KC_NO: PRESS(KC_RIGHT); break;
          case VIM_C: VIM_CHANGE_RIGHT(_BASE); break;
          case VIM_D: VIM_DELETE_RIGHT(); break;
          case VIM_V: VIM_VISUAL_RIGHT(); break;
          case VIM_Y: VIM_YANK_RIGHT(); break;
        }
      } else {
        RELEASE(KC_RIGHT);
      }
      return false;

    case VIM_O:
      if (PRESSED) { 
        if (isShiftPressed) {
          del_mods(MOD_MASK_SHIFT); 
          VIM_OPEN_ABOVE(_BASE); 
          set_mods(mod_state);
        } else {
          VIM_OPEN(_BASE); 
        }
      }
      return false;

    case VIM_P:
      if (PRESSED) { 
        if (isShiftPressed) {
          del_mods(MOD_MASK_SHIFT); 
          VIM_PUT_BEFORE(); 
          set_mods(mod_state);
        } else {
          VIM_PUT_AFTER();
        }
      }
      return false;
    
    case VIM_R:
      if (PRESSED) { 
        VIM_REPLACE(); 
        VIM_LEADER(VIM_R);
      }
      return false;

    case VIM_S:
      if (PRESSED) { 
        if (isShiftPressed) {
          del_mods(MOD_MASK_SHIFT); 
          VIM_CHANGE_WHOLE_LINE(_BASE);
          set_mods(mod_state);
        } else {
          VIM_SUBSTITUTE(_BASE);
        }
      }
      return false;

    case VIM_U:
      if (PRESSED) { 
        if (isCtrlPressed) {
          del_mods(MOD_MASK_CTRL); 
          //VIM_SCROLL_HALF_UP(); 
          set_mods(mod_state);
        } else {
          VIM_UNDO();
        }
      }
      return false;

    case VIM_V:
      if (PRESSED) { VIM_LEADER(VIM_V); }
      return false;

    case VIM_W:
      if (PRESSED) {
        switch (VIM_QUEUE) {
          case KC_NO: VIM_WORD(); break;
          case VIM_C: VIM_CHANGE_WORD(_BASE); break;
          case VIM_CI: VIM_CHANGE_INNER_WORD(_BASE); break;
          case VIM_D: VIM_DELETE_WORD(); break;
          case VIM_DI: VIM_DELETE_INNER_WORD(); break;
          case VIM_V: VIM_VISUAL_WORD(); break;
          case VIM_VI: VIM_VISUAL_INNER_WORD(); break;
          case VIM_Y: VIM_YANK_WORD(); break;
          case VIM_YI: VIM_YANK_INNER_WORD(); break;
        }
      }
      return false;

    case VIM_X:
      if (PRESSED) { VIM_CUT(); }
      return false;

    case VIM_Y:
      if (PRESSED) { 
        switch(VIM_QUEUE) {
          case KC_NO:
            if (isShiftPressed) {
              del_mods(MOD_MASK_SHIFT);
              VIM_YANK_TO_EOL();
              set_mods(mod_state);
            } else {
              VIM_LEADER(VIM_Y);
            }
            break;
          case VIM_Y: VIM_YANK_WHOLE_LINE(); break;
        }
      }
      return false;

    default:
      if (PRESSED) { 
        // if non VIM Keycode sent, clear VIM Leader queue
        VIM_LEADER(KC_NO);
      }
      return true;
  }
} 

// ************************************************ //
// ******** DYNAMIC TAP HOLD CONFIGURATION ******** //
// ************************************************ //
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case FNT_PSCR:
      return TAPPING_TERM + 40;
    default:
      return TAPPING_TERM;
  }
}
bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case CS_F14:
      return true;
    case FNT_PSCR:
      return true;
    case FNT_BSLS:
      return true;
    default:
      return false;
  }
}

// ************************************************ //
// ************* LAYER RGB INDICATORS ************* //
// ************************************************ //
#ifdef RGB_MATRIX_ENABLE
/* Leader Key per-key LED  */
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
/* WIP Code for layer state LED underglow */
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

/****
 *.##.......########..########.....########.##.....##.##....##..######..########.####..#######..##....##..######.
 *.##.......##.....##.##.....##....##.......##.....##.###...##.##....##....##.....##..##.....##.###...##.##....##
 *.##.......##.....##.##.....##....##.......##.....##.####..##.##..........##.....##..##.....##.####..##.##......
 *.##.......##.....##.########.....######...##.....##.##.##.##.##..........##.....##..##.....##.##.##.##..######.
 *.##.......##.....##.##...##......##.......##.....##.##..####.##..........##.....##..##.....##.##..####.......##
 *.##.......##.....##.##....##.....##.......##.....##.##...###.##....##....##.....##..##.....##.##...###.##....##
 *.########.########..##.....##....##........#######..##....##..######.....##....####..#######..##....##..######.
 */
#ifdef LEADER_ENABLE
// ***** Cursor Wrap Functions ***** //
/* (▌) PARENTHESIS */
void ldr_send_parenthesis_cursor_wrap(void) {
    SEND_STRING("()" SS_TAP(X_LEFT));
}
/* [▌] SQUARE BRACKET */
void ldr_send_bracket_cursor_wrap(void) {
    SEND_STRING("[]" SS_TAP(X_LEFT));
}
/* '▌' SINGLE QUOTE */
void ldr_send_quotesingle_cursor_wrap(void) {
    SEND_STRING("''" SS_TAP(X_LEFT));
}
/* "▌" DOUBLE QUOTE */
void ldr_send_quotedouble_cursor_wrap(void) {
    SEND_STRING("\"\"" SS_TAP(X_LEFT));
}
/* {▌} CURLY BRACE */
void ldr_send_curly_brace_cursor_wrap(void) {
    SEND_STRING("{}" SS_TAP(X_LEFT));
}
/* [▌] SQUARE BRACKET */
void ldr_send_squarebracket_cursor_wrap(void) {
    SEND_STRING("[]" SS_TAP(X_LEFT));
}
/* <▌> ANGLE BRACKET */
void ldr_send_angle_bracket_cursor_wrap(void) {
    SEND_STRING("<>" SS_TAP(X_LEFT));
}
/* `▌` GRAVE */
void ldr_send_grave_cursor_wrap(void) {
    SEND_STRING("``" SS_TAP(X_LEFT));
}
/* /▌/ FORWARD SLASH */
void ldr_send_forward_slash_cursor_wrap(void) {
    SEND_STRING("//" SS_TAP(X_LEFT));
}
/* *▌* ASTERISK */
void ldr_send_asterisk_cursor_wrap(void) {
    SEND_STRING("**" SS_TAP(X_LEFT));
}
/* @▌@ AT */
void ldr_send_at_cursor_wrap(void) {
    SEND_STRING("@@" SS_TAP(X_LEFT));
}
/* %▌% PERCENT */
void ldr_send_percent_cursor_wrap(void) {
    SEND_STRING("%%" SS_TAP(X_LEFT));
}

/****
 *.##.....##....###....########.########..####.##.....##.....######...######.....###....##....##
 *.###...###...##.##......##....##.....##..##...##...##.....##....##.##....##...##.##...###...##
 *.####.####..##...##.....##....##.....##..##....##.##......##.......##........##...##..####..##
 *.##.###.##.##.....##....##....########...##.....###........######..##.......##.....##.##.##.##
 *.##.....##.#########....##....##...##....##....##.##............##.##.......#########.##..####
 *.##.....##.##.....##....##....##....##...##...##...##.....##....##.##....##.##.....##.##...###
 *.##.....##.##.....##....##....##.....##.####.##.....##.....######...######..##.....##.##....##
 */
void matrix_init_user(void) {
  //debug_enable = true;
  VIM_LEADER(KC_NO);
};

LEADER_EXTERNS(); // Keep this line above matrix_scan_user

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    /* Caps Word */
    // Double tap LDR for CAPS_WORD
    SEQ_ONE_KEY(KC_LEAD) {
      caps_word_on();
    }
    /* Caps Lock */
    // Triple tap LDR for CAPSLOCK
    SEQ_TWO_KEYS(KC_LEAD, KC_LEAD) {
      tap_code(KC_CAPS);
      #ifdef RGBLIGHT_ENABLE
      if(IS_HOST_LED_ON(USB_LED_CAPS_LOCK)) { // Used to counter a CAPS and LED desync
        rgblight_enable_noeeprom();
      } else {
        rgblight_disable_noeeprom();
      }
      #endif // !RGBLIGHT_ENABLE
    }

    // ***** Cursor Wrap Macros by Symbol ***** //
    // NOTE: Pending removal
    /* (▌) PARENTHESIS */
    SEQ_TWO_KEYS(KC_LSFT, KC_9) {
      ldr_send_parenthesis_cursor_wrap();
    }
    /* [▌] SQUARE BRACKET */
    SEQ_ONE_KEY(KC_LBRC) {
      ldr_send_bracket_cursor_wrap();
    }
    /* '▌' SINGLE QUOTE */
    SEQ_ONE_KEY(KC_QUOT) {
      ldr_send_quotesingle_cursor_wrap();
    }
    /* "▌" DOUBLE QUOTE */
    SEQ_TWO_KEYS(KC_LSFT, KC_QUOT) {
      ldr_send_quotedouble_cursor_wrap();
    }
    
    // ***** Cursor Wrap Macros by Comfort ***** //
    // NOTE: Use the Symbol Layer as a Reference
    
    /* R4; Number Row*/
    /* @▌@ AT */
    SEQ_ONE_KEY(KC_2) {
      ldr_send_at_cursor_wrap();
    }
    /* %▌% PERCENT */
    SEQ_ONE_KEY(KC_5) {
      ldr_send_percent_cursor_wrap();
    }
    
    /* R3; Alpha */
    /* *▌* ASTERISK */
    SEQ_ONE_KEY(KC_E) {
      ldr_send_asterisk_cursor_wrap();
    }
    
    /* R2; Home Row */
    /* '▌' SINGLE QUOTE */
    SEQ_ONE_KEY(KC_F4) {
      ldr_send_quotesingle_cursor_wrap();
    }
    /* `▌` GRAVE */
    SEQ_ONE_KEY(KC_G) {
      ldr_send_grave_cursor_wrap();
    }
    /* (▌) PARENTHESIS */
    SEQ_ONE_KEY(KC_F) {
      ldr_send_parenthesis_cursor_wrap();
    }
    /* {▌} CURLY BRACE */
    SEQ_ONE_KEY(KC_D) {
      ldr_send_curly_brace_cursor_wrap();
    }
    /* <▌> ANGLE BRACKET */
    SEQ_ONE_KEY(KC_S) {
      ldr_send_angle_bracket_cursor_wrap();
    }
    /* "▌" DOUBLE QUOTE */
    SEQ_ONE_KEY(KC_A) {
      ldr_send_quotedouble_cursor_wrap();
    }
    
    /* R1; Alpha */
    /* /▌/ FORWARD SLASH */
    SEQ_ONE_KEY(KC_V) {
      ldr_send_forward_slash_cursor_wrap();
    }
    
    /* R0; Mod */
    
    leader_end();
  }
}

void leader_start(void) {
    isLeader = true;
}

void leader_end(void) {
    isLeader = false;
}
#endif // !LEADER_ENABLE

