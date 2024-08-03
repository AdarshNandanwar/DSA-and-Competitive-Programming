// https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/

// Method 1 (Stack, O(n)):

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
    void pushRight(stack<TreeNode *> & st, TreeNode * root){
        while(root){
            st.push(root);
            root = root->right;
        }
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        stack<TreeNode *> st;
        pushRight(st, root);
        int sum = 0;
        while(!st.empty()){
            TreeNode * cur = st.top();
            st.pop();
            sum += cur->val;
            cur->val = sum;
            pushRight(st, cur->left);
        }
        return root;
    }
};
