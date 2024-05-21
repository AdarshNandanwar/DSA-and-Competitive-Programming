// https://leetcode.com/problems/binary-tree-maximum-path-sum/

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

// Method 1 (Recursion, O(n)):

class Solution {
    int getMaxPathToChildSum(TreeNode * root, int & res){
        if(root == nullptr){
            return 0;
        }
        int left = getMaxPathToChildSum(root->left, res);
        int right = getMaxPathToChildSum(root->right, res);
        int maxSum = root->val;
        maxSum += max(0, left);
        maxSum += max(0, right);
        res = max(res, maxSum);
        return max(root->val, root->val + max(left, right));
    }
public:
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        getMaxPathToChildSum(root, res);
        return res;
    }
};

// Method 2 (Recursion, O(n)):

class Solution {
public:
    
    class PathInfo{
    public:
        int maxSum;
        int maxStraightSum;
        PathInfo(int maxSum, int maxStraightSum): maxSum(maxSum), maxStraightSum(maxStraightSum) {}
    };
    
    PathInfo * maxPathSumRecurse(TreeNode* root){
        if(!root) return new PathInfo(INT_MIN, 0);
        PathInfo * leftInfo = maxPathSumRecurse(root->left);
        PathInfo * rightInfo = maxPathSumRecurse(root->right);
        
        PathInfo * res = new PathInfo(0, 0);
        res->maxStraightSum = max(0, root->val+max(leftInfo->maxStraightSum, rightInfo->maxStraightSum));
        res->maxSum = max(leftInfo->maxSum, rightInfo->maxSum);
        res->maxSum = max(res->maxSum, root->val+leftInfo->maxStraightSum+rightInfo->maxStraightSum);
        return res;
    }
    
    int maxPathSum(TreeNode* root) {
        return maxPathSumRecurse(root)->maxSum;
    }
};