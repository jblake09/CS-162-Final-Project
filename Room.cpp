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

void Room::MovePlayer()
{
	char mover = ' ';

	while (mover != 'v')
	{
		
		level[player->getYpos()][player->getXpos()] = player->getDisplay();
		printLevel();
		cout << "Make a move: " << endl;
		cin >> mover;
		level[player->getYpos()][player->getXpos()] = '.';
		player->move(mover);
		level[player->getYpos()][player->getXpos()] = player->getDisplay();
		printLevel();
	}
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
}


void Room::createLevel()
{
	level = new char*[row];
	for (int i = 0; i < row; ++i)
	{
		level[i] = new char[col];
	}
}


void Room::printLevel()
{
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

Room::~Room()
{
}
