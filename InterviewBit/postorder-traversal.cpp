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
    vector<int> ans;
    if(!A) return ans;
    stack<TreeNode *> st;
    st.push(A);
    while(!st.empty()){
        auto cur = st.top();
        st.pop();
        ans.push_back(cur->val);
        if(cur->left) st.push(cur->left);
        if(cur->right) st.push(cur->right);
    }
    reverse(ans.begin(), ans.end());    // or use a stack and make array by popping
    return ans;
}

// Method 2 (Recursion):

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void trav(TreeNode * root, vector<int> & ans){
    if(root == NULL) return;
    trav(root->left, ans);
    trav(root->right, ans);
    ans.push_back(root->val);
}

vector<int> Solution::postorderTraversal(TreeNode* A) {
    vector<int> ans;
    trav(A, ans);
    return ans;
}
