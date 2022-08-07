// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

// Method 1 (Recursion, O(n)):

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return root;
        if(root == p or root == q) return root;
        auto left = lowestCommonAncestor(root->left, p, q);
        auto right = lowestCommonAncestor(root->right, p, q);
        return left and right ? root : (left?left:right);
    }
};

// Method 2 (Recursion, O(n)):

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct NodeInfo {
    TreeNode * ancestor;
    int count;
    NodeInfo(TreeNode * ancestor, int count) : count(count), ancestor(ancestor) {}
};

class Solution {
public:
    NodeInfo * countNodes(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL) return new NodeInfo(NULL, 0);
        
        auto leftInfo = countNodes(root->left, p, q);
        if(leftInfo->count == 2) return leftInfo;
        auto rightInfo = countNodes(root->right, p, q);
        if(rightInfo->count == 2) return rightInfo;
        
        int count = leftInfo->count+rightInfo->count;
        if(root == p or root == q) count++;
        
        if(count == 2){
            return new NodeInfo(root, count);
        } else {
            return new NodeInfo(NULL, count);
        }
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return countNodes(root, p, q)->ancestor;
    }
};