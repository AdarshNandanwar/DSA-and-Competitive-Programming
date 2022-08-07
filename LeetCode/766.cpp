// https://leetcode.com/problems/toeplitz-matrix/

// Method 1 (Hash map, O(n*m)):

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        unordered_map<int, int> diagValue;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int diag = i-j;
                if(diagValue.count(diag)){
                    if(matrix[i][j] != diagValue[diag]){
                        return false;
                    }
                } else {
                    diagValue[diag] = matrix[i][j];
                }
            }
        }
        return true;
    }
};