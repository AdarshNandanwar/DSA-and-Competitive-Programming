// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

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