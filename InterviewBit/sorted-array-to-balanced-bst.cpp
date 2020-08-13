// https://www.interviewbit.com/problems/sorted-array-to-balanced-bst/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
TreeNode* helper(const vector<int> &A, int st, int end){
    if(st == end) return new TreeNode(A[st]);
    if(st>end) return NULL;
    int mid = st + (end-st+1)/2;
    TreeNode * root = new TreeNode(A[mid]);
    root->left = helper(A, st, mid-1);
    root->right = helper(A, mid+1, end);
    return root;
}
 
TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    int n = A.size();
    return helper(A, 0, n-1);
}
