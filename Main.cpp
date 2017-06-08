#include"Character.hpp";
#include"Cave.hpp"
#include"Hero.hpp"
#include<iostream>
#include"Misc.hpp"

using std::cout;
using std::cin;
using std::endl;



int main()
{
	srand(time(0));
	int row = 5, col = 5;
	Hero *test = new Hero();
	Room *testCave = new Cave(test);
	testCave->createLevel();
	testCave->populateLevel();
	testCave->printLevel();
	testCave->MovePlayer();
	/*
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
	*/
	system("pause");
}