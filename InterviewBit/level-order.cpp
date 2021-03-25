// https://www.interviewbit.com/problems/level-order/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    if(!A) return {};
    vector<vector<int> > ans;
    queue<TreeNode *> q;
    q.push(A);
    while(!q.empty()){
        int sz = q.size();
        vector<int> row;
        for(int i = 0; i<sz; i++){
            auto cur = q.front();
            row.push_back(cur->val);
            q.pop();
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }
        ans.push_back(row);
    }
    return ans;
    
}
