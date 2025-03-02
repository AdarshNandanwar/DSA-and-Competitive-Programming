// https://leetcode.com/problems/convert-1d-array-into-2d-array/

// Method 1 (Loops, O(n*m)):

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int sz = original.size();
        if(sz != m * n){
            return {};
        }
        vector<vector<int>> ans(m, vector<int>(n));
        for(int i=0; i<sz; i++){
            ans[i/n][i%n] = original[i];
        }
        return ans;
    }
};
