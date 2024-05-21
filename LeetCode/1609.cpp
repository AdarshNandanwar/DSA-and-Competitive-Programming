// https://leetcode.com/problems/even-odd-tree/

// Method 1 (Level Order Traversal, O(n)):

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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()){
            int prev;
            bool isLevelEven = (level % 2 == 0);
            if(isLevelEven){
                prev = 0;
            } else {
                prev = INT_MAX;
            }

            int sz = q.size();
            while(sz--){
                TreeNode* cur = q.front();
                q.pop();
                bool isValEven = (cur->val % 2 == 0);

                if(isLevelEven){
                    if(isValEven or cur->val <= prev){
                        return false;
                    }
                    prev = cur->val;
                } else {
                    if(!isValEven or cur->val >= prev){
                        return false;
                    }
                    prev = cur->val;
                }

                if(cur->left){
                    q.push(cur->left);
                }
                if(cur->right){
                    q.push(cur->right);
                }
            }
            
            level++;
        }
        return true;
    }
};