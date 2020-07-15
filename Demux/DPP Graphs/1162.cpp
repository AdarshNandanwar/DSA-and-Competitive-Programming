// https://leetcode.com/problems/as-far-from-land-as-possible/

int dir[5] = {0,1,0,-1,0};

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        // Multi Source BFS
        queue<pair<int, int>> q;
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 1) q.push({i,j});
            }
        }
        if(q.size() == 0 or q.size() == n*n) return -1;

        int dist = 1, I, J, sz, ans = 0;
        while(!q.empty()){
            sz = q.size();
            while(sz--){
                auto [i, j] = q.front();
                q.pop();
                for(int x = 0; x<4; x++){
                    I = i+dir[x];
                    J = j+dir[x+1];
                    if(I>=0 and J>=0 and I<n and J<m and !grid[I][J]){
                        q.push({I, J});
                        grid[I][J] = 1;
                        ans = max(ans, dist);
                    }
                }
            }
            dist++;
        }
        return ans;
    }
};