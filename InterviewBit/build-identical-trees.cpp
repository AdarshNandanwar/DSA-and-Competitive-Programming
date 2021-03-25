// https://www.interviewbit.com/problems/build-identical-trees/?test_id=11866

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::cntMatrix(TreeNode* A, TreeNode* B) {
    if(!A and !B) return 0;
    if(!A){
        int c1 = cntMatrix(A, B->left), c2 = cntMatrix(A, B->right);
        if(c1 == -1 or c2 == -1) return -1;
        return 1+c1+c2;
    }
    if(!B) return -1;
    int c1 = cntMatrix(A->left, B->left), c2 = cntMatrix(A->right, B->right);
    if(c1 == -1 or c2 == -1) return -1;
    return c1+c2;
}
