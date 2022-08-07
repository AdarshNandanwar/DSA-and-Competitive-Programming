// https://leetcode.com/problems/transpose-matrix/

// Method 1 (O(n*m)):

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> transposedMatrix(m, vector<int>(n));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                transposedMatrix[j][i] = matrix[i][j];
            }
        }
        return transposedMatrix;
    }
};