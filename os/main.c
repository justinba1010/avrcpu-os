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
static const __flash char __exit[] = "Enter \"exit\" to exit";
void configure_interrupt(void);
void setup(void);

// TODO:
// Interrupt Flags?
// Could be turned into a some kind of polling RTOS
// Have flag to toggle if interrupt will count
// If count to some count, return from loop

static inline void boot(void) {
  setup();
  output_line_flash(__string_booting);
  scroll_line();
  output_line_flash(__copyright);
  scroll_line();
  output_line_flash(__programs);
  scroll_line();
}

uint8_t main(void) {
  boot();
  
  sei();
  // Load keyboard function to grab input
  char buffer[80] = {'\0'};
  while (1) {
    output_line_flash(__which_program);
    scroll_line();
    output_line_flash(__exit);
    scroll_line();
    keyboard_wait_for_line(buffer, 80);

    if (strcmp(buffer, "tictactoe") == 0) {
      // Tic Tac Toe
      tictactoe();
    } else if (strcmp(buffer, "basic") == 0) {
      // Basic
      // TODO Basic Interpreter
    } else if (strcmp(buffer, "exit") == 0) {
      break;
    }
  }
  cli();
  return 0;
}

ISR(TIMER0_OVF_vect, ISR_BLOCK) {
  read_keyboard();
  output_video_ram();
  increment_master_lights();
}

void setup(void) {
  // Configure ISR Interrupt
  screen_setup();
  keyboard_setup();
  master_lights_setup();
  configure_interrupt();
}

void configure_interrupt(void) {
  // 1024 Prescaler
  TCCR0B = (1 << CS02) | (1 << CS00);
  // 76 Hz
  TIFR0 = 1 << TOV0;
  // Enable Interrupt
  TIMSK0 = 1 << TOIE0;
}
