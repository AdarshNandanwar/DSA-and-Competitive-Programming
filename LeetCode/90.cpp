// https://leetcode.com/problems/subsets-ii/

// Method 1 (Recursion, Sort Trick, O(2^n))

class Solution {
public:
    void helper(vector<int> &A, int st, vector<int> & cur, vector<vector<int>> & ans){
        ans.push_back(cur);
        for(int i = st; i<A.size(); i++){
            if(i != st and A[i-1] == A[i]) continue;
            cur.push_back(A[i]);
            helper(A, i+1, cur, ans);
            cur.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& A) {
        vector<vector<int>> ans;
        vector<int> cur;
        sort(A.begin(), A.end());
        helper(A, 0, cur, ans);
        return ans;
    }
};