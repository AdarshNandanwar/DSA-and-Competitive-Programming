// https://www.interviewbit.com/problems/longest-valid-parentheses/

int Solution::longestValidParentheses(string A) {
    
    int n = A.length(), res = 0;
    // dp[i] = lvp in [0..i]
    vector<int> dp(n, 0);
    
    for(int i = 0; i<n; i++){
        if(A[i] == ')'){
            if(i-dp[i-1]-1 >= 0 and A[i-dp[i-1]-1] == '('){
                dp[i] = dp[i-1]+2;
                if(i-dp[i] >= 0) dp[i] += dp[i-dp[i]];
            } 
        }
        res = max(res, dp[i]);
    }
    
    return res;
}
