#include"Character.hpp"
#include"Cave.hpp"
#include"SubmergedCave.hpp"
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
	char action;
	bool program = true;
	Hero *test = new Hero();
	//Room *testCave = new Cave(test);
	Room *testSubmerge = new SubmergedCave(test);
	//testCave->createLevel();
	//testCave->populateLevel();
	testSubmerge->createLevel();
	testSubmerge->populateLevel();
	//testCave->printLevel();
	while (!(test->Dead()))
	{
		//testCave->MovePlayer();
		//testCave->printGame();
		testSubmerge->printGame();
		cout << "Controls a(Left), d(right), s(down), w(up), e(interact), t(use pack item): " << endl;
		cin >> action;
		if (action == 'a' || action == 'd' || action == 's' || action == 'w')
		{
			testSubmerge->MovePlayer(action);
			//testCave->MovePlayer(action);
		}
		else if (action == 't')
		{
			cout << "Which item would you like to use? (1,2,3) ";
			int itemChoice;
			cin >> itemChoice;
			test->useFromPack(itemChoice);
		}
		else if (action == 'e')
		{
			testSubmerge->playerInteract();
			//testCave->playerInteract();
		}

	}
	
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