#include <avr/io.h>

int main(void) {
  PORTB = 0;
  PORTB |= (1 << 5);
}
