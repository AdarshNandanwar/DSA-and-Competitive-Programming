// https://leetcode.com/problems/binary-tree-right-side-view/

// Method 1 (Preorder traversal, O(n)):

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
    void traversal(TreeNode * root, int level, vector<int> & rightView){
        if(!root){
            return;
        }
        if(level >= rightView.size()){
            rightView.push_back(root->val);
        }
        traversal(root->right, level+1, rightView);
        traversal(root->left, level+1, rightView);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightView;
        traversal(root, 0, rightView);
        return rightView;
    }
};

// Method 2 (BFS, O(n)):

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightView;
        queue<TreeNode *> q;
        if(root){
            q.push(root);
        }
        int level = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                TreeNode * cur = q.front();
                q.pop();
                if(rightView.size() == level){
                    rightView.push_back(cur->val);
                }
                if(cur->right){
                    q.push(cur->right);
                }
                if(cur->left){
                    q.push(cur->left);
                }
            }
            level++;
        }
        return rightView;
    }
};