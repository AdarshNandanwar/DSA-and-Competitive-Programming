// https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/

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
    
    int maxLen = 0;
    
    // <left, right>
    pair<int, int> helper(TreeNode * root){
        if(!root) return {0, 0};
        pair<int, int> res = {0, 0};
        if(root->left) res.first = 1+helper(root->left).second;
        if(root->right) res.second = 1+helper(root->right).first;
        maxLen = max(maxLen, max(res.first, res.second));
        return res;
    }
    
    int longestZigZag(TreeNode* root) {
        helper(root);
        return maxLen;
    }
};