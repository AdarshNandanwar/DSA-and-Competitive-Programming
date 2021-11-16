// https://leetcode.com/problems/count-complete-tree-nodes/

// Method 1 (Binary Recursion, O((logn)^2)):

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
    int height(TreeNode * root){
        if(!root) return 0;
        return 1+height(root->left);
    }
    
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int res;
        int hLeft = height(root->left);
        int hRight = height(root->right);
        if(hLeft == hRight){
            res = 1+(1<<hLeft)-1+countNodes(root->right);
        } else {
            res = 1+(1<<hRight)-1+countNodes(root->left);
        }
        return res;
    }
};

// Method 2 (Recursion, O(n)):

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
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};