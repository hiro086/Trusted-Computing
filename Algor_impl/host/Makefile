CC      = $(CROSS_COMPILE)gcc
LD      = $(CROSS_COMPILE)ld
AR      = $(CROSS_COMPILE)ar
NM      = $(CROSS_COMPILE)nm
OBJCOPY = $(CROSS_COMPILE)objcopy
OBJDUMP = $(CROSS_COMPILE)objdump
READELF = $(CROSS_COMPILE)readelf

OBJS = new_taps_ca_debug.o
OBJS += new_taps_ca.o
OBJS += new_taps_ca_test.o

CFLAGS += -Wall -I../ta/include -I$(TEEC_EXPORT)/include -I./include
#Add/link other required libraries here
LDADD += -lteec -L$(TEEC_EXPORT)/lib

BINARY=new_taps

.PHONY: all
all: $(BINARY)

$(BINARY): $(OBJS)
	$(CC) $(LDADD) -o $@ $^

.PHONY: clean
clean:
	rm -f $(OBJS) $(BINARY)
