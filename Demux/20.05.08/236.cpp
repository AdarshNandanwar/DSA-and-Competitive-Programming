// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

// Method 1 (Recursion):

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
        if(!root or root==p or root==q) return root;
        TreeNode * l = lowestCommonAncestor(root->left, p, q);
        TreeNode * r = lowestCommonAncestor(root->right, p, q);
        if(l and r) return root;
        return l?l:r;
    }
};

// Method 2 (Path Tracing):

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
    
    void getPath(TreeNode * root, TreeNode * t, deque<TreeNode *> & q, bool & found){
        if(root == NULL) return;
        q.push_back(root);
        if(root == t) {
            found = true;
            return;
        }
        getPath(root->left, t, q, found);
        if(found) return;
        getPath(root->right, t, q, found);
        if(found) return;
        q.pop_back();
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        deque<TreeNode *> q1, q2;
        bool found;
        found = false;
        getPath(root, p, q1, found);
        found = false;
        getPath(root, q, q2, found);
        TreeNode * curr = root;
        while(!q1.empty() and !q2.empty() and q1.front() == q2.front()){
            curr = q1.front();
            q1.pop_front(); q2.pop_front();
        }
        return curr;
    }
};