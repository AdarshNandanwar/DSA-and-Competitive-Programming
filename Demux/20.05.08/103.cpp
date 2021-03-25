// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

// Method 0 (2 stacks, O(n)):

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        vector<int> row;
        stack<TreeNode *> s1, s2;
        s1.push(root);
        while(s1.size() or s2.size()){
            row.clear();
            while(!s1.empty()){
                auto cur = s1.top();
                s1.pop();
                row.push_back(cur->val);
                if(cur->left) s2.push(cur->left);
                if(cur->right) s2.push(cur->right);
            }
            if(row.size()) ans.push_back(row);
            row.clear();
            while(!s2.empty()){
                auto cur = s2.top();
                s2.pop();
                row.push_back(cur->val);
                if(cur->right) s1.push(cur->right);
                if(cur->left) s1.push(cur->left);
            }
            if(row.size()) ans.push_back(row);
        }
        return ans;
    }
};

// Method 1 (Directioal way (long)):

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        
        queue<TreeNode *> q;
        q.push(root);
        bool dir = 1;
        
        while(!q.empty()){
            vector<int> lvl;
            stack<TreeNode *> st;
            int sz = q.size();
            
            // dir = <-------
            for(int i = sz-1; !dir and i>=0; i--){
                TreeNode * curr = q.front();
                q.pop();
                st.push(curr);
                lvl.push_back(curr->val);
            }
            while(!st.empty()){
                auto curr = st.top();
                st.pop();
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            
            // dir = ------->
            for(int i = 0; dir and i<sz; i++){
                TreeNode * curr = q.front();
                q.pop();
                st.push(curr);
                lvl.push_back(curr->val);
            }
            while(!st.empty()){
                auto curr = st.top();
                st.pop();
                if(curr->right) q.push(curr->right);
                if(curr->left) q.push(curr->left);
            }
            
            dir = !dir;
            ans.push_back(lvl);
        }
        return ans;
    }
};

// Method 2 (Reversing odd index vectors):

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        
        queue<TreeNode *> q;
        q.push(root);
        int h = 0;
        
        while(!q.empty()){
            vector<int> lvl;
            int sz = q.size();
            for(int i = 0; i<sz; i++){
                auto curr = q.front();
                q.pop();
                lvl.push_back(curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            if((h++)%2) reverse(lvl.begin(), lvl.end());
            ans.push_back(lvl);
        }
        return ans;
    }
};