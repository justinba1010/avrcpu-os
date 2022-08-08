#include <avr/interrupt.h>
#include <avr/io.h>
#include <keyboard_driver.h>
#include <screen_buffer_driver.h>

void setup(void) {
  // Configure ISR Interrupt
  clear_screen();
}

void main(void) {
}

ISR(TIMER1_OVF_vect, ISR_BLOCK) {
  // Run every 50 ms
  read_keyboard();
  output_video_ram();
}
