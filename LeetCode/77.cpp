// https://leetcode.com/problems/combinations/

// Method 1 (backtracking):

class Solution {
public:
    void helper(int n, int k, int st, vector<int> & cur, vector<vector<int>> & ans){
        if(k == 0){
            ans.push_back(cur);
            return;
        }
        for(int i = st; i<=n; i++){
            cur.push_back(i);
            helper(n, k-1, i+1, cur, ans);
            cur.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> cur;
        helper(n, k, 1, cur, ans);
        return ans;
    }
};