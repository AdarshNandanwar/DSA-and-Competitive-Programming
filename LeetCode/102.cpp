// https://leetcode.com/problems/binary-tree-level-order-traversal/

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ans = {{root->val}};
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            vector<TreeNode *> v;
            while(!q.empty()){
                auto cur = q.front();
                q.pop();
                if(cur->left) v.push_back(cur->left);
                if(cur->right) v.push_back(cur->right);
            }
            vector<int> temp;
            for(auto & i:v){
                q.push(i);
                temp.push_back(i->val);
            } 
            if(temp.size()) ans.push_back(temp);
        }
        return ans;
    }
};