MCU=atmega1284p
F_CPU=1000000
CC=avr-gcc
OBJCOPY=avr-objcopy
CFLAGS=-Wall -g -Os -I. -mmcu=${MCU} -DF_CPU=${F_CPU}
TARGET=test
SRCS=boot.c 

# TODO make all util scripts for includes
pixel.S: pixel.py utils.py
	python3 pixel.py > pixel.S

all: pixel.S
	${CC} ${CFLAGS} -o ${TARGET}.bin ${SRCS}
	${OBJCOPY} -j .text -j .data -O ihex ${TARGET}.bin ${TARGET}.hex

flash:
	avrdude -p ${MCU} -c avrisp -U flash:w:${TARGET}.hex:i -F -P /dev/cu.usbmodem111201

clean:
	rm -f *.bin *.hex pixel.S

