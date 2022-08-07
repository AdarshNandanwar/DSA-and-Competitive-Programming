// https://leetcode.com/problems/binary-tree-cameras/

// Method 1 (3D DP, O(n*2*2)):

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
    unordered_map<TreeNode *, vector<vector<int>>> dp;
    int getCount(TreeNode * root, bool parent, bool grandParent){
        if(root == NULL){
            return 0;
        }
        if(!dp.count(root)){
            dp[root] = {{-1, -1}, {-1, -1}};
        }
        if(dp[root][parent][grandParent] != -1){
            return dp[root][parent][grandParent];
        }
        // root itself covers root
        int res = 1+getCount(root->left, true, parent)+getCount(root->right, true, parent);
        if(parent){
            // parent covers root
            res = min(res, getCount(root->left, false, parent)+getCount(root->right, false, parent));
        }
        if(!parent and grandParent){
            if(root->right){
                // force right child to cover root
                res = min(res, getCount(root->left, false, true)+getCount(root->right, false, parent));
            }
            if(root->left){
                // force left child to cover root
                res = min(res, getCount(root->left, false, parent)+getCount(root->right, false, true));
            }
        }
        return dp[root][parent][grandParent] = res;
    }
    
public:
    int minCameraCover(TreeNode* root) {
        return getCount(root, false, true);
    }
};

// Method 2 (No DP, TLE):

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
    int getCount(TreeNode * root, bool parent, bool grandParent){
        if(root == NULL){
            return 0;
        }
        // root itself covers root
        int res = 1+getCount(root->left, true, parent)+getCount(root->right, true, parent);
        if(parent){
            // parent covers root
            res = min(res, getCount(root->left, false, parent)+getCount(root->right, false, parent));
        }
        if(!parent and grandParent){
            if(root->right){
                // force right child to cover root
                res = min(res, getCount(root->left, false, true)+getCount(root->right, false, parent));
            }
            if(root->left){
                // force left child to cover root
                res = min(res, getCount(root->left, false, parent)+getCount(root->right, false, true));
            }
        }
        return res;
    }
    
public:
    int minCameraCover(TreeNode* root) {
        return getCount(root, false, true);
    }
};