// https://leetcode.com/problems/unique-binary-search-trees-ii/

// Method 1 (Recursion + DP):

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
    string get_key(int x, int y){
        return to_string(x)+"_"+to_string(y);
    }
    
    vector<TreeNode*> helper(int st, int end, unordered_map<string, vector<TreeNode*>> & dp) {
        if(st > end) return {NULL};
        if(st == end) return {new TreeNode(st)};
        string key = get_key(st, end);
        if(dp.count(key)) return dp[key];
        
        vector<TreeNode *> res;
        for(int i = st; i<=end; i++){
            auto left = helper(st, i-1, dp);
            auto right = helper(i+1, end, dp);
            for(auto & j:left){
                for(auto & k:right){
                    TreeNode * root = new TreeNode(i);
                    root->left = j;
                    root->right = k;
                    res.push_back(root);
                }
            }
        }
        return dp[key] = res;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        unordered_map<string, vector<TreeNode*>> dp;
        return helper(1, n, dp);
    }
};