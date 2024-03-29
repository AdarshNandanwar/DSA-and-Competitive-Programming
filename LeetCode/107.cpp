// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            vector<int> v;
            for(int i = 0; i<sz; i++){
                auto t = q.front();
                v.push_back(t->val);
                q.pop();
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            res.push_back(v);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};