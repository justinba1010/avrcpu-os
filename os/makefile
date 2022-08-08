include config.mk

F_CPU_DEF=-DF_CPU=$(FCPU)
CC = avr-gcc
CFLAGS = -I. -mmcu=$(MCUNAME) $(OPTIMIZATION) -Wall -std=gnu99 -Wno-main
ASSEMBLY =

SRCS = keyboard_driver.c screen_buffer_driver.c
OBJECTS = $(SRCS:.c=.o)

.PHONY: clean all burn

all: main.elf main.lst main.hex

main.elf: main.c $(OBJECTS)
	$(CC) $(CFLAGS) $^ $(ASSEMBLY) -o $@

main.lst: main.elf
	avr-objdump -C -g -d -h -S main.elf > main.lst

main.map: main.elf
	$(CC) $(CFLAGS) -Wl,-Map,main.map *.o

main.hex: main.elf
	avr-objcopy -j .text -j .data -O ihex main.elf main.hex
	avr-size main.hex

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $<

%.o: $.c
	$(CC) $(CFLAGS) -c $<

%.o: $.S
	$(cc) $(CFLAGS) --mccu=$(MCUNAME) -x assembler-with-cpp $<


flash: main.hex
	@printf "Flashing...\n"
	avrdude -B $(AVRISP_BAUD) -p $(PARTNO) -c avrisp -U flash:w:main.hex:i


clean:
	rm -f *.o *.lst *.elf *.map *.hex *.out
