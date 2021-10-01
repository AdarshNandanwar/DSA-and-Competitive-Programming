// https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/

// Method 1 (3D BFS, O(n*m*k)):

vector<int> dir = {0, -1, 0, 1, 0};

class Solution {
public:
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size(), res = 0;
        vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(k+1, false)));
        queue<vector<int>> q;
        q.push({0, 0, k});
        visited[0][0][k] = true;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto cur = q.front();
                q.pop();
                int i = cur[0];
                int j = cur[1];
                int rem = cur[2];
                if(i == n-1 and j == m-1) return res;
                for(int x=0; x<4; x++){
                    int nbr_i = i+dir[x], nbr_j = j+dir[x+1];
                    if(nbr_i<0 or nbr_i>=n or nbr_j<0 or nbr_j>=m) continue;
                    if(grid[nbr_i][nbr_j] and rem>0 and !visited[nbr_i][nbr_j][rem-1]){
                        q.push({nbr_i, nbr_j, rem-1});
                        visited[nbr_i][nbr_j][rem-1] = true;
                    }
                    if(!grid[nbr_i][nbr_j] and !visited[nbr_i][nbr_j][rem]){
                        q.push({nbr_i, nbr_j, rem});
                        visited[nbr_i][nbr_j][rem] = true;
                    }
                }
            }
            res++;
        }
        return -1;
    }
};

// Method 2 (Brute Force DFS, TLE):

vector<int> dir = {0, -1, 0, 1, 0};

class Solution {
public:
    
    int helper(vector<vector<int>>& grid, int i, int j, int k, vector<vector<bool>>& visited){
        int n = grid.size(), m = grid[0].size(), res = 2000;
        if(grid[i][j]){
            if(k <= 0) return res;
            k--;
        }
        if(i == n-1 and j == m-1) return 0;
        visited[i][j] = true;
        for(int x = 0; x<4; x++){
            int nbr_i = i+dir[x], nbr_j = j+dir[x+1];
            if(nbr_i<0 or nbr_i>=n or nbr_j<0 or nbr_j>=m or visited[nbr_i][nbr_j]) continue;
            res = min(res, 1+helper(grid, nbr_i, nbr_j, k, visited));
        }
        visited[i][j] = false;
        return res;
    }
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int res = helper(grid, 0, 0, k, visited);
        return res >= 2000 ? -1 : res;
    }
};