global-incdirs-y += include
#global-incdirs-y += ../host/include
#srcs-y += new_taps_ta.c


srcs-y += new_taps_ta.c
srcs-y += new_taps_ta_handle.c
srcs-y += new_taps_ta_aes.c
srcs-y += new_taps_ta_hash.c
srcs-y += new_taps_ta_pbkdf2.c
srcs-y += new_taps_ta_debug.c
srcs-y += new_taps_ta_other.c
srcs-y += new_taps_ta_rsa.c



# To remove a certain compiler flag, add a line like this
#cflags-template_ta.c-y += -Wno-strict-prototypes
