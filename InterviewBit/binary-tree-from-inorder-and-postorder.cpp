// https://www.interviewbit.com/problems/binary-tree-from-inorder-and-postorder/

// Method 1 (Recursion with 3 pointers (1 global), O(n)):

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
TreeNode * helper(vector<int> &A, vector<int> &B, int st, int end, int & index, unordered_map<int, int> & inorderIndex){
    if(st>end or index<0) return NULL;
    int mid = inorderIndex[B[index]];
    TreeNode * root = new TreeNode(B[index]);
    index--;
    root->right = helper(A, B, mid+1, end, index, inorderIndex);
    root->left = helper(A, B, st, mid-1, index, inorderIndex);
    return root;
}
 
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    int n = A.size(), index = n-1;
    unordered_map<int, int> inorderIndex;
    for(int i = 0; i<n; i++) inorderIndex[A[i]] = i;
    return helper(A, B, 0, n-1, index, inorderIndex);
}
