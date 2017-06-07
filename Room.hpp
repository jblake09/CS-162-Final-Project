#ifndef ROOM_HPP
#define ROOM_HPP


class Room
{
private: 
	Room *East, *West, *North, *South;

public:
	Room();
	~Room();
};

#endif // ! ROOM_HPP