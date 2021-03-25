// https://leetcode.com/problems/shortest-path-in-binary-matrix/

int dir[10] = {0,1,1,1,0,-1,-1,-1,0,1};

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), I, J, len = 2, sz;
        if(grid[0][0]) return -1;
        if(n == 1) return 1;
        // BFS
        queue<pair<int, int>> q;
        q.push({0,0});
        while(!q.empty()){
            sz = q.size();
            while(sz--){
                auto [i, j] = q.front();
                q.pop();
                for(int x = 0; x<8; x++){
                    I = i+dir[x]; J = j+dir[x+2];
                    if(I>=0 and I<n and J>=0 and J<n and grid[I][J] == 0){
                        if(I == n-1 and J == n-1) return len;
                        q.push({I, J});
                        grid[I][J] = 1;
                    }
                }
            }
            len++;
        }
        return -1;
    }
};