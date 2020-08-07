// https://www.interviewbit.com/problems/construct-binary-tree-from-inorder-and-preorder/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
TreeNode * helper(vector<int> & preOrd, int preSt, int preEnd, vector<int> & inOrd, int inSt, int inEnd){
    if(preSt > preEnd) return NULL;
    if(preSt == preEnd) return new TreeNode(preOrd[preSt]);
    
    int pivot = preOrd[preSt], i;
    for(i = inSt; i<=inEnd; i++) if(inOrd[i] == pivot) break;
    
    TreeNode * root = new TreeNode(pivot);
    root->left = helper(preOrd, preSt+1, preSt+1+(i-inSt-1), inOrd, inSt, i-1);
    root->right = helper(preOrd, preSt+1+(i-inSt), preEnd, inOrd, i+1, inEnd);
    return root;
}
 
TreeNode* Solution::buildTree(vector<int> & preOrd, vector<int> & inOrd) {
    int n = preOrd.size();
    return helper(preOrd, 0, n-1, inOrd, 0, n-1);
}
