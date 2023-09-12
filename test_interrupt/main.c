#include <avr/interrupt.h>
#include <avr/io.h>
#include <string.h>
//#define F_CPU 20000000UL

static uint8_t counter = 0xFF;
void configure_interrupt(void);

uint8_t main(void) {
  configure_interrupt();
  sei();
  while (1) {

  }
  return 0;
}

ISR(TIMER0_OVF_vect, ISR_BLOCK) {
  // Run every ~125 ms
  cli();
  PORTA = ++counter; //counter;
  sei();
}

void configure_interrupt(void) {
  // Enable Interrupt
  TIMSK0 = (1 << TOIE0);
  // No wave generator
  // 1024 Prescaler
  TCCR0B = (1 << CS02) | (1 << CS00);
  // 76 Hz

  PORTA = counter;

  DDRA = 0xFF;
  TCNT0 = 0;
  TIMSK0 = 1 << TOIE0;
  TIFR0 = 1 << TOV0;
}
