#ifndef DEATHPIT_HPP
#define DEATHPIT_HPP
#endif // !DEATHPIT_HPP

#include "Room.hpp"
class DeathPit :
	public Room
{
public:
	DeathPit(Hero*);
	void populateLevel();
	void playerHealthDrain();
	~DeathPit();
};

