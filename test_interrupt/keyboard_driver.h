#include <avr/io.h>
#include <stdbool.h>
#ifndef keyboard_driver_h
#define keyboard_driver_h

#define KEYBOARD_BUFFER_LENGTH 64
#define GET_KFLAG(FLAG) GET_FLAG(FLAG, keyboard_status)
#define NGET_KFLAG(FLAG) NGET_FLAG(FLAG, keyboard_status)
#define SET_KFLAG(FLAG) SET_FLAG(FLAG, keyboard_status)
#define UNSET_KFLAG(FLAG) UNSET_FLAG(FLAG, keyboard_status)
static char keyboard_buffer[KEYBOARD_BUFFER_LENGTH];
static uint8_t keyboard_buffer_index;
static uint8_t keyboard_status;

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
void keyboard_wait_for_line(char *buffer, uint8_t size);
void keyboard_setup(void);
#endif
