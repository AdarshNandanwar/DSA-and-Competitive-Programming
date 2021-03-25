// https://www.interviewbit.com/problems/valid-binary-search-tree/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void inOrder(TreeNode* & A, TreeNode* & prev, bool & res){
    if(!res or !A) return;
    inOrder(A->left, prev, res);
    if(prev and A->val <= prev->val){
        res = false;
        return;
    }
    prev = A;
    inOrder(A->right, prev, res);
}
 
int Solution::isValidBST(TreeNode* A) {
    TreeNode* prev = NULL;
    bool res = true;
    inOrder(A, prev, res);
    return res;
}
