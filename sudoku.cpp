#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cassert>
#include "sudoku.h"

using namespace std;

/* You are pre-supplied with the functions below. Add your own 
   function definitions to the end of this file. */

/* pre-supplied function to load a Sudoku board from a file */
void load_board(const char* filename, char board[9][9]) {

  cout << "Loading Sudoku board from file '" << filename << "'... ";

  ifstream in(filename);
  if (!in)
    cout << "Failed!" << endl;
  assert(in);

  char buffer[512];

  int row = 0;
  in.getline(buffer,512);
  while (in && row < 9) {
    for (int n=0; n<9; n++) {
      assert(buffer[n] == '.' || isdigit(buffer[n]));
      board[row][n] = buffer[n];
    }
    row++;
    in.getline(buffer,512);
  }

  cout << ((row == 9) ? "Success!" : "Failed!") << endl;
  assert(row == 9);
}

/* internal helper function */
void print_frame(int row) {
  if (!(row % 3))
    cout << "  +===========+===========+===========+" << endl;
  else
    cout << "  +---+---+---+---+---+---+---+---+---+" << endl;
}

/* internal helper function */
void print_row(const char* data, int row) {
  cout << (char) ('A' + row) << " ";
  for (int i=0; i<9; i++) {
    cout << ( (i % 3) ? ':' : '|' ) << " ";
    cout << ( (data[i]=='.') ? ' ' : data[i]) << " ";
  }
  cout << "|" << endl;
}

/* pre-supplied function to display a Sudoku board */
void display_board(const char board[9][9]) {
  cout << "    ";
  for (int r=0; r<9; r++) 
    cout << (char) ('1'+r) << "   ";
  cout << endl;
  for (int r=0; r<9; r++) {
    print_frame(r);
    print_row(board[r],r);
  }
  print_frame(9);
}

/* add your functions here */

/*function to check whether board is complete*/
bool is_complete(char board[9][9]){
	for (int n=0;n<9;n++){
		for (int m=0;m<9;m++){
			if (board[n][m]=='.')
				return false;
		}
	}
	return true;
}

bool make_move(const char position[2], char digit, char board[9][9]){
	int row_index=position[0]-65;
	int column_index=position[1]-49;
	int sub_square_column_index=3*(column_index/3);	
	int sub_square_row_index=3*(row_index/3);
	if (row_index>8||row_index<0)
		return false;
	if (column_index>8||column_index<0)
		return false;
	if (board[row_index][column_index]!='.')
		return false;
	for(int n=0;n<9;n++){
		if(board[row_index][n]==digit||board[n][column_index]==digit)	
			return false;
	}
	for (int n=0; n<3;n++){
		for(int m=0; m<3;m++){
			if(board[sub_square_row_index+n][sub_square_column_index+m]==digit)
				return false;
		}
	}
	board[row_index][column_index]=digit;	
	return true;
}

bool save_board(const char filename[], char board[9][9]){
	ofstream out(filename);
	if (!out){
		cout<<"Failed.";
		return false;
	}
	assert(out);
	int row=0;
	while(out&&row<9){
		for (int n=0;n<9;n++){
			assert(board[row][n]=='.'||isdigit(board[row][n]));  
			out.put(board[row][n]);
		}
		out.put('\n');
		row++;
	}
	out.close();
}
	
bool solve_board(char board [9][9]){
	int n=0;
	int m=0;
	int count=0;
	recursive_solve(board,n,m,count);
	if(is_complete(board)){
		cout<<count<<" attempts to make a move.\n";
		return true;
	}
	else 
		return false;
	
} 
		
void recursive_solve(char board[9][9], int row, int column, int& count){
	if(column>8){
		row++;
		column=0;
	}
	count++;
	char position[2];
	position[0]=row+65;
	position[1]=column+49;
	if (isdigit(board[row][column])){
		recursive_solve(board, row, column+1,count);
		return;		
	}
	for(int n='1';n<='9';n++){
		if(make_move(position,n,board)){
			recursive_solve(board,row,column+1,count);
			if(!(is_complete(board)))
				board[row][column]='.';
		}
	}
	return;
}

