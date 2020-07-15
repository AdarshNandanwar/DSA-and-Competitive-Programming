// https://leetcode.com/problems/rotting-oranges/

int dir[5] = {0,1,0,-1,0};

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), fresh = 0, I, J, time = 1, sz;
        
        // Multi Source BFS
        queue<pair<int, int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1) fresh++;
                if(grid[i][j] == 2) q.push({i, j});
            }
        }      
        if(fresh == 0) return 0;
        while(!q.empty()){
            sz = q.size();
            while(sz--){
                auto [i, j] = q.front();
                q.pop();
                for(int x = 0; x<4; x++){
                    I = i+dir[x]; J = j+dir[x+1];
                    if(I>=0 and I<n and J>=0 and J<m and grid[I][J] == 1){
                        fresh--;
                        if(fresh == 0) return time;
                        q.push({I, J});
                        grid[I][J] = 2;
                    }
                }
            }
            time++;
        }
        return -1;
    }
};