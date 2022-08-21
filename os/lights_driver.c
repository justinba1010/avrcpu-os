#include <avr/io.h>
#include <stdbool.h>

#include "lights_driver.h"
#include "tools.h"

static uint8_t counter = 0;

void increment_master_lights(void) { PORTA = ++counter; }

void master_lights_setup(void) { DDRA = 0x0b11000000; }
