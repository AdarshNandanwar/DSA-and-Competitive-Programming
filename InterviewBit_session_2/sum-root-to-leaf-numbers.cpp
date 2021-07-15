// https://www.interviewbit.com/problems/sum-root-to-leaf-numbers/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void helper(TreeNode * root, int cur, int & res){
    if(!root) return;
    if(root and !root->left and !root->right){
        res = (res+cur*10+root->val)%1003;
        return;
    }
    helper(root->left, (cur*10+root->val)%1003, res);
    helper(root->right, (cur*10+root->val)%1003, res);
}
 
int Solution::sumNumbers(TreeNode* A) {
    int res = 0, cur = 0;
    helper(A, cur, res);
    return (int)res;
}
