// https://www.interviewbit.com/problems/spiral-order-matrix-i/

vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
    int dist = 0, n = A.size();
    vector<int> res;
    if(n == 0) return res;
    int m = A[0].size();
    while(1){
        for(int j = dist; j+dist<m and dist <= n-1-dist; j++) res.push_back(A[dist][j]);
        for(int i = dist+1; i+dist<n and dist <= m-1-dist; i++) res.push_back(A[i][m-1-dist]);
        for(int j = m-1-dist-1; j>=dist and dist < n-1-dist; j--) res.push_back(A[n-1-dist][j]);
        for(int i = n-1-dist-1; i>=dist+1 and m-1-dist > dist; i--) res.push_back(A[i][dist]);
        if(dist++ >= (n+1)/2) break;
    }
    return res;
}
