#ifndef LOCKROOM_HPP
#define LOCKROOM_HPP


#include "Room.hpp"
class LockRoom :
	public Room
{
public:
	LockRoom(Hero*);
	void populateLevel();
	void playerHealthDrain();
	void playerInteract();
	bool newRoom();
	~LockRoom();
};

#endif // !LOCKROOM_HPP