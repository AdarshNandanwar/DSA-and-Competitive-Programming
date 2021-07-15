// https://www.interviewbit.com/problems/inorder-traversal/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 
vector<int> Solution::inorderTraversal(TreeNode* A) {
    vector<int> res;
    stack<TreeNode*> st;
    TreeNode* cur = A;
    while(cur){
        st.push(cur);
        cur = cur->left;
    }
    while(!st.empty()){
        cur = st.top();
        st.pop();
        res.push_back(A->val);
        cur = cur->right;
        while(cur){
            st.push(cur);
            cur = cur->left;
        }
    }
    
    return res;
}
