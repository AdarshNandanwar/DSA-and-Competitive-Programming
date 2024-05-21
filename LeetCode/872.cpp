// https://leetcode.com/problems/leaf-similar-trees/description/

// Method 1 (Binary Tree Iterator, O(n+m)):

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
    void pushLeft(stack<TreeNode *>& st, TreeNode * root){
        while(root){
            st.push(root);
            root = root->left;
        }
    }
    TreeNode * getNext(stack<TreeNode *>& st){
        if(st.empty()){
            return nullptr;
        }
        
        TreeNode * cur = st.top();
        st.pop();
        pushLeft(st, cur->right);
        return cur;
    }
    TreeNode * getNextLeaf(stack<TreeNode *>& st){
        TreeNode * next = getNext(st);
        while(next){
            if(next->left == nullptr and next->right == nullptr){
                return next;
            }
            next = getNext(st);
        }
        return nullptr;
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode *> st1, st2;
        pushLeft(st1, root1);
        pushLeft(st2, root2);
        while(true){
            TreeNode * next1 = getNextLeaf(st1);
            TreeNode * next2 = getNextLeaf(st2);
            if(next1 == nullptr or next2 == nullptr){
                return next1 == next2;
            } else if(next1->val != next2->val){
                return false;
            }
        }
        return true;
    }
};

// Method 2 (Brute Force, O(n+m)):

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
    void getLeaves(TreeNode * root, vector<int>& leaves){
        if(root == nullptr){
            return;
        }
        getLeaves(root->left, leaves);
        if(root->left == nullptr and root->right == nullptr){
            leaves.push_back(root->val);
        }
        getLeaves(root->right, leaves);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1, leaves2;
        getLeaves(root1, leaves1);
        getLeaves(root2, leaves2);
        if(leaves1.size() != leaves2.size()){
            return false;
        }
        for(int i=0; i<leaves1.size(); i++){
            if(leaves1[i] != leaves2[i]){
                return false;
            }
        }
        return true;
    }
};