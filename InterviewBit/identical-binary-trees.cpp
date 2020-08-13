// https://www.interviewbit.com/problems/identical-binary-trees/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::isSameTree(TreeNode* A, TreeNode* B) {
    if(A == NULL) return B == NULL;
    if(B == NULL) return A == NULL;
    return A->val == B->val and isSameTree(A->left, B->left) and isSameTree(A->right, B->right);
}
