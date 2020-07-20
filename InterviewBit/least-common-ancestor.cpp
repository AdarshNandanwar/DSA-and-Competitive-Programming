// https://www.interviewbit.com/problems/least-common-ancestor/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool find(TreeNode* A, int B){
    if(!A) return false;
    return (A->val == B or find(A->left, B) or find(A->right, B));
}

int lcaHelper(TreeNode* A, int B, int C){
    if(!A) return -1;
    if(A->val == B or A->val == C) return A->val;
    if(lcaHelper(A->left, B, C) == -1){
        return lcaHelper(A->right, B, C);
    } else if(lcaHelper(A->right, B, C) == -1){
        return lcaHelper(A->left, B, C);
    } else {
        return A->val;
    }
}
 
int Solution::lca(TreeNode* A, int B, int C) {
    if(find(A, B) and find(A, C)) return lcaHelper(A, B, C);
    else return -1;
}
