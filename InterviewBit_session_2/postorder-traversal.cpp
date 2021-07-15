// https://www.interviewbit.com/problems/postorder-traversal/

// Method 1 (Iterative):

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::postorderTraversal(TreeNode* A) {
    vector<int> res;
    stack<TreeNode *> st;
    auto cur = A;
    while(cur){
        res.push_back(cur->val);
        st.push(cur);
        cur = cur->right;
    }
    while(!st.empty()){
        cur = st.top()->left;
        st.pop();
        while(cur){
            res.push_back(cur->val);
            st.push(cur);
            cur = cur->right;
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

// Method 2 (Recursive):

void helper(TreeNode* A, vector<int> &res){
    if(!A) return;
    helper(A->left, res);
    helper(A->right, res);
    res.push_back(A->val);
}
 
vector<int> Solution::postorderTraversal(TreeNode* A) {
    vector<int> res;
    helper(A, res);
    return res;
}