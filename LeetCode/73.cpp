// https://leetcode.com/problems/set-matrix-zeroes/

// Method 1 (Matrix encoding, time O(n*m), space O(1)):

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int zero_i = -1, zero_j = -1;
        // find first row and col with zero
        for(int i = 0; i<n and zero_i == -1; i++){
            for(int j = 0; j<m and zero_j == -1; j++){
                if(!matrix[i][j]) {
                    zero_i = i;
                    zero_j = j;
                }
            }
        }
        if(zero_i == -1) return;
        // use first row and col with zero as hash map
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!matrix[i][j]) {
                    matrix[zero_i][j] = matrix[i][zero_j] = 0;
                }
            }
        }
        for(int i = 0; i<n; i++){
            if(i == zero_i or matrix[i][zero_j]) continue;
            for(int j = 0; j<m; j++){
                matrix[i][j] = 0;
            }
        }
        for(int j = 0; j<m; j++){
            if(j == zero_j or matrix[zero_i][j]) continue;
            for(int i = 0; i<n; i++){
                matrix[i][j] = 0;
            }
        }
        // handle first row and col with zero
        for(int i = 0; i<n; i++){
            matrix[i][zero_j] = 0;
        }
        for(int j = 0; j<m; j++){
            matrix[zero_i][j] = 0;
        }
    }
};

// Method 2 (Unordered Set, time O(n*m), space O(n+m)):

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        unordered_set<int> row, col;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(matrix[i][j] == 0){
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        for(auto &i:row){
            for(int j = 0; j<m; j++){
                matrix[i][j] = 0;
            }
        }
        for(auto &j:col){
            for(int i = 0; i<n; i++){
                matrix[i][j] = 0;
            }
        }
    }
};