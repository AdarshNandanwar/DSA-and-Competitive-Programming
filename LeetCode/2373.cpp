// https://leetcode.com/problems/largest-local-values-in-a-matrix/

// Method 1 (Loop, O(n2)):

class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> res(n-2, vector<int>(n-2));
        for(int i=1; i<n-1; i++){
            for(int j=1; j<n-1; j++){
                int maxVal = grid[i][j];
                for(int nbrI=i-1; nbrI<=i+1; nbrI++){
                    for(int nbrJ=j-1; nbrJ<=j+1; nbrJ++){
                        maxVal = max(maxVal, grid[nbrI][nbrJ]);
                    }
                }
                res[i-1][j-1] = maxVal;
            }
        }
        return res;
    }
};
