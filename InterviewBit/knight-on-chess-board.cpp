// https://www.interviewbit.com/problems/knight-on-chess-board/

// Method 1(BFS, O(A*B)):

int X[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int Y[8] = {-1, -2, -2, -1, 1, 2, 2, 1};

int Solution::knight(int A, int B, int C, int D, int E, int F) {
    
    vector<vector<bool>> visited(A+1, vector<bool>(B+1, 0));
    
    queue<pair<int, int>> q;
    q.push({C, D});
    visited[C][D] = 1;
    int steps = 0;
    while(!q.empty()){
        int sz = q.size();
        for(int i = 0; i<sz; i++){
            auto cur = q.front();
            q.pop();
            int x = cur.first, y = cur.second;
            if(x == E and y == F) return steps;
            for(int i = 0; i<8; i++){
                if(x+X[i] > 0 and x+X[i] <= A and y+Y[i] > 0 and y+Y[i] <= B and !visited[x+X[i]][y+Y[i]]){
                    visited[x+X[i]][y+Y[i]] = 1;
                    q.push({x+X[i], y+Y[i]});
                }
            }
        }
        steps++;
    }
    return -1;
}
