// https://www.interviewbit.com/problems/max-sum-path-in-binary-tree/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
int helper(TreeNode* A, int & ans){
    if(!A) return 0;
    int maxSum = A->val;
    int l = helper(A->left, ans), r = helper(A->right, ans);
    if(l > 0) maxSum += l;
    if(r > 0) maxSum += r;
    ans = max(ans, maxSum);
    return max(A->val, max(A->val+l, A->val+r));
}
 
int Solution::maxPathSum(TreeNode* A) {
    if(!A) return 0;
    int ans = INT_MIN;
    helper(A, ans);
    return ans;
}
