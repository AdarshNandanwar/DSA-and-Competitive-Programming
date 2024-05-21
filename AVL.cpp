#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    int ht;
    TreeNode * left;
    TreeNode * right;

    TreeNode(int val): val(val), ht(1), left(nullptr), right(nullptr) {};
};

int getHeight(TreeNode * root){
    return root == nullptr ? 0 : root->ht;
}

TreeNode * rotateRight(TreeNode * root){
    TreeNode * left = root->left;
    root->left = left->right;
    left->right = root;
    root->ht = 1 + max(getHeight(root->left), getHeight(root->right));
    left->ht = 1 + max(getHeight(left->left), getHeight(left->right));
    return left;
}

TreeNode * rotateLeft(TreeNode * root){
    TreeNode * right = root->right;
    root->right = right->left;
    right->left = root;
    root->ht = 1 + max(getHeight(root->left), getHeight(root->right));
    right->ht = 1 + max(getHeight(right->left), getHeight(right->right));
    return right;
}

int getBalanceFactor(TreeNode * root){
    if(root == nullptr){
        return 0;
    }
    return getHeight(root->left) - getHeight(root->right);
}

TreeNode * insert(TreeNode * root,int val)
{
    if(root == nullptr){
        return new TreeNode(val);
    }

    if(val <= root->val){
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    root->ht = 1 + max(getHeight(root->left), getHeight(root->right));

    int balanceFactor = getBalanceFactor(root);
    if(abs(balanceFactor) > 1){
        // Imbalance
        if(val <= root->val){
            if(val <= root->left->val){
                // LL-imbalance
                root = rotateRight(root);
            } else {
                // LR-imbalance
                root->left = rotateLeft(root->left);
                root = rotateRight(root);
            }
        } else {
            if(val <= root->right->val){
                // RL-imbalance
                root->right = rotateRight(root->right);
                root = rotateLeft(root);
            } else {
                // RR-imbalance
                root = rotateLeft(root);
            }
        }
    }
    return root;  
}

void inorder(TreeNode * root){
    if(root == nullptr){
        return;
    }
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

void preorder(TreeNode * root){
    if(root == nullptr){
        return;
    }
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    TreeNode * root = nullptr;
    root = insert(root, 3);
    inorder(root); cout<<endl;
    preorder(root);cout<<endl;
    root = insert(root, 2);
    inorder(root); cout<<endl;
    preorder(root);cout<<endl;
    root = insert(root, 4);
    inorder(root); cout<<endl;
    preorder(root);cout<<endl;
    root = insert(root, 5);
    inorder(root); cout<<endl;
    preorder(root);cout<<endl;
    root = insert(root, 6);    
    inorder(root); cout<<endl;
    preorder(root);cout<<endl;
}