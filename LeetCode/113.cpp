// https://leetcode.com/problems/path-sum-ii/

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
     
    void helper(TreeNode* A, int B, vector<int> & cur, vector<vector<int>> & ans){
        if(A == NULL) return;
        if(A->left == NULL and A->right == NULL) {
            if(A->val == B) {
                cur.push_back(A->val);
                ans.push_back(cur);
                cur.pop_back();
            }
            return;
        }
        cur.push_back(A->val);
        helper(A->left, B-A->val, cur, ans);
        helper(A->right, B-A->val, cur, ans);
        cur.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        vector<int> cur;
        helper(root, sum, cur, ans);
        return ans;
    }
};