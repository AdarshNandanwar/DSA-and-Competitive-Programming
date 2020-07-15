// https://leetcode.com/problems/maximum-width-of-binary-tree/

// Method 1 (level order traversal, O(n)):

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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        int sz, maxWidth = 0, firstIndex;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        while(!q.empty()){
            sz = q.size();
            for(int i = 0; i<sz; i++){
                auto t = q.front();
                q.pop();
                if(i == 0) firstIndex = t.second;
                maxWidth = max(maxWidth, t.second-firstIndex+1);
                
                // subtracting 2*firstIndex to make the index of first entry of the level 0 to prevent overflow
                if(t.first->left) q.push({t.first->left, 2*t.second-2*firstIndex});
                if(t.first->right) q.push({t.first->right, 2*t.second+1-2*firstIndex});
            }
        }
        return maxWidth;
    }
};