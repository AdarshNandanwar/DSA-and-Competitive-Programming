#include <bits/stdc++.h>
using namespace std;
vector<int> ino;
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
void insert(Node* &root, int key)
{
  if (root == NULL)
  {
    root = newNode(key);
    return;
  }

  if (key < root->data)
    insert(root->left, key);

  else
    insert(root->right, key);
}
void inorder(Node* root)
{
  if (root == NULL)
    return;
  inorder(root->left);
  ino.push_back(root->data);
  inorder(root->right);
}
bool checkBST(Node* root, int minValue, int maxValue) {
    if (root == NULL)
        return true;

    if (root->data < minValue || root->data > maxValue)
        return false;

    return ( checkBST(root->left, minValue, root->data - 1) 
        && checkBST(root->right, root->data + 1, maxValue));
}

bool checkBST(Node* root) {
    return checkBST(root, 0, 1000);
}

int main()
{
  Node* root = NULL;
  vector<int> keys={ 15, 8,5,11,9,14,20,35,26,25 };
  for (int key : keys)
    insert(root, key);
    
    //CHECK IF INORDER OUTPUT IS SORTED
    inorder(root);
    //RECURSIVE FUNCTION TO CHECK BST
    cout<<"is BST: "<<checkBST(root);
    

  return 0;
}