// https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/description/

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
    int helper(TreeNode * root, int prevMin, int prevMax){
        if(root == nullptr){
            return 0;
        }

        int curMin = min(prevMin, root->val);
        int curMax = max(prevMax, root->val);

        int res = max(abs(prevMin - root->val), abs(prevMax - root->val));
        res = max(res, helper(root->left, curMin, curMax));
        res = max(res, helper(root->right, curMin, curMax));
        return res;
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        return max(helper(root->left, root->val, root->val), helper(root->right, root->val, root->val));
    }
};