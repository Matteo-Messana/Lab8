// OLList.cpp
// ENCM 339  Lab 8 Exercise A and B

#include <iostream>
#include <stdlib.h>
using namespace std;
#include "OLList.h"

//default constructor
OLList::OLList()
: headM(0)
{
}

//constructor
OLList::OLList(const OLList& source)
{
    copy(source);
}

//assignment operator
OLList& OLList::operator =(const OLList& rhs)
{
    if (this != &rhs) {
        destroy();
        copy(rhs);
    }
    return *this;
}

//destructor
OLList::~OLList()
{
    destroy();
}

void OLList::print() const
{
    cout << '[';
    if (headM != 0) {
        cout << ' ' << headM->item;
        for (const Node *p = headM->next; p != 0; p = p->next)
            cout << ", " << p->item;
    }
    cout << " ]\n";
}

void OLList::insert(const ListItem& itemA)
{
    Node *new_node = new Node;
    new_node->item = itemA;
    
    if (headM == 0 || itemA <= headM->item ) {
        new_node->next = headM;
        headM = new_node;
        // point one
    }
    else {
        Node *before = headM;      // will point to node in front of new node
        Node *after = headM->next; // will be 0 or point to node after new node
        while(after != 0 && itemA > after->item) {
            before = after;
            after = after->next;
        }
        new_node->next = after;
        before->next = new_node;
        // point two
    }
}

void OLList::remove(const ListItem& itemA)
{
    // if list is empty, do nothing
    if (headM == 0 || itemA < headM->item)
        return;
    
    Node *doomed_node = 0;
    
    if (itemA == headM->item) {
        doomed_node = headM;
        headM = headM->next;
    }
    else {
        Node *before = headM;
        Node *maybe_doomed = headM->next;
        while(maybe_doomed != 0 && itemA > maybe_doomed->item) {
            before = maybe_doomed;
            maybe_doomed = maybe_doomed->next;
        }
        doomed_node = maybe_doomed;
        before->next = doomed_node -> next;
    }
    // point three
    delete [] doomed_node;
    doomed_node = NULL;
}


void OLList::destroy()
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

void OLList::copy(const OLList& source)
{
    Node* temp = source.headM;
    
    Node *headNode = new Node;
    this -> headM = headNode;
    headNode -> next = NULL;
    headNode -> item = temp->item;
    temp = temp -> next;
    
    Node* previous = headNode;
    
    while(temp != NULL)
    {
    	Node *copyNode = new Node;
    	copyNode -> item = temp -> item;
    	copyNode -> next = NULL;
    	previous -> next = copyNode; 
    	previous = copyNode;
    	temp = temp -> next;
    }

}


