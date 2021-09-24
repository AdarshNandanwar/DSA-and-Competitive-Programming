// https://leetcode.com/problems/longest-turbulent-subarray/

// Method 1 (DP with state space optimization, O(n) time, O(1) space):

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size(), res = 1;
        // dp[i][0] = MTS in [0..i] where arr[i-1] > arr[1]
        // dp[i][0] = MTS in [0..i] where arr[i-1] < arr[1]
        vector<vector<int>> dp(2, vector<int>(2, 1));
        for(int i = 1; i<n; i++){
            dp[i%2][0] = dp[i%2][1] = 1;
            if(arr[i-1] < arr[i]) dp[i%2][1] = 1+dp[(i-1)%2][0];
            if(arr[i-1] > arr[i]) dp[i%2][0] = 1+dp[(i-1)%2][1];
            res = max(res, max(dp[i%2][0], dp[i%2][1]));
        }
        return res;
    }
};

// Method 2 (DP, O(n) time, O(n) space):

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size(), res = 1;
        // dp[i][0] = MTS in [0..i] where arr[i-1] > arr[1]
        // dp[i][0] = MTS in [0..i] where arr[i-1] < arr[1]
        vector<vector<int>> dp(n, vector<int>(2, 1));
        for(int i = 1; i<n; i++){
            if(arr[i-1] < arr[i]) dp[i][1] = 1+dp[i-1][0];
            if(arr[i-1] > arr[i]) dp[i][0] = 1+dp[i-1][1];
            res = max(res, max(dp[i][0], dp[i][1]));
        }
        return res;
    }
};