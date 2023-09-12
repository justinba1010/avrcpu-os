#include <avr/io.h>
#include <stdbool.h>

#include "screen_buffer_driver.h"
#include "tools.h"

static uint8_t screen_buffer[SCREEN_HEIGHT][SCREEN_WIDTH];

static uint8_t current_line = 22;

static uint8_t scrolling_offset = 0;

const uint8_t SB_FLAG_RESERVED0 = 0b00000001;
const uint8_t SB_FLAG_RESERVED1 = 0b00000010;
const uint8_t SB_FLAG_RESERVED2 = 0b00000100;
const uint8_t SB_FLAG_RESERVED3 = 0b00001000;
const uint8_t SB_FLAG_RESERVED4 = 0b00010000;
const uint8_t SB_FLAG_RESERVED5 = 0b00100000;
const uint8_t SB_FLAG_RESERVED6 = 0b01000000;
const uint8_t SB_FLAG_RESERVED7 = 0b10000000;

void clear_screen(void) {
  for (uint8_t i = 0; i < SCREEN_HEIGHT; ++i) {
    for (uint8_t j = 0; j < SCREEN_WIDTH; ++j) {
      screen_buffer[i][j] = 0;
    }
  }
}

void screen_setup(void) {
  DDRB = 0xFF;
  DDRD |= 0x03; // Input bit & Clock Bit on Port D
  clear_screen();
  // Output Boot Screen?
}

static inline void __set_input_dumb_terminal(void) {
  PORTD |= 0x02; // Set on
}

static inline void __unset_input_dumb_terminal(void) {
  PORTD &= ~0x02; // Set off
}

static inline void __set_clock_dumb_terminal(void) {
  PORTD |= 0x01; // Set on
}

static inline void __unset_clock_dumb_terminal(void) {
  PORTD &= ~0x01; // Set off
}

static inline void __put_on_dumb_terminal(char output) {
  PORTB = output;
  __set_clock_dumb_terminal();
  // ~ 1 microsecond delay, should be catchable on interrupt on RasPi
  __unset_clock_dumb_terminal();
}

void output_video_ram(void) {
  // Sync
  __set_input_dumb_terminal();
  // Delay ~25 us?
  // Should be enough to signal begin
  for (uint8_t i = 0; i < SYNC_DELAY; ++i) {
    asm volatile("nop\t\n");
    ++i;
  }
  for (uint8_t i = 0; i < SCREEN_HEIGHT; ++i) {
    for (uint8_t j = 0; j < SCREEN_WIDTH; ++j) {
      __put_on_dumb_terminal(
          screen_buffer[(i + scrolling_offset) % SCREEN_HEIGHT][j]);
    }
  }
  __unset_input_dumb_terminal();
}

void output_line(char line[]) {
  uint8_t i = 0;
  for (; i < 80 && line[i]; ++i) {
    screen_buffer[current_line][i] = line[i];
  }
  for (; i < 80; ++i) {
    screen_buffer[current_line][i] = 0;
  }
}

void output_line_flash(const char __flash *line) {
  uint8_t i = 0;
  for (; i < 80 && line[i]; ++i) {
    screen_buffer[current_line][i] = line[i];
  }
  for (; i < 80; ++i) {
    screen_buffer[current_line][i] = 0;
  }
}

void scroll_line(void) {
  current_line++;
  current_line %= SCREEN_HEIGHT;
}
