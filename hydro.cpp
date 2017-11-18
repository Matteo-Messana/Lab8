//hydro.cpp
//ENCM 339 Lab 8 Exercise C

#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
#include "hydro.h"
#include "list.h"

void displayHeader()
{
	cout << "Program: Flow Studies - Fall 2017" << endl;
	cout << "Version: 1.0" << endl;
	cout << "Lab section: B03" << endl;
	cout << "Produced by: Alexander Gorkoff and Matteo Messana" << endl;
	cout << "<<< Press Enter to Continue >>>" << endl;
	pressEnter();
}