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
 
void trav(TreeNode * root, vector<int> & ans){
    if(root == NULL) return;
    ans.push_back(root->val);
    trav(root->left, ans);
    trav(root->right, ans);
}

vector<int> Solution::preorderTraversal(TreeNode* A) {
    vector<int> ans;
    trav(A, ans);
    return ans;
}
