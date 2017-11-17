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
		
		void insert(const ListItem& itemA);
		void remove(const ListItem& itemA);
		//void print() const;
		Node* get_item()const;
	
	private:
		Node *headM;
		Node *cursor;
		void destroy();
		void copy(const FlowList&source);

};

#endif


