// https://leetcode.com/problems/decode-ways/

// Method 1 (Recursive, O(n)):

class Solution {
    int helper(const string & s, int index, vector<int> & dp){
        int n = s.length();
        if(index == n){
            return 1;
        }
        if(s[index] == '0'){
            return 0;
        }
        
        if(dp[index] != -1){
            return dp[index];
        }

        int ans = helper(s, index+1, dp);        
        if(s[index] == '1' and index+1 < n){
            ans += helper(s, index+2, dp);
        } else if(s[index] == '2' and index+1<n and s[index+1] >= '0' and s[index+1] <= '6'){
            ans += helper(s, index+2, dp);
        }
        return dp[index] = ans;
    }
public:
    int numDecodings(string s) {
        vector<int> dp(s.length(), -1);
        return helper(s, 0, dp);
    }
};

// Method 2 (Iterative, O(n)):

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