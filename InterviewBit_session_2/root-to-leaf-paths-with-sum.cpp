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
 
void helper(TreeNode* A, int B, vector<int> & cur, vector<vector<int>> & res){
    if(A == NULL) return;
    if(A and !A->left and !A->right){
        if(B == A->val){
            cur.push_back(A->val);
            res.push_back(cur);
            cur.pop_back();
        }
        return;
    }
    cur.push_back(A->val);
    helper(A->left, B-A->val, cur, res);
    helper(A->right, B-A->val, cur, res);
    cur.pop_back();
}

vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    vector<vector<int>> res;
    vector<int> cur;
    helper(A, B, cur, res);
    return res;
}
