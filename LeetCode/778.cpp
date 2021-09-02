// https://leetcode.com/problems/swim-in-rising-water/

// Method 1 (Binary Search + BFS, O(n*n*logn)):

class Solution {
public:
    
    vector<int> dir = {0, -1, 0, 1, 0};
    
    bool is_valid(vector<vector<int>>& grid, int t){
        if(grid[0][0] > t) return 0;
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        queue<pair<int, int>> q;
        q.push({0,0});
        visited[0][0] = true;
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            if(cur.first == n-1 and cur.second == n-1) return true;
            for(auto k = 0; k<4; k++){
                int nr = cur.first+dir[k];
                int nc = cur.second+dir[k+1];
                if(nr<0 or nc<0 or nr>=n or nc>=n or visited[nr][nc] or grid[nr][nc] > t) continue;
                q.push({nr, nc});
                visited[nr][nc] = true;
            }
        }
        return false;
    }
    
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int lo = 0, hi = n*n-1, mid;
        while(lo<hi){
            mid = lo+(hi-lo)/2;
            if(is_valid(grid, mid)){
                hi = mid;
            } else {
                lo = mid+1;
            }
        }
        return lo;
    }
};

// Method 2 (Dijkstra, O(n*n*logn)):

class Solution {
public:
    
    vector<int> dir = {0, -1, 0, 1, 0};
    
    struct Node{
        int r, c, cost;
        Node(int r, int c, int cost): r(r), c(c), cost(cost) {}
    };
    
    struct Cmp{
        bool operator()(const Node * a, const Node * b){
            return a->cost > b->cost;
        }
    };
    
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> d(n, vector(n, INT_MAX));
        priority_queue<Node *, vector<Node *>, Cmp> pq;
        pq.push(new Node(0, 0, grid[0][0]));
        while(!pq.empty()){
            auto cur = pq.top();
            if(cur->r == n-1 and cur->c == n-1) return cur->cost;
            pq.pop();
            if(d[cur->r][cur->c] <= cur->cost) continue;
            d[cur->r][cur->c] = cur->cost;
            for(auto k = 0; k<4; k++){
                int nr = cur->r+dir[k];
                int nc = cur->c+dir[k+1];
                if(nr<0 or nc<0 or nr>=n or nc>=n) continue;
                pq.push(new Node(nr, nc, max(cur->cost, grid[nr][nc])));
            }
        }
        return -1;
    }
};

// Method 3 (Dijkstra Like, TLE):

class Solution {
public:
    
    vector<int> dir = {0, -1, 0, 1, 0};
    
    struct Node{
        int r, c, cost;
        vector<vector<bool>> visited; 
        Node(int r, int c, int cost, int n){
            this->r = r;
            this->c = c;
            this->cost = cost;
            this->visited = vector(n, vector(n, false));
            this->visited[r][c] = true;
        }
    };
    
    struct Cmp{
        bool operator()(const Node * a, const Node * b){
            return a->cost > b->cost;
        }
    };
    
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<Node *, vector<Node *>, Cmp> pq;
        pq.push(new Node(0, 0, grid[0][0], n));
        while(!pq.empty()){
            auto cur = pq.top();
            if(cur->r == n-1 and cur->c == n-1) return cur->cost;
            pq.pop();
            for(auto k = 0; k<4; k++){
                int nr = cur->r+dir[k];
                int nc = cur->c+dir[k+1];
                if(nr<0 or nc<0 or nr>=n or nc>=n or cur->visited[nr][nc]) continue;
                auto next = new Node(nr, nc, max(cur->cost, grid[nr][nc]), n);
                next->visited = cur->visited;
                next->visited[nr][nc] = true;;
                pq.push(next);
            }
        }
        return -1;
    }
};