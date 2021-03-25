// https://leetcode.com/problems/find-largest-value-in-each-tree-row/submissions/

//  Method 1 (map):

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
    
    void traverse(TreeNode * root, map<int, int> & m, int h){
        if(root == NULL) return;
        
        if(m.find(h)==m.end()) 
            m[h] = root->val;
        else
            m[h] = max(m[h], root->val);
        traverse(root->right, m, h+1);
        traverse(root->left, m, h+1);
    }
    
    vector<int> largestValues(TreeNode* root) {
        map<int, int> m;
        traverse(root, m, 0);
        vector<int> ans;
        for(auto i:m){
            ans.push_back(i.second);
        }
        return ans;
    }
};

// Method 2 (level order traversal):

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
    
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        
        queue<TreeNode *> q;
        q.push(root);
        
        while(!q.empty()){
            int sz = q.size(), maxLvl = INT_MIN;
            for(int i =0; i<sz; i++){
                TreeNode * curr = q.front();
                q.pop();
                maxLvl = max(maxLvl, curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            ans.push_back(maxLvl);
        }
        return ans;
    }
};