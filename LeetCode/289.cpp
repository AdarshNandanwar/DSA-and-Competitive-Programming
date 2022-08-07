// https://leetcode.com/problems/game-of-life/

// Method 1 (O(n*m) time, O(n*m) space):

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<int>> prev(board);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int liveNbrs = 0;
                int deadNbrs = 0;
                vector<int> deltaI = {0, 1, 1, 1, 0, -1, -1, -1};
                vector<int> deltaJ = {1, 1, 0, -1, -1, -1, 0, 1};
                for(int k=0; k<8; k++){
                    int nbrI = i+deltaI[k];
                    int nbrJ = j+deltaJ[k];
                    if(nbrI>=0 and nbrI<n and nbrJ>=0 and nbrJ<m){
                        if(prev[nbrI][nbrJ] == 1){
                            liveNbrs++;
                        } else {
                            deadNbrs++;
                        }
                    }
                }
                if(board[i][j] == 1){
                    if(liveNbrs<2 or 3<liveNbrs){
                        board[i][j] = 0;
                    }
                } else {
                    if(liveNbrs==3){
                        board[i][j] = 1;
                    }
                }
            }
        }
    }
};