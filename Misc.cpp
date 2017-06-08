#include "Misc.hpp"




int d12()
{
	
	int randnum;
	int max = 12;
	int min = 1;
	//http://stackoverflow.com/questions/2254498/c-how-i-can-get-random-value-from-1-to-12
	// I started out using just the rand() function but found the numbers returned were not truly random
	randnum = min + rand() / (RAND_MAX / (max - min + 1) + 1);
	return randnum;
}

int d10()
{
	
	int randnum;
	int max = 10;
	int min = 1;
	//http://stackoverflow.com/questions/2254498/c-how-i-can-get-random-value-from-1-to-12
	// I started out using just the rand() function but found the numbers returned were not truly random
	randnum = min + rand() / (RAND_MAX / (max - min + 1) + 1);
	return randnum;
}

int d6()
{
	
	int randnum;
	int max = 6;
	int min = 1;
	//http://stackoverflow.com/questions/2254498/c-how-i-can-get-random-value-from-1-to-12
	// I started out using just the rand() function but found the numbers returned were not truly random
	randnum = min + rand() / (RAND_MAX / (max - min + 1) + 1);
	return randnum;
}

int randomNum(int max, int min)
{
	
	int randnum;
	//http://stackoverflow.com/questions/2254498/c-how-i-can-get-random-value-from-1-to-12
	// I started out using just the rand() function but found the numbers returned were not truly random
	randnum = min + rand() / (RAND_MAX / (max - min + 1) + 1);
	return randnum;
}
/*********************************************************************************************************************
** Description:  Main menu function displays user choices and allows them to make a proper choice
*********************************************************************************************************************/
void menu1(int &p1Choice)
{
	//output choices
	cout << "Fantasy Battle" << endl;
	cout << "Player 1 choose your creature" << endl;
	cout << "1) Vampire" << endl;
	cout << "2) Barbarian" << endl;
	cout << "3) Blue Men" << endl;
	cout << "4) Medusa" << endl;
	cout << "5) Harry Potter" << endl;
	cout << "6) Quit" << endl;
	cout << "Please enter the number of the creature you would like to select!";
	//ask user for through input validation function
	validMainMenu(p1Choice);
}
void menu2(int &p2Choice)
{
	//output choices
	cout << "Fantasy Battle" << endl;
	cout << "Player 2 choose your creature" << endl;
	cout << "1) Vampire" << endl;
	cout << "2) Barbarian" << endl;
	cout << "3) Blue Men" << endl;
	cout << "4) Medusa" << endl;
	cout << "5) Harry Potter" << endl;
	cout << "6) Quit" << endl;
	cout << "Please enter the number of the creature you would like to select!";
	//ask user for through input validation function
	validMainMenu(p2Choice);
}
/*********************************************************************************************************************
** Description: Validates main menu inout
*********************************************************************************************************************/
void validMainMenu(int &input)
{
	//ensure input is an int
	validateInput(input);
	//ensure input is appropiate with choices
	while (input != 1 && input != 2 && input != 3 && input != 4 && input != 5 && input != 6)
	{
		//if they didnt warn them and have them re input
		cout << "Input is invalid :(" << endl;
		cout << "Please make valid menu selection!" << endl;
		validateInput(input);
	}
}

void isDouble(double &doubleinput)
{
	while (!(cin >> doubleinput))
	{
		cin.clear();
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
		cout << "Please enter a integer: ";
	}
}

void validateInput(int &input)
{
	double test;
	isDouble(test);
	input = test;
	bool isinputVaild = false;
	while (isinputVaild == false)
	{
		if (test != input)
		{
			cout << "Please enter a whole number: ";
			isDouble(test);
		}
		else
		{
			isinputVaild = true;
		}
		input = test;
	}
}


void playAgain(int &in)
{
	//output choices
	cout << "Would you like to play again?" << endl;
	cout << "1) Play Again" << endl;
	cout << "2) Quit" << endl;
	cout << "Please enter your selection";
	//ask user for through input validation function
	validPlayAgain(in);
}

void validPlayAgain(int &inToBeValid)
{
	//ensure input is an int
	validateInput(inToBeValid);
	//ensure input is appropiate with choices
	while (inToBeValid != 1 && inToBeValid != 2)
	{
		//if they didnt warn them and have them re input
		cout << "Input is invalid :(" << endl;
		cout << "Please make valid menu selection!" << endl;
		validateInput(inToBeValid);
	}
}

