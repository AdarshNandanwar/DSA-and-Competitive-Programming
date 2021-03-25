// https://www.interviewbit.com/problems/prettyprint/

vector<vector<int> > Solution::prettyPrint(int A) {
    int n = 2*A-1;
    vector<vector<int>> res(n, vector<int>(n, 0));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            res[i][j] = max(max(A-i, A-j), max(A-(n-i-1), A-(n-j-1)));
        }
    }
    return res;
}
