//list.h
//ENCM 339 Exercise C

#ifndef LIST_H
#define LIST_H

struct ListItem
{
	int year;
	double flow;
};

struct Node
{
	ListItem item;
	Node *next;
};

class FlowList {
	
	public:
		FlowList(); //default constructor
		FlowList& operator =(const FlowList&rhs); //overloaded assignment operator
		~FlowList(); //destructor
		
		void insert(const ListItem& itemA);
		int remove(const ListItem& itemA);
		Node* get_headM()const;
	
	private:
		Node *headM;
		Node *cursor;
		void destroy();
		void copy(const FlowList&source);

};

#endif


