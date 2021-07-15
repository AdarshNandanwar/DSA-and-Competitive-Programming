// https://www.interviewbit.com/problems/spiral-order-matrix-i/

// Method 1 (Distance Method);

vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
    int n = A.size();
    if(n == 0) return {};
    int m = A[0].size(), dist = 0;
    vector<int> res;
    while(res.size() < n*m){
        for(int i = dist; i<m-dist and res.size()<n*m; i++) res.push_back(A[dist][i]);
        for(int i = dist+1; i<n-dist and res.size()<n*m; i++) res.push_back(A[i][m-1-dist]);
        for(int i = m-1-dist-1; i>=dist and res.size()<n*m; i--) res.push_back(A[n-1-dist][i]);
        for(int i = n-1-dist-1; i>=dist+1 and res.size()<n*m; i--) res.push_back(A[i][dist]);
        dist++;
    }
    return res;
}

// Method 2:

vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
    int n = A.size();
    if(n == 0) return {};
    int m = A[0].size();
    int right = m-1, left = 0, up = 1, down = n-1, i = 0, j = 0;
    vector<int> res;
    while(res.size() < n*m-1){
        while(res.size() < n*m-1 and j<right) res.push_back(A[i][j++]);
        while(res.size() < n*m-1 and i<down) res.push_back(A[i++][j]);
        while(res.size() < n*m-1 and j>left) res.push_back(A[i][j--]);
        while(res.size() < n*m-1 and i>up) res.push_back(A[i--][j]);
        right--; down--; left++; up++;
    }
    res.push_back(A[i][j]);
    return res;
}