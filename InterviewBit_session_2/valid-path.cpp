// https://www.interviewbit.com/problems/valid-path/

// Method 1 (BFS):

bool touch(int x, int y, int rad, vector<int> &X, vector<int> &Y){
    for(int i = 0; i<X.size(); i++){
        if((x-X[i])*(x-X[i])+(y-Y[i])*(y-Y[i]) <= rad*rad) return 1;
    }
    return 0;
}

string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {
    // BFS
    vector<vector<bool>> visited(A+1, vector<bool>(B+1, 0));
    queue<vector<int>> q;
    q.push({0, 0});
    while(!q.empty()){
        auto cur = q.front();
        int x = cur[0], y = cur[1];
        q.pop();
        if(x<0 or y<0 or x>A or y>B) continue;
        if(visited[x][y]) continue;
        visited[x][y] = 1;
        if(touch(x, y, D, E, F)) continue;
        if(x == A and y == B) return "YES";
        q.push({x+1, y});
        q.push({x+1, y-1});
        q.push({x, y-1});
        q.push({x-1, y-1});
        q.push({x-1, y});
        q.push({x-1, y+1});
        q.push({x, y+1});
        q.push({x+1, y+1});
    }
    return "NO";
}

// Method 2 (DFS, TLE):

bool touch(int x, int y, int rad, vector<int> &X, vector<int> &Y){
    for(int i = 0; i<X.size(); i++){
        if((x-X[i])*(x-X[i])+(y-Y[i])*(y-Y[i]) <= rad*rad) return 1;
    }
    return 0;
}
 
bool helper(int x, int y, int A, int B, int rad , vector<int> &X, vector<int> &Y, vector<vector<bool>> &visited){
    if(x<0 or y<0 or x>A or y>B) return 0;
    if(touch(x, y, rad, X, Y)) return 0;
    if(visited[x][y]) return 0;
    visited[x][y] = 1;
    if(x == A and y == B) return 1;
    bool res = helper(x+1, y, A, B, rad, X, Y, visited) 
    or helper(x+1, y-1, A, B, rad, X, Y, visited) 
    or helper(x, y-1, A, B, rad, X, Y, visited)
    or helper(x-1, y-1, A, B, rad, X, Y, visited)
    or helper(x-1, y, A, B, rad, X, Y, visited)
    or helper(x-1, y+1, A, B, rad, X, Y, visited)
    or helper(x, y+1, A, B, rad, X, Y, visited)
    or helper(x+1, y+1, A, B, rad, X, Y, visited);
    visited[x][y] = 0;
    return res;
}
 
string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {
    vector<vector<bool>> visited(A+1, vector<bool>(B+1, 0));
    return helper(0, 0, A, B, D, E, F, visited)?"YES":"NO";
}