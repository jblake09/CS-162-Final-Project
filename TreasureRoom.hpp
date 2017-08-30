#pragma once
#include "Room.hpp"
class TreasureRoom :
	public Room
{
public:
	TreasureRoom(Hero*);
	void populateLevel();
	void playerHealthDrain();
	void playerInteract();
	bool newRoom();
	~TreasureRoom();
};

