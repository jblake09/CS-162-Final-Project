#ifndef CAVE_HPP
#define CAVE_HPP

#include "Room.hpp"
class Cave :
	public Room
{
public:
	Cave(Hero*);
	void populateLevel();
	void playerHealthDrain();
	void playerInteract();
	bool newRoom();
	~Cave();
};

#endif // !CAVE_HPP