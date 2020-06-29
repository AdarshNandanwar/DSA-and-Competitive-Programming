// https://leetcode.com/problems/maximum-length-of-repeated-subarray/

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int na = A.size(), nb = B.size();
        
        // longest common subarray
        // dp[i][j] = longest common subarray ending at i-1 and j-1
        
        vector<vector<int>> dp(na+1, vector<int>(nb+1, 0));
        int maxLen = 0;
        
        for(int i =1; i<=na; i++){
            for(int j =1; j<=nb; j++){
                dp[i][j] = (A[i-1] == B[j-1])?1+dp[i-1][j-1]:0;
                maxLen = max(maxLen, dp[i][j]);
            }
        }
        
        return maxLen;
    }
};