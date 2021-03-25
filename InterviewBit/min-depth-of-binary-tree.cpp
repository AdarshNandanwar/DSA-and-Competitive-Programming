// https://www.interviewbit.com/problems/min-depth-of-binary-tree/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::minDepth(TreeNode* A) {
    if(A == NULL) return 0;
    if(A->left == NULL and A->right == NULL) return 1;
    int res = INT_MAX;
    if(A->left) res = min(res, minDepth(A->left));
    if(A->right) res = min(res, minDepth(A->right));
    return res+1;
}
