// https://www.interviewbit.com/problems/vertical-order-traversal-of-binary-tree/

// Wrong question: its asking level order and not pre order

// Method * (Correct code according to wrong question, pre order):

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void helper(TreeNode* A, int index, int & lo, int & hi, unordered_map<int, vector<int>> & m) {
    if(!A) return;
    lo = min(index, lo);
    hi = max(index, hi);
    helper(A->left, index-1, lo, hi, m);
    if(m.count(index)) m[index].push_back(A->val);
    else m[index] = vector(1, A->val);
    helper(A->right, index+1, lo, hi, m);
}
 
vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
    if(!A) return {};
    vector<vector<int>> res;
    int lo = 0, hi = 0;
    unordered_map<int, vector<int>> m;
    helper(A, 0, lo, hi, m);
    for(int i = lo; i<=hi; i++){
        res.push_back(m[i]);
    }
    return res;
}

// Method 1 (Correct code according to corrected question, level order):

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
    if(!A) return {};
    vector<vector<int>> res;
    int index = 0, lo = 0, hi = 0;
    unordered_map<int, vector<int>> m;
    queue<pair<TreeNode *, int>> q;
    q.push({A, 0});
    while(1){
        vector<pair<TreeNode *, int>> v;
        while(!q.empty()){
            auto cur = q.front();
            v.push_back(cur);
            if(m.count(cur.second)) m[cur.second].push_back(cur.first->val);
            else m[cur.second] = {cur.first->val};
            lo = min(lo, cur.second);
            hi = max(hi, cur.second);
            q.pop();
        }
        if(!v.size()) break;
        for(auto i:v){
            if(i.first->left) q.push({i.first->left, i.second-1});
            if(i.first->right) q.push({i.first->right, i.second+1});
        }
    }
    for(int i = lo; i<=hi; i++){
        res.push_back(m[i]);
    }
    return res;
}
