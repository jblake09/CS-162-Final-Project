#include "Cave.hpp"



Cave::Cave(Hero *player):Room(player)
{
	setCol(10);
	setRow(10);
	player->setXpos(5);
	player->setYpos(9);
}

void Cave::populateLevel()
{
	char **board = new char*[getRow()];
	for(int i = 0; i < getRow(); ++i)
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
	int count = 5;
	while (count > 0)
	{
		int x = randomNum(8, 1);
		int y = randomNum(8, 1);
		board[y][x] = 'H';
		count--;
	}
	
	for (int i = 0; i < getCol(); ++i)
	{
		board[i][0] = '#';
	}
	
	for (int i = 1; i < getRow(); ++i)
	{
		board[0][i] = '#';
	}
	
	for (int i = 1; i < getCol(); ++i)
	{
		board[i][9] = '#';
	}
	
	for (int i = 1; i < getRow() - 1; ++i)
	{
		board[9][i] = '#';
	}
	
	int leverX = randomNum(8, 1), leverY = randomNum(8, 1);
	board[leverX][leverY] = '/';
	setLevel(board);
}

void Cave::playerHealthDrain()
{
	Hero* temp = getHero();
	int health = temp->getHealth();
	int newHealth = health - 1;
	temp->setHealth(newHealth);
	setHero(temp);
}


Cave::~Cave()
{
}
