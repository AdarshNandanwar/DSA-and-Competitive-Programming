// https://leetcode.com/problems/find-the-safest-path-in-a-grid/

// Method 1 (BFS + Max Heap, O(n*n*logn)):

class Solution {
    vector<int> dir = {0, -1, 0, 1, 0};
public:
    int maximumSafenessFactor(vector<vector<int>>& grid){
        int n = grid.size();

        // Multi Source BFS
        vector<vector<int>> minimumDistance(n, vector<int>(n, INT_MAX));
        int valuesSet = 0;
        queue<pair<int, int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    minimumDistance[i][j] = 0;
                    valuesSet++;
                    q.push(make_pair(i, j));
                }
            }
        }
        int distance = 1;
        while(!q.empty() and valuesSet < n*n){
            int sz = q.size();
            while(sz--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                for(int k=0; k<4; k++){
                    int nbrI = i + dir[k];
                    int nbrJ = j + dir[k+1];
                    if(nbrI<0 or nbrI>=n or nbrJ<0 or nbrJ>=n or minimumDistance[nbrI][nbrJ]<=distance){
                        continue;
                    }
                    minimumDistance[nbrI][nbrJ] = distance;
                    valuesSet++;
                    q.push(make_pair(nbrI, nbrJ));
                }
            }
            distance++;
        }
        
        // Max Heap
        vector<vector<bool>> visited(n, vector<bool>(n));
        int safenessFactor = minimumDistance[0][0];
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>> pq;
        visited[0][0] = true;
        pq.push(make_pair(minimumDistance[0][0], make_pair(0, 0)));
        while(!pq.empty()){
            auto cur = pq.top();
            safenessFactor = min(safenessFactor, cur.first);
            int i = cur.second.first;
            int j = cur.second.second;
            pq.pop();

            if(i == n-1 and j == n-1){
                return safenessFactor;
            }

            for(int k=0; k<4; k++){
                int nbrI = i + dir[k];
                int nbrJ = j + dir[k+1];
                if(nbrI<0 or nbrI>=n or nbrJ<0 or nbrJ>=n or visited[nbrI][nbrJ]){
                    continue;
                }
                visited[nbrI][nbrJ] = true;
                pq.push(make_pair(minimumDistance[nbrI][nbrJ], (make_pair(nbrI, nbrJ))));
            }
        }

        return -1;
    }
};

// Method 2 (Binary Search + BFS + DFS, O((logn)*(n*m)), TLE):

class Solution {
    vector<int> dir = {0, -1, 0, 1, 0};

    // DFS
    bool isPath(const vector<vector<int>> & minimumDistance, int i, int j, const int safenessFactor, vector<vector<bool>> & visited){
        int n = minimumDistance.size();
        if(i<0 or i>=n or j<0 or j>=n or minimumDistance[i][j]<safenessFactor or visited[i][j]){
            return false;
        }
        if(i == n-1 and j == n-1){
            return true;
        }
        visited[i][j] = true;
        
        for(int k=0; k<4; k++){
            int nbrI = i+dir[k];
            int nbrJ = j+dir[k+1];
            if(isPath(minimumDistance, nbrI, nbrJ, safenessFactor, visited)){
                return true;
            }
        }
        return false;
    }
public:
    int maximumSafenessFactor(vector<vector<int>>& grid){
        int n = grid.size();

        vector<vector<int>> minimumDistance(n, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    minimumDistance[i][j] = 0;
                    q.push(make_pair(i, j));
                }
            }
        }
        int distance = 1;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                for(int k=0; k<4; k++){
                    int nbrI = i + dir[k];
                    int nbrJ = j + dir[k+1];
                    if(nbrI<0 or nbrI>=n or nbrJ<0 or nbrJ>=n or minimumDistance[nbrI][nbrJ]<=distance){
                        continue;
                    }
                    minimumDistance[nbrI][nbrJ] = distance;
                    q.push(make_pair(nbrI, nbrJ));
                }
            }
            distance++;
        }

        // Binary Search
        // TF Last T
        int lo = 0, hi = n-1, mid;
        while(lo<hi){
            vector<vector<bool>> visited(n, vector<bool>(n));
            mid = lo+(hi-lo+1)/2;
            if(isPath(minimumDistance, 0, 0, mid, visited)){
                lo = mid;
            } else {
                hi = mid-1;
            }
        }
        return lo;
    }
};

