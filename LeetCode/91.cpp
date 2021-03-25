// https://leetcode.com/problems/decode-ways/

class Solution {
public:
    int numDecodings(string A) {
        int n = A.length();
        if(n<=0) return 1;
        // dp[i] = no. of ways to decode [i..n)
        vector<int> dp(n+1, 1);

        for(int i = n-1; i>=0; i--){
            if(A[i] == '1'){
                if(i+1<n) dp[i] = dp[i+1]+dp[i+2];
                else dp[i] = dp[i+1];
            } else if(A[i] == '2'){
                if(i+1<n and '0'<=A[i+1] and A[i+1]<='6') dp[i] = dp[i+1]+dp[i+2];
                else dp[i] = dp[i+1];
            } else if(A[i] == '0'){
                dp[i] = 0;
            } else {
                dp[i] = dp[i+1];
            }
        }
        return dp[0];
    }
};