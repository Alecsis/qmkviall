#Support for VIAL
VIAL_ENABLE = yes

#Required for VIAL
VIA_ENABLE = yes

#Smaller firmware changes
LTO_ENABLE = yes
QMK_SETTINGS = no
TAP_DANCE_ENABLE = no

#Autoclicker
SRC += features/mouse_turbo_click.c
MOUSEKEY_ENABLE = yes
DEFERRED_EXEC_ENABLE = yes

#Encoder Support
ENCODER_MAP_ENABLE = yes

#OLED Support
OLED_ENABLE = yes
