#include "Character.hpp"



Character::Character()
{
	type = " ";
	Armor = 0;
	health = 0;
	x = 0;
	y = 0;
	pack = "";
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

void Character::removeFromPack(char itemRemove)
{
	if (pack.empty())
	{
		cout << "Pack is empty" << endl;
	}
	else
	{
		int index;
		index = pack.find(itemRemove);
		pack.erase(index);
	}
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

int Character::getOriginalHealth()
{
	return orignialHealth;
}

void Character::add2Pack(char inItem)
{
	if (pack.size() > 4)
	{
		//cout << "Pack is full!" << endl;
		return;
	}
	else
	{
		pack = pack + ' ' + inItem;
	}
}

void Character::useFromPack(int in)
{
	int size = pack.length();
	if (size == 6)
	{ 
		
		if (in == 1)
		{
			if (pack[1] == 'H')
			{
				char temp = pack[3];
				pack[1] = temp;
				pack[3] = pack[5];
				pack.erase(4);
				setHealth(getOriginalHealth());
				cout << "You just used a health potion!" << endl;
			}
			else if (pack[1] == 'K')
			{
				cout << "You cant use the key yet!" << endl;
			}
		}
		if (in == 2)
		{
			if (pack[3] == 'H')
			{
				pack[3] = pack[5];
				pack.erase(4);
				setHealth(getOriginalHealth());
				cout << "You just used a health potion!" << endl;
			}
			else if (pack[1] == 'K')
			{
				cout << "You cant use the key yet!" << endl;
			}
		}
		if (in == 3)
		{
			if (pack[5] == 'H')
			{
				pack.erase(4);
				setHealth(getOriginalHealth());
				cout << "You just used a health potion!" << endl;
			}
			else if (pack[1] == 'K')
			{
				cout << "You cant use the key yet!" << endl;
			}
		}
	}
	else if (size == 4)
	{
		if (in == 1)
		{

		}
		else if (in == 2)
		{

		}
		else if (in == 3)
	}
	else if (size == 5)
	{

	}
	
	
}

string Character::getType()
{
	return type;
}

char Character::getDisplay()
{
	return display;
}

string Character::getPack()
{
	return pack;
}

void Character::printPack()
{
	cout << "My Pack" << endl;
	cout << " 1 2 3 " << endl;
	cout << pack << endl;
}

void Character::printHealth()
{
	cout << type << " Health: " << health << endl;
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
