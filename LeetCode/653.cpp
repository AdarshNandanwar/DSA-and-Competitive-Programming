// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

// Method 1 (O(n), time, O(n) space):

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
    
    bool helper(TreeNode* A, int & B, unordered_set<int> & s) {
        if(!A) return 0;
        if(helper(A->left, B, s)) return 1;
        if(s.count(B-A->val)) return 1;
        s.insert(A->val);
        return helper(A->right, B, s);
    }
    
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> s;
        return helper(root, k, s);
    }
};