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
    if((A and !B) or (!A and B)) return 0;
    if(!A and !B) return 1;
    if(A->val != B->val) return 0;
    return isSameTree(A->left, B->left) and isSameTree(A->right, B->right);
}
