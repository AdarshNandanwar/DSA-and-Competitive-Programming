// https://www.interviewbit.com/problems/largest-area-of-rectangle-with-permutations/

// Method (Matrix DP, O(n*m*logm)):

int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    if(n == 0) return 0;
    int m = A[0].size();
    if(m == 0) return 0;
    // col wise prefix sum
    for(int j = 0; j<m; j++){
        for(int i = 1; i<n; i++){
            if(A[i][j]) A[i][j] += A[i-1][j];
        }
    }
    int res = 0;
    for(int i = 0; i<n; i++){
        sort(A[i].begin(), A[i].end(), greater<int>());
        for(int j = 0; j<m; j++) res = max(res, (j+1)*A[i][j]);
    }
    return res;
}
