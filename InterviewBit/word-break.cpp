// https://www.interviewbit.com/problems/word-break/

int Solution::wordBreak(string A, vector<string> &B) {
    unordered_set<string> s;
    for(auto i:B) s.insert(i);
    int n = A.length();
    vector<bool> dp(n+1, 0);
    // dp[i] = is possible for [i..n)
    
    dp[n] = 1;
    for(int i = n-1; i>=0; i--){
        string cur = "";
        for(int j = i; j<n; j++){
            cur.push_back(A[j]);
            dp[i] = (s.count(cur) and dp[j+1]);
            if(dp[i]) break;
        }
    }
    return dp[0];
}
