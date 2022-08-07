// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/

// Method 1 (DFS, O(n*m):

class Solution {
    vector<int> dir = {0, -1, 0, 1, 0};
    int getLongestPathLength(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        int n = matrix.size(), m = matrix[0].size();
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        dp[i][j] = 1;               // visited
        for(int k=0; k<4; k++){
            int nbrI = i+dir[k];
            int nbrJ = j+dir[k+1];
            if(nbrI<0 or nbrJ<0 or nbrI>=n or nbrJ>=m){
                continue;
            }
            if(matrix[i][j] < matrix[nbrI][nbrJ]){
                dp[i][j] = max(dp[i][j], 1+getLongestPathLength(nbrI, nbrJ, matrix, dp));
            }
        }
        return dp[i][j];
    }
public:    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int longestPathLength = 0;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                longestPathLength = max(longestPathLength, getLongestPathLength(i, j, matrix, dp));
            }
        }
        return longestPathLength;
    }
};

// Method 2 (Bottom Up 3D DP, O(n*m*(n*m))):

class Solution {
    vector<int> dir = {0, -1, 0, 1, 0};
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int longestPath = 1;
        // dp[i][j][k] = is it possible to make an increasing path of atleast length k starting at [i, j]
        vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(m, vector<bool>(n*m+1, false)));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                dp[i][j][0] = dp[i][j][1] = true;
            }
        }
        for(int k=2; k<=n*m; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    for(int x=0; x<4; x++){
                        int nbrI = i+dir[x];
                        int nbrJ = j+dir[x+1];
                        if(nbrI<0 or nbrJ<0 or nbrI>=n or nbrJ>=m){
                            continue;
                        }
                        if(matrix[i][j] < matrix[nbrI][nbrJ]){
                            dp[i][j][k] = dp[i][j][k] or dp[nbrI][nbrJ][k-1];
                        }
                    }
                    if(dp[i][j][k]){
                        longestPath = max(longestPath, k);
                    }
                }
            }
            if(longestPath < k){
                break;
            }
        }
        return longestPath;
    }
};

// Method 3 (Priority Queue, O(n4logn), TLE):

class Solution {
    vector<int> dir = {0, -1, 0, 1, 0};
    class Comp {
    public:
        bool operator()(const pair<pair<int, int>, pair<int, int>> & a, const pair<pair<int, int>, pair<int, int>> & b) const {
            return (a.second.first == b.second.first) ? (a.second.second < b.second.second) : (a.second.first > b.second.first);
        }
    };
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int maxLevel = 0;
        // {{row, col}, {value, pathLength}}
        priority_queue<pair<pair<int, int>, pair<int, int>>, vector<pair<pair<int, int>, pair<int, int>>>, Comp> q;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                vector<vector<bool>> visited(n, vector<bool>(m, false));
                q.push(make_pair(make_pair(i, j), make_pair(matrix[i][j], 1)));
                while(!q.empty()){
                    auto cur = q.top();
                    q.pop();
                    int row = cur.first.first;
                    int col = cur.first.second;
                    if(visited[row][col]){
                        continue;
                    }
                    visited[row][col] = true;
                    int value = matrix[row][col];
                    int pathLength = cur.second.second;
                    maxLevel = max(maxLevel, pathLength);
                    for(int k=0; k<4; k++){
                        int nbrRow = row+dir[k];
                        int nbrCol = col+dir[k+1];
                        if(nbrRow<0 or nbrCol<0 or nbrRow>=n or nbrCol>=m){
                            continue;
                        }
                        int nbrValue = matrix[nbrRow][nbrCol];
                        if(!visited[nbrRow][nbrCol] and nbrValue > value){
                            q.push(make_pair(make_pair(nbrRow, nbrCol), make_pair(nbrValue, pathLength+1)));
                        }
                    }
                }
            }
        }
        
        return maxLevel;
    }
};