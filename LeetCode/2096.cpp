// https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/

// Method 1 (Traversal, Least Common Ancestor, O(n) time, O(n) space):

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
    void getPath(TreeNode * root, int val, string & path){
        if(root == nullptr){
            return;
        }

        if(root->val == val){
            path = "F";
            return;
        }

        getPath(root->left, val, path);
        if(path.length() > 0){
            path.push_back('L');
            return;
        }

        getPath(root->right, val, path);
        if(path.length() > 0){
            path.push_back('R');
            return;
        }
    }
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string startPath, destPath;
        getPath(root, startValue, startPath);
        getPath(root, destValue, destPath);

        reverse(startPath.begin(), startPath.end());
        reverse(destPath.begin(), destPath.end());

        int n = startPath.length();
        int m = destPath.length();

        int i = 0;
        while(i < min(n, m)){
            if(startPath[i] != destPath[i]){
                break;
            }
            i++;
        }

        return string(n-i-1, 'U') + destPath.substr(i, m-i-1);
    }
};
