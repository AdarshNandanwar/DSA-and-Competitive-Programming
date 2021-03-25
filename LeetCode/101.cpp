// https://leetcode.com/problems/symmetric-tree/

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
    bool isMirror(TreeNode* a, TreeNode* b){
        if(a == NULL) return b == NULL;
        if(b == NULL) return a == NULL;
        if(a->val != b->val) return 0;
        if(!isMirror(a->left, b->right)) return  0;
        if(!isMirror(a->right, b->left)) return  0;
        return 1;
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return 1;
        return isMirror(root->left, root->right);
    }
};