#include <avr/interrupt.h>
#include <avr/io.h>
#include <string.h>

#include <keyboard_driver.h>
#include <lights_driver.h>
#include <screen_buffer_driver.h>
#include <tictactoe.h>

static const __flash char __string_booting[] = "Booting...";
static const __flash char __copyright[] = "Baumputer (c) 2022 ... 16 KB Memory";
static const __flash char __programs[] = "Programs loaded: Basic, TicTacToe";
static const __flash char __which_program[] = "Enter program name: ";

void setup(void) {
  // Configure ISR Interrupt
  screen_setup();
  keyboard_setup();
  master_lights_setup();
  configure_interrupt();
}

static inline void boot(void) {
  setup();
  output_line_flash(__string_booting);
  scroll_line();
  output_line_flash(__copyright);
  scroll_line();
  output_line_flash(__programs);
  scroll_line();
}

void main(void) {
  boot();
  // Load keyboard function to grab input
  char buffer[80] = {'\0'};
  while (true) {
    output_line_flash(__which_program);
    output_line("Enter \"exit\" to exit");
    keyboard_wait_for_line(buffer, 80);
    if (strcmp(buffer, "TicTacToe") == 0) {
      // Tic Tac Toe
      tictactoe();
    } else if (strcmp(buffer, "Basic") == 0) {
      // Basic
    } else if (strcmp(buffer, "exit") == 0) {
      break;
    }
  }
}

ISR(TIMER1_OVF_vect, ISR_BLOCK) {
  // Run every ~125 ms
  read_keyboard();
  output_video_ram();
  increment_master_lights();
}

void configure_interrupt(void) {}
