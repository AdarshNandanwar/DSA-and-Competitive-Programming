// https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/

// Method 1 (Greedy, O(n*m)):

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size(), m = colSum.size();
        
        vector<vector<int>> res(n, vector<int>(m, 0));
        vector<int> curRowSum(n, 0); // [0, i)
        vector<int> curColSum(m, 0); // [0, i)

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                res[i][j] = min(rowSum[i] - curRowSum[i], colSum[j] - curColSum[j]);
                curRowSum[i] += res[i][j];
                curColSum[j] += res[i][j];
            }
        }

        return res;
    }
};
