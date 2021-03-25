// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

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
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root == NULL) return {};
        vector<vector<int>> v(2001);
        int maxLeft = 1000, maxRight = 1000;
        
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1000});
        while(!q.empty()){
            unordered_map<int, set<int>> m;
            int sz = q.size();
            for(int i = 0; i<sz; i++){
                auto cur = q.front();
                q.pop();
                m[cur.second].insert(cur.first->val);
                maxLeft = min(cur.second, maxLeft);
                maxRight = max(cur.second, maxRight);
                if(cur.first->left) q.push({cur.first->left, cur.second-1});
                if(cur.first->right) q.push({cur.first->right, cur.second+1});
            }
            for(auto i:m){
                for(auto j:i.second){
                    v[i.first].push_back(j);
                }
            }
        }
        return vector<vector<int>>(v.begin()+maxLeft, v.begin()+maxRight+1);
    }
};