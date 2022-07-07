#ifndef global_justin
#define global_justin
#ifndef true
#define true 0xFF
#endif
#ifndef false
#define false 0x0
#endif

#define VGAPORT PORTD 

#define startImageFrame 0x3000;
uint16_t imageFrame;
uint8_t syncFlag;
uint8_t DRIVER_LINE;
#endif
