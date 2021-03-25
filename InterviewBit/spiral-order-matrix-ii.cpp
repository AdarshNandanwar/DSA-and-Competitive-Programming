// https://www.interviewbit.com/problems/spiral-order-matrix-ii/

vector<vector<int> > Solution::generateMatrix(int A) {
    int dist = 0, n = A, num = 1;
    vector<vector<int>> res(n, vector<int>(n, 0));
    while(1){
        for(int j = dist; j<n-dist and dist<(n+1)/2; j++) res[dist][j] = num++;
        for(int i = dist+1; i<n-dist and n-1-dist>=n/2; i++) res[i][n-1-dist] = num++;
        for(int j = n-1-dist-1; j>=dist and n-1-dist>=(n+1)/2; j--) res[n-1-dist][j] = num++;
        for(int i = n-1-dist-1; i>=dist+1 and dist<n/2; i--) res[i][dist] = num++;
        dist++;
        if(dist>n/2) break;
    }
    return res;
}
