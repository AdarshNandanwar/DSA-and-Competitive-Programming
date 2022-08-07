// https://leetcode.com/problems/search-a-2d-matrix-ii/

// Method 1 (O(n+m)):

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int i = n-1, j = 0;
        while(i>=0 and j<m){
            if(matrix[i][j] == target){
                return true;
            } else if(matrix[i][j] < target){
                j++;
            } else {
                i--;
            }
        }
        return false;
    }
};