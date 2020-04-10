/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void inOrder(TreeNode * root, vector<int> & v){
    if(root == NULL){
        return;
    }
    inOrder(root->left, v);
    v.push_back(root->val);
    inOrder(root->right, v);
}
 
int Solution::kthsmallest(TreeNode* A, int B) {
    vector<int> v;
    inOrder(A, v);
    return v[B-1];
}
