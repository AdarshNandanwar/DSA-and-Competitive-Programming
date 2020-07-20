// https://leetcode.com/problems/number-of-enclaves/

int dir[5] = {0,1,0,-1,0};

class Solution {
public:
    void dfs(vector<vector<int>> & A, int i, int j, int & n, int & m){
        if(i<0 or i>=n or j<0 or j>=m or A[i][j] == 0) return;
        A[i][j] = 0;
        for(int x = 0; x<4; x++) dfs(A, i+dir[x], j+dir[x+1], n, m);
    }
    
    int numEnclaves(vector<vector<int>>& A) {
        int n = A.size(), m = A[0].size();
        for(int i=0; i<n; i++){
            dfs(A, i, 0, n, m);
            dfs(A, i, m-1, n, m);
        }
        for(int j=0; j<m; j++){
            dfs(A, 0, j, n, m);
            dfs(A, n-1, j, n, m);
        }
        int count = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                count += A[i][j];
            }
        }
        return count;
    }
};