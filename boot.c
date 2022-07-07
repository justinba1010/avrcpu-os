#include <avr/interrupt.h>
#include <avr/io.h>

#include "global.h"
#include "keyboard_driver.c"
#include "registers.h"

#ifndef boot
#define boot

int main(void) {
  // Set up clock divider
  // 20 MHz /
  TCCR0B |= _BV(CS01);
  TIMSK0 |= _BV(TOIE0);
  DRIVER_LINE = 0;
  uint16_t *x;
  x = (void *)0x800102;
  return *x;
}

void reset(void) {
  syncFlag = false;
  imageFrame = 0x0;
  DRIVER_LINE = 0x0;
  charBufferIndex = 0;
}

ISR(TIMER0_OVF_vect, ISR_NAKED) {
  cli();
  Z = imageFrame + startImageFrame;
  // If we re-enter the interrupt and the sync flag is set, we should roll back
  // a DRIVER_LINE, otherwise it will skip vertical DRIVER_LINEs
  if (syncFlag) --DRIVER_LINE;
  for (;; ++DRIVER_LINE) {
    if (DRIVER_LINE <= 75) {
      // Image Display Vertical
      //
      // 400 clock cycles
      asm volatile(
#include "pixel.S"
          ::
              : "r16", "r30", "r31");
      // Horizontal - Front Porch (20 cycles)
      VGAPORT = 0xFF;

      // Horizontal - Sync (64 cycles)
      VGAPORT = ~0x01;

      // Horizontal - Back Porch (44 cycles)
      VGAPORT = 0xFF;
    } else if (DRIVER_LINE <= 76) {
      // Vertical - Front Porch (1 DRIVER_LINE - 528 clock cycles)
      if (syncFlag) {
        // Hsync (64 cycles)
        VGAPORT = ~0x01;
        // ...
        // Back Porch (44 cycles)
        VGAPORT = 0xFF;
        syncFlag = false;
      } else {
        syncFlag = true;
        // Set timer
        // Keyboard Driver
        keyboardDriver();
        break;
      }
    } else if (DRIVER_LINE <= 80) {
      // Vertical - Sync (4 lines - 2112 clock cycles)
      if (syncFlag) {
        // Horizontal - sync (64 cycles)
        // Can we fit a keyboard driver in ~50 cycles?
        VGAPORT = ~0x11;
        //...
        // Vertical - Back Porch (44 cycles)
        VGAPORT = ~0x10;
        syncFlag = false;
      } else {
        syncFlag = true;
        // Set timer
        // Work
        // 400 + 20 - X
        break;
      }
    } else if (DRIVER_LINE <= 91) {
      // Vertical - Back Porch (11 lines - 12144 cycles)
      if (syncFlag) {
        // Hsync (64 cycles)
        VGAPORT = ~0x01;
        // ...
        // Vertical - Back Porch (44 cycles)
        VGAPORT = 0xFF;
        // ...
        syncFlag = false;
      }
    } else {
      DRIVER_LINE = 0;
    }
    sei();
  }
}
#endif
