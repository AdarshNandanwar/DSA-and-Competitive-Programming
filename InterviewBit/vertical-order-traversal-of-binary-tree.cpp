// https://www.interviewbit.com/problems/vertical-order-traversal-of-binary-tree/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
    if(!A) return {};
    vector<vector<int> > ans;
    unordered_map<int, vector<int>> m;
    int left = 0, right = 0;
    queue<pair<TreeNode *, int>> q;
    q.push({A, 0});
    while(!q.empty()){
        int sz = q.size();
        for(int i  =0; i<sz; i++){
            auto cur = q.front();
            q.pop();
            left = min(left, cur.second);
            right = max(right, cur.second);
            m[cur.second].push_back(cur.first->val);
            if(cur.first->left) q.push({cur.first->left, cur.second-1});
            if(cur.first->right) q.push({cur.first->right, cur.second+1});
        }
    }
    for(int i = left; i<=right; i++) ans.push_back(m[i]);
    return ans;
}
