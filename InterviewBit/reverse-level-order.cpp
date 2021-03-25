// https://www.interviewbit.com/problems/reverse-level-order/

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
    if(A == NULL) return {};
    vector<int> res;
    queue<TreeNode *> q;
    q.push(A);
    while(!q.empty()){
        int sz = q.size();
        while(sz--){
            auto cur = q.front();
            q.pop();
            res.push_back(cur->val);
            if(cur->right) q.push(cur->right);
            if(cur->left) q.push(cur->left);
        }
    }
    reverse(res.begin(), res.end());
    return res;
}
