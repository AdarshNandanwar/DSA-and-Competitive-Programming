// https://leetcode.com/problems/lucky-numbers-in-a-matrix/submissions/1326412467/?envType=daily-question&envId=2024-07-19

// Method 1 (Loops, O(n*m) time, O(1) space):

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> rowMin(n, INT_MAX), colMax(m, INT_MIN);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                rowMin[i] = min(rowMin[i], matrix[i][j]);
                colMax[j] = max(colMax[j], matrix[i][j]);
            }
        }
        vector<int> lucky;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == rowMin[i] and matrix[i][j] == colMax[j]){
                    lucky.push_back(matrix[i][j]);
                }
            }
        }
        return lucky;
    }
};
