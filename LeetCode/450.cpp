// https://leetcode.com/problems/delete-node-in-a-bst/

// Method 1 (Recursion, O(logn)):

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool found = false;
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(found or !root) return root;
        if(root->val == key){
            found = true;
            if(root->left){
                auto cur = root->left;
                while(cur->right) cur = cur->right;
                cur->right = root->right;
                root->right = NULL;
                return root->left;
            } else {
                return root->right;
            }
        } else {
            if(root->val < key) root->right = deleteNode(root->right, key);
            else root->left = deleteNode(root->left, key);
            return root;
        }
    }
};

// Method 2 (In order successor, O(log(n))):

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