// https://www.interviewbit.com/problems/flatten-binary-tree-to-linked-list/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 

void helper(TreeNode * A, TreeNode * & prev){
    if(!A) return;
    helper(A->right, prev);
    helper(A->left, prev);
    A->right = prev;
    A->left = NULL;
    prev = A;
}
 
TreeNode* Solution::flatten(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    TreeNode* prev = NULL;
    helper(A, prev);
    return A;
}
