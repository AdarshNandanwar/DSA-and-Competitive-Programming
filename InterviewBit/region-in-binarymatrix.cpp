// https://www.interviewbit.com/problems/region-in-binarymatrix/

// Method 1 (DFS, O(n)):

int dir[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dfs(vector<vector<int> > &A, int i, int j, vector<vector<bool>> & visited){
    int n = A.size(), m = A[0].size(), res = 1;
    if(i<0 or j<0 or i>=n or j>=m or visited[i][j] or !A[i][j]) return 0;
    visited[i][j] = 1;
    for(int x = 0; x<8; x++) res += dfs(A, i+dir[x], j+dir[(x+2)%8], visited);
    return res;
}

int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    if(n == 0) return 0;
    int m = A[0].size(), res = 0;
    vector<vector<bool>> visited(n, vector<bool>(m, 0));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            res = max(res, dfs(A, i, j, visited));
        }
    }
    return res;
}
