// https://leetcode.com/problems/snakes-and-ladders/

// Method 1 (BFS, O(V+E)):

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size(), res = 0;
        vector<int> next(n*n+1);
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(i%2) next[i*n+j+1] = board[n-1-i][n-1-j] == -1 ? i*n+j+1 : board[n-1-i][n-1-j];
                else next[i*n+j+1] = board[n-1-i][j] == -1 ? i*n+j+1 : board[n-1-i][j];
            }
        }
        vector<bool> visited(n*n+1, 0);
        queue<int> q;
        q.push(1);
        visited[1] = 1;
        while(!q.empty()){
            int sz = q.size();
            for(int t = 0; t<sz; t++){
                auto cur = q.front();
                q.pop();
                if(cur == n*n) return res;
                for(int i = 1; i<=6 and cur+i<=n*n; i++){
                    if(!visited[next[cur+i]]) q.push(next[cur+i]);
                    visited[next[cur+i]] = 1;
                }
            }
            res++;
        }
        return -1;
    }
};