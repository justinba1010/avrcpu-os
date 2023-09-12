#include <avr/io.h>
#include <stdbool.h>
#ifndef lights_driver_h
#define lights_driver_h

void increment_master_lights(void);
void master_lights_setup(void);
uint8_t random(uint8_t);

#endif
