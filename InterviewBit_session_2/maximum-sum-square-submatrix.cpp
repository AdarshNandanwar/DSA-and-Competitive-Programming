// https://www.interviewbit.com/problems/maximum-sum-square-submatrix/

// Method 1 (Prefix sum, O(n2), O(1) space):

int Solution::solve(vector<vector<int> > &A, int B) {
    int n = A.size(), res = INT_MIN;
    for(int i = 1; i<n; i++){
        for(int j = 0; j<n; j++){
            A[i][j] += A[i-1][j];
        }
    }
    for(int i = 0; i<n; i++){
        for(int j = 1; j<n; j++){
            A[i][j] += A[i][j-1];
        }
    }
    res = A[B-1][B-1];
    for(int i = B; i<n; i++){
        res = max(res, A[i][B-1]-A[i-B][B-1]);
    }
    for(int j = B; j<n; j++){
        res = max(res, A[B-1][j]-A[B-1][j-B]);
    }
    for(int i = B; i<n; i++){
        for(int j = B; j<n; j++){
            res = max(res, A[i][j]-A[i-B][j]-A[i][j-B]+A[i-B][j-B]);
        }
    }
    return res;
}

// Method 2 (Prefix sum, O(n2), O(n2) space):

int Solution::solve(vector<vector<int> > &A, int B) {
    int n = A.size(), res = INT_MIN;
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    for(int i = n-1; i>=0; i--){
        for(int j = n-1; j>=0; j--){
            dp[i][j] = A[i][j]+dp[i+1][j]+dp[i][j+1]-dp[i+1][j+1];
        }
    }
    for(int i = 0; i<n-B+1; i++){
        for(int j = 0; j<n-B+1; j++){
            res = max(res, dp[i][j]-dp[i+B][j]-dp[i][j+B]+dp[i+B][j+B]);
        }
    }
    return res;
}
