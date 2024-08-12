#oled on
OLED_ENABLE = yes
#Smaller Firmware 
LTO_ENABLE = yes
#Encoders on
ENCODER_ENABLE = yes
#How oled is talking to mcu
OLED_TRANSPORT = i2c

#Rules for the autoclicker
SRC += features/mouse_turbo_click.c
MOUSEKEY_ENABLE = yes
DEFERRED_EXEC_ENABLE = yes
