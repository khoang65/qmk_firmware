#include QMK_KEYBOARD_H

 enum layer_names {
    BASE = 0,
    FUNCTION, 
    VIM,
    NUMPAD,
    ADJUST
};

enum custom_keycodes {
  CUSTOMKC1 = SAFE_RANGE,
  MO_LYR_LEADER
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  
   /* Keymap 0: BASE layer
   * ,-----------------------------------------------------------.                              ,-----------------------------------------------------------.
   * | ESC     | !1      | @2      | #3      | $4      | %5      |---------.          ,---------| ^6      | &7      | *8      | (9      | )0      | _-      |
   * |---------+---------+---------+---------+---------+---------| {[      |          | }]      |---------+---------+---------+---------+---------+---------|
   * | Tab     | Q       | W       | E       | R       | T       |---------|          |---------| Y       | U       | I       | O       | P       | LEADER  |
   * |---------+---------+---------+---------+---------+---------| F4      |          | +=      |---------+---------+---------+---------+---------+---------|
   * | ~`      | A       | S       | D       | F       | G       |---------|          |---------| H       | J       | K       | L       | :;      | "'      |
   * |---------+---------+---------+---------+---------+---------| PSCR    |          | |\      |---------+---------+---------+---------+---------|---------|
   * | LShift  | Z       | X       | C       | V       | B       |---------'          `---------| N       | M       | <,      | >.      | ?/      | RShift  |
   * |---------+---------+---------+-----------------------------'                              `-----------------------------+---------+---------+---------|
   * | LCtrl   | Meh(F13)| OS      || LAlt    |                                                                    | All()   || F15     | Ins     | TT(3)   |
   * `-----------------------------'`---------'        ,-------------------.          ,-------------------.        `---------'`-----------------------------'
   *                                                   |         |         |          |         |         |       
   *                                                   | LT(1),  |_________|          | MO(2)   | Enter   |
   *                                         ,---------| Del     |         |          |         |         +---------.
   *                                         | Space   |         | CST(F14)|          |         |         | BckSpc  |
   *                                         `-----------------------------'          `-----------------------------'
   */
	[BASE] = LAYOUT_4key_2u_inner(
      KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_LBRC,             KC_RBRC,  KC_6,     KC_7,     KC_8,      KC_9,     KC_0,    KC_MINS, 
      KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_F4,               KC_EQL,   KC_Y,     KC_U,     KC_I,      KC_O,     KC_P,    KC_LEAD, 
      KC_GRV,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_PSCR,             KC_BSLS,  KC_H,     KC_J,     KC_K,      KC_L,     KC_SCLN, KC_QUOT, 
      KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_NO,               KC_NO,    KC_N,     KC_M,     KC_COMM,   KC_DOT,   KC_SLSH, KC_RSFT, 
      KC_LCTL,  MEH_T(KC_F13), KC_LGUI, KC_LALT, KC_SPC,  LT(1,KC_DEL), C_S_T(KC_F14),   MO(2),    KC_ENT,   KC_BSPC,  ALL_T(KC_NO), KC_F15, KC_INS, TT(3)
      ),
  

