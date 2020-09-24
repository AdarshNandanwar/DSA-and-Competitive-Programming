// https://leetcode.com/problems/count-good-nodes-in-binary-tree/

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
    
    int helper(TreeNode * root, int maxTillNow){
        if(!root) return 0;
        int res = root->val >= maxTillNow;
        maxTillNow = max(maxTillNow, root->val);
        res += helper(root->left, maxTillNow);
        res += helper(root->right, maxTillNow);
        return res;
    }
    
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        return helper(root, root->val);
    }
};