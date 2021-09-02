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

bool helper(TreeNode* A, int & B, vector<int> & res){
    if(A == NULL) return false;
    res.push_back(A->val);
    if(A->val == B) return true;
    if(helper(A->left, B, res)) return true;
    if(helper(A->right, B, res)) return true;
    res.pop_back();
    return false;
}
 
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> res;
    helper(A, B, res);
    return res;
}
