// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

// Method 1 (O(n)):

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
    
    TreeNode * helper( vector<int> & preorder, int & index, int breaker){
        if(index >= preorder.size() or preorder[index]>breaker) return NULL;
        TreeNode * root = new TreeNode(preorder[index]);
        index++;
        root->left = helper(preorder, index, preorder[index-1]);
        root->right = helper(preorder, index, breaker);
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size() == 0){
            return NULL;
        }
        int index = 0;
        return helper(preorder, index, INT_MAX);
    }
};

// Method 2 (O(n2) ???)

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
    
    void helper(TreeNode * & root, vector<int> & preorder, int st, int end){
        if(st > end) return;
        
        root = new TreeNode(preorder[st]);
        int i;
        for(i = st; i<=end; i++)
            if(preorder[i] > preorder[st])
                break;
        helper(root->left, preorder, st+1, i-1);
        helper(root->right, preorder, i, end);
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size() == 0){
            return NULL;
        }
        TreeNode * root = NULL;
        helper(root, preorder, 0, preorder.size()-1);
        return root;
    }
};