#pragma once
#define DYNAMIC_KEYMAP_LAYER_COUNT 6

#define ENCODERS_PAD_A { B2, F6 }
#define ENCODERS_PAD_B { B3, F5 }
#define ENCODER_RESOLUTION 4


#define MINUTE_TO_MS 60000  // 60 seconds * 1000 milliseconds
 
#ifdef OLED_ENABLE
    #define OLED_SCREENSAVER_TIMEOUT  5 * MINUTE_TO_MS  // 1 minute of no activity to turn on OLED screensaver
    #define OLED_TIMEOUT             10 * MINUTE_TO_MS  // 10 minutes of no activity to turn OLED off
#endif