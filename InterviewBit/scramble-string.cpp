// https://www.interviewbit.com/problems/scramble-string/

bool helper(const string & A, const string & B, int stA, int endA, int stB, int endB, vector<vector<vector<int>>> & dp){
    if(stA == endA) return dp[stA][endA][stB] = A[stA] == B[stB];
    if(dp[stA][endA][stB] != -1) return dp[stA][endA][stB];
    int len = endA-stA+1;
    bool res = 0;
    // i = length of the first part
    for(int i = 1; i<len; i++){
        // no flip
        if(helper(A, B, stA, stA+i-1, stB, stB+i-1, dp) and helper(A, B, stA+i, endA, stB+i, endB, dp)) res = 1;
        if(res) break;
        // flip
        if(helper(A, B, stA, stA+i-1, endB-i+1, endB, dp) and helper(A, B, stA+i, endA, stB, stB+len-i-1, dp)) res = 1;
        if(res) break;
    }
    return dp[stA][endA][stB] = res;
}

int Solution::isScramble(const string A, const string B) {
    int n = A.length(), m = B.length();
    if(n != m) return 0;
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -1)));
    return helper(A, B, 0, n-1, 0, n-1, dp);
}
