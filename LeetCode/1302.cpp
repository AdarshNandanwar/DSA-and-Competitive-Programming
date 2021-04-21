// https://leetcode.com/problems/deepest-leaves-sum/

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
    
    void helper(TreeNode* root, int level, int & deepest_level, int & ans){
        if(!root) return;
        if(level > deepest_level){
            ans = 0;
            deepest_level = level;
        }
        if(level == deepest_level){
            ans += root->val;
        }
        helper(root->left, level+1, deepest_level, ans);
        helper(root->right, level+1, deepest_level, ans);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        int deepest_level = 0, ans = 0;
        helper(root, 0, deepest_level, ans);
        return ans;
    }
};