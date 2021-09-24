// https://leetcode.com/problems/minimum-depth-of-binary-tree/

// Method 1 (Recursive, O(n)):

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
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;  // empty tree
        if(!root->left and !root->right) return 1;
        int res = INT_MAX;
        if(root->left) res = min(res, 1+minDepth(root->left));
        if(root->right) res = min(res, 1+minDepth(root->right));
        return res;
    }
};