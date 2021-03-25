// https://leetcode.com/problems/pacific-atlantic-water-flow/

// Method 1 (Multi Source BFS):

class Solution {
public:
    
    vector<int> dir = {0, 1, 0, -1, 0};
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n <= 0) return {};
        int m = matrix[0].size();
        
        vector<vector<int>> ans;
        queue<pair<int, int>> q;
        
        
        // PACIFIC
        vector<vector<bool>> visited_pacific(n, vector<bool>(m, false));
        // -1: unvisited, 0: visited, 1: reaches ocean        
        
        for(int i=0; i<n; i++){
            q.push({i, 0});
            visited_pacific[i][0] = 1;
        } 
        for(int i=0; i<m; i++){
            q.push({0, i});
            visited_pacific[0][i] = 1;
        }
        
        while(!q.empty()){
            auto cur = q.front();
            int i = cur.first, j = cur.second;
            q.pop();
            for(int k = 0; k<4; k++){
                int I = i+dir[k], J = j+dir[k+1];
                if(I<0 or J<0 or I>=n or J>=m or visited_pacific[I][J]) continue;
                if(matrix[I][J] >= matrix[i][j]){
                    q.push({I, J});
                    visited_pacific[I][J] = 1;
                }
            }
        }
        
        
        // ATLANTIC
        vector<vector<bool>> visited_atlantic(n, vector<bool>(m, false));
        // -1: unvisited, 0: visited, 1: reaches ocean       
        
        for(int i=0; i<n; i++){
            q.push({i, m-1});
            visited_atlantic[i][m-1] = 1;
        } 
        for(int i=0; i<m; i++){
            q.push({n-1, i});
            visited_atlantic[n-1][i] = 1;
        }
        
        while(!q.empty()){
            auto cur = q.front();
            int i = cur.first, j = cur.second;
            q.pop();
            for(int k = 0; k<4; k++){
                int I = i+dir[k], J = j+dir[k+1];
                if(I<0 or J<0 or I>=n or J>=m or visited_atlantic[I][J]) continue;
                if(matrix[I][J] >= matrix[i][j]){
                    q.push({I, J});
                    visited_atlantic[I][J] = 1;
                }
            }
        }
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(visited_pacific[i][j] and visited_atlantic[i][j]) ans.push_back({i,j});
            }
        }
        
        
        return ans;
    }
};

// Method 1 (Multi Source BFS, Alternate Code):

int dir[5] = {0, 1, 0, -1, 0};

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& A) {
        int n = A.size();
        vector<vector<int>> res;
        if(n == 0) return res;
        int m = A[0].size();

        vector<vector<bool>> visitedBlue(n, vector<bool>(m, 0));
        queue<pair<int, int>> q;
        for(int i = 0; i<n; i++){
            q.push({i, 0});
            visitedBlue[i][0] = 1;
        }
        for(int j = 1; j<m; j++){
            q.push({0, j});
            visitedBlue[0][j] = 1;
        }
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            for(int k = 0; k<4; k++){
                int i = cur.first+dir[k], j = cur.second+dir[k+1];
                if(i>=0 and j>=0 and i<n and j<m and !visitedBlue[i][j] and A[i][j] >= A[cur.first][cur.second]){
                    visitedBlue[i][j] = 1;
                    q.push({i, j});
                }
            }
        }

        vector<vector<bool>> visitedRed(n, vector<bool>(m, 0));
        q = queue<pair<int,int>>();
        for(int i = 0; i<n; i++){
            q.push({i, m-1});
            visitedRed[i][m-1] = 1;
        }
        for(int j = 0; j<m-1; j++){
            q.push({n-1, j});
            visitedRed[n-1][j] = 1;
        }
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            for(int k = 0; k<4; k++){
                int i = cur.first+dir[k], j = cur.second+dir[k+1];
                if(i>=0 and j>=0 and i<n and j<m and !visitedRed[i][j] and A[i][j] >= A[cur.first][cur.second]){
                    visitedRed[i][j] = 1;
                    q.push({i, j});
                }
            }
        }
        int count = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(visitedBlue[i][j] and visitedRed[i][j]) res.push_back({i, j});
            }
        }
        return res;
    }
};

// Method 2 (DFS, TLE):

class Solution {
public:
    
    vector<int> dir = {0, 1, 0, -1, 0};
    
    bool helper_pacific(vector<vector<int>>& matrix, int i, int j, vector<vector<int>> & visited){
        int n = matrix.size(), m = matrix[0].size();
            
        if(visited[i][j] != -1) return visited[i][j];
        visited[i][j] = 0;
        
        for(int k = 0; k<4; k++){
            int next_i = i+dir[k], next_j = j+dir[k+1];
        
            if(next_i == -1 or next_j == -1){
                visited[i][j] = 1;
                continue;
            } 
            if(next_i == n or next_j == m) continue;
            
            if(matrix[next_i][next_j] <= matrix[i][j] and helper_pacific(matrix, next_i, next_j, visited)) visited[i][j] = 1;
        }
        
        return visited[i][j];
    }
    
    bool helper_atlantic(vector<vector<int>>& matrix, int i, int j, vector<vector<int>> & visited){
        int n = matrix.size(), m = matrix[0].size();
            
        if(visited[i][j] != -1) return visited[i][j];
        visited[i][j] = 0;
        
        for(int k = 0; k<4; k++){
            int next_i = i+dir[k], next_j = j+dir[k+1];
        
            if(next_i == -1 or next_j == -1) continue;
            if(next_i == n or next_j == m){
                visited[i][j] = 1;
                continue;
            }
            
            if(matrix[next_i][next_j] <= matrix[i][j] and helper_atlantic(matrix, next_i, next_j, visited)) visited[i][j] = 1;
        }
        
        return visited[i][j];
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n <= 0) return {};
        int m = matrix[0].size();
        
        vector<vector<int>> ans;
        
        vector<vector<int>> visited_pacific(n, vector<int>(m, -1)), visited_atlantic(n, vector<int>(m, -1));;
        // -1: unvisited, 0: visited, 1: reaches ocean
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(helper_pacific(matrix, i, j, visited_pacific) and helper_atlantic(matrix, i, j, visited_atlantic)) ans.push_back({i,j});
                visited_pacific = visited_atlantic = vector<vector<int>>(n, vector<int>(m, -1));
            }
        }
        
        
        return ans;
    }
};