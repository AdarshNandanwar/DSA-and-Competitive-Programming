// https://leetcode.com/problems/longest-arithmetic-sequence/

class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int n = A.size(), maxLen = 1;
        if(n == 0) return 0;
        vector<unordered_map<int, int>> dp(n);
        
        for( int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                dp[i][A[i]-A[j]] = dp[j][A[i]-A[j]]+1;
                maxLen = max(maxLen, dp[i][A[i]-A[j]]);
            }
        }
        return maxLen+1;
    }
};

// Time Optimised code

class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int n = A.size(), maxLen = 1, temp, diff = 0;
        if(n == 0) return 0;
        vector<unordered_map<int, int>> dp(n);
        
        for( int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                diff = A[i]-A[j];
                temp = dp[i][diff];
                if(dp[j].find(diff) == dp[j].end()){
                    temp = max(temp, 2);
                } else {
                    temp = dp[j][diff]+1;
                }
                dp[i][diff] = temp;
                maxLen = max(maxLen, temp);
            }
        }
        return maxLen;
    }
};