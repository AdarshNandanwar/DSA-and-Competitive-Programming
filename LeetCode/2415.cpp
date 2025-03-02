// https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/

// Method 1 (Level Order Traversal, O(n) time, O(n) space):

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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode *> q;
        q.push(root);
        int level = 0;
        while(!q.empty()){
            int sz = q.size();
            vector<TreeNode *> levelNodes;
            while(sz--){
                TreeNode * curNode = q.front();
                q.pop();
                levelNodes.push_back(curNode);
                q.push(curNode);
            }
            if(level%2){
                int p1 = 0, p2 = levelNodes.size()-1;
                while(p1 < p2){
                    swap(levelNodes[p1]->val, levelNodes[p2]->val);
                    p1++;
                    p2--;
                }
            }
            sz = q.size();
            while(sz--){
                TreeNode * curNode = q.front();
                q.pop();
                if(curNode->left){
                    q.push(curNode->left);
                }
                if(curNode->right){
                    q.push(curNode->right);
                }
            }
            level++;
        }
        return root;
    }
};
