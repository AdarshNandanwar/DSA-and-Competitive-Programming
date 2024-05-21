// https://leetcode.com/problems/sum-root-to-leaf-numbers/

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
    int helper(TreeNode * root, int pathNum){
        if(root == nullptr){
            return 0;
        }
        int curPathNum = pathNum*10 + root->val;
        if(root->left == nullptr and root->right == nullptr){
            return curPathNum;
        }
        int leftSum = helper(root->left, curPathNum);
        int rightSum = helper(root->right, curPathNum);
        return leftSum + rightSum;
    }
public:
    int sumNumbers(TreeNode* root) {
        return helper(root, 0);
    }
};

// Alternate Code:

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
    
    void helper(TreeNode * root, int cur, int & ans){
        if(!root) return;
        int val = cur*10+root->val;
        if(!root->left and !root->right){
            ans += val;
            return;
        }
        if(root->left) helper(root->left, val, ans);
        if(root->right) helper(root->right, val, ans);
    }
    
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        helper(root, 0, ans);
        return ans;
    }
};