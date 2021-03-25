// https://www.interviewbit.com/problems/inorder-traversal/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void inOrder(TreeNode* A, vector<int> & res){
    if(!A) return;
    inOrder(A->left, res);
    res.push_back(A->val);
    inOrder(A->right, res);
}
 
vector<int> Solution::inorderTraversal(TreeNode* A) {
    vector<int> res;
    inOrder(A, res);
    return res;
}
