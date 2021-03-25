#include <bits/stdc++.h>
using namespace std;
struct node
{
  int data;
  node *left, *right;
};
node* newNode(int key)
{
  node* nod = new node;
  nod->data = key;
  nod->left = nod->right = NULL;
  return nod;
}
void inorder(node* root)
{
  if (root == NULL)
    return;
  inorder(root->left);
  cout << root->data << " ";
  inorder(root->right);
}
void swap( int* a, int* b ) 
{ 
	int t = *a; 
	*a = *b; 
	*b = t; 
} 

void correctBSTUtil( struct node* root, struct node** first, 
					struct node** middle, struct node** last, 
					struct node** prev ) 
{ 
	if( root ) 
	{ 
		correctBSTUtil( root->left, first, middle, last, prev ); 

		if (*prev && root->data < (*prev)->data) 
		{ 
			if ( !*first ) 
			{ 
				*first = *prev; 
				*middle = root; 
			} 
			else
				*last = root; 
		} 

		*prev = root; 

		correctBSTUtil( root->right, first, middle, last, prev ); 
	} 
} 

void correctBST( struct node* root ) 
{ 
	struct node *first, *middle, *last, *prev; 
	first = middle = last = prev = NULL; 

	correctBSTUtil( root, &first, &middle, &last, &prev ); 

	if( first && last ) 
		swap( &(first->data), &(last->data) ); 
	else if( first && middle ) // Adjacent nodes swapped 
		swap( &(first->data), &(middle->data) ); 

} 

int main() 
{ 
	/*    6 
	   	/   \ 
	   2    7 
	   / \  / \ 
	  1  3 10 12 

	10 and 2 are swapped 
	*/
	// 1 2,3,6,10,7,12
	// first=10
	// middle=7
	// last=Null


	struct node *root = newNode(6); 
	root->left	 = newNode(10); 
	root->right	 = newNode(2); 
	root->left->left = newNode(1); 
	root->left->right = newNode(3); 
	root->right->right = newNode(12); 
	root->right->left = newNode(7); 

	printf("Inorder Traversal of the original tree \n"); 
	inorder(root); 

	correctBST(root); 

	printf("\nInorder Traversal of the fixed tree \n"); 
	inorder(root); 

	return 0; 
} 
