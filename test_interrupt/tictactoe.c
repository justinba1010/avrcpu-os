#include <avr/interrupt.h>
#include <avr/io.h>
#include <string.h>

#include <keyboard_driver.h>
#include <lights_driver.h>
#include <screen_buffer_driver.h>

static const __flash char __which_move[] = "Would you like to play X or O?";
static const __flash char __invalid_move[] = "Invalid selection...";
static const __flash char __make_move[] =
    "Enter the number for selection of play. ie. 5 for center";
static const __flash char __winner_player[] = "Congrats. You win.";
static const __flash char __winner_computer[] = ":(. Computer wins.";
static const __flash char __winner_tie[] = "It's a draw.";

enum Move { EMPTY, X, O };

enum Move winner(enum Move board[3][3]);
bool game_over(enum Move board[3][3]);
void clear_board(enum Move board[3][3]);

void tictactoe(void) {
  char buffer[80] = "\0";
  enum Move board[3][3];
  enum Move player;
  enum Move current_move = X;
  clear_board(board);

  while (true) {
    output_line_flash(__which_move);
    scroll_line();
    keyboard_wait_for_line(buffer, 80);

    if (strcmp(buffer, "O") || strcmp(buffer, "o")) {
      player = O;
      break;
    } else if (strcmp(buffer, "X") || strcmp(buffer, "x")) {
      player = X;
      break;
    }
  }

  while (!game_over(board) && winner(board) == EMPTY) {
    uint8_t i, j;
    if (current_move == player) {
      do {
        output_line_flash(__make_move);
        scroll_line();
        keyboard_wait_for_line(buffer, 80);
        i = buffer[0] - '0';
        j = i % 3;
        i /= 3;
      } while (i >= 0 && i < 3 && j >= 0 && j < 3 && board[i][j] != EMPTY);
      board[i][j] = player;
    } else {
      do {
        i = random(9);
        j = i % 3;
        i /= 3;
      } while (board[i][j] != EMPTY);
      board[i][j] = player == X ? O : X;
    }
    current_move = current_move == X ? O : X;
  }

  enum Move game_winner = winner(board);
  if (game_winner == player) {
    output_line_flash(__winner_player);
  } else if (game_winner == EMPTY) {
    output_line_flash(__winner_computer);
  } else {
    output_line_flash(__winner_tie);
  }
  scroll_line();
  return;
}

void clear_board(enum Move board[3][3]) {
  for (uint8_t i = 0; i < 3; ++i) {
    for (uint8_t j = 0; j < 3; ++j) {
      board[i][j] = EMPTY;
    }
  }
}

void print_board(enum Move board[3][3]) {
  char buffer[6] = "\0|\0|\0\0";
  for (uint8_t i = 0; i < 3; ++i) {
    for (uint8_t j = 0; j < 3; ++j) {
      buffer[j * 2] = (i * 3 + j) + '0';
      if (board[i][j] != EMPTY) {
        buffer[j * 2] = board[i][j] == X ? 'X' : 'O';
      }
    }
    output_line(buffer);
    scroll_line();
  }
}

enum Move winner(enum Move board[3][3]) {
  for (uint8_t i = 0; i < 3; ++i) {
    if (board[i][0] != EMPTY && board[i][0] == board[i][1] &&
        board[i][1] == board[i][2]) {
      return board[i][0];
    }
    if (board[0][i] != EMPTY && board[0][i] == board[1][i] &&
        board[1][i] == board[2][i]) {
      return board[0][i];
    }
  }
  if (board[1][1] != EMPTY) {
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
      return board[1][1];
    }
  }
  return EMPTY;
}

bool game_over(enum Move board[3][3]) {
  for (uint8_t i = 0; i < 3; ++i) {
    for (uint8_t j = 0; j < 3; ++j) {
      if (board[i][j] == EMPTY) {
        return true;
      }
    }
  }
  return false;
}
