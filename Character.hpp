#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include<string>;
#include"Misc.hpp"

using std::string;

class Character
{
private:
	string type;
	int Armor, health,orignialHealth, x, y;
	char display;
	string pack;
public:
	Character();
	void setType(string);
	void setArmor(int);
	void setHealth(int);
	void setDisplay(char);
	void setXpos(int);
	void setYpos(int);
	void printCreature();
	void removeFromPack(char);
	int getHealth();
	int getArmor();
	int getXpos();
	int getYpos();
	int getOriginalHealth();
	void add2Pack(char);
	void useFromPack(int);
	string getType();
	char getDisplay();
	string getPack();
	void printPack();
	void printHealth();
	virtual void move(char);
	virtual int attack();
	virtual int defend();
	virtual int special();
	virtual bool Dead();
	~Character();
};

#endif // !CHARACTER_HPP