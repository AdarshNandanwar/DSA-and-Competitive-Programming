// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

// Method 1 (Global Variable):

class Solution {
public:
    
    TreeNode * prev = NULL;
    
    void flatten(TreeNode* root) {
        
        // traversal: 6, 5, 4, 3, 2, 1, 
        // We just link cur node to prev node

        if(!root) return;
        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        root->left = NULL;
        prev = root;
    }
};

// Method 2 (Brute Force):

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
    void flatten(TreeNode* root) {
        if(!root) return;
        flatten(root->right);
        auto cur = root->left;
        if(!cur) return;
        flatten(root->left);
        while(cur->right) cur = cur->right;
        cur->right = root->right;
        root->right = root->left;
        root->left = NULL;
    }
};