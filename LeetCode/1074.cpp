// https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/

// Method 1 (PrefixSum, DP, O(n*m2)):

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        
        int n = matrix.size();
        if(n == 0) return 0;
        int m = matrix[0].size(), count = 0, rowSum, prefixSum;

        // row wise prefix sum
        for(int i = 0; i<n; i++){
            for(int j = 1; j<m; j++){
                matrix[i][j] += matrix[i][j-1];
            }
        }
        
        // selecting 2 columns c1 and c2
        // to get a vector of sum: matrix[r][c1..c2]
        // this is a 1D vector on r where c1 and c2 are fixed
        // now apply leetcode 560. logic
        // https://leetcode.com/problems/subarray-sum-equals-k/ 
        
        for(int c1 = 0; c1<m; c1++){
            for(int c2 = c1; c2<m; c2++){
                // 1D logic from 560.
                unordered_map<int, int> freq;
                prefixSum = 0;
                freq[prefixSum]++;
                for(int r = 0; r<n; r++){
                    rowSum = matrix[r][c2]-(c1==0 ? 0 : matrix[r][c1-1]);
                    prefixSum += rowSum;
                    if(freq.count(prefixSum-target)) count += freq[prefixSum-target];
                    freq[prefixSum]++;
                }
            }
        }
        return count;
    }
};

// Method 2 (TLE, O(n2*m2)):

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if(n == 0) return 0;
        int m = matrix[0].size(), count = 0, sum;

        vector<vector<int>> suffixSum(n+1, vector<int>(m+1, 0));
        for(int i = n-1; i>=0; i--){
            for(int j = m-1; j>=0; j--){
                suffixSum[i][j] = matrix[i][j]-suffixSum[i+1][j+1]+suffixSum[i+1][j]+suffixSum[i][j+1];
            }
        }

        for(int i = n-1; i>=0; i--){
            for(int j = m-1; j>=0; j--){
                for(int I = i+1; I<=n; I++){
                    for(int J = j+1; J<=m; J++){
                        if(i == I and j == J) continue;
                        sum = suffixSum[i][j]-suffixSum[I][j]-suffixSum[i][J]+suffixSum[I][J];
                        if(sum == target) count++;
                    }
                }
            }
        }
        return count;
    }
};