// Alternate Code (Without constructing minimumDistance matrix):

class Solution {
    vector<int> dir = {0, -1, 0, 1, 0};

    // DFS
    bool isPath(const vector<vector<int>> & grid, int i, int j, vector<vector<bool>> & visited){
        int n = grid.size();
        if(i<0 or i>=n or j<0 or j>=n or grid[i][j] or visited[i][j]){
            return false;
        }
        if(i == n-1 and j == n-1){
            return true;
        }
        visited[i][j] = 1;
        for(int k=0; k<4; k++){
            int nbrI = i+dir[k];
            int nbrJ = j+dir[k+1];
            if(isPath(grid, nbrI, nbrJ, visited)){
                return true;
            }
        }
        return false;
    }

    bool predicate(vector<vector<int>> grid, int minDistanceToThief) {
        if(minDistanceToThief == 0){
            return true;
        }

        int n = grid.size();
        
        // BFS
        queue<pair<int, int>> q;
        for(int i=0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j]){
                    q.push(make_pair(i, j));
                }
            }
        }

        minDistanceToThief--;
        while(minDistanceToThief--){
            int sz = q.size();
            while(sz--){
                auto cur = q.front();
                int i = cur.first;
                int j = cur.second;
                q.pop();
                for(int k=0; k<4; k++){
                    int nbrI = i + dir[k];
                    int nbrJ = j + dir[k+1];
                    if(nbrI<0 or nbrI>=n or nbrJ<0 or nbrJ>=n or grid[nbrI][nbrJ]){
                        continue;
                    }
                    grid[nbrI][nbrJ] = 1;
                    q.push(make_pair(nbrI, nbrJ));
                }
            }
        }

        vector<vector<bool>> visited(n, vector<bool>(n));
        return isPath(grid, 0, 0, visited);
    }
public:
    int maximumSafenessFactor(vector<vector<int>>& grid){
        // Binary Search
        // TF Last T
        int n = grid.size();
        int lo = 0, hi = n-1, mid;
        while(lo<hi){
            mid = lo+(hi-lo+1)/2;
            if(predicate(grid, mid)){
                lo = mid;
            } else {
                hi = mid-1;
            }
        }
        return lo;
    }
};

// Method 3 (BFS + DFS, O(n*n*m), TLE):

class Solution {
    vector<int> dir = {0, -1, 0, 1, 0};

    bool isPath(const vector<vector<int>> & grid, int i, int j, vector<vector<bool>> & visited){
        int n = grid.size();
        if(i<0 or i>=n or j<0 or j>=n or grid[i][j] or visited[i][j]){
            return false;
        }
        if(i == n-1 and j == n-1){
            return true;
        }
        visited[i][j] = 1;
        for(int k=0; k<4; k++){
            int nbrI = i+dir[k];
            int nbrJ = j+dir[k+1];
            if(isPath(grid, nbrI, nbrJ, visited)){
                return true;
            }
        }
        return false;
    }
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        
        queue<pair<int, int>> q;
        for(int i=0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j]){
                    q.push(make_pair(i, j));
                }
            }
        }

        int minDistanceToThief = 0;
        int iterations = n;
        while(iterations--){
            vector<vector<bool>> visited(n, vector<bool>(n));
            if(!isPath(grid, 0, 0, visited)){
                return minDistanceToThief; 
            }

            int sz = q.size();
            while(sz--){
                auto cur = q.front();
                int i = cur.first;
                int j = cur.second;
                q.pop();
                for(int k=0; k<4; k++){
                    int nbrI = i + dir[k];
                    int nbrJ = j + dir[k+1];
                    if(nbrI<0 or nbrI>=n or nbrJ<0 or nbrJ>=n or grid[nbrI][nbrJ]){
                        continue;
                    }
                    grid[nbrI][nbrJ] = 1;
                    q.push(make_pair(nbrI, nbrJ));
                }
            }

            minDistanceToThief++;
        }
        
        return -1;
    }
};
