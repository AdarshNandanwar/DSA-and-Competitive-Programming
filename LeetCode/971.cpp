// https://leetcode.com/problems/flip-binary-tree-to-match-preorder-traversal/

// Method (Verbose):

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
    // [st,end)
    vector<int> helper(TreeNode * root, int st, int end, vector<int> & voyage, vector<int> & size){
        
        if(root->val != voyage[st] or size[root->val] != end-st) return {-1};
        
        vector<int> res = {-1}, res1 = {}, res2 = {};
        
        int left_size = 0, right_size = 0;
        if(root->left) left_size = size[root->left->val];
        if(root->right) right_size = size[root->right->val];
        
        if(root->left) res1 = helper(root->left, st+1, st+1+left_size, voyage, size);
        if(root->right) res2 = helper(root->right, st+1+left_size, end, voyage, size);
        
        if(res1 != res and res2 != res){
            res = res1;
            res.insert(res.end(), res2.begin(), res2.end());
            return res;
        }
        
        if(root->right) res1 = helper(root->right, st+1, st+1+right_size, voyage, size);
        if(root->left) res2 = helper(root->left, st+1+right_size, end, voyage, size);
        
        if(res1 != res and res2 != res){
            res = res1;
            res.insert(res.end(), res2.begin(), res2.end());
            res.push_back(root->val);
            return res;
        }    
        
        return res;
    }
    
    int find_size(TreeNode* root, vector<int> & size){
        if(root == NULL) return 0;
        return size[root->val] = 1+find_size(root->left, size)+find_size(root->right, size);
    }
    
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        int n = voyage.size();
        vector<int> size(n+1, 0);
        find_size(root, size);
        return helper(root, 0, n, voyage, size);
        
    }
};