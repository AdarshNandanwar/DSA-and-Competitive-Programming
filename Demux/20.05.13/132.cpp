// https://leetcode.com/problems/palindrome-partitioning-ii/

class Solution {
public:
    
    bool isPalindrome(string s){
        int n = s.length();
        for(int i = 0; i<n/2; i++){
            if(s[i] != s[n-1-i])    
                return false;
        }
        return true;
    }
    
    int minCut(string s) {
        int n = s.length();
        if(n == 0) return 0;
        vector<int> dp(n+1);
        for(int i =0; i<=n; i++){
            dp[i] = n-i-1;
        }
        for(int i=n-1; i>=0; i--){
            string curr = "";
            for(int j=i; j<n; j++){
                curr += s[j];
                if(isPalindrome(curr)){
                    if(j+1<n)
                        dp[i] = min(dp[i], 1+dp[j+1]);
                    else
                        dp[i] = 0;
                }
            }
        }
        return dp[0];
    }
};