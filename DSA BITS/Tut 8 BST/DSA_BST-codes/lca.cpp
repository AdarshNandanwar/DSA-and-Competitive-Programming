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
Node *lca_it(Node *root, int v1,int v2) {
    while (root != NULL) 
    {  
    if (root->data > v1 && root->data > v2) 
       root = root->left;  
    else if (root->data < v1 && root->data < v2) 
       root = root->right; 

    else break; 
    } 
    return root; 
}
 
Node *lca(Node* root, int v1, int v2) 
{ 
    if (root == NULL) return NULL;  
    if (root->data > v1 && root->data > v2) 
        return lca(root->left, v1, v2); 
    if (root->data < v1 && root->data < v2) 
        return lca(root->right, v1, v2); 
  
    return root; 
} 

int main()
{
  Node* root = NULL;
  vector<int> keys={ 15, 8,5,11,9,14,20,35,26,25 };

  for (int key : keys)
    insert(root, key);

    Node* lca1=lca(root,5,20);
    cout<<"LCA of 5,20: "<<lca1->data<<endl;

    cout<<"LCA of 5,9,14: "<<lca_it(root,5,lca_it(root,9,14)->data)->data;
    

  return 0;
}