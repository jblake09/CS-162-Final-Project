#include "Character.hpp"



Character::Character()
{
	type = " ";
	Armor = 0;
	health = 0;
	x = 0;
	y = 0;
}

void Character::setType(string inType)
{
	type = inType;
}

void Character::setArmor(int inArmor)
{
	Armor = inArmor;
}

void Character::setHealth(int inHealth)
{
	health = inHealth;
}

void Character::setDisplay(char inDisplay)
{
	display = inDisplay;
}

void Character::setXpos(int input)
{
	x = input;
}

void Character::setYpos(int in)
{
	y = in;
}

void Character::printCreature()
{
}

int Character::getHealth()
{
	return health;
}

int Character::getArmor()
{
	return Armor;
}

int Character::getXpos()
{
	return x;
}

int Character::getYpos()
{
	return y;
}

string Character::getType()
{
	return type;
}

char Character::getDisplay()
{
	return display;
}

void Character::move(char)
{
}

int Character::attack()
{
	return 0;
}

int Character::defend()
{
	return 0;
}

int Character::special()
{
	return 0;
}

bool Character::Dead()
{
	return false;
}


Character::~Character()
{
}
