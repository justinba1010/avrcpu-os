#include <avr/interrupt.h>
#include <avr/io.h>
#include <string.h>

#include <keyboard_driver.h>
#include <lights_driver.h>
#include <screen_buffer_driver.h>

static const __flash char __which_move[] = "Would you like to play X or O?";
static const __flash char __invalid_move[] = "Invalid selection...";

enum Move { EMPTY, X, O };

void tictactoe(void) {
  char buffer[80] = "\0";
  enum Move board[3][3];
  clear_board(board);

  while (true) {
    output_line_flash(__which_move);
    keyboard_wait_for_line(buffer, 80);

    if (strcmp(buffer, "O") || strcmp(buffer, "o")) {
    } else if (strcmp(buffer, "X") || strcmp(buffer, "x")) {
    }
  }
}

void clear_board(enum Move board[3][3]) {
  for (uint8_t i = 0; i < 3; ++i) {
    for (uint8_t j = 0; j < 3; ++j) {
      board[i][j] = EMPTY;
    }
  }
}
