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