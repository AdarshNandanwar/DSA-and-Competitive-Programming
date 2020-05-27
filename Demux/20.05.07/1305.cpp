// https://leetcode.com/problems/all-elements-in-two-binary-search-trees/

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
    int next() {
        TreeNode * curr = st.top();
        st.pop();
        pushLeft(curr->right);
        return curr->val;
    }
    
    /** peek next without popping */
    int peek() {
        return st.top()->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !st.empty();
    }
};

class Solution {
public:
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;
        BSTIterator bst1(root1), bst2(root2);
        while(bst1.hasNext() and bst2.hasNext()){
            int t1 = bst1.peek(), t2 = bst2.peek();
            if(t1<t2)
                ans.push_back(bst1.next());
            else 
                ans.push_back(bst2.next());
        }
        while(bst1.hasNext()) ans.push_back(bst1.next());
        while(bst2.hasNext()) ans.push_back(bst2.next());
        return ans;
    }
};