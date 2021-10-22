// https://leetcode.com/problems/cousins-in-binary-tree/

// Method 1 (DFS, O(n)):

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
    void helper(TreeNode * root, const int & x, const int & y, int depth, int parent, int & hx, int & hy, int & px, int & py){
        if(!root) return;
        if(root->val == x){
            hx = depth;
            px = parent;
        } 
        if(root->val == y){
            hy = depth;
            py = parent;
        } 
        helper(root->left, x, y, depth+1, root->val, hx, hy, px, py);
        helper(root->right, x, y, depth+1, root->val, hx, hy, px, py);
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        int hx = -1, hy = -2, px = -3, py = -4;
        helper(root, x, y, 0, -1, hx, hy, px, py);
        return hx == hy and px != py;
    }
};