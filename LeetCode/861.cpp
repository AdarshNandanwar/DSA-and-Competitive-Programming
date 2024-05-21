// https://leetcode.com/problems/score-after-flipping-matrix/

// Method 1 (Bit Manipulation, O((n*m)):

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> rowValues;
        for(int i=0; i<n; i++){
            int rowValue = 0;
            for(int j=0; j<m; j++){
                rowValue <<= 1;
                rowValue += grid[i][j];
            }
            rowValues.push_back(rowValue);
        }
        for(int i=0; i<n; i++){
            if(grid[i][0] == 0){
                rowValues[i] ^= ((1<<m)-1);
            }
        }
        for(int j=1; j<m; j++){
            int setBits = 0;
            for(int i=0; i<n; i++){
                if((rowValues[i]>>(m-1-j))&1){
                    setBits++;
                }
            }
            if(setBits < (n+1)/2){                
                for(int i=0; i<n; i++){
                    rowValues[i] ^= (1<<(m-1-j));
                }
            }
        }
        
        int score = 0;
        for(int rowValue:rowValues){
            score += rowValue;
        }
        return score;
    }
};

// Method 2 (Brute Force, O((n+m)*2^(n+m))):

class Solution {
    int helper(vector<vector<int>> & grid, int row, int col){
        int n = grid.size();
        int m = grid[0].size();
        int score = 0;
        if(row == n){
            if(col == m){
                for(int i=0; i<n; i++){
                    int num = 0;
                    for(int j=0; j<m; j++){
                        num <<= 1;
                        num |= grid[i][j];
                    }
                    score += num;
                }
            } else {
                score = helper(grid, row, col+1);
                for(int i=0; i<n; i++){
                    grid[i][col] ^= 1;
                }
                score = max(score, helper(grid, row, col+1));
                for(int i=0; i<n; i++){
                    grid[i][col] ^= 1;
                }
            }
        } else {
            score = helper(grid, row+1, col);
            for(int j=0; j<m; j++){
                grid[row][j] ^= 1;
            }
            score = max(score, helper(grid, row+1, col));
            for(int j=0; j<m; j++){
                grid[row][j] ^= 1;
            }
        }
        return score;
    }
public:
    int matrixScore(vector<vector<int>>& grid) {
        return helper(grid, 0, 0);
    }
};
