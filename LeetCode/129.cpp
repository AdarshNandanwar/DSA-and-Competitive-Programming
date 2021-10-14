// https://leetcode.com/problems/sum-root-to-leaf-numbers/

// Method 1 (Recursion, O(n)):

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
    
    void helper(TreeNode * root, int cur, int & ans){
        if(!root) return;
        int val = cur*10+root->val;
        if(!root->left and !root->right){
            ans += val;
            return;
        }
        if(root->left) helper(root->left, val, ans);
        if(root->right) helper(root->right, val, ans);
    }
    
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        helper(root, 0, ans);
        return ans;
    }
};