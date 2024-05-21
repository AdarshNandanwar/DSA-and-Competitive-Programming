// https://leetcode.com/problems/validate-binary-search-tree/

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

// Method 1 (Inorder Traversal, O(n)):

class Solution {
    bool isInOrder(TreeNode * root, long & prev){
        if(root == nullptr){
            return true;
        }
        if(!isInOrder(root->left, prev)){
            return false;
        }
        if(root->val <= prev){
            return false;
        }
        prev = root->val;
        if(!isInOrder(root->right, prev)){
            return false;
        }
        return true;
    }
public:
    bool isValidBST(TreeNode* root) {
        long prev = LONG_MIN;
        return isInOrder(root, prev);
    }
};

// Method 2 (Recursion, O(n)):

class Solution {
public:
    
    bool helper(TreeNode * root, long left, long right){
        if(!root) return 1;
        return left<root->val and root->val<right and helper(root->left, left, root->val) and helper(root->right, root->val, right);
    }
    
    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }
};

// Method 3 (Recursion, O(n)):

class TreeInfo {
public:
    long maxVal, minVal;
    bool isValid;
    TreeInfo(long maxVal, long minVal, bool isValid): maxVal(maxVal), minVal(minVal), isValid(isValid) {}
};

class Solution {
public:
    TreeInfo * isValidHelper(TreeNode * root){
        if(root == NULL){
            return new TreeInfo(LONG_MIN, LONG_MAX, true);
        }
        
        auto leftTreeInfo = isValidHelper(root->left);
        auto rightTreeInfo = isValidHelper(root->right);
        
        bool isValid = leftTreeInfo->isValid and rightTreeInfo->isValid;
        isValid = isValid and leftTreeInfo->maxVal < (long)root->val;
        isValid = isValid and (long)root->val < rightTreeInfo->minVal;
        
        long maxVal = max(leftTreeInfo->maxVal, rightTreeInfo->maxVal);
        maxVal = max(maxVal, (long)root->val);
        
        long minVal = min(leftTreeInfo->minVal, rightTreeInfo->minVal);
        minVal = min(minVal, (long)root->val);
        
        return new TreeInfo(maxVal, minVal, isValid);
    }
    
    bool isValidBST(TreeNode* root) {
        return isValidHelper(root)->isValid;
    }
};