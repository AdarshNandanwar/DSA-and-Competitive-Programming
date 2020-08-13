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
 
 
void inOrder(TreeNode * root, TreeNode * & prev, vector<int> & ans){
    if(root == NULL) return;
    inOrder(root->left, prev, ans);
    
    if(prev and root->val<prev->val){
        if(ans.size() == 0){
            ans.push_back(root->val);
            ans.push_back(prev->val);
        } else {
            ans[0] = root->val;
        }
    }
    prev = root;
    inOrder(root->right, prev, ans);
}
 
 
vector<int> Solution::recoverTree(TreeNode* A) {
    vector<int> ans;
    TreeNode * prev = NULL;
    inOrder(A, prev, ans);
    return ans;
}
