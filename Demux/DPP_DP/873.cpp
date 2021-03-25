// https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        int n = A.size(), p1, p2, ans = 1;
        
        // dp[i][j] = length of fib series with i and j as last 2 numbers
        vector<vector<int>> dp(n+1, vector<int>(n+1, 2));
        
        for(int i = 2; i<n; i++){
            p1 = 0; p2 = i-1;
            while(p1<p2){
                if(A[p1]+A[p2] > A[i]){
                    p2--;
                } else if(A[p1]+A[p2] < A[i]){
                    p1++;
                } else {
                    // do something
                    dp[p2][i] = max(dp[p2][i], 1+dp[p1][p2]);
                    ans = max(ans, dp[p2][i]);
                    p1++;
                }
            }
        }
        
        return ans>=3?ans:0;
    }
};