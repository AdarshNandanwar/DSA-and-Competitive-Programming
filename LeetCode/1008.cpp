// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/submissions/

// Method 1 (Stack, O(n)):

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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        if(n == 0) return NULL;
        TreeNode * root = new TreeNode(preorder[0]), * prev = NULL, * tn;
        stack<TreeNode *> st;
        st.push(root);
        for(int i = 1; i<n; i++){
            if(st.top()->val >= preorder[i]){
                tn = new TreeNode(preorder[i]);
                st.top()->left = tn;
                st.push(tn);
            } else {
                while(!st.empty() and st.top()->val < preorder[i]){
                    prev = st.top();
                    st.pop();
                }
                tn = new TreeNode(preorder[i]);
                prev->right = tn;
                st.push(tn);
            }
        }
        return root;
    }
};

// Method 2 (Reference pointer, O(n)):

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
    
    TreeNode * helper( vector<int> & preorder, int & index, int breaker){
        if(index >= preorder.size() or preorder[index]>breaker) return NULL;
        TreeNode * root = new TreeNode(preorder[index]);
        index++;
        root->left = helper(preorder, index, preorder[index-1]);
        root->right = helper(preorder, index, breaker);
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size() == 0){
            return NULL;
        }
        int index = 0;
        return helper(preorder, index, INT_MAX);
    }
};

// Method 3 (Recursion, O(n2)):

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
    
    TreeNode * helper(vector<int>& preorder, int st, int end){
        if(st >= end) return NULL;
        int val = preorder[st], i;
        for(i = st+1; i<end; i++){
            if(preorder[i] > val) break;
        }
        return new TreeNode(val, helper(preorder, st+1, i), helper(preorder, i, end));
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        return helper(preorder, 0, n);
    }
};