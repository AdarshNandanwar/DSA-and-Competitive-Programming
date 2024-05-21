// https://leetcode.com/problems/distribute-coins-in-binary-tree/

// Method 1 (Recursion, O(n) time, O(1) space):

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
    // {cost (including cost to take out or bring in coines needed to the root), coins needed}
    pair<int, int> helper(TreeNode * root){
        if(!root){
            return make_pair(0, 0);
        }

        auto left = helper(root->left);
        auto right = helper(root->right);

        int coinsNeeded = 1 + left.second + right.second - root->val;
        int cost = abs(coinsNeeded) + abs(left.first) + abs(right.first);
        
        return make_pair(cost, coinsNeeded);
    }
public:
    int distributeCoins(TreeNode* root) {
        return helper(root).first;
    }
};
