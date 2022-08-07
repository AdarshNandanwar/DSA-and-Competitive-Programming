// https://leetcode.com/problems/path-with-minimum-effort/

// Mehtod 1 (Dijkstra's Algorithm, O(ElogV) = O(4*n*m*log(n*m)) = O(nmlog(nm))):

class Solution {
    vector<int> dir = {0, -1, 0, 1, 0};
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        // Dijkstra's Algorithm Requirement: 
        // The path weight should not decrease on adding a new node.
        // This is applicable here as we are taking the max. 
        // Hence it will increase or remain the same.
        int n=heights.size(), m=heights[0].size();
        vector<vector<int>> shortestDist(n, vector<int>(m, INT_MAX));
        // {pathCost, {row, col}}
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push(make_pair(0, make_pair(0, 0)));
        shortestDist[0][0] = 0;
        while(!pq.empty()){
            auto cur = pq.top();
            pq.pop();
            int pathCost = cur.first;
            int row = cur.second.first;
            int col = cur.second.second;
            if(shortestDist[row][col] < pathCost){
                continue;
            }
            for(int k=0; k<4; k++){
                int nextRow = row+dir[k];
                int nextCol = col+dir[k+1];
                if(nextRow<0 or nextCol<0 or nextRow>=n or nextCol>=m){
                    continue;
                }
                int nbrCost = abs(heights[row][col]-heights[nextRow][nextCol]);
                int nextPathCost = max(pathCost, nbrCost);
                if(nextPathCost < shortestDist[nextRow][nextCol]){
                    shortestDist[nextRow][nextCol] = nextPathCost;
                    pq.push(make_pair(nextPathCost, make_pair(nextRow, nextCol)));
                }
            }
        }
        return shortestDist[n-1][m-1];
    }
};

// Method 2 (Binary Search + BFS, O((E+V)log(maxHeight)) = O((4*m*n+m*n)log(maxHeight)) = O(nmlog(maxHeight))):

class Solution {
    vector<int> dir = {0, -1, 0, 1, 0};
    
    bool isPath(vector<vector<int>>& heights, int limit){
        // BFS
        int n = heights.size(), m = heights[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<int, int>> q;
        q.push(make_pair(0, 0));
        visited[0][0] = true;
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            int row = cur.first;
            int col = cur.second;
            for(int k=0; k<4; k++){
                int nextRow = row+dir[k];
                int nextCol = col+dir[k+1];
                if(nextRow<0 or nextCol<0 or nextRow>=n or nextCol>=m or visited[nextRow][nextCol]){
                    continue;
                }
                int nbrCost = abs(heights[row][col]-heights[nextRow][nextCol]);
                if(nbrCost <= limit){
                    q.push(make_pair(nextRow, nextCol));
                    visited[nextRow][nextCol] = true;
                }
            }
        }
        return visited[n-1][m-1];
    }
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        // Binary Search
        // FT first T
        int lo = 0, mid, hi = 1e6;
        while(lo<hi){
            mid = lo+(hi-lo)/2;
            if(isPath(heights, mid)){
                hi = mid;
            } else {
                lo = mid+1;
            }
        }
        return lo;
    }
};

// Method 3 (Binary Search + DFS)

// Attempt 1 (Reverse DFS, TLE):

class Solution {
    vector<int> dir = {0, -1, 0, 1, 0};
    void dfs(int row, int col, int cost, vector<vector<int>> & heights, vector<vector<int>> & minCost){
        int n=heights.size(), m=heights[0].size();
        minCost[row][col] = min(minCost[row][col], cost);
        for(int k=0; k<4; k++){
            int nextRow = row+dir[k];
            int nextCol = col+dir[k+1];
            if(nextRow<0 or nextCol<0 or nextRow>=n or nextCol>=m){
                continue;
            }
            int nbrCost = max(cost, abs(heights[row][col]-heights[nextRow][nextCol]));
            if(minCost[nextRow][nextCol] <= nbrCost){
                continue;
            }
            dfs(nextRow, nextCol, nbrCost, heights, minCost);
        }
    }
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size(), m=heights[0].size();
        vector<vector<int>> minCost(n, vector<int>(m, INT_MAX));
        dfs(n-1, m-1, 0, heights, minCost);
        return minCost[0][0];
    }
};

// Attempt 2 (DFS, TLE):

class Solution {
    vector<int> dir = {0, -1, 0, 1, 0};
    int dfs(int row, int col, vector<vector<int>> & heights, vector<vector<bool>> & visited){
        int n=heights.size(), m=heights[0].size();
        if(row == n-1 and col == m-1){
            return 0;
        }
        int cost = INT_MAX;
        visited[row][col] = true;
        for(int k=0; k<4; k++){
            int nextRow = row+dir[k];
            int nextCol = col+dir[k+1];
            if(nextRow<0 or nextCol<0 or nextRow>=n or nextCol>=m or visited[nextRow][nextCol]){
                continue;
            }
            int nbrCost = dfs(nextRow, nextCol, heights, visited);
            cost = min(cost, max(abs(heights[row][col]-heights[nextRow][nextCol]), nbrCost));
        }
        visited[row][col] = false;
        return cost;
    }
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size(), m=heights[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        return dfs(0, 0, heights, visited);
    }
};