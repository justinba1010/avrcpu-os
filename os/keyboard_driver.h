#include <avr/io.h>
#include <stdbool.h>
#ifndef keyboard_driver_h
#define keyboard_driver_h

static char keyboard_buffer[];
static uint8_t keyboard_buffer_index;
static uint8_t keyboard_flags;

const uint8_t K_FLAG_BUFFER_EMPTY;
const uint8_t K_FLAG_BUFFER_FULL;
const uint8_t K_FLAG_READ_LAST;
const uint8_t K_FLAG_RESERVED3;
const uint8_t K_FLAG_RESERVED4;
const uint8_t K_FLAG_RESERVED5;
const uint8_t K_FLAG_RESERVED6;
const uint8_t K_FLAG_RESERVED7;

void read_keyboard(void);
char kgetc(void);
uint8_t kputc(char c);
#endif
