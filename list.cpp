// list.cpp
// ENCM 339 Lab 8 Exercise C 

#include <iostream>
#include <stdlib.h>
using namespace std;
#include "list.h"

// default constructor
FlowList::FlowList()
{
	headM = NULL;
	cursor = NULL;
}

// constructor
FlowList::FlowList(const FlowList& source)
{
	copy(source);
}
//don't go past line 45 o/w conflict

FlowList& Flowlist::operator =(const FlowList& rhs)
{
	if(this != rhs)
	{
		destroy();
		copy(rhs);
	}
	
	return *this;
}

FlowList::~FlowList()
{
	destroy();
}