// https://www.interviewbit.com/problems/root-to-leaf-paths-with-sum/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void helper(TreeNode* A, int B, vector<int> & cur, vector<vector<int>> & ans){
    if(A == NULL) return;
    if(A->left == NULL and A->right == NULL) {
        if(A->val == B) {
            cur.push_back(A->val);
            ans.push_back(cur);
            cur.pop_back();
        }
        return;
    }
    cur.push_back(A->val);
    helper(A->left, B-A->val, cur, ans);
    helper(A->right, B-A->val, cur, ans);
    cur.pop_back();
}
 
vector<vector<int>> Solution::pathSum(TreeNode* A, int B) {
    vector<vector<int>> ans;
    vector<int> cur;
    helper(A, B, cur, ans);
    return ans;
}