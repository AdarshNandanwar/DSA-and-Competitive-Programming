// https://leetcode.com/problems/surrounded-regions/

int dir[5] = {0, 1, 0, -1, 0};

class Solution {
public:
    void dfs(vector<vector<char>> & board, vector<vector<char>> & orig, int i, int j, int & n, int & m){
        if(i<0 or i>=n or j<0 or j>=m or orig[i][j] == 'X' or board[i][j] == 'O') return;
        board[i][j] = 'O';
        for(int x = 0; x<4; x++) dfs(board, orig, i+dir[x], j+dir[x+1], n, m);
    }
    
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m;
        if(n == 0) return;
        m = board[0].size();
        vector<vector<char>> orig(board);
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                board[i][j] = 'X';
            }
        }
        for(int i = 0; i<n; i++){
            dfs(board, orig, i, 0, n, m);
            dfs(board, orig, i, m-1, n, m);
        }
        for(int j = 0; j<m; j++){
            dfs(board, orig, 0, j, n, m);
            dfs(board, orig, n-1, j, n, m);
        }
    }
};