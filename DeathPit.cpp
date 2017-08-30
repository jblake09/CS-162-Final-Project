#include "DeathPit.hpp"



DeathPit::DeathPit(Hero* player):Room(player)
{
	setCol(5);
	setRow(5);
	player->setXpos(2);
	player->setYpos(2);
}

void DeathPit::populateLevel()
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
	setLevel(board);
}

void DeathPit::playerHealthDrain()
{
	Hero* temp = getHero();
	int health = temp->getHealth();
	int newHealth = health - 20;
	temp->setHealth(newHealth);
	setHero(temp);
}


DeathPit::~DeathPit()
{
}
