// https://leetcode.com/problems/numbers-with-same-consecutive-differences/

class Solution {
public:
    void helper(int N, int K, int cur, vector<int> & ans){
        if(N == 0) {
            ans.push_back(cur);
            return;
        }
        for(int i = 0; i<10; i++){
            if(abs(i-(cur%10)) == K) helper(N-1, K, cur*10+i, ans);
        }
    }
    
    vector<int> numsSameConsecDiff(int N, int K) {
        vector<int> ans;
        if(N == 1) ans.push_back(0);
        for(int cur = 1; cur<10; cur++) helper(N-1, K, cur, ans);
        return ans;
    }
};