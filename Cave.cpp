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
		int x = randomNum(9, 0);
		int y = randomNum(9, 0);
		board[x][y] = 'H';
		count--;
	}
	
	setLevel(board);
}


Cave::~Cave()
{
}
