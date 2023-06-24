AUTO_SHIFT_ENABLE  	 	 = no
BOOTMAGIC_ENABLE       = no
COMMAND_ENABLE     	 	 = no
CONSOLE_ENABLE     	 	 = no
GRAVE_ESC_ENABLE   	 	 = no 
MAGIC_ENABLE       	 	 = no
SPACE_CADET_ENABLE 	 	 = no
TAP_DANCE_ENABLE   	 	 = no

AVR_USE_MINIMAL_PRINTF = yes
CAPS_WORD_ENABLE   	 	 = yes
COMBO_ENABLE       	 	 = yes
LTO_ENABLE         	 	 = yes
NKRO_ENABLE        	 	 = yes
RGBLIGHT_ENABLE    	 	 = yes 
SEND_STRING_ENABLE 	 	 = yes
TRI_LAYER_ENABLE   	 	 = yes
DEFERRED_EXEC_ENABLE 	 = yes
DYNAMIC_MACRO_ENABLE   = yes
DYNAMIC_TAPPING_TERM_ENABLE = yes

SRC                   += src/achordion.c
SRC                   += src/cRGB_functions.c
SRC                   += src/cRGB_fader.c
SRC                   += src/util.c
SRC                   += src/tap_number.c

CFLAGS                += -funroll-loops

TOP_SYMBOLS            = 15

# EEPROM_DRIVER          = transient



TOP_SYMBOLS            = 15

# EEPROM_DRIVER          = transient

