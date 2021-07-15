// https://www.interviewbit.com/problems/zigzag-level-order-traversal-bt/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    vector<vector<int>> res;
    stack<TreeNode *> st;
    st.push(A);
    while(1){
        vector<TreeNode *> v;
        vector<int> row;
        while(!st.empty()){
            v.push_back(st.top());
            st.pop();
        }
        if(v.size() == 0) break;
        for(auto i:v){
            row.push_back(i->val);
            if(res.size()%2){
                if(i->right) st.push(i->right);
                if(i->left) st.push(i->left);
            } else {
                if(i->left) st.push(i->left);
                if(i->right) st.push(i->right);
            }
        }
        res.push_back(row);
    }
    return res;
}
