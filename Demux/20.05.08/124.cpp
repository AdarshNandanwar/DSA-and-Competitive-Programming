// https://leetcode.com/problems/binary-tree-maximum-path-sum/

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
    
    int maxSum = INT_MIN;
    
    int helper(TreeNode* root){
        if(!root) return 0;
        int l = helper(root->left);
        int r = helper(root->right);
        maxSum = max(maxSum, root->val + (l>0?l:0) + (r>0?r:0));
        return max(root->val, root->val+max(l, r));
    }
    
    int maxPathSum(TreeNode* root) {
        helper(root);
        return maxSum;
    }
};