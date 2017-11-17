//list.h
//ENCM 339 Exercise C

#ifndef LIST_H
#define LIST_H

struct ListItem
{
	int year;
	double flow;
}

struct Node
{
	ListItem item;
	Node *next;
}

class FlowList {
	
	public:
		FlowList(); //default constructor
		FlowList(const &FlowList itemA); //copy constructor
		FlowList& operator =(const FlowList&rhs) //overloaded assignment operator
		~FlowListI(); //destructor
	
	private:


WAAWAWAWAWAWAWAWAWAW
tg

};

#endif


