#include"Character.hpp"
#include"Cave.hpp"
#include"SubmergedCave.hpp"
#include"TriviaRoom.hpp"
#include"DeathPit.hpp"
#include"LockRoom.hpp"
#include"TreasureRoom.hpp"
#include"Hero.hpp"
#include<iostream>
#include"Misc.hpp"

using std::cout;
using std::cin;
using std::endl;



int main()
{
	srand(time(0));
	int mainChoice;
	char action;
	bool program = true ,GameWin = false;
	while (program)
	{
		//Room *BeginCave = NULL;
		menu1(mainChoice);
		if (mainChoice == 1)
		{
			Hero *test = new Hero();
			Room *BeginCave = NULL, *fWaterCave = NULL, *trivia = NULL, *deathPit = NULL, *lR = NULL, *treasure = NULL;
			int level = 1;
			while (!(test->Dead()) && !GameWin)
			{
				if (level == 1)
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
						validCharInput(action);
						if (action == 'a' || action == 'd' || action == 's' || action == 'w')
						{
							BeginCave->MovePlayer(action);
						}
						else if (action == 't')
						{
							cout << "Which item would you like to use? (1,2,3) ";
							int itemChoice;
							validItemSelect(itemChoice);
							test->useFromPack(itemChoice);
						}
						else if (action == 'e')
						{
							BeginCave->playerInteract();
						}
						if (test->Dead() == true)
						{
							//BeginCave->~Room();
							//delete[] BeginCave;
							break;
						}
						if (BeginCave->newRoom() == true)
						{
							test = BeginCave->getHero();
							level = 2;
							//BeginCave->~Room();
							//delete[] BeginCave;
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
						BeginCave->setNorth(fWaterCave);
						fWaterCave->setSouth(BeginCave);
						timeThroughLevel++;
					}
					while (level == 2)
					{
						fWaterCave->printGame();
						cout << "Current Level: The submerged Cave of sorrows" << endl;
						cout << "Ph no we slipped into a submerged cave quick get through ig before we run out of health!" << endl;
						cout << "Controls a(Left), d(right), s(down), w(up), e(interact), t(use pack item): " << endl;
						validCharInput(action);
						if (action == 'a' || action == 'd' || action == 's' || action == 'w')
						{
							fWaterCave->MovePlayer(action);
						}
						else if (action == 't')
						{
							cout << "Which item would you like to use? (1,2,3) ";
							int itemChoice;
							validItemSelect(itemChoice);
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
						//cout << 1 << endl;
						trivia = new TriviaRoom(test);
						//cout << 2 << endl;
						trivia->createLevel();
						//cout << 3 << endl;
						trivia->populateLevel();
						//cout << 4 << endl;
						fWaterCave->setNorth(trivia);
						trivia->setSouth(fWaterCave);
						timeThroughLevel++;
					}
					while (level == 3)
					{
						trivia->printGame();
						cout << "Current Level: The Choice" << endl;
						cout << "It looks like there is a clue in the room!" << endl;
						cout << "Controls a(Left), d(right), s(down), w(up), e(interact), t(use pack item): " << endl;
						validCharInput(action);
						if (action == 'a' || action == 'd' || action == 's' || action == 'w')
						{
							trivia->MovePlayer(action);
						}
						else if (action == 't')
						{
							cout << "Which item would you like to use? (1,2,3) ";
							int itemChoice;
							validItemSelect(itemChoice);
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
								//trivia->~Room();
							}
							else if (trivia->newRommDir() == "Right")
							{
								test = trivia->getHero();
								level = 5;
								//trivia->~Room();
							}
						}
					}
				}
				else if (level == 4)
				{
					int timeThroughLevel = 1;
					if (timeThroughLevel == 1)
					{
						//cout << 1 << endl;
						deathPit = new DeathPit(test);
						//cout << 2 << endl;
						deathPit->createLevel();
						//cout << 3 << endl;
						deathPit->populateLevel();
						//cout << 4 << endl;
						trivia->setWest(deathPit);
						deathPit->setEast(trivia);
						timeThroughLevel++;
					}
					while (level == 4)
					{
						//cout << 5 << endl;
						deathPit->printGame();
						cout << "Current Level: Deathg Pit" << endl;
						cout << "You chose poorly!" << endl;
						cout << "Controls a(Left), d(right), s(down), w(up), e(interact), t(use pack item): " << endl;
						validCharInput(action);
						if (action == 'a' || action == 'd' || action == 's' || action == 'w')
						{
							deathPit->MovePlayer(action);
						}
						else if (action == 't')
						{
							cout << "Which item would you like to use? (1,2,3) ";
							int itemChoice;
							validItemSelect(itemChoice);
							test->useFromPack(itemChoice);
						}
						else if (action == 'e')
						{
							cout << "Theres nothing in here to interact with." << endl;
						}
						if (test->Dead() == true)
						{
							//deathPit->~Room();
							//cout << 1 << endl;
							break;
						}
					}

				}
				else if (level == 5)
				{
					int timeThroughLevel = 1;
					if (timeThroughLevel == 1)
					{
						//cout << 1 << endl;
						lR = new LockRoom(test);
						//cout << 2 << endl;
						lR->createLevel();
						//cout << 3 << endl;
						lR->populateLevel();
						//cout << 4 << endl;
						trivia->setEast(lR);
						lR->setWest(trivia);
						timeThroughLevel++;
					}
					while (level == 5)
					{
						lR->printGame();
						cout << "Current Level: Lock Room" << endl;
						cout << "It looks we need a key 'k' to in the O to open the next chamber!" << endl;
						cout << "It looks like the key only fits in one way!" << endl;
						cout << "Controls a(Left), d(right), s(down), w(up), e(interact), t(use pack item): " << endl;
						validCharInput(action);
						if (action == 'a' || action == 'd' || action == 's' || action == 'w')
						{
							lR->MovePlayer(action);
						}
						else if (action == 't')
						{
							cout << "Which item would you like to use? (1,2,3) ";
							int itemChoice;
							validItemSelect(itemChoice);
							test->useFromPack(itemChoice);
						}
						else if (action == 'e')
						{
							lR->playerInteract();
						}
						if (test->Dead() == true)
						{
							break;
						}
						if (lR->newRoom() == true)
						{
							test = lR->getHero();
							level = 6;
							//lR->~Room();
						}
					}
				}
				else if (level == 6)
				{
					int timeThroughLevel = 1;
					if (timeThroughLevel == 1)
					{
						//cout << 1 << endl;
						treasure = new TreasureRoom(test);
						//cout << 2 << endl;
						treasure->createLevel();
						//cout << 3 << endl;
						treasure->populateLevel();
						//cout << 4 << endl;
						treasure->setNorth(lR);
						trivia->setSouth(fWaterCave);
						timeThroughLevel++;
					}
					while (level == 6)
					{
						treasure->printGame();
						cout << "Current Level: Treasure Room" << endl;
						cout << "Quick grab the GOLD (G)!!!" << endl;
						cout << "Controls a(Left), d(right), s(down), w(up), e(interact), t(use pack item): " << endl;
						validCharInput(action);
						if (action == 'a' || action == 'd' || action == 's' || action == 'w')
						{
							treasure->MovePlayer(action);
						}
						else if (action == 't')
						{
							cout << "Which item would you like to use? (1,2,3) ";
							int itemChoice;
							validItemSelect(itemChoice);
							test->useFromPack(itemChoice);
						}
						else if (action == 'e')
						{
							treasure->playerInteract();
						}
						if (test->Dead() == true)
						{
							break;
						}
						if (treasure->newRoom() == true)
						{
							//test = lR->getHero();
							//treasure->~Room();
							string tempList = test->getPack();
							int index;
							index = tempList.find('G');
							if (index == string::npos)
							{
								cout << "You forgot the GOLD!!! You lose and your poor!" << endl;
								test->setHealth(0);
							}
							else
							{
								GameWin = true;
							}
							//treasure->~Room();
							level = 7;

						}

					}

				}
			}

			cout << "Game OVER" << endl;
			if (GameWin)
			{
				cout << " You won!!!!!" << endl;
			}
			else
				cout << "You lost!" << endl;
			
			//BeginCave->~Room();
			//delete BeginCave;
			
			//delete fWaterCave;
			//delete trivia;
			//delete deathPit;
			//delete lR;
			//delete treasure;
			//delete test;
			
		}
		else
			program = false;
			
	}
		
	//system("pause");
	return 0;
}