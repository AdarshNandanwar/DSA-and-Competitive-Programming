// https://leetcode.com/problems/binary-tree-cameras/

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
    
    int helper(TreeNode* root, bool p, bool gp, unordered_map<TreeNode *, vector<vector<int>>> & dp) {
        if(root == NULL) return !(p or gp);
        
        if(dp.count(root)){
            if(dp[root][p][gp] != -1) return dp[root][p][gp];
        } else {
            dp[root] = {{-1, -1}, {-1, -1}};
        }
        int res = INT_MAX;
        
        // place camera
        res = min(res, 1+helper(root->left, true, p, dp)+helper(root->right, true, p, dp));
        
        // don't place camera
        if(p or gp){
            // let left child cover this
            res = min(res, helper(root->left, false, p, dp)+helper(root->right, false, true, dp));
            // let right child cover this
            res = min(res, helper(root->left, false, true, dp)+helper(root->right, false, p, dp));
        }
        
        return dp[root][p][gp] = res;
    }
    
    int minCameraCover(TreeNode* root) {
        // p : parent has camera, gp : grandparent has camera
        unordered_map<TreeNode *, vector<vector<int>>> dp;
        return helper(root, false, true, dp);
    }
};