// https://leetcode.com/problems/pacific-atlantic-water-flow/

// Method 1 (Multi Source BFS):

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