#include <avr/io.h>
#include <stdbool.h>
#ifndef screen_buffer_driver_h
#define screen_buffer_driver_h

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25
#define SYNC_DELAY 25
#define GET_SBFLAG(FLAG) GET_FLAG(FLAG, screen_buffer_status)
#define NGET_SBFLAG(FLAG) NGET_FLAG(FLAG, screen_buffer_status)
#define SET_SBFLAG(FLAG) SET_FLAG(FLAG, screen_buffer_status)
#define UNSET_SBFLAG(FLAG) UNSET_FLAG(FLAG, screen_buffer_status)

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
void output_line(char[]);
void output_line_flash(const __flash char *);
void scroll_line(void);
void screen_setup(void);

#endif
