#ifndef HERO_HPP
#define HERO_HPP

#include "Character.hpp"
class Hero :
	public Character
{
public:
	Hero();
	void move(char);
	~Hero();
};

#endif // !HERO_HPP