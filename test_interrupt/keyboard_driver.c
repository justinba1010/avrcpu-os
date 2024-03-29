#include <avr/io.h>
#include <stdbool.h>

#include "keyboard_driver.h"
#include "tools.h"
const uint8_t K_FLAG_BUFFER_EMPTY = 0b00000001;
const uint8_t K_FLAG_BUFFER_FULL = 0b00000010;
const uint8_t K_FLAG_READ_LAST = 0b00000100;
const uint8_t K_FLAG_RESERVED3 = 0b00001000;
const uint8_t K_FLAG_RESERVED4 = 0b00010000;
const uint8_t K_FLAG_RESERVED5 = 0b00100000;
const uint8_t K_FLAG_RESERVED6 = 0b01000000;
const uint8_t K_FLAG_RESERVED7 = 0b10000000;

static const __flash char keyboard_char_table[KEYBOARD_BUFFER_LENGTH] = {
    '\e', '~', '\0', '\0', '1', 'Q', 'A', 'Z'};

void keyboard_setup(void) {
  DDRA |= 0x3F; // PORTA{0...5} are output
  DDRC = 0;     // PORTC is input
}

// Private calls

static inline char __read_keyboard_scan(void) {
  // Scan each line of the keyboard
  for (uint8_t i = 0; i < 6; ++i) {
    // Output a 1 on each line
    PORTA = 1 << i;
    if (PORTC) {
      // Grab input
      // TODO: This is wrong
      return keyboard_char_table[PORTC + i * 8];
    }
  }
  return 0;
}

static inline uint8_t __kputc(char c) {
  if (NGET_KFLAG(K_FLAG_BUFFER_FULL)) {
    keyboard_buffer[keyboard_buffer_index++] = c;
    return 1;
  }
  return 0;
}

// Syscalls

void read_keyboard(void) {
  // Check if buffer is full
  if (GET_KFLAG(K_FLAG_BUFFER_FULL)) {
    return;
  }
  // Scan keyboard for inputs
  uint8_t keyboard_code = __read_keyboard_scan();
  PORTA = 0;
  if (keyboard_code && ~GET_KFLAG(K_FLAG_READ_LAST)) {
    __kputc(keyboard_char_table[keyboard_code]);
  }
  if (keyboard_code == 0) {
    UNSET_KFLAG(K_FLAG_READ_LAST);
  }
  if (keyboard_buffer_index == KEYBOARD_BUFFER_LENGTH) {
    SET_KFLAG(K_FLAG_BUFFER_FULL);
  }
}

char kgetc(void) {
  if (GET_KFLAG(K_FLAG_BUFFER_EMPTY)) {
    return 0;
  }
  if (keyboard_buffer_index == 0) {
    UNSET_KFLAG(K_FLAG_BUFFER_EMPTY);
    return 0;
  }
  return keyboard_buffer[--keyboard_buffer_index];
}

uint8_t kputc(char c) { return __kputc(c); }

void keyboard_wait_for_line(char *buffer, uint8_t size) {
  char key_pressed = '\0';
  uint8_t index = 0;
  do {
    key_pressed = kgetc();
    if (key_pressed == '\b' && index > 0) {
      buffer[index--] = '\0';
    } else if (key_pressed != '\0') {
      buffer[index++] = key_pressed;
    }
  } while (key_pressed != '\n' && index < size - 1);

  // Terminate string
  buffer[index] = '\0';
}
