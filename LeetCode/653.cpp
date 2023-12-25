// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

// Method 1 (Hash Table, Recursion, O(n) time, O(n) space):

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
    unordered_set<int> s;
    bool findTarget(TreeNode* root, int k) {
        if(root == NULL) return false;
        if(s.count(k-root->val)) return true;
        s.insert(root->val);
        return findTarget(root->left, k) or findTarget(root->right, k);
    }
};

// Method 2 (2 pointer approach, O(n) time, O(height) = O(n) space):

class BSTIterator {
    stack<TreeNode *> st;
    bool reverse;
    public:
    BSTIterator(TreeNode * root, bool reverse = false){
        this->reverse = reverse;
        while(root){
            this->st.push(root);
            if(this->reverse) root = root->right;
            else root = root->left;
        }
    }
    void next(){
        TreeNode * cur;
        if(this->reverse) cur = this->st.top()->left;
        else cur = this->st.top()->right;
        this->st.pop();
        while(cur){
            this->st.push(cur);
            if(this->reverse) cur = cur->right;
            else cur = cur->left;
        }
    }
    TreeNode * peek(){
        return this->st.top();
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        
        // 2 pointer on BST
        BSTIterator * left = new BSTIterator(root), * right = new BSTIterator(root, true);
        while(true){
            int l = left->peek()->val;
            int r = right->peek()->val;
            if(l == r) break;
            if(l+r < k){
                left->next();
            } else if(l+r > k){
                right->next();
            } else {
                return true;
            }
        }
        return false;      
    }
};