// https://www.interviewbit.com/problems/zigzag-level-order-traversal-bt/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    if(!A) return {};
    vector<vector<int>> ans;
    bool flag = 0;
    queue<TreeNode*> q;
    q.push(A);
    while(!q.empty()){
        vector<int> row;
        int sz = q.size();
        for(int i = 0; i<sz; i++){
            auto cur = q.front();
            q.pop();
            row.push_back(cur->val);
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }
        if(flag) reverse(row.begin(), row.end());
        flag = !flag;
        ans.push_back(row);
    }
    return ans;
}
