CAPS_WORD_ENABLE = yes
DIGITIZER_ENABLE = yes

MOUSEKEY_ENABLE = no
BACKLIGHT_ENABLE = no

SRC += mouse_manipulation.c
SRC += abnt2.c
SRC += features/custom_shift_keys.c

CONSOLE_ENABLE = yes

#REPEAT_KEY_ENABLE = yes


# Squeezing the most out of AVR
LTO_ENABLE = yes
#CONSOLE_ENABLE = no
#COMMAND_ENABLE = no
#MOUSEKEY_ENABLE = no
#EXTRAKEY_ENABLE = no
#SPACE_CADET_ENABLE = no
#GRAVE_ESC_ENABLE = no
#MAGIC_ENABLE = no
#AVR_USE_MINIMAL_PRINTF = yes
