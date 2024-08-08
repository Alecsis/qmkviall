#pragma once
#define VIAL_KEYBOARD_UID {0xA4, 0x1F, 0x57, 0x31, 0x69, 0x2A, 0x37, 0xA5}
#define VIAL_UNLOCK_COMBO_ROWS { 0, 2 }
#define VIAL_UNLOCK_COMBO_COLS { 3, 0 }
#define DYNAMIC_KEYMAP_LAYER_COUNT 6
#define VIAL_TAP_DANCE_ENTRIES 1
#define ENCODERS_PAD_A { B2, F6 }
#define ENCODERS_PAD_B { B3, F5 }
#define ENCODER_RESOLUTION 4


#define MINUTE_TO_MS 60000  // 60 seconds * 1000 milliseconds
 
#ifdef OLED_ENABLE
    #define OLED_SCREENSAVER_TIMEOUT  5 * MINUTE_TO_MS  // 1 minute of no activity to turn on OLED screensaver
    #define OLED_TIMEOUT             10 * MINUTE_TO_MS  // 10 minutes of no activity to turn OLED off
#endif