// https://leetcode.com/problems/pascals-triangle-ii/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> row(2, vector<int>(rowIndex+1, 1));
        for(int i = 0; i<=rowIndex; i++){
            for(int j = 1; j<i; j++){
                row[i%2][j] = row[(i-1)%2][j-1]+row[(i-1)%2][j];
            }
        }
        return row[rowIndex%2];
    }
};