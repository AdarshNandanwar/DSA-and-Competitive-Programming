// https://www.interviewbit.com/problems/black-shapes/

vector<int> dir = {0, -1, 0, 1, 0};

int dfs(vector<string> &A, int i, int j){
    int n = A.size(), m = A[0].length();
    if(i<0 or j<0 or i>=n or j>=m or A[i][j] == 'O') return 0;
    A[i][j] = 'O';
    for(int k = 0; k<4; k++){
        dfs(A, i+dir[k], j+dir[k+1]);
    }
    return 1;
}

int Solution::black(vector<string> &A) {
    int n = A.size(), m = A[0].length();
    int ans = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            ans += dfs(A, i, j);
        }
    }
    return ans;
}
