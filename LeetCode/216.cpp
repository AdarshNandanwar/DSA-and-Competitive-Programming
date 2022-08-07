// https://leetcode.com/problems/combination-sum-iii/

// Method 1 (Backtracking, O(9*8*7)):

class Solution {
public:
    void helper(int st, int k, int target, vector<int> & cur, vector<vector<int>> & ans){
        if(target == 0){
            if(k == 0) ans.push_back(cur);
            return;
        }
        if(k == 0) return;
        for(int i = st; i<=9; i++){
            if(target-i < 0) break;
            cur.push_back(i);
            helper(i+1, k-1, target-i, cur, ans);
            cur.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> cur;
        helper(1, k, n, cur, ans);
        return ans;
    }
};