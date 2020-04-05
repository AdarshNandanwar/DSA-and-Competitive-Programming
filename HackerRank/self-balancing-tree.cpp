#include <bits/stdc++.h>
using namespace std;

struct node{
    int val, ht;
    node * right, * left;
    node(){};
    node(int val):val(val), left(NULL), right(NULL), ht(0){};
};

int getHeight(node * root){
    if(root == NULL){
        return -1;
    }
    return root->ht;
}

int getBalance(node * root){
    if (root == NULL){
        return 0;
    }
    return getHeight(root->left)-getHeight(root->right);
}

node * rotateLeft(node * root){
    node * right = root->right;
    root->right = right->left;
    right->left = root;
    right->ht = 1+max(getHeight(right->left), getHeight(right->right));
    root->ht = 1+max(getHeight(root->left), getHeight(root->right));
    return right;
}

node * rotateRight(node * root){
    node * left = root->left;
    root->left = left->right;
    left->right = root;
    left->ht = 1+max(getHeight(left->left), getHeight(left->right));
    root->ht = 1+max(getHeight(root->left), getHeight(root->right));
    return left;
}

node * insert(node * root, int val){
    if(root == NULL){
        root = new node();
        root->val = val;
        root->left = NULL;
        root->right = NULL;
        root->ht = 0;
        return root;
    }
    if(val < root->val){
        root->left = insert(root->left, val);
    } else if(root->val < val){
        root->right = insert(root->right, val);
    } else {
        return root;
    }
    
    if(getBalance(root) > 1 && val < root->left->val){
        root = rotateRight(root);
    }
    else if(getBalance(root) > 1 && val > root->left->val){
        root->left = rotateLeft(root->left);
        root = rotateRight(root);
    }
    else if(getBalance(root) < -1 && val < root->right->val){
        root->right = rotateRight(root->right);
        root = rotateLeft(root);
    }
    else if(getBalance(root) < -1 && val > root->right->val){
        root = rotateLeft(root);
    }

    root->ht = 1+max(getHeight(root->left), getHeight(root->right));

    return root;
}

void inOrder(node * root){
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->val<<" ";
    inOrder(root->right);
}

void preOrder(node * root){
    if(root == NULL){
        return;
    }
    cout<<root->val<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
 
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    node * root = NULL;

    int n;
    cin>>n;
    while(n--){
        int val;
        cin>>val;
        root = insert(root, val);
    }
    cout<<root->val<<" "<<root->ht<<endl;
    preOrder(root);
    cout<<endl;
    inOrder(root);

    return 0;
}