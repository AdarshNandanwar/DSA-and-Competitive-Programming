// https://leetcode.com/problems/add-one-row-to-tree/

// Method 1 (Recursion, Dummy Pointer, O(n)):

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
    TreeNode * helper(TreeNode * root, const int & val, int depth){
        if(root == nullptr){
            return root;
        }
        if(depth == 1){
            TreeNode * res = new TreeNode(root->val);
            res->left = new TreeNode(val, root->left, nullptr);
            res->right = new TreeNode(val, nullptr, root->right);
            return res;
        } else {
            root->left = helper(root->left, val, depth-1);
            root->right = helper(root->right, val, depth-1);
            return root;
        }
    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        TreeNode * dummy = new TreeNode (0, root, nullptr);
        dummy = helper(dummy, val, depth);
        return dummy->left;
    }
};