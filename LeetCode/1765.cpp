// https://leetcode.com/problems/map-of-highest-peak/

// Method 1 (Multi Source BFS, O(n*m)):

class Solution {
    vector<int> dirs = {0, -1, 0, 1, 0};
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size(), m = isWater[0].size();
        vector<vector<int>> heights(n, vector<int>(m, -1));
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<vector<int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(isWater[i][j]){
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }
        int curHeight = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto cur = q.front();
                q.pop();
                int i = cur[0];
                int j = cur[1];
                heights[i][j] = curHeight;
                for(int k=0; k<4; k++){
                    int nbrI = i + dirs[k];
                    int nbrJ = j + dirs[k+1];
                    if(nbrI>=0 and nbrJ>=0 and nbrI<n and nbrJ<m and !visited[nbrI][nbrJ]){
                        q.push({nbrI, nbrJ});
                        visited[nbrI][nbrJ] = true;
                    }
                }
            }
            curHeight++;
        }
        return heights;
    }
};
