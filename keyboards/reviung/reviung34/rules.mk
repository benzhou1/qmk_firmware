# Build Options
#   change yes to no to disable
#
BOOTLOADER = caterina
BOOTMAGIC_ENABLE = yes       # Enable Bootmagic Lite
MOUSEKEY_ENABLE = no       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = yes        # Console for debug
COMMAND_ENABLE = yes        # Commands for debug and configuration
NKRO_ENABLE = yes            # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output

COMBO_ENABLE = yes
VPATH = keyboards/gboards
TAP_DANCE_ENABLE = no
DYNAMIC_TAPPING_TERM_ENABLE = yes
OLED_ENABLE = yes
LTO_ENABLE = yes            # Link time optimise, reduce firmware size
