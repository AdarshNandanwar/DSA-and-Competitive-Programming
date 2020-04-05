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

Node* search(Node* root, int key) 
{ 
    // Base Cases: root is null or key is present at root 
    if (root == NULL || root->data == key) 
       return root; 
    // Key is greater than root's key 
    if (root->data < key) 
       return search(root->right, key); 
    // Key is smaller than root's key 
    return search(root->left, key); 
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
int main()
{
  Node* root = NULL;
  vector<int> keys={ 15, 10, 20, 8, 12, 16, 25 };

  for (int key : keys)
    insert(root, key);

  if(search(root,10))
    cout<<"Found"<<endl;
  else
    cout<<"Not Found"<<endl;
  if(search(root,7))
    cout<<"Found"<<endl;
  else
    cout<<"Not Found"<<endl;

  return 0;
}