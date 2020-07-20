// https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/

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
    
    long long totalSum = 0;
    unordered_map<TreeNode *, long long> dp;
    
    long long calculateSum(TreeNode * root){
        if(!root) return 0ll;
        long long sum = root->val;
        sum += calculateSum(root->left);
        sum += calculateSum(root->right);
        return dp[root] = sum;
    }
    
    int maxProduct(TreeNode* root) {
        long long prod = -1;
        totalSum = calculateSum(root);
        for(auto [i,j]:dp) prod = max(prod, j*(totalSum-j));
        return (int)(prod%(1000000007));
    }
};