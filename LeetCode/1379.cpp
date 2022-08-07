// https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/

// Method 1 (Preorder Traversal, O(n)):

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(original == NULL){
            return NULL;
        }
        if(original == target){
            return cloned;
        }
        auto leftRes = getTargetCopy(original->left, cloned->left, target);
        if(leftRes){
            return leftRes;
        }
        auto rightRes = getTargetCopy(original->right, cloned->right, target);
        if(rightRes){
            return rightRes;
        }
        return NULL;
    }
};