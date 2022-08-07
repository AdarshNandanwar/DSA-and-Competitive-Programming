// https://leetcode.com/problems/surrounded-regions/

// Method 1 (Inverse BFS, O(n*m)):

class Solution {
public:
    
    vector<int> dir = {0, -1, 0, 1, 0};
    
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<char>> origBoard = board;
        queue<pair<int, int>> q;
        for(int i = 0; i<n; i++){
            if(board[i][0] == 'O') q.push({i, 0});
            if(board[i][m-1] == 'O') q.push({i, m-1});
            board[i][0] = board[i][m-1] = 'X';
        }
        for(int j = 0; j<m; j++){
            if(board[0][j] == 'O') q.push({0, j});
            if(board[n-1][j] == 'O') q.push({n-1, j});
            board[0][j] = board[n-1][j] = 'X';
        }
        while(!q.empty()){
            int curI = q.front().first;
            int curJ = q.front().second;
            q.pop();
            for(int k = 0; k<4; k++){
                int nbrI = curI+dir[k];
                int nbrJ = curJ+dir[k+1];
                if(nbrI>=0 and nbrI<n and nbrJ>=0 and nbrJ<m and board[nbrI][nbrJ] == 'O'){
                    q.push({nbrI, nbrJ});
                    board[nbrI][nbrJ] = 'X';
                }
            }
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(origBoard[i][j] == 'O'){
                    if(board[i][j] == 'O') board[i][j] = 'X';
                    else board[i][j] = 'O';
                } 
            }
        }
    }
};

// Method 2 (DFS, O(n*m)):

class Solution {
public:
    vector<int> dir = {0,-1,0,1,0};
    
    void dfs(vector<vector<char>>& board, int row, int col){
        int n = board.size(), m = board[0].size();
        if(!(row>=0 and col>=0 and row<n and col<m)) return;
        if(board[row][col] != 'O') return;
        board[row][col] = 'o';
        for(int i=0; i<4; i++){
            int nbrRow = row+dir[i];
            int nbrCol = col+dir[i+1];
            dfs(board, nbrRow, nbrCol);
        }
    }
    
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        for(int i=0; i<n; i++){
            dfs(board, i, 0);
            dfs(board, i, m-1);
        }
        for(int j=0; j<m; j++){
            dfs(board, 0, j);
            dfs(board, n-1, j);
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                if(board[i][j] == 'o') board[i][j] = 'O';
            }
        }
    }
};

// Alternate Code:

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