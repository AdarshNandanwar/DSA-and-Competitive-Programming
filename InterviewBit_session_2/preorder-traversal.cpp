// https://www.interviewbit.com/problems/preorder-traversal/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::preorderTraversal(TreeNode* A) {
    vector<int> res;
    stack<TreeNode *> st;
    auto cur = A;
    while(cur){
        res.push_back(cur->val);
        st.push(cur);
        cur = cur->left;
    }
    while(!st.empty()){
        cur = st.top()->right;
        st.pop();
        while(cur){
            res.push_back(cur->val);
            st.push(cur);
            cur = cur->left;
        }
    }
    return res;
}
