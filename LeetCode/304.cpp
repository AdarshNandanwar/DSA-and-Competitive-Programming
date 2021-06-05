// https://leetcode.com/problems/range-sum-query-2d-immutable/

// method 1 (DP, O(n*m)):

class NumMatrix {
public:
    
    vector<vector<int>> cum_sum;
    
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        cum_sum.clear();
        cum_sum = vector<vector<int>>(n+1, vector<int>(m+1, 0));
        for(int i = n-1; i>=0; i--){
            for(int j = m-1; j>=0; j--){
                cum_sum[i][j] = matrix[i][j]+cum_sum[i+1][j]+cum_sum[i][j+1]-cum_sum[i+1][j+1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return cum_sum[row1][col1]-cum_sum[row2+1][col1]-cum_sum[row1][col2+1]+cum_sum[row2+1][col2+1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */