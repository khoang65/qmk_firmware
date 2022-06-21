# Bootloader Mode
BOOTMAGIC_ENABLE = no
BACKLIGHT_ENABLE = no
# Underglow; ~18%, 5192 byte difference 
RGBLIGHT_ENABLE = no
# Per-key RGB
RGB_MATRIX_ENABLE = no

LEADER_ENABLE = yes
TAP_DANCE_ENABLE = yes
CAPS_WORD_ENABLE = yes
# Mouse Key; ~5%, 600 byte
MOUSEKEY_ENABLE = yes

# Firmware Size Optimizations
EXTRAFLAGS += -flto
SPACE_CADET_ENABLE = no
BLUETOOTH_ENABLE = no
OLED_DRIVER_ENABLE = no
AUDIO_ENABLE = no
MIDI_ENABLE = no