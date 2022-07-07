#include <avr/io.h>

#include "registers.h"

#ifndef keyboard_driver
#define keyboard_driver
char lastChar = 0x0;
char asciiMap[48] = {
    0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15,
    16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
    32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47,
};
void keyboardDriver(void) {
  // ~50 Cycles
  char keyPress = 0x0;
  PORTA = 1;
  if (PORTC) {
    keyPress = PORTC + (8 * 0);
  }
  PORTA = 1 << 1;
  if (PORTC) {
    keyPress = PORTC + (8 * 1);
  }
  PORTA = 1 << 2;
  if (PORTC) {
    keyPress = PORTC + (8 * 2);
  }
  PORTA = 1 << 3;
  if (PORTC) {
    keyPress = PORTC + (8 * 3);
  }
  PORTA = 1 << 4;
  if (PORTC) {
    keyPress = PORTC + (8 * 4);
  }
  PORTA = 1 << 5;
  if (PORTC) {
    keyPress = PORTC + (8 * 5);
  }
  if (keyPress) {
    // Should be same cycles
    // Check
    if (keyPress == '\b') {
      // Backspace
      charBuffer[charBufferIndex--] = 0x0;
    } else {
      charBuffer[charBufferIndex++] = keyPress;
    }
  } else {
    asm volatile(
        // How many?
        "nop\t\n");
  }
}
#endif
