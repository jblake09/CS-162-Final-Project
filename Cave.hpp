#ifndef CAVE_HPP
#define CAVE_HPP

#include "Room.hpp"
class Cave :
	public Room
{
public:
	Cave(Hero*);
	void populateLevel();
	~Cave();
};

#endif // !CAVE_HPP