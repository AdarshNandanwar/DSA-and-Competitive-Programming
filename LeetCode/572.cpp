// https://leetcode.com/problems/subtree-of-another-tree/description/

// Method 1 (Recursive, O(n*m)):

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
    bool exactMatch(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr or subRoot == nullptr){
            return root == subRoot;
        }
        if(root->val == subRoot->val){
            return exactMatch(root->left, subRoot->left) and exactMatch(root->right, subRoot->right);
        }
        return false;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot == nullptr){
            return true;
        }
        if(root == nullptr){
            return false;
        }
        return exactMatch(root, subRoot) or isSubtree(root->left, subRoot) or isSubtree(root->right, subRoot);
    }
};