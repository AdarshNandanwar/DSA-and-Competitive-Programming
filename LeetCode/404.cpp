// https://leetcode.com/problems/sum-of-left-leaves/

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
    int helper(TreeNode* root, bool isLeft){
        if(root == NULL) return 0;
        if(root->left == NULL and root->right == NULL) return isLeft ? root->val : 0;
        int res = 0;
        if(root->left) res += helper(root->left, 1);
        if(root->right) res += helper(root->right, 0);
        return res;
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        return helper(root, 0);
    }
};