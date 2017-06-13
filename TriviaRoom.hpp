#pragma once
#include "Room.hpp"
class TriviaRoom :
	public Room
{
public:
	TriviaRoom(Hero*);
	void populateLevel();
	void playerHealthDrain();
	void playerInteract();
	bool newRoom();
	string newRommDir();
	~TriviaRoom();
};

