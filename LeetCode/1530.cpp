// https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/

// Method 1 (Recursion, Exploiting constraints, O(n * maxDist) = O(n * 10) = O(n)):

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
    vector<int> helper(TreeNode * root, const int distanceLimit, int & ans){
        if(root == nullptr){
            return vector<int>(11, 0);
        }

        bool isLeaf = root->left == nullptr and root->right == nullptr;

        vector<int> res(11, 0);

        if(isLeaf){
            vector<int> res(11, 0);
            res[0] = 1;
            return res;
        }
        
        vector<int> left = helper(root->left, distanceLimit, ans);
        vector<int> right = helper(root->right, distanceLimit, ans);
        for(int i=10; i>0; i--){
            left[i] = left[i-1];
            right[i] = right[i-1];
            res[i] = left[i] + right[i];
        }
        left[0] = 0;
        right[0] = 0;

        for(int i=0; i<=10; i++){
            for(int j=0; j<=10; j++){
                if(i+j > distanceLimit){
                    break;
                }
                ans += (left[i]*right[j]);
            }
        }
        
        return res;
    }
public:
    int countPairs(TreeNode* root, int distance) {
        int ans = 0;
        helper(root, distance, ans);
        return ans;
    }
};
