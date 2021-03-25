// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

// Method 1 (My):

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
    
    TreeNode* helper(TreeNode * root){
        if(!root->left and !root->right) return root;
        TreeNode * leftLast = root, * rightLast = root;
        if(root->left) leftLast = helper(root->left);
        if(root->right) rightLast = helper(root->right);
        leftLast->right = root->right;
        if(leftLast != root) root->right = root->left; 
        root->left = NULL;
        return rightLast == root ? leftLast : rightLast;
    }
    
    void flatten(TreeNode* root) {
        if(root) root = helper(root);
    }
};

// Method 2:

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
    
    TreeNode* prev = NULL;
    
    void flatten(TreeNode* root) {
        if(!root) return;
        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        root->left = NULL;
        prev = root;
    }
};