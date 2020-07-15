// https://leetcode.com/problems/01-matrix/

int dir[5] = {0,1,0,-1,0};

class Solution {
public:    
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n == 0) return vector<vector<int>>(0);
        int m = matrix[0].size();
        vector<vector<int>> ans(matrix);
        
        // Multi Source BFS
        queue<pair<int, int>> q;
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(matrix[i][j] == 0) q.push({i,j});
            }
        }
        
        int dist = 1, I, J, sz;
        while(!q.empty()){
            sz = q.size();
            while(sz--){
                auto [i, j] = q.front();
                q.pop();
                for(int x = 0; x<4; x++){
                    I = i+dir[x];
                    J = j+dir[x+1];
                    if(I>=0 and J>=0 and I<n and J<m and matrix[I][J]){
                        q.push({I, J});
                        matrix[I][J] = 0;
                        ans[I][J] = dist;
                    }
                }
            }
            dist++;
        }        
        return ans;
    }
};