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

// assignment overide
FlowList& FlowList::operator =(const FlowList& rhs)
{
	if(this != &rhs)
	{
		destroy();
		copy(rhs);
	}
	
	return *this;
}

// destructor
FlowList::~FlowList()
{
	destroy();
}

// insert member function
void FlowList::insert(const ListItem& itemA)
{
	Node *new_node = new Node;
    new_node->item = itemA;
    
    if (headM == 0 || itemA.flow <= headM->item.flow ) {
        new_node->next = headM;
        headM = new_node;
    }
    else {
        Node *before = headM;      
        Node *after = headM->next; 
        while(after != 0 && itemA.flow > after->item.flow) {
            before = after;
            after = after->next;
        }
        new_node->next = after;
        before->next = new_node;
     }
}

// remove member function
int FlowList::remove(const ListItem& itemA)
{
    if (headM == 0)
        return 0;
    
    Node *doomed_node = 0;
    
    if ((itemA.year == headM->item.year)) {
        doomed_node = headM;
        headM = headM->next;
    }
    else {
        Node *before = headM;
        Node *maybe_doomed = headM->next;
        while(maybe_doomed != 0 || itemA.year != maybe_doomed->item.year) {
            before = maybe_doomed;
            maybe_doomed = maybe_doomed->next;
            if(maybe_doomed == NULL)
            {
            	return 0;
            }   
        }
        doomed_node = maybe_doomed;
        before->next = doomed_node -> next;
    }

    delete [] doomed_node;
    doomed_node = NULL;
    
    return 1;
}

Node* FlowList::get_headM()const
{
	return headM;
}

// destroy member function
void FlowList::destroy()
{
	Node* annihilate = headM;

    while(headM != NULL)
    { 
    	headM = headM -> next;	
    	annihilate -> next = NULL;
    	delete annihilate;
    	annihilate = headM;
    }

    delete annihilate;
    annihilate = NULL;
    headM = NULL;

}

// copy member function
void FlowList::copy(const FlowList& source)
{
	cursor = source.headM;
    
    Node *headNode = new Node;
    this -> headM = headNode;
    headNode -> next = NULL;
    headNode -> item = cursor->item;
    cursor = cursor -> next;
    
    Node* previous = headNode;
    
    while(cursor != NULL)
    {
    	Node *copyNode = new Node;
    	copyNode -> item = cursor -> item;
    	copyNode -> next = NULL;
    	previous -> next = copyNode; 
    	previous = copyNode;
    	cursor = cursor -> next;
    }
}
