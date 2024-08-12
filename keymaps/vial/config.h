#pragma once
//USB Connector identifyer 
#define VIAL_KEYBOARD_UID {0xA4, 0x1F, 0x57, 0x31, 0x69, 0x2A, 0x37, 0xA5}

//Security unlock combo for huge changes in VIAL
#define VIAL_UNLOCK_COMBO_ROWS { 0, 2 }
#define VIAL_UNLOCK_COMBO_COLS { 3, 0 }

//How many layers
#define DYNAMIC_KEYMAP_LAYER_COUNT 6

//I didnt want tap dance
#define VIAL_TAP_DANCE_ENTRIES 1

//Encoder configs for VIAL
#define ENCODERS_PAD_A { B2, F6 }
#define ENCODERS_PAD_B { B3, F5 }
#define ENCODER_RESOLUTION 4

//How many key combos i want
#define VIAL_COMBO_ENTRIES 7

//Macros that I can use
#define DYNAMIC_KEYMAP_MACRO_COUNT 99

//When oled turns of 5 mins
#define OLED_TIMEOUT 300000