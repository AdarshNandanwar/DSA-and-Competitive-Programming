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

typedef long long int ll;
#define MOD 1003
 
void helper(TreeNode* A, ll num, ll & sum){
    if(!A->left and !A->right){
        sum  = (sum+((num*10)%MOD+A->val)%MOD)%MOD;
        return;
    }
    if(A->left) helper(A->left, ((num*10)%MOD+A->val)%MOD, sum);
    if(A->right) helper(A->right, ((num*10)%MOD+A->val)%MOD, sum);
}
 
int Solution::sumNumbers(TreeNode* A) {
    if(!A) return 0;
    ll sum = 0;
    helper(A, (ll)0, sum);
    return sum%MOD;
}
