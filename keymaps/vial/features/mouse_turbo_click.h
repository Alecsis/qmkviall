#pragma once
#include "quantum.h"
#ifdef __cplusplus
extern "C" {
#endif
bool process_mouse_turbo_click(uint16_t keycode, keyrecord_t* record,
                               uint16_t turbo_click_keycode);

#ifdef __cplusplus
}
#endif