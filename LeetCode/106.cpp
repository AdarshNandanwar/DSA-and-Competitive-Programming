// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

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
    
    TreeNode * helper(vector<int>& inorder, vector<int>& postorder, int st, int end, int & index, unordered_map<int, int> & indexMap){
        if(st>end or index<0) return NULL;
        int val = postorder[index--];
        TreeNode * root = new TreeNode(val);
        root->right = helper(inorder, postorder, indexMap[val]+1, end, index, indexMap);
        root->left = helper(inorder, postorder, st, indexMap[val]-1, index, indexMap);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        unordered_map<int, int> indexMap;
        for(int i = 0; i<n; i++) indexMap[inorder[i]] = i;
        // st and end is for inorder
        // index is for postorder
        int index = n-1;
        return helper(inorder, postorder, 0, n-1, index, indexMap);
    }
};