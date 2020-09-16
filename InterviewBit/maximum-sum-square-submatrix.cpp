// https://www.interviewbit.com/problems/maximum-sum-square-submatrix/

// Method 1 (Prefix Sum, O(n2)):

int Solution::solve(vector<vector<int> > &A, int B) {
    int n = A.size();
    for(int i = 0; i<n; i++){
        for(int j = 1; j<n; j++){
            A[i][j] += A[i][j-1];
        }
    }
    int res = INT_MIN;
    for(int j = B-1; j<n; j++){
        int sum = 0;
        for(int i = 0; i<B; i++) sum += (A[i][j]-(j-B>=0 ? A[i][j-B] : 0));
        res = max(res, sum);
        for(int i = B; i<n; i++){
            sum = sum - (A[i-B][j]-(j-B>=0 ? A[i-B][j-B] : 0)) + (A[i][j]-(j-B>=0 ? A[i][j-B] : 0));
            res = max(res, sum);
        }
    }
    return res;
}
