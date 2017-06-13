#include "SubmergedCave.hpp"



SubmergedCave::SubmergedCave(Hero *player):Room(player)
{
	setCol(3);
	setRow(10);
	player->setXpos(1);
	player->setYpos(8);
}

void SubmergedCave::populateLevel()
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
			board[i][j] = '~';
		}
	}

	for (int i = 0; i < getRow(); ++i)
	{
		board[i][0] = '#';
		board[i][2] = '#';
	}
	board[9][1] = '#';
	/*
	for (int i = 1; i < getRow() - 1; ++i)
	{
		board[i][2] = '#';
	}

	for (int i = 1; i < getCol(); ++i)
	{
		board[i][9] = '#';
	}
	*/
	setLevel(board);
	
}

void SubmergedCave::playerHealthDrain()
{
	Hero* temp = getHero();
	int health = temp->getHealth();
	int newHealth = health - 3;
	temp->setHealth(newHealth);
	setHero(temp);
}

void SubmergedCave::playerInteract()
{
	cout << "Theres nothing to interact with here" << endl;
}

bool SubmergedCave::newRoom()
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

	if (temp->getYpos() == 0 && temp->getXpos() == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}


SubmergedCave::~SubmergedCave()
{
}
