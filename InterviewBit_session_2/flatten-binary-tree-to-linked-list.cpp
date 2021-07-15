// https://www.interviewbit.com/problems/flatten-binary-tree-to-linked-list/

// Method 1 (global variable):

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
TreeNode* helper(TreeNode * root, TreeNode * & prev){
    if(root == NULL) return NULL;
    helper(root->right, prev);
    helper(root->left, prev);
    root->right = prev;
    root->left = NULL;
    prev = root;
    return root;
}
 
TreeNode* Solution::flatten(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    TreeNode * prev = NULL;
    return helper(A, prev);
}

// Method 2 (recursion):

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
TreeNode* Solution::flatten(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A == NULL) return NULL;
    auto cur = A->left;
    if(A->left){
        while(cur->right) cur = cur->right;
        cur->right = A->right;
        A->right = A->left;
        A->left = NULL;
    }
    A->right = flatten(A->right);
    return A;
}
