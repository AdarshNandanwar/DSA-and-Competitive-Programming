// https://www.interviewbit.com/problems/spiral-order-matrix-ii/

vector<vector<int> > Solution::generateMatrix(int A) {
    vector<vector<int>> ans(A, vector<int>(A, 0));
    int dist = 0, k = 1;
    while(k<=A*A){
        for(int i = dist; i<=A-1-dist and k<=A*A; i++) ans[dist][i] = k++;
        for(int i = dist+1; i<=A-1-dist and k<=A*A; i++) ans[i][A-1-dist] = k++;
        for(int i = A-1-dist-1; i>=dist and k<=A*A; i--) ans[A-1-dist][i] = k++;
        for(int i = A-1-dist-1; i>=dist+1 and k<=A*A; i--) ans[i][dist] = k++;
        dist++;
    }
    return ans;
}
