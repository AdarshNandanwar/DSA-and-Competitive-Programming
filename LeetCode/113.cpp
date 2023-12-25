// https://leetcode.com/problems/path-sum-ii/

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
    void helper(TreeNode * root, int targetSum, vector<int> & path, vector<vector<int>> & ans){
        if(root == nullptr){
            return;
        }
        path.push_back(root->val);
        if(root->left==nullptr and root->right==nullptr and targetSum==root->val){
            ans.push_back(path);
        }
        helper(root->left, targetSum-root->val, path, ans);
        helper(root->right, targetSum-root->val, path, ans);
        path.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        helper(root, targetSum, path, ans);
        return ans;
    }
};