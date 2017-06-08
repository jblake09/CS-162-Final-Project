#ifndef MISC_HPP
#define MISC_HPP

#include<stdlib.h>
#include<iostream>
#include<ctime>
#include<limits>
using std::cout;
using std::cin;
using std::endl;
using std::numeric_limits;
using std::streamsize;

int d12();
int d10();
int d6();
int randomNum(int, int);
void menu1(int&);
void menu2(int&);
void validMainMenu(int &);
void isDouble(double&);
void validateInput(int&);
void playAgain(int&);
void validPlayAgain(int&);


#endif