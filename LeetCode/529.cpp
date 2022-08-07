// https://leetcode.com/problems/minesweeper/

// Method 1 (DFS, O(n*m)):

class Solution {
    void dfs(vector<vector<char>>& board, vector<int> click){
        int n = board.size(), m = board[0].size();
        int row = click[0], col = click[1];
        if(row<0 or col<0 or row>=n or col>=m or board[row][col]=='B' or isdigit(board[row][col])){
            return;
        }
        if(board[row][col] == 'M'){
            board[row][col] = 'X';
            return;
        }
        board[row][col] = 'B';      // visited
        int mineCount = 0;
        vector<int> deltaRow = {0, 1, 1, 1, 0, -1, -1, -1};
        vector<int> deltaCol = {1, 1, 0, -1, -1, -1, 0, 1};
        for(int k=0; k<8; k++){
            int nbrRow = row+deltaRow[k];
            int nbrCol = col+deltaCol[k];
            if(nbrRow<0 or nbrCol<0 or nbrRow>=n or nbrCol>=m){
                continue;
            }
            if(board[nbrRow][nbrCol]=='M'){
                mineCount++;
            }
        }
        if(mineCount){
            board[row][col] = '0'+mineCount;
            return;
        }
        
        for(int k=0; k<8; k++){
            int nbrRow = row+deltaRow[k];
            int nbrCol = col+deltaCol[k];
            dfs(board, {nbrRow, nbrCol});
        }
    }
    
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        dfs(board, click);
        return board;
    }
};