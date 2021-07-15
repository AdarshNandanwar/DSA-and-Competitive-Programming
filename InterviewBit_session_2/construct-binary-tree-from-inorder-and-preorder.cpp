// https://www.interviewbit.com/problems/construct-binary-tree-from-inorder-and-preorder/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
TreeNode* helper(vector<int> &A, vector<int> &B, int & index, int B_start, int B_end, unordered_map<int, int> & m){
    if(B_start == B_end) return NULL;
    int val = A[index++];
    TreeNode * root = new TreeNode(val);
    root->left = helper(A, B, index, B_start, m[val], m);
    root->right = helper(A, B, index, m[val]+1, B_end, m);
    return root;
}

TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    int n = B.size(), index = 0;
    unordered_map<int, int> m;
    for(int i = 0; i<n; i++){
        m[B[i]] = i;
    }
    return helper(A, B, index, 0, n, m);
}
