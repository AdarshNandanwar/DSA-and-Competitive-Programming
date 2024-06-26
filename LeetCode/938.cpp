// https://leetcode.com/problems/range-sum-of-bst/description/

// Method 1 (Recursion, o(n)):

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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root == nullptr){
            return 0;
        }
        int sum = 0;
        if(root->val < low){
            sum += rangeSumBST(root->right, low, high);
        } else if(low <= root->val and root->val <= high){
            sum += rangeSumBST(root->left, low, high);
            sum += root->val;
            sum += rangeSumBST(root->right, low, high);
        } else if(high < root->val){
            sum += rangeSumBST(root->left, low, high);
        }
        return sum;
    }
};