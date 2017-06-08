#ifndef ROOM_HPP
#define ROOM_HPP

#include<cstdlib>
#include"Character.hpp"
#include"Hero.hpp"
#include<iostream>

using std::cout;
using std::cin;
using std::endl;

class Room
{
private: 
	Room *East, *West, *North, *South;
	int row, col;
	char **level;
	Hero* player;

public:
	Room(Hero*);
	void setRow(int);
	void setCol(int);
	void setEast(Room*);
	void setWest(Room*);
	void setNorth(Room*);
	void setSouth(Room*);
	void createLevel();
	void MovePlayer();
	Room* getEast();
	Room* getWest();
	Room* getNorth();
	Room* getSouth();
	char** getLevel();
	int getRow();
	int getCol();
	void setLevel(char**);
	virtual void populateLevel() = 0;
	void printLevel();
	~Room();
};

#endif // ! ROOM_HPP