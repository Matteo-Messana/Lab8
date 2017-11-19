//hydro.cpp
//ENCM 339 Lab 8 Exercise C

#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
#include "hydro.h"
#include "list.h"

int main(void)
{
	FlowList ListofLinks;
	int TotalRecords;
	int quit = 0;
	displayHeader();
	TotalRecords = readData(ListofLinks);
	
	while(1)
	{
		switch(menu()){
			case 1: 
				cout << "User has chosen Option #1: Display flow list, average and median." << endl;
				display(ListofLinks, TotalRecords);
				pressEnter();
				break;
			
			case 2:
				cout << "User has chosen Option #2: Add data" << endl;
				TotalRecords = addData(ListofLinks, TotalRecords);
				pressEnter();
				break;
				
			case 3:
				cout << "This is choice #3" << endl;
				pressEnter();
				break;
				
			case 4:
				cout << "User has chosen Option #4: Remove Data" << endl;
				TotalRecords = removeData(ListofLinks, TotalRecords);
				pressEnter();
				break;
				
			case 5:
				cout << "\nProgram Terminated Successfully!\n" << endl;
			 	quit = 1;
				break;
			
			default:
				cout << "\nNot a valid input." << endl;
				pressEnter();
				break;
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
	int dataNum = 0;
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
		dataNum++;
	}
	stream.close();
	cout << "Data from the file was successfully read" << endl;
	
	return dataNum;
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
	return ++size;
}

void display(const FlowList& list, int size)
{
	int year;
	double flow;
	Node* cursorM = list.get_headM();
	
	cout << "YEAR		FLOW (in billions of cubic meters)" << endl;
	while(cursorM != NULL)
	{
		year = cursorM->item.year;
		flow = cursorM->item.flow;
		cout << year << "		" << flow << endl;
		cursorM = cursorM->next;
	}
	
	cout << "The number of records in this data set is:" << size << endl;
	cout << "The median for the data set is:" << median(list, size) << endl;
	
}

int removeData(FlowList& list, int size)
{
	int user_input;
	cout << "Please enter the year that you want to remove:" << endl;
	cin >> user_input;
	
	ListItem temp = {user_input};
	int success = list.remove(temp);
	
	if(success == 1)
	{
		cout << "successful removal" << endl;
		return --size;
	}
	else
	{
		cout << "unsuccessful removal" << endl;
		return size;
	}
}

double median(const FlowList& list, int size)
{
	Node* cursorM = list.get_headM();
	
	if(size%2 == 0)
	{
		int i = 1;
		while(i <= size/2)
		{
			cursorM = cursorM->next;
			i++;
		}
		return ((cursorM->item.flow + (cursorM->next)->item.flow)/2);
	}
	else
	{
		int j = 1;
		while(j <= size/2)
		{
			cursorM = cursorM -> next;
			j++;
		}
		return cursorM->item.flow;
	}
}
	



