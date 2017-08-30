#include "TreasureRoom.hpp"



TreasureRoom::TreasureRoom(Hero* player):Room(player)
{
	setCol(5);
	setRow(5);
	player->setXpos(1);
	player->setYpos(1);
}

void TreasureRoom::populateLevel()
{
	char **board = new char*[getRow()];
	for (int i = 0; i < getRow(); ++i)
	{
		board[i] = new char[getCol()];
	}
	for (int i = 0; i < getRow(); i++)
	{
		for (int j = 0; j < getCol(); j++)
		{
			board[i][j] = '.';
		}
	}

	for (int i = 0; i < getRow(); ++i)
	{
		board[i][0] = '#';
		board[i][4] = '#';
		board[0][i] = '#';
		board[4][i] = '#';
	}
	board[4][3] = '.';
	board[2][2] = 'G';
	setLevel(board);
}

void TreasureRoom::playerHealthDrain()
{
	Hero* temp = getHero();
	int health = temp->getHealth();
	int newHealth = health - 1;
	temp->setHealth(newHealth);
	setHero(temp);
}

void TreasureRoom::playerInteract()
{
	cout << "There is nothing to interact with!" << endl;
}

bool TreasureRoom::newRoom()
{
	Hero *temp = getHero();
	char **copyOriginal = getLevel();
	char **board = new char*[getRow()];
	for (int i = 0; i < getRow(); ++i)
	{
		board[i] = new char[getCol()];
	}
	for (int i = 0; i < getRow(); i++)
	{
		for (int j = 0; j < getCol(); j++)
		{
			board[i][j] = copyOriginal[i][j];
		}
	}
	string tempList = temp->getPack();
	int index;
	index = tempList.find('G');
	if ((temp->getYpos() == 4 && temp->getXpos() == 3))
	{
		for (int i = 0; i < getRow(); ++i)
		{
			delete[]board[i];
		}
		delete[]board;
		return true;
	}
	else
	{
		for (int i = 0; i < getRow(); ++i)
		{
			delete[]board[i];
		}
		delete[]board;
		return false;

	}
}


TreasureRoom::~TreasureRoom()
{
}
