// https://leetcode.com/problems/count-unguarded-cells-in-the-grid/

// Method 1 (Loops, O(n*m)):

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> unchecked(m, vector<int>(n, true));
        vector<vector<bool>> guardsMatrix(m, vector<bool>(n));
        vector<vector<bool>> wallsMatrix(m, vector<bool>(n));
        for(auto guard:guards){
            guardsMatrix[guard[0]][guard[1]] = true;
            unchecked[guard[0]][guard[1]] = false;
        }
        for(auto wall:walls){
            wallsMatrix[wall[0]][wall[1]] = true;
            unchecked[wall[0]][wall[1]] = false;
        }

        for(int i=0; i<m; i++){
            int prevGuard = -1;
            int prevWall = -1;
            for(int j=0; j<n; j++){
                if(guardsMatrix[i][j]){
                    prevGuard = j;
                } else if(wallsMatrix[i][j]){
                    prevWall = j;
                } else {
                    if(prevGuard > prevWall){
                        unchecked[i][j] = false;
                    }
                }
            }
            prevGuard = n;
            prevWall = n;
            for(int j=n-1; j>=0; j--){
                if(guardsMatrix[i][j]){
                    prevGuard = j;
                } else if(wallsMatrix[i][j]){
                    prevWall = j;
                } else {
                    if(prevGuard < prevWall){
                        unchecked[i][j] = false;
                    }
                }
            }
        }
        for(int j=0; j<n; j++){
            int prevGuard = -1;
            int prevWall = -1;
            for(int i=0; i<m; i++){
                if(guardsMatrix[i][j]){
                    prevGuard = i;
                } else if(wallsMatrix[i][j]){
                    prevWall = i;
                } else {
                    if(prevGuard > prevWall){
                        unchecked[i][j] = false;
                    }
                }
            }
            prevGuard = m;
            prevWall = m;
            for(int i=m-1; i>=0; i--){
                if(guardsMatrix[i][j]){
                    prevGuard = i;
                } else if(wallsMatrix[i][j]){
                    prevWall = i;
                } else {
                    if(prevGuard < prevWall){
                        unchecked[i][j] = false;
                    }
                }
            }
        }

        int uncheckedCount = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                uncheckedCount += unchecked[i][j];
            }
        }

        return uncheckedCount;
    }
};
