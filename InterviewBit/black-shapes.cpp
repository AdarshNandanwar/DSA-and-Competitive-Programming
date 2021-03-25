// https://www.interviewbit.com/problems/black-shapes/

int dir[5] = {0,1,0,-1,0};

void dfs(vector<string> &A, int r, int c, int & n, int & m){
    if(r<0 or c<0 or r>=n or c>=m or A[r][c] == 'O') return;
    A[r][c] = 'O';
    for(int i = 0; i<4; i++) dfs(A, r+dir[i], c+dir[i+1], n, m);
}

int Solution::black(vector<string> &A) {
    int n =A.size();
    if(n == 0) return 0;
    int m = A[0].length();
    int count = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(A[i][j] == 'X'){
                dfs(A, i, j, n, m);
                count++;
            }
        }
    }
    return count;
}
