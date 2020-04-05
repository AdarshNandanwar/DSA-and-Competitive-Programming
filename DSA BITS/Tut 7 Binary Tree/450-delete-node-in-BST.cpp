// https://leetcode.com/problems/delete-node-in-a-bst/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    int inOrderSuccessor(TreeNode * root){
        while(root->left != NULL){
            root = root->left;
        }
        return root->val;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL){
            return NULL;
        }
        if(key < root->val){
            root->left = deleteNode(root->left, key);
        } else if(root->val < key){
            root->right = deleteNode(root->right, key);
        } else {
            if(root->left == NULL){
                if(root->right == NULL){
                    root = NULL;
                } else {
                    root = root->right;
                }
            } else {
                if(root->right == NULL){
                    root = root->left;
                } else {
                    int successor = inOrderSuccessor(root->right);
                    root->val = successor;
                    root->right = deleteNode(root->right, successor);
                }
            }
        }
        return root;
    }
};