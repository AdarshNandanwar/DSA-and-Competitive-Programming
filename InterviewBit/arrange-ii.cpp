// https://www.interviewbit.com/problems/arrange-ii/

int helper(string & A, int B, int index, vector<vector<int>> & dp) {
    int res = INT_MAX, bn = 0, wn = 0;
    if(B == 1){
        for(int i = 0; i<=index; i++){
            if(A[i] == 'W') wn++;
            else bn++;
        }
        return bn*wn;
    }
    if(dp[index][B] != -1) return dp[index][B];
    if(A[index] == 'W') wn++;
    else bn++;
    for(int i = index-1; i+1>=B-1; i--){
        res = min(res, bn*wn+helper(A, B-1, i, dp));
        if(A[i] == 'W') wn++;
        else bn++;
    }
    return dp[index][B] = res;
}

int Solution::arrange(string A, int B) {
    int n = A.length();
    if(n<B) return -1;
    // [0..i]
    vector<vector<int>> dp(n, vector<int>(B+1, -1));
    return helper(A, B, n-1, dp);
}