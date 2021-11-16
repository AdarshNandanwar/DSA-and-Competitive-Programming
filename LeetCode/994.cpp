// https://leetcode.com/problems/rotting-oranges/

// Method 1 (Multi Source BFS, O(n*m)):

class Solution {
public:
    vector<int> dir = {0, -1, 0, 1, 0};
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), time = 0;
        int remaining = n*m;
        // Multi Source BFS
        queue<pair<int, int>> q;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] != 1) remaining--;
                if(grid[i][j] == 2){
                    q.push({i, j});
                    grid[i][j] = 0;
                }
            }
        }
        while(!q.empty() and remaining){
            int sz = q.size();
            while(sz--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                for(int k = 0; k<4; k++){
                    int nbrI = i+dir[k], nbrJ = j+dir[k+1];
                    if(0<=nbrI and nbrI<n and 0<=nbrJ and nbrJ<m and grid[nbrI][nbrJ] == 1){
                        q.push({nbrI, nbrJ});
                        grid[nbrI][nbrJ] = 0;
                        remaining--;
                    }
                }
            }
            time++;
        }
        return remaining ? -1 : time;
    }
};