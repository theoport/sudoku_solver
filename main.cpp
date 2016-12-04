#include <iostream>
#include <cstdio>
#include "sudoku.h"

using namespace std;

int main() {

  char board[9][9];

  /* This section illustrates the use of the pre-supplied helper functions. */
  cout << "============== Pre-supplied functions ==================" << endl << endl;

  cout << "Calling load_board():" << endl;
  load_board("easy.dat", board);

  cout << endl << "Displaying Sudoku board with display_board():" << endl;
  display_board(board);
  cout << "Done!" << endl << endl;

  cout << "====================== Question 1 ======================" << endl << endl;

  load_board("easy.dat", board);
  cout << "Board is ";
  if (!is_complete(board))
    cout << "NOT ";
  cout << "complete." << endl << endl;

  load_board("easy-solution.dat", board);
  cout << "Board is ";
  if (!is_complete(board))
    cout << "NOT ";
  cout << "complete." << endl << endl;

  cout << "====================== Question 2 ======================" << endl << endl;

  load_board("easy.dat", board);

  //Should be OK
  cout << "Putting '1' into I8 is ";
  if (!make_move("I8", '1', board)) 
    cout << "NOT ";
  cout << "a valid move. The board is:" << endl;
  display_board(board);

	//Shouldn't be ok due to matching number in row
  cout << "Putting '2' into B4 is ";
  if (!make_move("B4", '2', board)) 
    cout << "NOT ";
  cout << "a valid move. The board is:" << endl;
  display_board(board);
  
	//Shouldn't be ok based on matching number in column
	cout << "Putting '2' into D1 is ";
  if (!make_move("D1", '2', board)) 
    cout << "NOT ";
  cout << "a valid move. The board is:" << endl;
  display_board(board);
  
	//Shouldn't be ok due to matching number in sub-square
	cout << "Putting '6' into F3 is ";
  if (!make_move("F3", '6', board)) 
    cout << "NOT ";
  cout << "a valid move. The board is:" << endl;
  display_board(board);
  
	//Shouldn't be ok due to out of range position
	cout << "Putting '2' into K2 is ";
  if (!make_move("K2", '2', board)) 
    cout << "NOT ";
  cout << "a valid move. The board is:" << endl;
  display_board(board);
  
	//Shouldn't be ok due to a number occupying that position
	cout << "Putting '1' into B2 is ";
  if (!make_move("B2", '1', board)) 
    cout << "NOT ";
  cout << "a valid move. The board is:" << endl;
  display_board(board);
	// write more tests

  cout << "====================== Question 3 ======================" << endl << endl;

  load_board("easy.dat", board);
  if (save_board("easy-copy.dat", board))
    cout << "Save board to 'easy-copy.dat' successful." << endl;
  else
    cout << "Save board failed." << endl;
  cout << endl;

  cout << "====================== Question 4 ======================" << endl << endl;

  load_board("easy.dat", board);
  if(solve_board(board)){
    cout << "the 'easy' board has a solution:" << endl;
    display_board(board);
 		}
	 else 
		 cout << "A solution cannot be found." << endl;	
		 cout << endl;

  load_board("medium.dat", board);
  if (solve_board(board)) {
    cout << "the 'medium' board has a solution:" << endl;
    display_board(board);
  } else 
    cout << "A solution cannot be found." << endl;
  cout << endl;

  load_board("mystery1.dat", board);
  if (solve_board(board)) {
    cout << "the 'mystery1' board has a solution:" << endl;
    display_board(board);
  } else 
    cout << "A solution cannot be found." << endl;
  cout << endl;
	
  load_board("mystery2.dat", board);
  if (solve_board(board)) {
    cout << "the 'mystery2' board has a solution:" << endl;
    display_board(board);
  } else 
    cout << "A solution cannot be found." << endl;
  cout << endl;

  load_board("mystery3.dat", board);
  if (solve_board(board)) {
    cout << "the 'mystery3' board has a solution:" << endl;
    display_board(board);
  } else 
    cout << "A solution cannot be found." << endl;
  cout << endl;
	
  load_board("temp.txt", board);
  if (solve_board(board)) {
    cout << "the 'temp' board has a solution:" << endl;
    display_board(board);
  } else 
    cout << "A solution cannot be found." << endl;
  cout << endl;


  cout << "====================== Question 5 ======================" << endl << endl;

	/*Tests for question 5 are included in question 4 by
	outputting the count of the number of function calls
	to the console in the solve_board function*/


  return 0;
}

