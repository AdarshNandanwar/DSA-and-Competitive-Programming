// https://leetcode.com/problems/smallest-string-starting-from-leaf/

// Method 1 (Recursion, O(n^2)):

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
    void helper(TreeNode * root, string & cur, string & smallest){
        if(root == nullptr){
            return;
        }
        cur.push_back('a'+root->val);
        if(root->left == nullptr and root->right == nullptr){
            string rev = cur;
            reverse(rev.begin(), rev.end());
            smallest = min(smallest, rev);
        }
        helper(root->left, cur, smallest);
        helper(root->right, cur, smallest);
        cur.pop_back();
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        string cur, smallest(8501, 'z'+1);
        helper(root, cur, smallest);
        return smallest;
    }
};
