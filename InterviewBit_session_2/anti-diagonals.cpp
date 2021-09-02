// https://www.interviewbit.com/problems/anti-diagonals/

vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    vector<vector<int>> res;
    int n = A.size();
    if(n == 0) return res;
    int m = A[0].size();
    for(int k = 0; k<n+m-1; k++){
        vector<int> row;
        for(int i = 0; i<=k; i++){
            int j = k-i;
            if(i<n and j<m) row.push_back(A[i][j]);
        }
        res.push_back(row);
    }
    return res;
}
