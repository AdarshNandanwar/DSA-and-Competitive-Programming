// https://leetcode.com/problems/shortest-path-in-binary-matrix/

// Method 1 (BFS, O(n2)):

class Solution {
    vector<int> x = {1, 1, 0, -1, -1, -1, 0, 1};
    vector<int> y = {0, 1, 1, 1, 0, -1, -1, -1};
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // {row, col}
        queue<pair<int, int>> q;
        if(grid[0][0] == 0){
            q.push(make_pair(0, 0));
        }
        int length = 1;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto pos = q.front();
                q.pop();
                int row = pos.first;
                int col = pos.second;
                if(row == n-1 and col == n-1){
                    return length;
                }
                for(int k=0; k<8; k++){
                    int nextRow = row+y[k];
                    int nextCol = col+x[k];
                    if(nextRow<0 or nextRow>=n or nextCol<0 or nextCol>=n or grid[nextRow][nextCol]){
                        continue;
                    }
                    grid[nextRow][nextCol] = 1;
                    q.push(make_pair(nextRow, nextCol));
                }
            }
            length++;
        }
        return -1;
    }
};