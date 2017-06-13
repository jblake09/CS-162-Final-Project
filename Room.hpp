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
	bool lever = false, first = true;

public:
	Room(Hero*);
	void setRow(int);
	void setCol(int);
	void setEast(Room*);
	void setWest(Room*);
	void setNorth(Room*);
	void setSouth(Room*);
	void setHero(Hero*);
	void createLevel();
	void MovePlayer(char);
	Hero* getHero();
	Room* getEast();
	Room* getWest();
	Room* getNorth();
	Room* getSouth();
	char** getLevel();
	int getRow();
	int getCol();
	void setLevel(char**);
	virtual void populateLevel() = 0;
	virtual void playerHealthDrain();
	virtual void playerInteract();
	void printLevel();
	void printGame();
	virtual bool newRoom();
	virtual string newRommDir();
	~Room();
};

#endif // ! ROOM_HPP