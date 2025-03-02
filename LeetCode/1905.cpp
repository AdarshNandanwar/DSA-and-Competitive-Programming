// https://leetcode.com/problems/count-sub-islands/

// Method 1 (DFS, O(n*m)):

class Solution {
    vector<int> dirs = {0, -1, 0, 1, 0};
    bool dfs(const vector<vector<int>>& grid1, const vector<vector<int>>& grid2, int i, int j, vector<vector<bool>>& visited){
        int n = grid1.size();
        int m = grid1[0].size();
        if(i<0 or j<0 or i>=n or j>=m or grid2[i][j] == 0 or visited[i][j]){
            return true;
        }

        bool isSubIsland = true;
        if(grid1[i][j] == 0){
            isSubIsland = false;
        }
        visited[i][j] = true;
        for(int k=0; k<4; k++){
            if(dfs(grid1, grid2, i+dirs[k], j+dirs[k+1], visited) == false){
                isSubIsland = false;
            }
        }
        return isSubIsland;
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1[0].size();
        int count = 0;
        vector<vector<bool>> visited(n, vector<bool>(m));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid2[i][j] == 1 and !visited[i][j]){
                    count += dfs(grid1, grid2, i, j, visited);
                }
            }
        }
        return count;
    }
};
