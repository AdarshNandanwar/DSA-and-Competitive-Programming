// https://leetcode.com/problems/cousins-in-binary-tree-ii/

// Method 1 (Tree Traversal, O(n))

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
    void getDepthSum(TreeNode * root, int depth, vector<int> & depthSum){
        if(root == nullptr){
            return;
        }
        depthSum[depth] += root->val;
        getDepthSum(root->left, depth+1, depthSum);
        getDepthSum(root->right, depth+1, depthSum);
    }
    TreeNode * helper(TreeNode * root, int depth, int sibling, vector<int> & depthSum){
        if(root == nullptr){
            return nullptr;
        }
        root->val = depthSum[depth] - sibling - root->val;
        int leftSibling = root->left ? root->left->val : 0;
        int rightSibling = root->right ? root->right->val : 0;
        root->left = helper(root->left, depth+1, rightSibling, depthSum);
        root->right = helper(root->right, depth+1, leftSibling, depthSum);
        return root;
    }
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<int> depthSum(1e5 + 1);
        getDepthSum(root, 0, depthSum);
        return helper(root, 0, 0, depthSum);
    }
};
