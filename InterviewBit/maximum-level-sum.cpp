// https://www.interviewbit.com/problems/maximum-level-sum/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::solve(TreeNode* A) {
    if(!A) return 0;
    queue<TreeNode *> q;
    q.push(A);
    int res = 0;
    while(!q.empty()){
        int sz = q.size(), sum = 0;
        while(sz--){
            auto cur = q.front();
            q.pop();
            sum += cur->val;
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }
        res = max(res, sum);
    }
    return res;
}
