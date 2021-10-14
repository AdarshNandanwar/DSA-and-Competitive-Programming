// https://leetcode.com/problems/diameter-of-binary-tree/

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
    
    // returns depth of subtree
    int helper(TreeNode* root, int & ans){
        if(!root) return 0;
        int l = helper(root->left, ans);
        int r = helper(root->right, ans);
        ans = max(ans, l+r);
        return 1+max(l, r);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        helper(root, ans);
        return ans;
    }
};