// https://leetcode.com/problems/balanced-binary-tree/

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
    int getDepth(TreeNode * root, bool & ans){
        if(!root or !ans) return 0;
        int l = getDepth(root->left, ans), r = getDepth(root->right, ans);
        if(abs(l-r) > 1) ans = 0;
        return 1+max(l, r);
    }
    bool isBalanced(TreeNode* root) {
        bool ans = 1;
        getDepth(root, ans);
        return ans;
    }
};