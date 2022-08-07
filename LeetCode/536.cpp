// https://leetcode.com/problems/binary-tree-tilt/

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
    
    // {sum, tilt}
    pair<int, int> helper(TreeNode * root){
        if(!root) return {0, 0};
        auto l = helper(root->left);
        auto r = helper(root->right);
        return {l.first + r.first + root->val, l.second + r.second + abs(l.first-r.first)};
    }
    int findTilt(TreeNode* root) {
        return helper(root).second;
    }
};