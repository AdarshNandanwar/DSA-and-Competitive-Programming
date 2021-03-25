// https://www.interviewbit.com/problems/cousins-in-binary-tree/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> res;
    if(!A) return res;
    if(A->val == B) return res;
    bool found = 0;
    queue<TreeNode *> q;
    q.push(A);
    while(!q.empty()){
        int sz = q.size();
        if(found){
            for(int i = 0; i<sz; i++){
                auto cur = q.front();
                q.pop();
                res.push_back(cur->val);
            }
            return res;
        } else {
            for(int i = 0; i<sz; i++){
                auto cur = q.front();
                q.pop();
                if((cur->left and cur->left->val == B) or (cur->right and cur->right->val == B)){
                    found = 1;
                } else {
                    if(cur->left) q.push(cur->left);
                    if(cur->right) q.push(cur->right);
                }
            }
        }
    }
    return res;
}
