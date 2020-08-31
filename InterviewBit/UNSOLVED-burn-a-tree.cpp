// https://www.interviewbit.com/problems/burn-a-tree/

// Mehtod 1 (Return 2 values, dosen't accept as wrong test case, not leaf node):

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
// {timeToResch, heightLeftToBurn}
vector<int> helper(TreeNode * A, const int & B, int & ans){
    if(A->left == NULL and A->right == NULL){
        if(A->val == B) return {0, 0};
        return {INT_MAX, 0};
    }
    int ttr = INT_MAX, htb = 0;
    vector<int> l = {INT_MAX, 0}, r = {INT_MAX, 0};
    
    if(A->left){
        l = helper(A->left, B, ans);
        if(l[0] != INT_MAX){
            ttr = 1+l[0];
        } else {
            htb = max(htb, 1+l[1]);
        }
    }
    if(A->right){
        r = helper(A->right, B, ans);
        if(r[0] != INT_MAX){
            ttr = 1+r[0];
        } else {
            htb = max(htb, 1+r[1]);
        }
    }
    
    if(ttr == INT_MAX){
        return {INT_MAX, htb};
    } else {
        if(l[0] == INT_MAX) ans = max(ans, (r[0]+1)+(l[1]+1));
        else ans = max(ans, (l[0]+1)+(r[1]+1));
        return {ttr, 0};
    }
}
 
int Solution::solve(TreeNode* A, int B) {
    int ans = 0;
    if(!A) return 0;
    helper(A, B, ans);
    return ans;
}
