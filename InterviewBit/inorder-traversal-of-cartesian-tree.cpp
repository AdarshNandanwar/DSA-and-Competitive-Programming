// https://www.interviewbit.com/problems/inorder-traversal-of-cartesian-tree/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
TreeNode * helper(vector<int> &A, int st, int end){
    if(st == end) return new TreeNode(A[st]);
    if(st > end) return NULL;
    int brk = max_element(A.begin()+st, A.begin()+end+1)-A.begin();
    TreeNode * root = new TreeNode(A[brk]);
    root->left = helper(A, st, brk-1);
    root->right = helper(A, brk+1, end);
    return root;
}
 
TreeNode* Solution::buildTree(vector<int> &A) {
    int n = A.size();
    return helper(A, 0, n-1);
}
