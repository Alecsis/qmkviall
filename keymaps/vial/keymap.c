// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "features/mouse_turbo_click.h"

enum custom_keycodes
{
    TURBO = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_pad_4x3(
        //main
        KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_MPLY,
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
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] =   { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [1] =   { ENCODER_CCW_CW(RGB_HUD, RGB_HUI),           ENCODER_CCW_CW(RGB_SAD, RGB_SAI)  },
    [2] =   { ENCODER_CCW_CW(RGB_VAD, RGB_VAI),           ENCODER_CCW_CW(RGB_SPD, RGB_SPI)  },
    [3] =   { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD),          ENCODER_CCW_CW(KC_RIGHT, KC_LEFT) },
    [4] =   { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD),          ENCODER_CCW_CW(KC_RIGHT, KC_LEFT) },
    [5] =   { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD),          ENCODER_CCW_CW(KC_RIGHT, KC_LEFT) },

};
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{    if (!process_mouse_turbo_click(keycode, record, TURBO)) {
        return false;
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
    // Set cursor position
    

    // Define image array

    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.caps_lock ? PSTR(" Caps Lock "): PSTR(" EVA-03 "), false);
    oled_advance_page(true);
    oled_advance_page(true);

    // Switch on current active layer
    switch (get_highest_layer(layer_state)) {
        case _MAC_DEFAULT :
            oled_write_P( PSTR(" EVA-03 "), false);
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

    void oled_clear(void);

    static const char PROGMEM raw_logo[] = {
        0,  0,  0,  0,  0,  0,  8, 24, 48, 64,192,192,192,254,255,255,255,255,255,255,255,241,248,248,248,248,248,248,240,224,192,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,252, 28, 56, 96,192,192,172,  0,253,255, 71,111, 31,127,255,255,255,255,255,255,255,255,223,207,143, 15,  7,  3,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        12,  0,  0,  3,  0,  0,  0,  0,  1,  0,  0,255,255, 68,228,254,158, 12, 29, 63,119,239,223,255,127,255,255,255,255,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
        0,  0,  1,  1, 12,  8, 16, 48,  0,  0,  0,131,  3,128,  0,129,131,131,128,  0,  0,  0,129,  1, 64, 32, 49, 27,  7,  9,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    };

    oled_write_raw_P(raw_logo, sizeof(raw_logo));

    



    return false;
}

#endif