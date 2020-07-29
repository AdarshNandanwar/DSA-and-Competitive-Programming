// https://www.interviewbit.com/problems/increasing-path-in-matrix/

bool helper(vector<vector<int> > &A, int i, int j){
    int n = A.size(), m = A[0].size();
    if(i == n-1 and j == m-1) return 1;
    bool res = 0;
    if(i+1 < n and A[i][j] < A[i+1][j]) res = res or helper(A, i+1, j);
    if(j+1 < m and A[i][j] < A[i][j+1]) res = res or helper(A, i, j+1);
    return res;
}

int Solution::solve(vector<vector<int> > &A) {
    int n = A.size(); 
    if(n == 0) return -1;
    int m = A[0].size();
    return helper(A, 0, 0) ? n+m-1 : -1;
}
