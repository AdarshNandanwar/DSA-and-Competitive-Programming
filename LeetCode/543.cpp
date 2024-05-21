// https://leetcode.com/problems/diameter-of-binary-tree/

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
    int getLongestPathLengthToRoot(TreeNode* root, int& diameter){
        if(root == nullptr){
            return 0;
        }
        int leftPath = getLongestPathLengthToRoot(root->left, diameter);
        int rightPath = getLongestPathLengthToRoot(root->right, diameter);
        diameter = max(diameter, leftPath + rightPath);
        return 1 + max(leftPath, rightPath);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        getLongestPathLengthToRoot(root, diameter);
        return diameter;
    }
};