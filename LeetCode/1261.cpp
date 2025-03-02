// https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/

// Method 1 (DFS, O(n)):

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
class FindElements {
    TreeNode* root;
public:
    FindElements(TreeNode* root) {
        this->root = root;
    }

    bool helper(TreeNode* cur, int curVal, const int target){
        if(cur == nullptr){
            return false;
        }
        if(curVal == target){
            return true;
        }
        if(curVal > target){
            return false;
        }
        return helper(cur->left, 2 * curVal + 1, target) or helper(cur->right, 2 * curVal + 2, target);
    }
    
    bool find(int target) {
        return helper(this->root, 0, target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
