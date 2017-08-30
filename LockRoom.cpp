#include "LockRoom.hpp"



LockRoom::LockRoom(Hero* player):Room(player)
{
	setCol(10);
	setRow(10);
	player->setXpos(1);
	player->setYpos(1);
}

void LockRoom::populateLevel()
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
	int count = 8;
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

	int keyHoleX = randomNum(8, 1), KeyHoleY = randomNum(8, 1);
	board[4][4] = 'K';
	board[8][8] = 'O';
	
	setLevel(board);
}

void LockRoom::playerHealthDrain()
{
	Hero* temp = getHero();
	int health = temp->getHealth();
	int newHealth = health - 1;
	temp->setHealth(newHealth);
	setHero(temp);
}

void LockRoom::playerInteract()
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
	/*
	for (int i = 0; i < getRow(); i++)
	{
	for (int j = 0; j < getCol(); j++)
	{

	cout << board[i][j];
	}
	cout << endl;
	}
	*/
	if (board[temp->getYpos()][temp->getXpos() + 1] == 'O' || board[temp->getYpos()][temp->getXpos() - 1] == 'O' )
	{
		string tempList = temp->getPack();
		int index;
		index = tempList.find('K');
		if (index == string::npos)
		{
			cout << "You dont have the key!" << endl;
		}
		else
		{
			cout << "Holy cow this key is made of gold beter hold onto this!" << endl;
			board[8][1] = '.';
			setLevel(board);
		}
	}
	
	else if (board[temp->getYpos() + 1][temp->getXpos()] == 'O' || board[temp->getYpos()][temp->getXpos()-1] == 'O')
	{
		string tempList = temp->getPack();
		int index;
		index = tempList.find('K');
		if (index == string::npos)
		{
			cout << "You dont have the key!" << endl;
		}
		else
		{
			cout << "Holy cow this key is made of gold beter hold onto this!" << endl;
			board[9][1] = '.';
			setLevel(board);
		}
		
	}
	
	else
	{
		cout << "There is nothing to interact with!" << endl;
		
		for (int i = 0; i < getRow(); i++)
		{
			delete[]board[i];
		}

		delete[]board;
	
	}
}

bool LockRoom::newRoom()
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
	if (temp->getYpos() == 9 && temp->getXpos() == 1)
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


LockRoom::~LockRoom()
{
}
