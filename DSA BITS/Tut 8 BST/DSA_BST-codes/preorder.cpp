#include <bits/stdc++.h>
using namespace std;
struct Node
{
  int data;
  Node *left, *right;
};
Node* newNode(int key)
{
  Node* node = new Node;
  node->data = key;
  node->left = node->right = NULL;
  return node;
}
void inorder(Node* root)
{
  if (root == NULL)
    return;
  inorder(root->left);
  cout << root->data << " ";
  inorder(root->right);
}

struct Node* constructBST(vector<int> preorder, int start, int end)
{
	if (start > end)
		return NULL;

	struct Node *node = newNode(preorder[start]);

	int i;
	for (i = start; i <= end; i++) {
		if (preorder[i] > node->data)
			break;
	}

	node->left = constructBST(preorder, start + 1, i - 1);
	node->right = constructBST(preorder, i, end);

	return node;
}

int main(void)
{
	/* Construct below BST
			  15
			/	\
		   /	  \
		  10	   20
		 /  \	 /  \
		/	\   /	\
	   8	 12 16	25
	*/

	vector<int> preorder = { 15, 10, 8, 12, 20, 16, 25 };
	struct Node* root = constructBST(preorder, 0, preorder.size() - 1);

	cout<<"Inorder Traversal of BST is : ";
	inorder(root);

	return 0;
}