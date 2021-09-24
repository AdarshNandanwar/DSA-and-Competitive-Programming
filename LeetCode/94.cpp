// https://leetcode.com/problems/binary-tree-inorder-traversal/

// Method 1 (Recursive, O(n)):

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
    void helper(TreeNode * root, vector<int> &res){
        if(root == NULL) return;
        helper(root->left, res);
        res.push_back(root->val);
        helper(root->right, res);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        helper(root, res);
        return res;
    }
};


// Method 2 (Iterative, O(n)):

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode *> st;
        auto cur = root;
        while(cur){
            st.push(cur);
            cur = cur->left;
        }
        while(!st.empty()){
            auto cur = st.top();
            st.pop();
            res.push_back(cur->val);
            cur = cur->right;
            while(cur){
                st.push(cur);
                cur = cur->left;
            }
        }
        return res;
    }
};