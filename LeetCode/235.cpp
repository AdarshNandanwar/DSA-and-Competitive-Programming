// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

// Method 1 (Recursion, O(n)):

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr){
            return root;
        }
        if(root == p or root == q){
            return root;
        }
        TreeNode * left = lowestCommonAncestor(root->left, p, q);
        TreeNode * right = lowestCommonAncestor(root->right, p, q);
        if(left and right){
            return root;
        }
        if(left){
            return left;
        }
        if(right){
            return right;
        }
        return nullptr;
    }
};