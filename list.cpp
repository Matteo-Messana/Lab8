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
























