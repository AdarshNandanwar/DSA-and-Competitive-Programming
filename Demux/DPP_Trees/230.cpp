// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

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
    
    void inOrder(TreeNode* root, int & k, int & res){
        if(root == NULL) return;
        
        inOrder(root->left, k, res);
        if(--k == 0) res = root->val;
        if(k<=0) return;
        inOrder(root->right, k, res);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int res = 0;
        
        // FOLLOW UP: add count to each node and decide left or right while traversal        
        
        inOrder(root, k, res);
        return res;
    }
};