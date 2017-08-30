#include "Hero.hpp"



Hero::Hero()
{
	setHealth(50);
	setDisplay('V');
	setArmor(5);
	setType("Bob Jones");
	setXpos(2);
	setYpos(2);
	setOriginalHealth(50);
}

void Hero::move(char movement)
{
	int temp;
	//a = move left
	if (movement == 'a')
	{
		temp = getXpos();
		temp--;
		setXpos(temp);
	}
	//s = move down
	else if (movement == 's')
	{
		temp = getYpos();
		temp++;
		setYpos(temp);
	}
	//d = move right
	else if(movement == 'd')
	{
		temp = getXpos();
		temp++;
		setXpos(temp);
	}
	//w = move up
	else if (movement == 'w')
	{
		temp = getYpos();
		temp--;
		setYpos(temp);
	}
}

bool Hero::Dead()
{
	if (getHealth() > 0)
	{
		return false;
	}
	else
	{
		return true;
	}
	
}


Hero::~Hero()
{
}
