COMMAND_ENABLE     	 	 = no
CONSOLE_ENABLE     	 	 = no
GRAVE_ESC_ENABLE   	 	 = no 
MAGIC_ENABLE       	 	 = no
SPACE_CADET_ENABLE 	 	 = no
TAP_DANCE_ENABLE   	 	 = no

LTO_ENABLE         	 	 = yes
AVR_USE_MINIMAL_PRINTF = yes

AUTO_SHIFT_ENABLE  	 	 = yes
CAPS_WORD_ENABLE   	 	 = yes
COMBO_ENABLE       	 	 = yes
NKRO_ENABLE        	 	 = yes
RGBLIGHT_ENABLE    	 	 = yes 
SEND_STRING_ENABLE 	 	 = yes
TRI_LAYER_ENABLE   	 	 = yes
DEFERRED_EXEC_ENABLE 	 = yes

SRC += features/achordion.c
SRC += lwsm/src/rgb.c
SRC += lwsm/src/rgb_fader.c

CFLAGS += -Wno-error=unused-variable -funroll-loops
