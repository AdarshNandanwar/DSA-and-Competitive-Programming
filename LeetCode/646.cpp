// https://leetcode.com/problems/maximum-length-of-pair-chain/

// Method 1 (Sorting, O(nlogn)):

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](const vector<int> & a, const vector<int> & b){
            return a[1] == b[1] ? a[0] < b[0] : a[1] < b[1];
        });
        int n = pairs.size(), res = 0, curEnd = INT_MIN;
        for(int i = 0; i<n; i++){
            if(pairs[i][0] > curEnd){
                curEnd = pairs[i][1];
                res++;
            }
        }
        return res;
    }
};

// Method 2 (DP, O(n2)):

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        int n = pairs.size(), res = 1;;
        vector<int> dp(n, 1);
        // dp[i] = len of max subseq ending at i
        // dp[i] = max(dp[i], 1+dp[j])
        for(int  i =0; i<n; i++){
            for(int j = 0; j<i; j++){
                if(pairs[i][0] > pairs[j][1]) res = max(res, dp[i] = max(dp[i], 1+dp[j]));
            }
        }
        return res;
    }
};