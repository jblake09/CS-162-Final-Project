#ifndef TRIVIAROOM_HPP
#define TRIVIAROOM_HPP


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

#endif // !TRIVIAROOM_HPP