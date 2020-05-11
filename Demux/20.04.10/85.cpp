// https://leetcode.com/problems/maximal-rectangle/

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if(n == 0) return 0;
        int m = matrix[0].size();
        
        vector<vector<int>> mat(n, vector<int>(m, 0));
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(matrix[i][j] == '1'){
                    mat[i][j] = 1;
                } else {
                    mat[i][j] = 0;
                }
            }
        }
        
        for(int i = 1; i<n; i++){
            for(int j = 0; j<m; j++){
                if(mat[i][j]){
                    mat[i][j] += mat[i-1][j];
                }
            }
        }
        int ans = 0;
        for(int i = 0; i<n; i++){
            
            // largest rect in histogram logic
            
            stack<int> st1;
            vector<int> next(m, m);
            for(int j = 0; j<m; j++){
                while(!st1.empty() && mat[i][j]<mat[i][st1.top()]){
                    next[st1.top()] = j;
                    st1.pop();
                }
                st1.push(j);
            }
            stack<int> st2;
            vector<int> prev(m, -1);
            for(int j = m-1; j>=0; j--){
                while(!st2.empty() && mat[i][j]<mat[i][st2.top()]){
                    prev[st2.top()] = j;
                    st2.pop();
                }
                st2.push(j);
            }
            for(int j = 0; j<m; j++){
                ans = max(ans, mat[i][j]*(next[j]-prev[j]-1));
            }
        }
        return ans;
        
    }
};