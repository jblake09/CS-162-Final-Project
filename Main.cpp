#include"Character.hpp";
#include"Hero.hpp"
#include<iostream>


using std::cout;
using std::cin;
using std::endl;

void printBoard(char **inBoard, int inrow, int incol)
{

	for (int i = 0; i < inrow; i++)
	{
		for (int j = 0; j < incol; j++)
		{
			//placeAntOnBoard(*&inBoard, inAnt);
			cout << inBoard[i][j] << " | ";
		}
		cout << endl;
		cout << string(incol * 4, '-') << endl;
	}
	//placeAntOnBoard(*&Inboard, inAnt);
}


int main()
{
	
	int row = 5, col = 5;
	Hero test;
	char ** board = new char *[row];
	for (int i = 0; i < row; ++i)
	{
		board[i] = new char[col];
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			board[i][j] = '.';
		}
	}
	test.setDisplay('V');
	//cout << "Hey " << test.getDisplay() << endl;
	char mover = ' ';
	
	while (mover != 'v')
	{
		board[test.getYpos()][test.getXpos()] = test.getDisplay();
		printBoard(board, row, col);
		cout << "Make a move: " << endl;
		cin >> mover;
		board[test.getYpos()][test.getXpos()] = '.';
		test.move(mover);
		board[test.getYpos()][test.getXpos()] = test.getDisplay();
	}
	
	system("pause");
}