CAPS_WORD_ENABLE = yes
CUSTOM_MATRIX = lite
WS2812_DRIVER = vendor
RGBLIGHT_ENABLE = yes
DEFERRED_EXEC_ENABLE = yes
SRC += cheapino.c
SRC += encoder.c
SRC += ghosting.c
SRC += matrix.c

COMBO_ENABLE = yes
VPATH = keyboards/gboards
TAP_DANCE_ENABLE = no
DYNAMIC_TAPPING_TERM_ENABLE = yes
OLED_ENABLE = no
LTO_ENABLE = yes            # Link time opimise, reduce firmware size
