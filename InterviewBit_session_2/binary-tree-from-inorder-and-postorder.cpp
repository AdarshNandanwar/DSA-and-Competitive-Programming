// https://www.interviewbit.com/problems/binary-tree-from-inorder-and-postorder/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
TreeNode * helper(vector<int> &inorder, vector<int> &postorder, int st, int end, int &index, unordered_map<int, int> & m){
    if(st >= end) return NULL;
    int val = postorder[index--];
    TreeNode * root = new TreeNode(val);
    root->right = helper(inorder, postorder, m[val]+1, end, index, m);
    root->left = helper(inorder, postorder, st, m[val], index, m);
    return root;
}
 
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    int n = A.size();
    unordered_map<int, int> m;
    int index = n-1;
    for(int i = 0; i<n; i++) m[A[i]] = i;
    return helper(A, B, 0, n, index, m);
}
