// https://leetcode.com/problems/find-bottom-left-tree-value/

// Method 1 (Reverse level order traversal):

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
    
    int findBottomLeftValue(TreeNode* root) {
        // rev level order
        queue<TreeNode *> q;
        q.push(root);
        TreeNode * curr;
        while(!q.empty()){
            curr = q.front();
            q.pop();
            if(curr->right) q.push(curr->right);
            if(curr->left) q.push(curr->left);
        }
        return curr->val;
    }
};

// Method 2 (Using height map):

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
    
    void traverse(TreeNode * root, map<int, int, greater<int>> & m, int h){
        if(root == NULL) return;
        
        if(m.find(h)==m.end()) m[h] = root->val;
        traverse(root->left, m, h+1);
        traverse(root->right, m, h+1);
    }
    
    int findBottomLeftValue(TreeNode* root) {
        map<int, int, greater<int>> m;
        traverse(root, m, 0);
        return m.begin()->second;
    }
};