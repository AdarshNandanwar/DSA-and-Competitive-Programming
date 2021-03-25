// https://leetcode.com/problems/recover-binary-search-tree/

// Method 1 (Iterator):

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

class BSTIterator {
public:
    
    stack<TreeNode *> st;
    
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }
    
    void pushLeft(TreeNode * root){
        while(root){
            st.push(root);
            root = root->left;
        }
    }
    
    /** @return the next smallest number */
    TreeNode * next() {
        TreeNode * curr = st.top();
        st.pop();
        pushLeft(curr->right);
        return curr;
    }
    
    /** peek next without popping */
    TreeNode * peek() {
        return st.top();
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !st.empty();
    }
};


class Solution {
public:
    
    void recoverTree(TreeNode* root) {
        vector<TreeNode *> mismatch;
        BSTIterator it(root);
        while(it.hasNext()){
            TreeNode * curr = it.next();
            if(it.hasNext() and curr->val > it.peek()->val){
                if(mismatch.size() == 0){
                    mismatch.push_back(curr);
                    mismatch.push_back(it.peek());
                } else {
                    mismatch[1] = it.peek();
                    break;
                }
            }
        }
        swap(mismatch[0]->val, mismatch[1]->val);
    }
};

// Method 2 (inOrderPredecessor):

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
    
    void inOrderPred(TreeNode * root, TreeNode * & pred, vector<TreeNode *> & mismatch){
        if(root == NULL) return;
        
        inOrderPred(root->left, pred, mismatch);
        if(pred)
            if(root->val < pred->val){
                if(mismatch.size() == 0){
                    mismatch.push_back(pred);
                    mismatch.push_back(root);
                } else {
                    mismatch[1] = root;
                }
            }
        pred = root;
        inOrderPred(root->right, pred, mismatch);
    }
    
    void recoverTree(TreeNode* root) {
        vector<TreeNode *> mismatch;
        TreeNode * pred = NULL;
        inOrderPred(root, pred, mismatch);
        swap(mismatch[0]->val, mismatch[1]->val);
    }
};