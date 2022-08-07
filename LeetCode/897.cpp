// https://leetcode.com/problems/increasing-order-search-tree/

// Method 1 (Recursion, Global prev pointer, O(n)):

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
    void helper(TreeNode * root, TreeNode * & prev) {
        if(root == NULL){
            return;
        }
        helper(root->right, prev);
        root->right = prev;
        prev = root;
        helper(root->left, prev);
        root->left = NULL;
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode * prev = NULL;
        helper(root, prev);
        return prev;
    }
};