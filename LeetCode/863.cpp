// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void addNodes(TreeNode * root, int d, vector<int> & ans){
        if(!root) return;
        if(d<0) return;
        if(d == 0){
            ans.push_back(root->val);
            return;
        }
        addNodes(root->left, d-1, ans);
        addNodes(root->right, d-1, ans);
    }
    
    int helper(TreeNode * root, TreeNode * target, const int & K, vector<int> & ans){
        if(!root) return -1;
        if(root == target){
            if(K == 0){
                addNodes(root, K, ans);
            } else {
                addNodes(root->left, K-1, ans);
                addNodes(root->right, K-1, ans);
            }
            return 1;
        } 
        int l = helper(root->left, target, K, ans);
        int r = helper(root->right, target, K, ans);
        int h = -1;
        if(l != -1 and l<=K){
            if(l == K) addNodes(root, 0, ans);
            else addNodes(root->right, K-l-1, ans); 
            h = max(h, l+1);
        } 
        if(r != -1 and r<=K){
            if(r == K) addNodes(root, 0, ans);
            else addNodes(root->left, K-r-1, ans); 
            h = max(h, r+1);
        } 
        return h;
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        if(!target) return {};
        vector<int> ans;
        helper(root, target, K, ans);
        return ans;
    }
};