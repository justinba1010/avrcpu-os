#include <avr/interrupt.h>
#include <avr/io.h>
#include "include1.h"
#include "memory_registers.h"

void setup(void) {
  cli();
  include1_h();

  // Set vertical lines
  // TCCR0A = COM0A1 | COM0A0 | COM0B1 | COM0B0 | - | - | WGM01 | WGM00
  // Waveform Generation Mode
  // WGM[2:0] = 0b010 => CTC Mode 0, 1, 2 ... OCRA
  TCCR0A = (1 << WGM01);
  // TCCR0B = FOC0A | FOC0B | - | - | WGM02 | CS02 | CS01 | CS00
  // CS[2:0] = 0b010 => clk/8
  TCCR0B = (1 << CS01);
  // CTC Mode Compare A value
  OCR1A = 66; // 20 MHz / 8 * 26.4 uS
  TIMSK0 |= ( 1 << OCIE0A); // Set interupt on timer 0


  sei();
}

void test(void) {
  G_LINES++;

  if (G_LINES < 602) {
    if (G_LINES == 601) {
      G_LINES = 1;
    } else {
      G_LINES = 0;
    }
  } else {
    if (G_LINES == 628) {
      G_LINES = 4;
    } else if (G_LINES < 605) {
      G_LINES = 2;
    } else {
      G_LINES = 3;
    }
  }
}

void main(void) {
}
