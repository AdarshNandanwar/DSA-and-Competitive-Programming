// https://www.interviewbit.com/problems/right-view-of-binary-tree/

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
    vector<int> ans;
    queue<TreeNode *> q;
    q.push(A);
    while(!q.empty()){
        int sz = q.size();
        ans.push_back(q.front()->val);
        for(int i = 0; i<sz; i++){
            auto cur = q.front();
            q.pop();
            if(cur->right) q.push(cur->right);
            if(cur->left) q.push(cur->left);
        }
    }
    return ans;
}
