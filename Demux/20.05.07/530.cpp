// https://leetcode.com/problems/minimum-absolute-difference-in-bst/

// Method 1 (in order predecessor):

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
    
    void inOrderPredecessor(TreeNode * root, TreeNode * & predecessor, int &res){
        if(!root) return;
        
        inOrderPredecessor(root->left, predecessor, res);
        
        if(predecessor) 
            res = min(res, root->val - predecessor->val);
        predecessor = root;
        cout<<res<<" ";
        
        inOrderPredecessor(root->right, predecessor, res);
    }
    
    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX;
        TreeNode * predecessor = NULL;
        inOrderPredecessor(root, predecessor, ans);
        return ans;
    }
};

// Method 2 (Recursion):

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
    
    int helper(TreeNode * root, int & minVal, int & maxVal){
        
        int leftVal, rightVal, res = INT_MAX, minValLocal = root->val, maxValLocal = root->val;
        
        if(root->left){
            leftVal = helper(root->left, minVal, maxVal);
            res = min(leftVal, root->val - maxVal);
            minValLocal = minVal;
        }
        if(root->right){
            rightVal = helper(root->right, minVal, maxVal);
            res = min(res, min(rightVal, minVal - root->val));
            maxValLocal = maxVal;
        }
        minVal = minValLocal;
        maxVal = maxValLocal;
        return res;
    }
    
    int getMinimumDifference(TreeNode* root) {
        int minVal = root->val, maxVal = root->val;
        
        return helper(root, minVal, maxVal);
    }
};

// Method 3 (inOrder):

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
    
    void inOrder(TreeNode * root, vector<int> & v){
        if(root == NULL)
            return;
        inOrder(root->left, v);
        v.push_back(root->val);
        inOrder(root->right, v);
    }
    
    int getMinimumDifference(TreeNode* root) {
        int minDiff = INT_MAX;
        vector<int> v;
        inOrder(root, v);
        for(int i = 1; i<v.size(); i++){
            minDiff = min(minDiff, v[i]-v[i-1]);
        }
        return minDiff;
    }
};