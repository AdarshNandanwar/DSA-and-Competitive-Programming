// https://leetcode.com/problems/sort-the-matrix-diagonally/

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        unordered_map<int, vector<int>> diag;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                diag[i-j].push_back(mat[i][j]);
            }
        }
        for(auto & [i,j]:diag) sort(j.begin(), j.end());
        for(int i = n-1; i>=0; i--){
            for(int j = m-1; j>=0; j--){
                mat[i][j] = diag[i-j].back();
                diag[i-j].pop_back();
            }
        }
        return mat;
    }
};