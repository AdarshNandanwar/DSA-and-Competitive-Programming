// https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/

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

class Info{
    public:
    bool isBST;
    int sum, minVal, maxVal;
    Info(){
        isBST = true;
        sum = 0;
        minVal = INT_MAX;
        maxVal = INT_MIN;
    }
};

Info helper(TreeNode * root, int & maxSum){
    Info res;
    if(!root){
        return res;
    }
    Info l = helper(root->left, maxSum);
    Info r = helper(root->right, maxSum);
    res.isBST = (l.isBST and r.isBST and root->val>l.maxVal and root->val<r.minVal);
    if(!root->left){
        res.minVal = root->val;
    }
    if(!root->right){
        res.maxVal = root->val;
    }
    if(res.isBST){
        res.minVal = min(l.minVal, root->val);
        res.maxVal = max(r.maxVal, root->val);
        res.sum = root->val + l.sum + r.sum;
    } else {
        res.sum = max(l.sum, r.sum);
    }
    maxSum = max(maxSum, res.sum);
    return res;
}


class Solution {
public:
    int maxSumBST(TreeNode* root) {
        int maxSum = 0;
        helper(root, maxSum);
        return maxSum;
    }
};