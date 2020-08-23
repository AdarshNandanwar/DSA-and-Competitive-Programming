// https://leetcode.com/problems/search-a-2d-matrix/

// Method 1 (Binary Search, O(log(n)*log(m)):

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if(n == 0) return 0;
        int m = matrix[0].size();
        if(m == 0) return 0;
        vector<int> col0;
        for(int i = 0; i<n; i++) col0.push_back(matrix[i][0]);
        int r = upper_bound(col0.begin(), col0.end(), target)-col0.begin()-1;
        if(r<0) return 0;
        return binary_search(matrix[r].begin(), matrix[r].end(), target);        
    }
};