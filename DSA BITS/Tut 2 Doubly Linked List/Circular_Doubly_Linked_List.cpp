#include<bits/stdc++.h>
using namespace std;

// Circular Doubly Linked List

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

// Maintain global pointer ( size helps in easy traversal )
Node *head = NULL;
int size = 0;

// Insert node (at the end) with data as val into the list.
void insert( int val )
{
	// Base case, empty list
	if( size == 0 )
	{
		head = new Node(val);
		head->next = head;
		head->prev = head;
		size++;
		return;
	}
	// non-empty list

	// CREATE NEW NODE
	Node *temp = new Node(val);
	Node *last = head->prev;
 
	// manage all links
	last->next = temp;
	temp->next = head;
 
	head->prev = temp;
	temp->prev = last;

	// maintain size accurately
	size++;
}

// Insert node with data as val, in a sorted manner
// Eg. Insert 5 in {2,4,7,8} should give, {2,4,5,7,8}
void sorted_insert( int val )
{
	// Base case, empty list
	if( size == 0 )
	{
		head = new Node(val);
		head->next = head;
		head->prev = head;
		size++;
		return;
	}
	// non-empty list

	// traverse list, find place to insert
	// to insert in sorted manner, place to insert is first node >= val
	// NOTE: here trav is used for travelling through the list, and not temp
	Node *trav = head;
	for(int i=0;i<size;i++)
	{
		if( trav->data >= val )
		{
			// insert between trav->prev and trav

			// CREATE NEW NODE
			Node *temp = new Node(val);
			Node *last = trav->prev;
		 
			// manage all links
			last->next = temp;
			temp->next = trav;
		 
			trav->prev = temp;
			temp->prev = last;

			// must rectify head, in case insertion is at beginning
			if( i == 0 )
			{
				head = temp;
			}

			// maintain size accurately
			size++;

			// this return is very important, was discussed in tutorial
			return;
		}
		// if here, then not returned
		// check for next node
		trav = trav->next;
	}
	// if here, then not returned
	// val greater than all elements of list, i.e. must insert at end

	// CREATE NEW NODE
	Node *temp = new Node(val);
	Node *last = head->prev;
 
	// manage all links
	last->next = temp;
	temp->next = head;
 
	head->prev = temp;
	temp->prev = last;

	// maintain size accurately
	size++;
}

// Erase node at position given by pos
void erase_by_pos( int pos )
{
	// Go to the "pos"th position
	Node *temp = head;
	for(int i=0;i<pos-1;i++)
	{
		temp = temp->next;
	}

	// manage all links
	Node *left = temp->prev;
	Node *right = temp->next;
 
	left->next = right;
	right->prev = left;

	// When deleting first node, we must rectify head
	if( pos == 1 )
	{
		head = right;
	}

	// free/delete memory
	delete temp;

	// maintain size accurately
	size--;
}
 
void erase_by_val( int val )
{
	// Must delete on the go, look through the list, find the node with data == val
	Node *temp = head;
	for(int i=0;i<size;i++)
	{
		if( temp->data == val )
		{
			// manage all links
			Node *left = temp->prev;
			Node *right = temp->next;
 
			left->next = right;
			right->prev = left;

			// When deleting first node, we must rectify head
			if( i == 0 )
			{
				head = right;
			}


			// free/delete memory
			delete temp;

			// maintain size accurately
			size--;

			// ensures only one deletion
			// removing this return causes all nodes with data == val to be deleted
			// removing return has another problem, which we discussed in the tutorial
			// line 159 would cause a seg fault, because we freed temp
			// how to resolve this? ( given below as comment )
			return;

			// in case you remove return, you should add the following line
			// temp = left;
		}
		// if here, then not returned
		// check for next node
		temp = temp->next;
	}
}

// Display list starting from head ( helps to debug "next" links )
void display()
{
	Node *temp = head;
	for(int i=0;i<size;i++)
	{
		cout<<temp->data<<" -> ";
		temp = temp->next;
	}
	cout<<endl;
}
 
int main()
{
	// take input
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		// insert x ( here sorted, but depends on use case/ instruction )
		sorted_insert(x);
		// displaying each time, to view results of sorted insert
		display();
	}
 
 	// Call functions to debug/test your code
 	// display before and after to actually see the differences
 	cout<<"Checking erase_by_pos method, pos = 2:"<<endl;
 	display();
	erase_by_pos(2);
	display();
 
 	cout<<"Checking erase_by_val method, val = 6:"<<endl;
 	display();
	erase_by_val(6);
	display();
 
	return 0;
}