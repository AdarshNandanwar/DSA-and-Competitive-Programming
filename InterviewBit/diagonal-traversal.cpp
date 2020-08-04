// https://www.interviewbit.com/problems/diagonal-traversal/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
vector<int> Solution::solve(TreeNode* A) {
    if(!A) return {};
    queue<TreeNode *> q;
    q.push(A);
    vector<int> res;
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        while(cur){
            res.push_back(cur->val);
            if(cur->left) q.push(cur->left);
            cur = cur->right;
        }
    }
    return res;
}
