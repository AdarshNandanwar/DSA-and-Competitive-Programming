// https://leetcode.com/problems/binary-tree-preorder-traversal/

// Method 1 (Iterative Method using Stack, O(n)):

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
    
    void pushLeft(TreeNode * root, stack<TreeNode *> &st, vector<int> &res){
        while(root){
            st.push(root);
            res.push_back(root->val);
            root = root->left;
        }
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode *> st;
        pushLeft(root, st, res);
        while(!st.empty()){
            auto cur = st.top();
            st.pop();
            pushLeft(cur->right, st, res);
        }
        return res;
    }
};