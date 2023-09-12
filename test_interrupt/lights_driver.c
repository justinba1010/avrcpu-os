#include <avr/io.h>
#include <stdbool.h>

#include "lights_driver.h"
#include "tools.h"

static uint8_t counter = 0xFF;

void increment_master_lights(void) { PORTA = ++counter; }
/*
void lighta(bool set) {
  counter = set ? counter | 1 << 6 : counter & (~(1 << 6));
  PORTA = counter;
}

void lightb(bool set) {
  counter = set ? counter | 1 << 7 : counter & (~(1 << 7));
  PORTA = counter;
}
*/

void master_lights_setup(void) {
  DDRA = 0b11000000;
  PORTA = counter;
}

uint8_t random(uint8_t count) {
  // LCG of Garbage Quality
  return (7 * counter++) + 251 % count;
}
