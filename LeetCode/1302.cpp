// https://leetcode.com/problems/deepest-leaves-sum/

// Method 1 (Recursion, O(n) time, O(logn) stack space, O(1) space):

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
    
    void helper(TreeNode* root, int level, int & deepest_level, int & ans){
        if(!root) return;
        if(level > deepest_level){
            ans = 0;
            deepest_level = level;
        }
        if(level == deepest_level){
            ans += root->val;
        }
        helper(root->left, level+1, deepest_level, ans);
        helper(root->right, level+1, deepest_level, ans);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        int deepest_level = 0, ans = 0;
        helper(root, 0, deepest_level, ans);
        return ans;
    }
};

// Method 2 (Level order traversal, O(n) time, O(logn) space):

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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode * > q;
        q.push(root);
        int levelSum;
        while(!q.empty()){
            int sz = q.size();
            levelSum = 0;
            while(sz--){
                auto cur = q.front();
                q.pop();
                levelSum += cur->val;
                if(cur->left){
                    q.push(cur->left);
                }
                if(cur->right){
                    q.push(cur->right);
                }
            }
        }
        return levelSum;
    }
};