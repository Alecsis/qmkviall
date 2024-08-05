// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "features/mouse_turbo_click.h"

enum custom_keycodes
{
    DSC,
    SPOT,
    ARC,
    TURBO = SAFE_RANGE,


};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_pad_4x3(
        //main
        DSC,   SPOT,   ARC,   KC_MPLY,
        TURBO ,   KC_6,   KC_7,   KC_8,
        LCTL(KC_C),   LCTL(KC_V),   KC_F13,   TG(1)
      
    ),
    [1] = LAYOUT_pad_4x3(
        KC_6,   KC_2,   KC_3,   KC_4,
        KC_5,   KC_6,   KC_7,   KC_8,
        KC_9,   KC_A,   MO(3),   TG(2)
      
    ), 
    [2] = LAYOUT_pad_4x3(
        KC_9,   KC_2,   KC_3,   KC_4,
        KC_5,   KC_6,   KC_7,   KC_8,
        KC_9,   KC_A,   KC_B,   TG(4)
      
    ),
    [3] = LAYOUT_pad_4x3(
        //mo
        QK_BOOT,   KC_2,   KC_3,   KC_4,
        KC_5,   KC_6,   KC_7,   KC_8,
        KC_9,   KC_A,   KC_B,   KC_C
      
    ),
    [4] = LAYOUT_pad_4x3(
        //numpad
        TG(5),   KC_1,   KC_4,   KC_7,
        KC_0,   KC_2,   KC_5,   KC_8,
        KC_ENT,   KC_3,   KC_6,   KC_9
      
    ),
    [5] = LAYOUT_pad_4x3(
        //f360
        KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_TRNS,   KC_TRNS,   KC_TRNS,   TO(0)
      
    ),                          
};

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{    if (!process_mouse_turbo_click(keycode, record, TURBO)) {
        return false;
    }
    switch (keycode)
    {
       case DSC:
            if (record->event.pressed)
            {
                SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_R) SS_UP(X_LGUI) SS_DELAY(100) "C:\\Users\\Truong Dang\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Discord Inc\\Discord.lnk" SS_TAP(X_ENTER));


            }
            else{

                //no trigger
            }
            break;
                        
       case SPOT:
            if (record->event.pressed)
            {
                SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_R) SS_UP(X_LGUI) SS_DELAY(100) 
            "C:\\Users\\Truong Dang\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Spotify.lnk" 
            SS_TAP(X_ENTER));


            }
            else{
                //no trigger
            }
            break;
       case ARC:
            if (record->event.pressed)
            {
                SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_R) SS_UP(X_LGUI) SS_DELAY(100) 
            "arc" 
            SS_TAP(X_ENTER));     

            }
            else{
                //no trigger
            }
            break;            
    }
    return true;
}   

bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) { return false; }
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(KC_MNXT);
        } else {
            tap_code(KC_MPRV);
        }
    } else if (index == 1) { /* Second encoder */
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return true;
}
    
enum layer_names {
    _MAC_DEFAULT,
    _MAC_UTILITY,
    _MAC_MOMENTARY,
    _MAC_MOLAYER,
    _MAC_NUMPAD,
    _MAC_F360

};


#ifdef OLED_ENABLE



// Draw to OLED
bool oled_task_user() {
    //128x32 
        // Default OLED code
    led_t led_state = host_keyboard_led_state();
    oled_set_cursor(5,0);
    oled_write_P(led_state.caps_lock ? PSTR(" Caps Lock "): PSTR(" EVA-03 "), false);
    oled_set_cursor(6,2);
    // Switch on current active layer
    switch (get_highest_layer(layer_state)) {
        case _MAC_DEFAULT :
            oled_write("Main Layer", false);
            break;
        case _MAC_UTILITY :
            oled_write("Util Layer", false);
            break;
        case _MAC_MOMENTARY : 
            oled_write("AUX Layer", false);
            break;
        case _MAC_MOLAYER :            
            oled_write("MO Layer", false);
            break;
        case _MAC_NUMPAD :            
            oled_write("Numpad Layer", false);
            break;
        case _MAC_F360 :
            oled_write("Fusion Layer", false);
            break;
    }

    return false;
}

#endif