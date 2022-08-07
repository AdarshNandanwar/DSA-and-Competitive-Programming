// https://leetcode.com/problems/recover-binary-search-tree/

// Method 1 (Inorder Traversal, O(n) time, O(1) space, O(h) recursion stack space):

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
    void recover(TreeNode * root, TreeNode * & left, TreeNode * & right, TreeNode * & prev){
        if(root == NULL){
            return;
        }
        recover(root->left, left, right, prev);
        if(prev and prev->val > root->val){
            if(left == NULL){
                left = prev;
                right = root;
            } else {
                right = root;
            }
        }
        prev = root;
        recover(root->right, left, right, prev);
    }
    
    void recoverTree(TreeNode* root) {
        TreeNode * left = NULL, * right = NULL, * prev = NULL;
        recover(root, left, right, prev);
        swap(left->val, right->val);
    }
};