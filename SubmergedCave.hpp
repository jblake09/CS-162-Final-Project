#ifndef SUBMERGEDCAVE_HPP
#define SUBMERGEDCAVE_HPP


#include "Room.hpp"
class SubmergedCave :
	public Room
{
public:
	SubmergedCave(Hero*);
	void populateLevel();
	void playerHealthDrain();
	void playerInteract();
	bool newRoom();
	~SubmergedCave();
};

#endif // !SUBMERGEDCAVE_HPP