#include <bits/stdc++.h>
using namespace std;

// definition of Node. Note the variable for height. It will be used to calculate the balance at the nodes
struct Node
{
    int data;
    int height;
    Node* left;
    Node* right;
    Node(int val)
    {
        data = val;
        height = 1;
        left = NULL;
        right = NULL;
    }
};

int height( Node* root )        // getter function for height of node
{
    if( root == NULL )          // base case
        return 0;
    return root->height;
}
 
Node* rightRotate( Node* root )   
{
    Node* l = root->left;
    Node* r = l->right;
 
    l->right = root;            
    root->left = r;
    
    // updating heights for nodes that have been affected by rotation

    root->height = max( height(root->left), height(root->right) ) + 1;
    l->height = max( height(l->left), height(l->right) ) + 1;

    return l;
}
 
Node* leftRotate( Node* root )
{
    Node* r = root->right;
    Node* l = r->left;  

    r->left = root;
    root->right = l;
    
    // updating heights for nodes that have been affected by rotation
 
    root->height = max( height(root->left), height(root->right) ) + 1;
    r->height = max( height(r->left), height(r->right) ) + 1;
    return r;
}
 
int getBalance( Node* root )
{
    if( root == NULL )
        return 0;
    return height(root->left) - height(root->right);
}
 
Node* insert( Node* root, int val )
{
    // base case
    if( root == NULL )
    {
        Node* tmp = new Node(val);
        return tmp;
    }
    
    // first we go down the tree to find the right place to insert val. To do this, 
    // If the value in current node is less than val, it must be inserted to the right of this node.
    // So we recusively call insert for root->right.
    //  (line 83) Since the insert function call returns the root of a balanced tree, we replace root->right with the return value
    // Similarly for left.

    if( val < root->data )
        root->left = insert(root->left,val);
    else if( val > root->data )
        root->right = insert(root->right,val);
    else
        return root;    // only possible when the value to be inserted is already present in the tree
    
    // we now need to update the height of this node since the left or right subtree may have changed when adding the new node
    root->height = 1 + max( height(root->left), height(root->right) );

    // here we know that the value has been inserted in its place and the left and right subtrees of this node are balanced.
    // we need to ensure that the subtree rooted at this node is also balanced.
    
    // rotations to balance the subtree rooted at this node 

    int bal = getBalance(root);
    

    //Left Left
    if( bal > 1 && val < root->left->data )
    {
        return rightRotate(root);
    }
 
    //Right Right
    if( bal < -1 && val > root->right->data )
    {
        return leftRotate(root);
    }
 
    //Left Right
    if( bal > 1 && val > root->left->data )
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
 
    //Right Left
    if( bal < -1 && val < root->right->data )
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
 
    return root;
}
 
Node* minValueNode(Node* node)  
{   
    while (node->left != NULL)  
        node = node->left;  
  
    return node;  
}  

Node* deleteNode(Node* root, int val)  
{  
    // no node with value val
    if (root == NULL)  
        return root;    

    // to delete the element, we first need to locate it in the tree. 
    // Similar to the insert function, we compare the val with this node's value, and move to the left or right accordingly
    // (line 146) also note that we assign the return value of delete function (root of a balanced tree) to root->left
  
    if ( val < root->data )  
        root->left = deleteNode(root->left, val);  
    else if( val > root->data )  
        root->right = deleteNode(root->right, val);  
    else
    {  
        // we have found the node to be deleted

        // we need to delete the node and find the node that takes its place.
        // if either right or left child is null, we directly pick the non-null child to replace the current node

        if( (root->left == NULL) || (root->right == NULL) )  
        {  
            Node *temp;
            if(root->left == NULL)
                temp = root->right;
            else
                temp = root->left;

            if (temp == NULL)  
            {  
                temp = root;  
                root = NULL;  
            }  
            else  
                *root = *temp; 
        } 

        // if both children are non-null, as done in BST, we find the node that has a value just greater that this node's value
        // minValueNode will find such a node, lets call it temp
        // we replace the value in this node with the value in temp since doing this preserves the properties of BST
        // since now we have two nodes with value = temp's value (temp, and this node), we have to delete temp now

        else
        {
            Node* temp = minValueNode(root->right);  
            root->data = temp->data;  
            
            root->right = deleteNode(root->right, temp->data);  
        }  
    }  
    
    // this is the case when a leaf node is deleted
    // we dont need to check balance as the subtree is empty,  so we can return directly
    if (root == NULL)  
        return root;  
    
    // once we reach here, the appropriate node has been deleted and the left and right subtrees of this node are balanced.
    // we have to ensure that this node is balanced so We perform the rotations to balance the subtree. 
    // as done in insert operation

    root->height = 1 + max( height(root->left), height(root->right) );
 
    int bal = getBalance(root);
 
    //Left Left
    if( bal > 1 && val < root->left->data )
    {
        return rightRotate(root);
    }
 
    //Right Right
    if( bal < -1 && val > root->right->data )
    {
        return leftRotate(root);
    }
 
    //Left Right
    if( bal > 1 && val > root->left->data )
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
 
    //Right Left
    if( bal < -1 && val < root->right->data )
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
 
    return root; 
}  


Node* find( Node* root, int val )
{
    Node* temp = root;
    while( temp != NULL )
    {
        if( val == temp->data )
            return temp;
        if( val > temp->data )
            temp = temp->right;
        else
            temp = temp->left;
    }
    return NULL;
}
 
void preorder( Node* root )
{
    if( root == NULL )
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}


int main()
{
    Node* root = NULL;

    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 2);
    root = insert(root, 6);
    root = insert(root, 1);
    root = insert(root, 4);
    
    preorder(root);
    cout<<endl;

    root = deleteNode(root, 5);

    preorder(root);

    return 0;
}