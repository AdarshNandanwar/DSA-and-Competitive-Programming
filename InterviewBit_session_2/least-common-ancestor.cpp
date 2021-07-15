// https://www.interviewbit.com/problems/least-common-ancestor/

// Method 1 (Recursion, Bit Masking):

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
int helper(TreeNode* A, int B, int C, int & ans) {
    if(A == NULL) return 0;
    auto l = helper(A->left, B, C, ans);
    auto r = helper(A->right, B, C, ans);
    if(ans != -1) return 4;
    
    int cur = 0;
    if(A->val == B) cur |= 2;
    if(A->val == C) cur |= 1;
    int res = (l|r|cur);
    if(res == 3) ans = A->val;
    return res;
}

int Solution::lca(TreeNode* A, int B, int C) {
    int ans = -1;
    helper(A, B, C, ans);
    return ans;
}
