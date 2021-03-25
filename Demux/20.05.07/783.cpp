// https://leetcode.com/problems/minimum-distance-between-bst-nodes/

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
    
    void inOrderPredecessor(TreeNode * root, TreeNode * & predecessor, int &res){
        if(!root) return;
        
        inOrderPredecessor(root->left, predecessor, res);
        
        if(predecessor) 
            res = min(res, root->val - predecessor->val);
        predecessor = root;
        cout<<res<<" ";
        
        inOrderPredecessor(root->right, predecessor, res);
    }
    
    int minDiffInBST(TreeNode* root) {
        int ans = INT_MAX;
        TreeNode * predecessor = NULL;
        inOrderPredecessor(root, predecessor, ans);
        return ans;
    }
};