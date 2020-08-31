// https://www.interviewbit.com/problems/anti-diagonals/

vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    vector<vector<int>> res;
    int n = A.size();
    if(n == 0) return res;
    int m = A[0].size();
    for(int d = 0; d<=n-1+m-1; d++){
        vector<int> diag;
        for(int i = max(0, d-(m-1)); d-i>=0 and i<n; i++){
            diag.push_back(A[i][d-i]);
        }
        res.push_back(diag);
    }
    return res;
}
