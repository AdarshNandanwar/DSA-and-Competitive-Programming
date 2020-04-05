#include<bits/stdc++.h>
using namespace std;

// Doubly Linked List

// Node structure, with integer data. ( could be anything depending on use case, eg real numbers/strings etc )
struct Node
{
	int data;
	Node *next, *prev;
	// constructor
	Node( int val )
	{
		data = val;
		next = NULL;
		prev = NULL;
	}
};

// Maintain global pointers ( tail helps in O(1) insertion at back )
Node *head = NULL, *tail = NULL;

// Insert node (at the end) with data as val into the list.
void insert( int val )
{
	// Base case, empty list
	if( head == NULL )
	{
		// CREATE NEW NODE
		head = new Node(val);
		tail = head;
		return;
	}
	// non-empty list

	// CREATE NEW NODE
	Node *temp = new Node(val);

	// manage all links
	tail->next = temp;
	temp->prev = tail;

	// newly inserted node at end is now tail ( important for further inserts )
	tail = temp;
}

// Display list starting from head ( helps to debug "next" links )
void display()
{
	Node *temp = head;
	while( temp != NULL )
	{
		cout<<temp->data<<" -> ";
		temp = temp->next;
	}
	cout<<"null"<<endl;
}

// Display list in reverse starting from prev ( helps to debug "prev" links )
void display_reverse()
{
	Node *temp = tail;
	while( temp != NULL )
	{
		cout<<temp->data<<" -> ";
		temp = temp->prev;
	}
	cout<<"null"<<endl;
}
 
// main
int main()
{
	// take input
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		// insert x
		insert(x);
	}

	// do whatever is asked in the problem

	// debugging
	display();
	display_reverse();
 
	return 0;
}