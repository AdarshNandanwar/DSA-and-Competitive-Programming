// https://www.interviewbit.com/problems/recover-binary-search-tree/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void helper(TreeNode* A, int prev, vector<int> & res){
    if(A == NULL) return;
    helper(A->left, prev, res);
    if(prev > A->val){
        if(res.size() == 0){
            res.push_back(A->val);
            res.push_back(prev);
        } else {
            res[0] = A->val;
        }
    }
    prev = A->val;
    helper(A->right, prev, res);
} 

vector<int> Solution::recoverTree(TreeNode* A) {
    vector<int> res;
    int prev = INT_MIN;
    helper(A, prev, res);
    return res;
}
