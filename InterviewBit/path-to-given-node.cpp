// https://www.interviewbit.com/problems/path-to-given-node/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void helper(TreeNode* A, int B, vector<int> & cur, vector<int> & ans){
    if(ans.size() or !A) return;
    if(A->val == B){
        cur.push_back(A->val);
        ans = cur;
        return;
    }
    cur.push_back(A->val);
    helper(A->left, B, cur, ans);
    helper(A->right, B, cur, ans);
    cur.pop_back();
}
 
vector<int> Solution::solve(TreeNode* A, int B) {
    if(A == NULL) return {};
    vector<int> ans, cur;
    helper(A, B, cur, ans);
    return ans;
}
