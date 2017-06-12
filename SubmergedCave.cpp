#include "SubmergedCave.hpp"



SubmergedCave::SubmergedCave(Hero *player):Room(player)
{
	setCol(5);
	setRow(20);
	player->setXpos(2);
	player->setYpos(18);
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
	}
	
	
	board[17][1] = '#';
	board[17][3] = '#';
	
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


SubmergedCave::~SubmergedCave()
{
}
