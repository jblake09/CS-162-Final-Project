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
	cout << "Welcom to Bob Jones Adventure!" << endl;
	cout << "Indiana Jones was out of town but a message came in" << endl;
	cout << "that the lost the treasure of the lost tomb of Arkanas" << endl;
	cout << "was in danger there was no time to wait for Indy" << endl;
	cout << "You must find the treasure before it is to late, but beware" << endl;
	cout << "you cant survive for long in there without health potion!" << endl;
	cout << "1) Play" << endl;
	cout << "2) Quit" << endl;
	cout << "Please enter your selection! ";
	//ask user for through input validation function
	validMainMenu(p1Choice);
}

/*********************************************************************************************************************
** Description: Validates main menu inout
*********************************************************************************************************************/
void validMainMenu(int &input)
{
	//ensure input is an int
	validateInput(input);
	//ensure input is appropiate with choices
	while (input != 1 && input != 2)
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
void validItemSelect(int &inToBeValid)
{
	//ensure input is an int
	validateInput(inToBeValid);
	//ensure input is appropiate with choices
	while (inToBeValid != 1 && inToBeValid != 2 && inToBeValid != 3)
	{
		//if they didnt warn them and have them re input
		cout << "Input is invalid :(" << endl;
		cout << "Please make valid menu selection!" << endl;
		validateInput(inToBeValid);
	}
}

void validCharInput(char &inChar)
{
	validateChar(inChar);
	while (inChar != 'a' && inChar != 'd' && inChar != 's' && inChar != 'w' && inChar != 'e' && inChar != 't')
	{
		cout << "please enter a vaild input ";
		validateChar(inChar);
	}
}

void validateChar(char &in)
{
	string inString;
	cin >> inString;
	while (inString.size() > 1)
	{
		cout << "Please enter a single character! ";
		cin >> inString;

	}
	
	in = inString[0];
	
}

