// https://leetcode.com/problems/delete-nodes-and-return-forest/

// Method 1 (Recursion, O(n) time):

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
    TreeNode * helper(TreeNode * root, const unordered_set<int> & toDelete, bool isRoot, vector<TreeNode *> & forest){
        if(root == nullptr){
            return root;
        }

        bool deleteCur = toDelete.count(root->val) == 1;

        if(!deleteCur and isRoot){
            forest.push_back(root);
        }

        bool isChildRoot = deleteCur;

        root->left = helper(root->left, toDelete, isChildRoot, forest);
        root->right = helper(root->right, toDelete, isChildRoot, forest);

        return deleteCur ? nullptr : root;
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> toDelete(to_delete.begin(), to_delete.end());
        vector<TreeNode *> forest;
        helper(root, toDelete, true, forest);
        return forest;
    }
};
