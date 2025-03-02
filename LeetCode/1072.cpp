// https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/

// Method 1 (Loops, O(m*n^2)):

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int maxSameCount = 1;
        for(int i=0; i<n; i++){
            int sameCount = 1;
            for(int j=i+1; j<n; j++){
                bool same = true;
                for(int k=0; k<m; k++){
                    if(matrix[i][k] != matrix[j][k]){
                        same = false;
                        break;
                    }
                }
                if(same){
                    sameCount++;
                    continue;
                }
                same = true;
                for(int k=0; k<m; k++){
                    if(matrix[i][k] == matrix[j][k]){
                        same = false;
                        break;
                    }
                }
                if(same){
                    sameCount++;
                }
            }
            maxSameCount = max(maxSameCount, sameCount);
        }
        return maxSameCount;
    }
};
