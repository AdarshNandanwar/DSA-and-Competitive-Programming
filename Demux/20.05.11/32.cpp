// https://leetcode.com/problems/longest-valid-parentheses/

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length(), maxLen = 0;
        vector<int> dp(n, 0);
        for(int i=1; i<n; i++){
            if(s[i]==')' and i-1-dp[i-1]>=0 and s[i-1-dp[i-1]] == '('){
                dp[i] = 2+dp[i-1];
                if(i-1-dp[i-1]-1>=0)
                    dp[i] += dp[i-1-dp[i-1]-1];
            }
            maxLen = max(maxLen, dp[i]);
        }
        return maxLen;
    }
};

// Same logic, less efficient (useless loop, always constant number of itertions)

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length(), maxLen = 0;
        
        vector<int> dp(n, 0);
        for(int i =0; i<n; i++){
            if(s[i] == ')'){
                int j = i-1;
                while(j>=0){
                    if(s[j] == '('){
                        dp[i] = i-j+1;
                        if(j>0){
                            dp[i] += dp[j-1];
                        }
                        break;
                    } else {
                        if(dp[j]){
                            j -= dp[j];
                        } else {
                            break;
                        }
                    }
                }
            }
            maxLen = max(maxLen, dp[i]);
        }
        return maxLen;
    }
};