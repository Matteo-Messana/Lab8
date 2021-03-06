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
		switch(menu())
		{
			case 1: 
				cout << "\n----------------------------------------------------------------" << endl;
				cout << "User has chosen Option #1: Display flow list, average and median" << endl;
				cout << "----------------------------------------------------------------" << endl;
				display(ListofLinks, TotalRecords);
				break;
			
			case 2:
				cout << "\n-----------------------------------" << endl;
				cout << "User has chosen Option #2: Add data" << endl;
				cout << "-----------------------------------" << endl;
				TotalRecords = addData(ListofLinks, TotalRecords);
				break;
				
			case 3:
				cout << "\n----------------------------------" << endl;
				cout << "User has chosen Option #3: Save data" << endl;
				cout << "------------------------------------" << endl;
				saveData(ListofLinks);
				break;
				
			case 4:
				cout << "\n------------------------------------" << endl;
				cout << "User has chosen Option #4: Remove Data" << endl;
				cout << "--------------------------------------" << endl;
				TotalRecords = removeData(ListofLinks, TotalRecords);
				break;
				
			case 5:
				cout << "\n--------------------------------" << endl;
				cout << "Program Terminated Successfully!" << endl;
				cout << "--------------------------------" << endl;
			 	quit = 1;
				break;
			
			default:
				cout << "\n------------------" << endl;
				cout << "Not a valid input." << endl;
				cout << "------------------" << endl;
				break;
		}				
		if(quit == 1)
			break;
			
		if(cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
		}
	}
}


void displayHeader()
{
	cout << "\n-------------------------------------------------" << endl;
	cout << "Program: Flow Studies - Fall 2017" << endl;
	cout << "Version: 1.0" << endl;
	cout << "Lab section: B03" << endl;
	cout << "Produced by: Alexander Gorkoff and Matteo Messana" << endl;
	cout << "-------------------------------------------------" << endl;
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
	cout << "-----------------------------------------" << endl;
	cout << "Data from the file was successfully read!" << endl;
	cout << "-----------------------------------------" << endl;
	
	return dataNum;
}

void pressEnter()
{
	cout << "\n<<< Press Enter to Continue >>>" << endl;
	cin.get();
}

int menu()
{
	cout << "\n----------------------------------------------" << endl;
	cout << "Please select one of the following operations:" << endl;
	cout << "1. Display flow list, average and median." << endl;
	cout << "2. Add data." << endl;
	cout << "3. Save data into the file." << endl;
	cout << "4. Remove data." << endl;
	cout << "5. Quit" << endl;
	cout << "----------------------------------------------" << endl;
	cout << "Enter your choice (1, 2, 3, 4, or 5):" << endl;
	cout << "----------------------------------------------" << endl;
	
	double user_input;
	cin >> user_input;
	if(cin.get() == ' ')
	{
		cin.clear();
		cin.ignore(1000, '\n');
		return 0;
	}
	if(user_input == (int)user_input)
		return (int)user_input;	
	else
		return 0;
}

int addData(FlowList& list, int size)
{
	int year;
	double flow;
	cout << "\n----------------------------------------------------------------------" << endl;
	cout << "Please enter a year" << endl;
	cout << "----------------------------------------------------------------------" << endl;
	cin >> year;
	cout << "\n----------------------------------------------------------------------" << endl;
	cout << "Please enter a flow rate" << endl;
	cout << "----------------------------------------------------------------------" << endl;
	cin >> flow;
	
	if(cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "\n----------------------------------------------" << endl;
		cout << "Input invalid. Data could not be added to set." << endl;
		cout << "----------------------------------------------" << endl;
		return size;
	}
	
	ListItem temp = {year,flow};
	list.insert(temp);
	
	cout << "\n--------------------------------------------" << endl;
	cout << "Data was successfully added to the data set!" << endl;
	cout << "--------------------------------------------" << endl;
	return ++size;
	
}

void display(const FlowList& list, int size)
{
	int year;
	double flow;
	Node* cursorM = list.get_headM();
	
	cout << "\n--------------------------------------------------" << endl;
	cout << "YEAR		FLOW (in billions of cubic meters)" << endl;
	cout << "--------------------------------------------------" << endl;
	while(cursorM != NULL)
	{
		year = cursorM->item.year;
		flow = cursorM->item.flow;
		cout << year << "		" << flow << endl;
		cursorM = cursorM->next;
	}
	cout << "---------------------------------------------" << endl;
	cout << "The number of records in the data set is:" << size << endl;	
	cout << "The median flow for the data set is:" << median(list, size) << endl;
	cout << "The average flow for the data set is:" << average(list, size) << endl;
	cout << "---------------------------------------------" << endl;
}	

int removeData(FlowList& list, int size)
{
	int user_input;
	cout << "\n----------------------------------------------" << endl;
	cout << "Please enter the year that you want to remove:" << endl;
	cout << "----------------------------------------------" << endl;
	cin >> user_input;
	
	ListItem temp = {user_input};
	int success = list.remove(temp);
	
	if(success == 1)
	{
		cout << "\n---------------------------------------------------" << endl;
		cout << "You successfully removed an item from the data set!" << endl;
		cout << "---------------------------------------------------" << endl;
		return --size;
	}
	else
	{
		cout << "\n-----------------------------------------------------" << endl;
		cout << "User input invalid. Target item could not be removed!" << endl;
		cout << "-----------------------------------------------------" << endl;
		return size;
	}
}

double average(const FlowList& list, int size)
{

	double average=0;
	Node* cursorM = list.get_headM();
	while(cursorM != NULL)
	{
		average+=cursorM->item.flow;
		cursorM=cursorM->next;
	}
	return average/size;	
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

void saveData(const FlowList& list)
{
	Node* cursorM = list.get_headM();
	ofstream stream;
	stream.open("flow.txt");
	
	if(stream.fail())
	{
		cerr << "\nCould not open file.";
		exit(1);
	}
	
	while(cursorM != NULL)
	{
		stream << cursorM -> item.year << "		" << cursorM -> item.flow << endl;
		cursorM = cursorM -> next;
	}
	
	stream.close();
	cout << "\n-------------------------------------------------------------" << endl;
	cout << "The data set was successfully written into the file flow.txt!" << endl;
	cout << "-------------------------------------------------------------" << endl;
}