// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

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

// Method 1 (Iterative Inorder Traversal, O(k) time, O(h) space):

class Solution {
public:
    void pushLeft(stack<TreeNode *> & st, TreeNode * root){
        while(root){
            st.push(root);
            root = root->left;
        }
    }
    
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode *> st;
        pushLeft(st, root);
        while(!st.empty()){
            TreeNode * cur = st.top();
            st.pop();
            if(--k == 0){
                return cur->val;
            }
            pushLeft(st, cur->right);
        }
        return -1;
    }
};

// Method 2 (Recursive Inorder Traversal, O(n) time, O(h) space):

class Solution {
public:
    void inOrder(TreeNode* root, int & k, int & ans){
        if(root == NULL){
            return;
        }
        inOrder(root->left, k, ans);
        if(k == 1){
            ans = root->val;
        }
        k--;
        inOrder(root->right, k, ans);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        inOrder(root, k, ans);
        return ans;
    }
};