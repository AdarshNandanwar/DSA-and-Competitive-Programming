//  https://www.interviewbit.com/problems/valid-path/

int dirx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int diry[8] = {0, -1, -1, -1, 0, 1, 1, 1};

bool isValid(int i, int j, int N, int R, vector<int> &X, vector<int> &Y, vector<vector<int>> & dp){
    if(dp[i][j] != -1) return dp[i][j];
    for(int k = 0; k<N; k++){
        if(pow(i-Y[k], 2)+pow(j-X[k], 2) <= R*R) return dp[i][j] = 0;
    }
    return dp[i][j] = 1;
}

void dfs(vector<vector<int>> & visited, int & x, int & y, int  i, int j, int N, int R, vector<int> &X, vector<int> &Y, vector<vector<int>> & valid){
    if(i>y or j>x or i<0 or j<0 or visited[i][j] or !isValid(i, j, N, R, X, Y, valid)) return;
    visited[i][j] = 1;
    for(int k = 0; k<8; k++){
        dfs(visited, x, y, i+diry[k], j+dirx[k], N, R, X, Y, valid);
    }
}

string Solution::solve(int x, int y, int N, int R, vector<int> &X, vector<int> &Y) {
    vector<vector<int>> visited(y+1, vector<int>(x+1, 0)), valid(y+1, vector<int>(x+1, -1));
    dfs(visited, x, y, 0, 0, N, R, X, Y, valid);
    return visited[y][x] ? "YES" : "NO";
}
