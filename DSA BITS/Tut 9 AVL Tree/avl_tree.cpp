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

int inOrderSuccessor(node * root){
    // if(!root || !root->right)
    //     return -1;
    node * curr = root->right;
    while(curr->left)
        curr = curr->left;
    return curr->val;
}

node * deleteNode(node * root, int val){
    if(root == NULL){
        return root;
    }
    if(val < root->val){
        root->left = deleteNode(root->left, val);
    } else if(root->val < val){
        root->right = deleteNode(root->right, val);
    } else {
        if(root->left){
            if(root->right){
                int successor = inOrderSuccessor(root);
                root->val = successor;
                root->right = deleteNode(root->right, successor);
            } else {
                root = root->left;
            }
        } else {
            if(root->right){
                root = root->right;
            } else {
                root = NULL;
            }
        }
    }
    
    // If root is deleted
    if(root == NULL)
        return NULL;

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

void levelOrder(node * root){
    if(root == NULL){
        return;
    }
    queue<node *> q;
    q.push(root);
    while(!q.empty()){
        cout<<q.front()->val<<" ";
        if(q.front()->left){
            q.push(q.front()->left);
        }
        if(q.front()->right){
            q.push(q.front()->right);
        }
        q.pop();
    }
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
    levelOrder(root);
    
    int del_count;
    cin>>del_count;
    while(del_count--){
        int data;
        cin>>data;
        root = deleteNode(root, data);
    }
    levelOrder(root);
    return 0;
}