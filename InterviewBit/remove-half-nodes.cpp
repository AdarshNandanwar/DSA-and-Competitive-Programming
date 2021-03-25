// https://www.interviewbit.com/problems/remove-half-nodes/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
TreeNode* Solution::solve(TreeNode* A) {
    if(A == NULL) return A;
    if(A->left and A->right){
        A->left = solve(A->left);
        A->right = solve(A->right);
    } else {
        if(A->left) return solve(A->left);
        if(A->right) return solve(A->right);
    }
    return A;
}
