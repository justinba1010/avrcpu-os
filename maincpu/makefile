include config.mk

F_CPU_DEF=-DF_CPU=$(F_CPU)
CC = avr-gcc
#LFLAGS = --verbose
CFLAGS = -mmcu=$(MCUNAME) $(OPTIMIZATION) -Wall --std=gnu11
ASSEMBLY = jump.S

.PHONY: clean all burn

all: main.elf main.lst main.hex

main.elf: jump.S main.c
	$(CC) $(CFLAGS) $^ -o $@

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

flash_fuse:

clean:
	rm -f *.o *.lst *.elf *.map *.hex *.out


%.d: %.c
	@set -e; rm -f $@; \
	$(CC) -M $(CFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$
%.d: %.S
	@set -e; rm -f $@; \
	$(CC) -M $(CFLAGS) -x assembler-with-cpp $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$
