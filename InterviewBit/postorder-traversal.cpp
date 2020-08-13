// https://www.interviewbit.com/problems/postorder-traversal/

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
