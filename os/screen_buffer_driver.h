#include <avr/io.h>
#include <stdbool.h>
#ifndef screen_buffer_driver_h
#define screen_buffer_driver_h

static uint8_t screen_buffer_index;
static uint8_t screen_buffer_status;

const uint8_t SB_FLAG_RESERVED0;
const uint8_t SB_FLAG_RESERVED1;
const uint8_t SB_FLAG_RESERVED2;
const uint8_t SB_FLAG_RESERVED3;
const uint8_t SB_FLAG_RESERVED4;
const uint8_t SB_FLAG_RESERVED5;
const uint8_t SB_FLAG_RESERVED6;
const uint8_t SB_FLAG_RESERVED7;

void clear_screen(void);
void output_video_ram(void);

#endif
