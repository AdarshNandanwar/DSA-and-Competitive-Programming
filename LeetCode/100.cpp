// https://leetcode.com/problems/same-tree/

// Method 1 (Recursive, O(n)):

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if((p and !q) or (!p and q) or (p and q and p->val^q->val)) return false;
        return (!p and !q) or (isSameTree(p->left, q->left) and isSameTree(p->right, q->right));
    }
};

// Alternative Code:

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr or q == nullptr){
            return p == q;
        }
        return p->val == q->val and isSameTree(p->left, q->left) and isSameTree(p->right, q->right);
    }
};