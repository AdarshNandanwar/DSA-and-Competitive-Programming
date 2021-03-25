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

Node* insert_ret(Node* root, int key)
{
  if (root == NULL)
    return newNode(key);
 
  if (key < root->data)
    root->left = insert_ret(root->left, key);
 
  else
    root->right = insert_ret(root->right, key);
 
  return root;
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
  vector<int> keys={ 15,20,10, 8, 16,12, 25 };
 
  //INSERT_RETURN
  // for (int key : keys)
  //   root = insert_ret(root, key);

  //INSERT REFERENCE
  for (int key : keys)
    insert(root, key);

  inorder(root);
  return 0;
}
//         15
//        /  \
//       /    \
//      10     20
//     /  \   /  \
//    /    \ /    \
//    8   12 16   25