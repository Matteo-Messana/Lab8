//hydro.cpp
//ENCM 339 Lab 8 Exercise C

#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
#include "hydro.h"
#include "list.h"
#define SIZE 15;

void displayHeader()
{
	cout << "Program: Flow Studies - Fall 2017" << endl;
	cout << "Version: 1.0" << endl;
	cout << "Lab section: B03" << endl;
	cout << "Produced by: Alexander Gorkoff and Matteo Messana" << endl;
	pressEnter();
}

int readData(FlowList& list)
{
	ifstream stream;
	stream.open("flow.txt");
	if(stream.fail())
	{
		cerr<<"Could not open file."
		exit(1);
	}
	for(int i =0;i<SIZE;i++)
	{
		stream<<i+1;
		list.insert(stream);
	}
	
}