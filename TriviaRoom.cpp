#include "TriviaRoom.hpp"



TriviaRoom::TriviaRoom(Hero *player):Room(player)
{
	setCol(5);
	setRow(5);
	player->setXpos(2);
	player->setYpos(3);
}

void TriviaRoom::populateLevel()
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
	board[2][2] = '?';
	board[2][1] = '/';
	board[2][3] = '\\';
	board[3][1] = 'H';
	board[3][3] = 'H';
	setLevel(board);
}

void TriviaRoom::playerHealthDrain()
{
	Hero* temp = getHero();
	int health = temp->getHealth();
	int newHealth = health - 1;
	temp->setHealth(newHealth);
	setHero(temp);
}

void TriviaRoom::playerInteract()
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

	if (board[temp->getYpos()][temp->getXpos() + 1] == '/' || board[temp->getYpos()][temp->getXpos() - 1] == '/'||
		board[temp->getYpos() + 1][temp->getXpos()] == '/' || board[temp->getYpos() - 1][temp->getXpos()] == '/')
	{

		board[3][0] = '.';
		setLevel(board);
	}
	else if (board[temp->getYpos() + 1][temp->getXpos()] == '\\' || board[temp->getYpos() - 1][temp->getXpos()] == '\\'||
			 board[temp->getYpos() + 1][temp->getXpos()] == '\\' || board[temp->getYpos() - 1][temp->getXpos()] == '\\')
	{
		board[3][4] = '.';
		setLevel(board);
	}
	else if (board[temp->getYpos() + 1][temp->getXpos()] == '?' || board[temp->getYpos() - 1][temp->getXpos()] == '?' ||
		board[temp->getYpos() + 1][temp->getXpos()] == '?' || board[temp->getYpos() - 1][temp->getXpos()] == '?')
	{
		cout << "Which way to go?" << endl;
		cout << "Left is right" << endl;
		cout << "Right is wrong" << endl;
		cout << "Right is right" << endl;
		cout << "Left is left" << endl;
	}
	else
	{
		cout << "There is nothing to interact with!" << endl;
	}
	/*
	for (int i = 0; i < getRow(); i++)
	{
		delete[]board[i];
	}

	delete[]board;
	*/
}

bool TriviaRoom::newRoom()
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
	if ((temp->getYpos() == 3 && temp->getXpos() == 0) || (temp->getYpos() == 3 && temp->getXpos() == 4))
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

string TriviaRoom::newRommDir()
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
	if (temp->getYpos() == 3 && temp->getXpos() == 0)
	{
		for (int i = 0; i < getRow(); ++i)
		{
			delete[]board[i];
		}
		delete[]board;
		return "Left";
	}
	else if (temp->getYpos() == 3 && temp->getXpos() == 4)
	{
		for (int i = 0; i < getRow(); ++i)
		{
			delete[]board[i];
		}
		delete[]board;
		return "Right";
	}
	
}



TriviaRoom::~TriviaRoom()
{
}
