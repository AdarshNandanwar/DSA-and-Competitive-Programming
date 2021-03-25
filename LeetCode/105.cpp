// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
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
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return helper(preorder, 0, n-1, inorder, 0, n-1);
    }
};