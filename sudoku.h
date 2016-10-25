#ifndef SUDOKU_H
#define SUDOKU_H

void load_board(const char* filename, char board[9][9]);
void display_board(const char board[9][9]);
bool is_complete(char [9][9]);
bool make_move(const char position[2], char digit, char board[9][9]);
bool save_board(const char filename[],char board[9][9]);
void recursive_solve(char board[9][9], int row, int column, int& count);
bool solve_board(char board [9][9]);

#endif
