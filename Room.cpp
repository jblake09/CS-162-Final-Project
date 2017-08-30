#include "Room.hpp"



Room::Room(Hero* inplayer)
{
	East = NULL;
	South = NULL;
	West = NULL;
	North = NULL;
	player = inplayer;
	col = 0;
	row = 0;
}


void Room::setRow(int r)
{
	row = r;
}

void Room::setCol(int c)
{
	col = c;
}

void Room::setEast(Room *e)
{
	East = e;
}

void Room::setWest(Room *w)
{
	West = w;
}

void Room::setNorth(Room *n)
{
	North = n;
}

void Room::setSouth(Room *s)
{
	South = s;
}

void Room::setHero(Hero *in)
{
	player = in;
}

void Room::MovePlayer(char mover)
{
	//player->printPack();
	//level[player->getYpos()][player->getXpos()] = player->getDisplay();
	//printLevel();
	//player->printHealth();
	//player->printPack();
	//cout << "Make a move: " << endl;
	//char mover = ' ';
	//cin >> mover;
	int prevX = player->getXpos(), prevY = player->getYpos();
	player->move(mover);
	int nextX = player->getXpos(), nextY = player->getYpos();
	if (level[nextY][nextX] == '.' || level[nextY][nextX] == '~')
	{
		level[player->getYpos()][player->getXpos()] = player->getDisplay();
		level[prevY][prevX] = '.';
	}
	else if (level[nextY][nextX] == 'H')
	{
		if ((player->getPack()).size() < 5)
		{
			level[player->getYpos()][player->getXpos()] = player->getDisplay();
			level[prevY][prevX] = '.';
			player->add2Pack('H');
		}
		else
		{
			cout << "Your pack is full!" << endl;
			player->setXpos(prevX);
			player->setYpos(prevY);
			level[player->getYpos()][player->getXpos()] = player->getDisplay();
		}
	}
	else if (level[nextY][nextX] == 'K')
	{
		if ((player->getPack()).size() < 5)
		{
			level[player->getYpos()][player->getXpos()] = player->getDisplay();
			level[prevY][prevX] = '.';
			player->add2Pack('K');
		}
		else
		{
			cout << "Your pack is full!" << endl;
			player->setXpos(prevX);
			player->setYpos(prevY);
			level[player->getYpos()][player->getXpos()] = player->getDisplay();
		}
	}
	else if (level[nextY][nextX] == 'G')
	{
		if ((player->getPack()).size() < 5)
		{
			level[player->getYpos()][player->getXpos()] = player->getDisplay();
			level[prevY][prevX] = '.';
			player->add2Pack('G');
		}
		else
		{
			cout << "Your pack is full!" << endl;
			player->setXpos(prevX);
			player->setYpos(prevY);
			level[player->getYpos()][player->getXpos()] = player->getDisplay();
		}
	}
	else if (level[nextY][nextX] != '.')
	{
		//cout << "hey" << endl;
		player->setXpos(prevX);
		player->setYpos(prevY);
		level[player->getYpos()][player->getXpos()] = player->getDisplay();
		//return;
		//level[prevY][prevX] = '.';
	}
	playerHealthDrain();
	/*
	{
		while (mover != 'v')
		{

			//level[player->getYpos()][player->getXpos()] = player->getDisplay();
			//printLevel();
			//cout << "Make a move: " << endl;
			//cin >> mover;
			level[player->getYpos()][player->getXpos()] = '.';
			player->move(mover);
			level[player->getYpos()][player->getXpos()] = player->getDisplay();
			//printLevel();
		}
	}
	*/
}

Hero * Room::getHero()
{
	return player;
}


Room * Room::getEast()
{
	return East;
}

Room * Room::getWest()
{
	return West;
}

Room * Room::getNorth()
{
	return North;
}

Room * Room::getSouth()
{
	return South;
}

char ** Room::getLevel()
{
	return level;
}

int Room::getRow()
{
	return row;
}

int Room::getCol()
{
	return col;
}

void Room::setLevel(char **in)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			level[i][j] = in[i][j];
		}
	}
	
	for (int i = 0; i < row; i++)
	{
		delete[]in[i];
	}
	
	delete in;
	
	//delete in
}


void Room::createLevel()
{
	level = new char*[row];
	for (int i = 0; i < row; ++i)
	{
		level[i] = new char[col];
	}
}


void Room::playerHealthDrain()
{
	return;
}

void Room::playerInteract()
{
	return;
}

void Room::printLevel()
{
	cout << endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			
			cout << level[i][j] << " | ";
		}
		cout << endl;
		cout << string(col * 4, '-') << endl;
	}
}

void Room::printGame()
{
	level[player->getYpos()][player->getXpos()] = player->getDisplay();
	printLevel();
	player->printHealth();
	player->printPack();
}

bool Room::newRoom()
{
	return false;
}

string Room::newRommDir()
{
	return 0;
}

Room::~Room()
{
	for (int i = 0; i < row; i++)
	{
		delete[]level[i];
	}

	delete[]level;
}
