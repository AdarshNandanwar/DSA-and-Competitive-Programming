// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

// Method 1 (Hash Map, Recursion, O(n)):

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
    TreeNode * makeTree(const vector<int> & preorder, const vector<int> & inorder, int & index, int left, int right, unordered_map<int, int> & inorderIndex){
        if(left > right){
            return NULL;
        }
        int value = preorder[index];
        TreeNode * root = new TreeNode(value);
        index++;
        root->left = makeTree(preorder, inorder, index, left, inorderIndex[value]-1, inorderIndex);
        root->right = makeTree(preorder, inorder, index, inorderIndex[value]+1, right, inorderIndex);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size(), index = 0;
        unordered_map<int, int> inorderIndex;
        for(int i=0; i<n; i++){
            inorderIndex[inorder[i]] = i;
        }
        return makeTree(preorder, inorder, index, 0, n-1, inorderIndex);
    }
};

// Method 2 (Recursion, O(n)):

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
    TreeNode * helper(vector<int> & preOrd, int preSt, int preEnd, vector<int> & inOrd, int inSt, int inEnd){
        if(preSt > preEnd) return NULL;
        if(preSt == preEnd) return new TreeNode(preOrd[preSt]);

        int pivot = preOrd[preSt], i;
        for(i = inSt; i<=inEnd; i++) if(inOrd[i] == pivot) break;

        TreeNode * root = new TreeNode(pivot);
        root->left = helper(preOrd, preSt+1, preSt+1+(i-inSt-1), inOrd, inSt, i-1);
        root->right = helper(preOrd, preSt+1+(i-inSt), preEnd, inOrd, i+1, inEnd);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return helper(preorder, 0, n-1, inorder, 0, n-1);
    }
};