   /* Keymap 1: F layer
   * ,-----------------------------------------------------------.                              ,-----------------------------------------------------------.
   * | TRNS    | F1      | F2      | F3      | F4      | F5      |---------.          ,---------| F6      | F7      | F8      | F9      | F10     | TRNS    |
   * |---------+---------+---------+---------+---------+---------| F11     |          | F12     |---------+---------+---------+---------+---------+---------|
   * | TRNS    | TRNS    | TRNS    | TRNS    | TRNS    | TRNS    |---------|          |---------| TRNS    | TRNS    | TRNS    | TRNS    | TRNS    | TRNS    |
   * |---------+---------+---------+---------+---------+---------| TRNS    |          | TRNS    |---------+---------+---------+---------+---------+---------|
   * | TRNS    | TRNS    | TRNS    | TRNS    | TRNS    | TRNS    |---------|          |---------| TRNS    | TRNS    | TRNS    | TRNS    | TRNS    | TRNS    |
   * |---------+---------+---------+---------+---------+---------| TRNS    |          | TRNS    |---------+---------+---------+---------+---------|---------|
   * | TRNS    | TRNS    | TRNS    | TRNS    | TRNS    | TRNS    |---------'          `---------| TRNS    | TRNS    | TRNS    | TRNS    | TRNS    | TRNS    |
   * |---------+---------+---------+-----------------------------'                              `-----------------------------+---------+---------+---------|
   * | TRNS    | TRNS    | TRNS    || TRNS    |                                                                    | TRNS    || TRNS    | TRNS    | TO(0)   |
   * `-----------------------------'`---------'        ,-------------------.          ,-------------------.        `---------'`-----------------------------'
   *                                                   |         | TRNS    |          | TRNS    |         |       
   *                                                   | TRNS    |_________|          |_________| TRNS    |
   *                                         ,---------|         | TRNS    |          | TRNS    |         +---------.
   *                                         | TRNS    |         |         |          |         |         | TRNS    |
   *                                         `-----------------------------'          `-----------------------------'
   */  
	[FUNCTION] = LAYOUT_4key_2u_inner(
      KC_TRNS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F11,              KC_F12,   KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,    KC_TRNS, 
      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,             KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS, 
      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,             KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS, 
      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,             KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS, 
      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,             KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   TO(0)
      ),
      
      
   /* Keymap 2: VIM layer
   * ,-----------------------------------------------------------.                              ,-----------------------------------------------------------.
   * |         |         |         |         |         |         |---------.          ,---------| Rewind  |         |         | Fastfwd |         |         |
   * |---------+---------+---------+---------+---------+---------|         |          |         |---------+---------+---------+---------+---------+---------|
   * |         |         |Ctrl righ|         | Again   |         |---------|          |---------| Ctrl C  | Ctrl Z  |         |         | Ctrl V  |         |
   * |---------+---------+---------+---------+---------+---------|         |          | Play    |---------+---------+---------+---------+---------+---------|
   * |         |         |         | Ctrl X  | Find    |         |---------|          |---------| Left    | Down    | Up      | Right   |         | Calc    |
   * |---------+---------+---------+---------+---------+---------|         |          | Mute    |---------+---------+---------+---------+---------|---------|
   * | LShift  | Undo    | Cut     | Copy    | Paste   |Ctrl left|---------'          `---------| Prev Tra| Vol -   | Vol +   | Next Tra| Ctrl F  |         |
   * |---------+---------+---------+-----------------------------'                              `-----------------------------+---------+---------+---------|
   * | LCtrl   | Meh(F13)| N/A     || N/A     |                                                                    |         ||         |         | TO(0)   |
   * `-----------------------------'`---------'        ,-------------------.          ,-------------------.        `---------'`-----------------------------'
   *                                                   |         |         |          | TRNS    |         |       
   *                                                   | Del     |_________|          |_________| Enter   |
   *                                         ,---------|         | CST(F14)|          | TRNS    |         +---------.
   *                                         | Spc     |         |         |          |         |         | BckSpc  |
   *                                         `-----------------------------'          `-----------------------------'
   */     
	[VIM] = LAYOUT_4key_2u_inner(
      KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,               KC_NO,    KC_MRWD,    KC_NO,    KC_NO,    KC_MFFD,    KC_NO,    KC_NO, 
      KC_NO,    KC_NO,    LCTL(KC_RGHT), KC_NO, KC_AGIN, KC_NO,   KC_NO,               KC_MPLY,  LCTL(KC_C), LCTL(KC_Z), KC_NO,  KC_NO,      LCTL(KC_V), KC_NO, 
      KC_NO,    KC_NO,    KC_NO,    LCTL(KC_X), KC_FIND, KC_NO,   KC_NO,               KC_MUTE,  KC_LEFT,    KC_DOWN,  KC_UP,    KC_RGHT,    KC_NO,    KC_CALC, 
      KC_LSFT,  KC_UNDO,  KC_CUT,   KC_COPY,  KC_PSTE,  LCTL(KC_LEFT), KC_NO,          KC_TRNS,  KC_MPRV,    KC_VOLD,  KC_VOLU,  KC_MNXT,    LCTL(KC_F), KC_NO, 
      KC_LCTL,  MEH_T(KC_F13), KC_NO, KC_NO,    KC_SPC,   KC_DEL,   C_S_T(KC_F14),       KC_TRNS,  KC_ENT,     KC_BSPC,  KC_NO,    KC_NO,      KC_NO, TO(0)
      ),
      
      
   /* Keymap 3: NUMPAD Layer
   * ,-----------------------------------------------------------.                              ,-----------------------------------------------------------.
   * | Esc     | !       | @       | #       | $       | %       |---------.          ,---------| ^       | &       | Num Lk  | *       | /       | -       |
   * |---------+---------+---------+---------+---------+---------| {[      |          | }]      |---------+---------+---------+---------+---------+---------|
   * | Tab     |         |         |         |         |         |---------|          |---------|         | &7      | *8      | (9      | +       |         |
   * |---------+---------+---------+---------+---------+---------| TO(4)   |          | +=      |---------+---------+---------+---------+---------+---------|
   * | ~`      |         |         |         |         |         |---------|          |---------|         | $4      | %5      | ^6      | .       | =+      |
   * |---------+---------+---------+---------+---------+---------| Meh()   |          | |\      |---------+---------+---------+---------+---------|---------|
   * | LShift  |         |         |         |         |         |---------'          `---------|         | !1      | @2      | #3      | =       | RShift  |
   * |---------+---------+---------+-----------------------------'                              `-----------------------------+---------+---------+---------|
   * | LCtrl   | Meh(F13)|         || LAlt    |                                                                    | .       || F15     | Ins     | TO(0)   |
   * `-----------------------------'`---------'        ,-------------------.          ,-------------------.        `---------'`-----------------------------'
   *                                                   |         |         |          |         |         |       
   *                                                   | Del     |_________|          |         | Enter   |
   *                                         ,---------|         | CST(F14)|          | MO(2)   |         +---------.
   *                                         | Spc     |         |         |          |         |         | BckSpc  |
   *                                         `-----------------------------'          `-----------------------------'
   */     
	[NUMPAD] = LAYOUT_4key_2u_inner(
      KC_ESC,  KC_EXLM,   KC_AT,    KC_HASH,   KC_DLR,   KC_PERC, KC_LBRC,             KC_RBRC,  KC_CIRC,  KC_AMPR,  KC_NLCK,  KC_PAST,  KC_PSLS,  KC_PMNS, 
      KC_TAB,  KC_NO,     KC_NO,    KC_NO,     KC_NO,    KC_NO,   TO(4),               KC_EQL,   KC_NO,    KC_7,     KC_8,     KC_9,     KC_PPLS,  KC_NO, 
      KC_GRV,  KC_NO,     KC_NO,    KC_NO,     KC_NO,    KC_NO,   MEH(KC_NO),          KC_BSLS,  KC_NO,    KC_4,     KC_5,     KC_6,     KC_PCMM,  KC_QUOT,
      KC_LSFT, KC_NO,     KC_NO,    KC_NO,     KC_NO,    KC_NO,   KC_NO,               KC_NO,    KC_P0,    KC_1,     KC_2,     KC_3,     KC_PEQL,  KC_RSFT, 
      KC_LCTL, MEH_T(KC_F13), KC_NO,  KC_LALT,   KC_SPC,   KC_DEL,  C_S_T(KC_F14),       MO(2),    KC_ENT,   KC_BSPC,  KC_PDOT,  KC_F15,   KC_INS,    TO(0)
      ),
	
  
   /* Keymap 4: SYMBOL/ADJUST Layer
   * ,-----------------------------------------------------------.                              ,-----------------------------------------------------------.
   * | Esc     | !       | @       | #       | $       | %       |---------.          ,---------|         |         |         |         |         |         |
   * |---------+---------+---------+---------+---------+---------| {[      |          |         |---------+---------+---------+---------+---------+---------|
   * |         | ^       | &       | *       | -       | _       |---------|          |---------| Hue-    | Bright- | Bright+ | Hue+    |         |         |
   * |---------+---------+---------+---------+---------+---------| '       |          |         |---------+---------+---------+---------+---------+---------|
   * | ~       | "       | <       | {       | (       | `       |---------|          |---------|<RGB_MODE| RGB_TOG |RGB_PLAIN|RGB_MODE>|         |         |
   * |---------+---------+---------+---------+---------+---------| :       |          |         |---------+---------+---------+---------+---------|---------|
   * |         | .       | +       | =       | /       | \       |---------'          `---------|         |         |         |         | EEP_RST |         |
   * |---------+---------+---------+-----------------------------'                              `-----------------------------+---------+---------+---------|
   * |         |         |         ||         |                                                                    |         ||         |         | TO(0)   |
   * `-----------------------------'`---------'        ,-------------------.          ,-------------------.        `---------'`-----------------------------'
   *                                                   |         |         |          |         |         |       
   *                                                   |         |_________|          |         |         |
   *                                         ,---------|         | CST(F14)|          |         |         +---------.
   *                                         |         |         |         |          |         |         |         |
   *                                         `-----------------------------'          `-----------------------------'
   */ 
  [ADJUST] = LAYOUT_4key_2u_inner(
      KC_ESC,   KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,  KC_LBRC,             KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO, 
      KC_NO,    KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_MINS,  KC_UNDS,  KC_QUOT,             KC_NO,    RGB_HUD,  RGB_VAD,  RGB_VAI,  RGB_HUI,  KC_NO,    KC_NO, 
      KC_TILD,  KC_DQUO,  KC_LT,    KC_LCBR,  KC_LPRN,  KC_DQUO,  KC_COLN,             KC_NO,    RGB_RMOD, RGB_TOG,  RGB_M_P,  RGB_MOD,  KC_NO,    KC_NO, 
      KC_NO,    KC_PDOT,  KC_PLUS,  KC_EQL,   KC_PSLS,  KC_BSLS,  KC_NO,               KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    EEP_RST,  KC_NO, 
      KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    C_S_T(KC_F14),       KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    TO(0))
};

// ************************************************ //
// **************** RGB INDICATORS **************** //
// ************************************************ //
void rgb_matrix_indicators_user(void) { 
  #ifdef RGB_MATRIX_ENABLE
  
  /* CapsLock Underglow Indicator */
  
  /* Leader Underglow Indicator*/
  
  #endif // !RGB_MATRIX_ENABLE
}



// ************************************************ //
// ******************** LEADER ******************** //
// ************************************************ //
#ifdef LEADER_ENABLE

// ***** LEADER KEY FUNCTIONS` ***** //
// used to repeat a macro for two different sequences 

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

// ***** Selection Wrap Functions(?) ***** //

LEADER_EXTERNS(); // Keep this line above matrix_scan_user

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    
    // Note: These sequence functions aren't arrays, you 
    // don't need to put any commasor semicolons between sequences.
    
    /* Capslock */
    // Double tap LDR for CAPS
    SEQ_ONE_KEY(KC_LEAD) {
      tap_code(KC_CAPS);
    }
    
    // ***** Macros by Symbol ***** //
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
    
    // ***** Macros by Comfort ***** //
    // Use symbol layer as a reference
    
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

#endif // !LEADER_ENABLE

