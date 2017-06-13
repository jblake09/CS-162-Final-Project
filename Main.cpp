#include"Character.hpp"
#include"Cave.hpp"
#include"SubmergedCave.hpp"
#include"TriviaRoom.hpp"
#include"Hero.hpp"
#include<iostream>
#include"Misc.hpp"

using std::cout;
using std::cin;
using std::endl;



int main()
{
	srand(time(0));
	int row = 5, col = 5, level = 2;
	char action;
	bool program = true;
	Hero *test = new Hero();
	Room *BeginCave = NULL, *fWaterCave = NULL, *trivia = NULL;
	//trivia = new TriviaRoom(test);
	//BeginCave->setNorth(fWaterCave);
	//Room *testCave = new Cave(test);
	//Room *testSubmerge = new SubmergedCave(test);
	//trivia->createLevel();
	//trivia->populateLevel();
	//testSubmerge->createLevel();
	//testSubmerge->populateLevel();
	//testCave->setNorth(testSubmerge);
	//Room *currentRoom = new Cave(test);
	//currentRoom->createLevel();
	//currentRoom->populateLevel();
	//trivia->printLevel();
	//currentRoom->printGame();
	
	while (!(test->Dead()))
	{
		if(level == 1)
		{
			int timeThoughLevel = 1;
			if (timeThoughLevel == 1)
			{
				BeginCave = new Cave(test);
				BeginCave->createLevel();
				BeginCave->populateLevel();
				timeThoughLevel++;
			}
			while (level == 1)
			{
				BeginCave->printGame();
				cout << "Current Level is the Entry Cave" << endl;
				cout << "Pick up (H) health potions" << endl;
				cout << "Oh look a lever what happens if i pull it?" << endl;
				cout << "Controls a(Left), d(right), s(down), w(up), e(interact), t(use pack item): " << endl;
				cin >> action;
				if (action == 'a' || action == 'd' || action == 's' || action == 'w')
				{
					BeginCave->MovePlayer(action);
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
					BeginCave->playerInteract();
				}
				if (test->Dead() == true)
				{
					break;
				}
				if (BeginCave->newRoom() == true)
				{
					test = BeginCave->getHero();
					level = 2;
					BeginCave->~Room();
					//delete[]BeginCave;
				}
			}
		}
		else if (level == 2)
		{
			int timeThroughLevel = 1;
			if (timeThroughLevel == 1)
			{
				fWaterCave = new SubmergedCave(test);
				fWaterCave->createLevel();
				fWaterCave->populateLevel();
				//BeginCave->setNorth(fWaterCave);
				//fWaterCave->setSouth(BeginCave);
				timeThroughLevel++;
			}
			while (level == 2)
			{
				fWaterCave->printGame();
				cout << "Current Level: The submerged Cave of sorrows" << endl;
				cout << "Ph no we slipped into a submerged cave quick get through ig before we run out of health!" << endl;
				cout << "Controls a(Left), d(right), s(down), w(up), e(interact), t(use pack item): " << endl;
				cin >> action;
				if (action == 'a' || action == 'd' || action == 's' || action == 'w')
				{
					fWaterCave->MovePlayer(action);
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
					fWaterCave->playerInteract();
				}
				if (test->Dead() == true)
				{
					break;
				}
				if (fWaterCave->newRoom() == true)
				{
				
					test = fWaterCave->getHero();
					level = 3;
					fWaterCave->~Room();
					//delete[]fWaterCave;
				}
			}
		}
		else if (level == 3)
		{
			int timeThroughLevel = 1;
			if (timeThroughLevel == 1)
			{
				cout << 1 << endl;
				trivia = new TriviaRoom(test);
				cout << 2 << endl;
				trivia->createLevel();
				cout << 3 << endl;
				trivia->populateLevel();
				cout << 4 << endl;
				//fWaterCave->setNorth(trivia);
				//trivia->setSouth(fWaterCave);
				timeThroughLevel++;
			}
			while (level == 3)
			{
				cout << 5 << endl;
				trivia->printGame();
				cout << "Current Level: The Choice" << endl;
				cout << "It looks like there is a clue in the room!" << endl;
				cout << "Controls a(Left), d(right), s(down), w(up), e(interact), t(use pack item): " << endl;
				cin >> action;
				if (action == 'a' || action == 'd' || action == 's' || action == 'w')
				{
					trivia->MovePlayer(action);
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
					trivia->playerInteract();
				}
				if (test->Dead() == true)
				{
					break;
				}
				if (trivia->newRoom() == true)
				{
					if (trivia->newRommDir() == "Left")
					{
						test = trivia->getHero();
						level = 4;
					}
					else if (trivia->newRommDir() == "Right")
					{
						test = trivia->getHero();
						level = 5;
					}
				}
			}

		}

	}
		//testCave->MovePlayer();
		//testCave->printGame();
		//testSubmerge->printGame();
		//currentRoom->printGame();
		
		/**
		cout << "Controls a(Left), d(right), s(down), w(up), e(interact), t(use pack item): " << endl;
		cin >> action;
		if (action == 'a' || action == 'd' || action == 's' || action == 'w')
		{
			//currentRoom->MovePlayer(action);
			//testSubmerge->MovePlayer(action);
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
			//currentRoom->playerInteract();
			//testSubmerge->playerInteract();
			//testCave->playerInteract();
		}
		//currentRoom = currentRoom->getNorth();
		cout << "next Level = " << currentRoom->newRoom();
	}
	*/
		/*
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
	*/
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