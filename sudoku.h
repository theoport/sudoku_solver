#ifndef SUDOKU_H
#define SUDOKU_H

void load_board(const char* filename, char board[9][9]);
void display_board(const char board[9][9]);
bool is_complete(char board[9][9]);
//Pre-Condition: "board" contains only digits or full stops.
//Post-Condition: Returns true if "board" only contains digits, returns false otherwise
 
bool make_move(const char position[2], char digit, char board[9][9]);
//Pre-Condition: "board" contains only digits or full stops, position describes a legal position
//on the sudoku board, digit is a number between 1 and 9.
//Post-Condition: Places "digit" into "position" and returns true if doing so is a legal move.
//Returns false if otherwise and leaves "position" on the "board" unchanged.

bool save_board(const char filename[],char board[9][9]);
//Pre-Condition: "board" only contains digits or numbers, "filename" is an empty file.
//Post-Condition: Returns true if "board" was succesfully copied to "filename". Returns false 
//if otherwise

void recursive_solve(char board[9][9], int row, int column, int& count);
//Pre-Condition: "board" only contains digits or full stops. 
//Post-Condition: Attempts to solve "board" recursively, and alters "board" to its solved version
//when having succefully solved it. "count" counts the number of calls to "recursive_solve" before
//solving it. 

bool solve_board(char board [9][9]);
//Pre-Condition: "board" only contains digits or full stops.
//Post-Condition: returns true if board is solveable and outputs the solved board together with
//the number of calls to "recursive_solve".

#endif
