// https://leetcode.com/problems/create-binary-tree-from-descriptions/

// Method 1 (Hash Map, O(n) time, O(n) space):

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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_set<int> rootCandidates;
        unordered_map<int, TreeNode *> m;
        for(auto & edge:descriptions){
            int parent = edge[0];
            int child = edge[1];
            int isLeft = edge[2];

            rootCandidates.insert(parent);

            if(m.count(parent) == 0){
                m[parent] = new TreeNode(parent);
            }
            if(m.count(child) == 0){
                m[child] = new TreeNode(child);
            }

            if(isLeft){
                m[parent]->left = m[child];
            } else {
                m[parent]->right = m[child];
            }
        }
        for(auto & edge:descriptions){
            int child = edge[1];

            rootCandidates.erase(child);
        }

        return m[*rootCandidates.begin()];
    }
};
