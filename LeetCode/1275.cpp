// https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/

// Method 1 (Brute Force, O(9)):

class Solution {
public:
    
    int get_status(vector<vector<int>> &grid){
        vector<int> row(3, 0), col(3, 0), diag(2, 0);
        for(int i = 0; i<3; i++){
            for(int j = 0; j<3; j++){
                if(grid[i][j] == 0){
                    row[i]--;
                    col[j]--;
                    if(i == j) diag[0]--;
                    if(i+j == 2) diag[1]--;
                } else if(grid[i][j] == 1){
                    row[i]++;
                    col[j]++;
                    if(i == j) diag[0]++;
                    if(i+j == 2) diag[1]++;
                }
                if(row[i] == -3 or col[j] == -3 or diag[0] == -3 or diag[1] == -3) return 0;
                if(row[i] == 3 or col[j] == 3 or diag[0] == 3 or diag[1] == 3) return 1;
            }
        }
        return -1;
    }
    
    string tictactoe(vector<vector<int>>& moves) {
        int n = moves.size(), status = -1, i;
        vector<vector<int>> grid(3, vector<int>(3, -1));
        for(i = 0; i<moves.size(); i++){
            grid[moves[i][0]][moves[i][1]] = i%2;
            status = get_status(grid);
            if(status == -1) continue;
            return status ? "B" : "A";
        }
        return i == 9 ? "Draw" : "Pending";
    }
};