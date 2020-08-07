// https://www.interviewbit.com/problems/symmetric-binary-tree/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool isMirror(TreeNode* a, TreeNode* b){
    if(a == NULL) return b == NULL;
    if(b == NULL) return a == NULL;
    if(a->val != b->val) return 0;
    if(!isMirror(a->left, b->right)) return  0;
    if(!isMirror(a->right, b->left)) return  0;
    return 1;
}
 
int Solution::isSymmetric(TreeNode* A) {
    return isMirror(A->left, A->right);
}