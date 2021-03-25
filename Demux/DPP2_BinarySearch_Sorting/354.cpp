// https://leetcode.com/problems/russian-doll-envelopes/

bool cmp(vector<int> & a, vector<int> & b){
    if(a[0] == b[0]) return a[1]>b[1];
    else return a[0]<b[0];
}

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size(), lis = 1;
        if(n == 0) return 0;
        
        sort(envelopes.begin(), envelopes.end(), cmp);
        
        // Longest Increasing Subsequence on height
        
        
        // O(nlogn)
        // tails[i] = last element of the longest increasing subsequence of length i+1
        vector<int> tails;
        for(int i = 0; i<n; i++){
            auto it = lower_bound(tails.begin(), tails.end(), envelopes[i][1]);
            if(it == tails.end()){
                tails.push_back(envelopes[i][1]);
            } else {
                *it = envelopes[i][1];
            }
        }
        return tails.size();
        
        
        // O(n2)
        // dp[i] = LIS in [0..i] ending at i
        // vector<int> dp(n, 1);
        // for(int i = 0; i<n; i++){
        //     for(int j=0; j<i; j++){
        //         if(envelopes[j][1] < envelopes[i][1]){
        //             dp[i] = max(dp[i], dp[j]+1);
        //             lis = max(lis, dp[i]);
        //         }
        //     }
        // }
        // return lis;
    }
};