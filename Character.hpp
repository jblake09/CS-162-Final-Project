#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include<string>;

using std::string;

class Character
{
private:
	string type;
	int Armor, health, x, y;
	char display;
public:
	Character();
	void setType(string);
	void setArmor(int);
	void setHealth(int);
	void setDisplay(char);
	void setXpos(int);
	void setYpos(int);
	void printCreature();
	int getHealth();
	int getArmor();
	int getXpos();
	int getYpos();
	string getType();
	char getDisplay();
	virtual void move(char);
	virtual int attack();
	virtual int defend();
	virtual int special();
	virtual bool Dead();
	~Character();
};

#endif // !CHARACTER_HPP