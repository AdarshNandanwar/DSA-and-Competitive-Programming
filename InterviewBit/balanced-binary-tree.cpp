// https://www.interviewbit.com/problems/balanced-binary-tree/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
int getDepth(TreeNode * root, bool & ans){
    if(!root or !ans) return 0;
    int l = getDepth(root->left, ans), r = getDepth(root->right, ans);
    if(abs(l-r) > 1) ans = 0;
    return 1+max(l, r);
}
 
int Solution::isBalanced(TreeNode* A) {
    bool ans = 1;
    getDepth(A, ans);
    return ans;
}
