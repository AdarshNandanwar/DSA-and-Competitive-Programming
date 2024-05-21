// https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/description/

// Method 1 (Recursion, O(n)):

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
    bool isPseudoPalindromicPath(const vector<int>& freq){
        int oddCount = 0;
        for(int i=1; i<=9; i++){
            if(freq[i] % 2 == 1){
                oddCount++;
            }
        }
        return oddCount <= 1;
    }

    int countPseudoPalindromicPaths(TreeNode * root, vector<int>& freq){
        freq[root->val]++;
        int res = 0;

        if(root->left == nullptr and root->right == nullptr){
            res = isPseudoPalindromicPath(freq);
        }

        if(root->left){
            res += countPseudoPalindromicPaths(root->left, freq);
        }
        if(root->right){
            res += countPseudoPalindromicPaths(root->right, freq);
        }
        
        freq[root->val]--;
        return res;        
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> freq(10, 0);
        return countPseudoPalindromicPaths(root, freq);
    }
};
