//hydro.cpp
//ENCM 339 Lab 8 Exercise C

#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
#include "hydro.h"
#include "list.h"
#define SIZE 15;

int main(void)
{
	//FlowList ListofLinks;
	//int TotalRecords;
	int quit = 0;
	displayHeader();
	//TotalRecords = readData(ListofLinks);
	
	
	while(1)
	{
		switch(menu()){
			case 1: 
				cout << "This is choice #1" << endl;
				pressEnter();
				break;
			
			case 2:
				cout << "This is choice #2" << endl;
				pressEnter();
				break;
				
			case 3:
				cout << "This is choice #3" << endl;
				pressEnter();
				break;
				
			case 4:
				cout << "This is choice #4" << endl;
				pressEnter();
				break;
				
			case 5:
				cout << "\nProgram Terminated Successfully!\n" << endl;
			 	quit = 1;
				break;
			
			default:
				cout << "\nNot a valid input." << endl;
				pressEnter();
		}				
		if(quit == 1)
			break;
	}
}


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
	int year;
	double flow;
	ifstream stream;
	stream.open("flow.txt");
	if(stream.fail())
	{
		cerr<<"Could not open file.";
		exit(1);
	}
	while(!stream.eof())
	{
		stream >> year >> flow;
		ListItem temp = {year, flow};
		list.insert(temp);
	}
	stream.close();
}

void pressEnter()
{
	cout << "\n<<< Press Enter to Continue >>>" << endl;
	cin.get();
}

int menu()
{
	cout << "Please select one of the following operations:" << endl;
	cout << "1. Display flow list, average and median." << endl;
	cout << "2. Add data." << endl;
	cout << "3. Save data into the file." << endl;
	cout << "4. Remove data." << endl;
	cout << "5. Quit" << endl;
	cout << "Enter your choice (1, 2, 3, 4, or 5):" << endl;
	
	double user_input;
	cin >> user_input;
	
	if(user_input == (int)user_input)
		return (int)user_input;	
	else
		return 0;
}

int addData(FlowList& list, int size)
{
	int year;
	double flow;
	cout << "Please enter a year and a flow rate" << endl;
	cin >> year >> flow;
	ListItem temp = {year,flow};
	list.insert(temp);
	size++;	
	return size;
}