// https://leetcode.com/problems/path-sum-iii/

// Method 1 (O(n)):

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
    
    void helper(TreeNode* root, int & sum, int curSum, unordered_map<int, int> & prefixSum, int & ans){
        if(root == NULL) return;
        if(prefixSum.count(curSum+root->val-sum)) ans += prefixSum[curSum+root->val-sum];
        prefixSum[curSum+root->val]++;
        helper(root->left, sum, curSum+root->val, prefixSum, ans);
        helper(root->right, sum, curSum+root->val, prefixSum, ans);
        prefixSum[curSum+root->val]--;
        if(prefixSum[curSum+root->val] == 0) prefixSum.erase(curSum+root->val);
    }
    
    int pathSum(TreeNode* root, int sum) {
        int ans = 0;
        unordered_map<int, int> prefixSum;
        prefixSum[0]++;
        helper(root, sum, 0, prefixSum, ans);
        return ans;
    }
};

// Method 2 (O(nlogn)):

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
    
    void helper(TreeNode* root, int & sum, vector<int> & prevSum, int & ans){
        if(root == NULL) return;
        for(auto & i:prevSum) i+= root->val;
        prevSum.push_back(root->val);
        for(auto i:prevSum) ans += (i==sum);
        helper(root->left, sum, prevSum, ans);
        helper(root->right, sum, prevSum, ans);
        prevSum.pop_back();
        for(auto & i:prevSum) i-= root->val;
    }
    
    int pathSum(TreeNode* root, int sum) {
        int ans = 0;
        vector<int> prevSum;
        helper(root, sum, prevSum, ans);
        return ans;
    }
};