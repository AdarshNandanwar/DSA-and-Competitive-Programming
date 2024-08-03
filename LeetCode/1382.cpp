// https://leetcode.com/problems/balance-a-binary-search-tree/

// Method 1 (Vector conversion, O(n) time, O(n) space):

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
    void fillVector(TreeNode * root, vector<int> & v){
        if(root == nullptr){
            return;
        }
        fillVector(root->left, v);
        v.push_back(root->val);
        fillVector(root->right, v);
    }

    TreeNode * makeTree(const vector<int> & v, int st, int end){
        if(st > end){
            return nullptr;
        }
        int mid = st + (end-st)/2;
        return new TreeNode(
            v[mid],
            makeTree(v, st, mid-1),
            makeTree(v, mid+1, end));
    } 
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> v;
        fillVector(root, v);
        return makeTree(v, 0, v.size()-1);
    }
};
