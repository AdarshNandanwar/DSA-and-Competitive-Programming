// https://leetcode.com/problems/search-a-2d-matrix/

// Method 1 (Single Binary Search, O(log(n*m))):

class Solution {
public:    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        // FT First T
        int lo = 0, hi = n*m-1, mid;
        while(lo<hi){
            mid = lo+(hi-lo)/2;
            if(matrix[mid/m][mid%m] >= target){
                hi = mid;
            } else {
                lo = mid+1;
            }
        }
        return matrix[lo/m][lo%m] == target;
    }
};

// Method 2 (Double Pure Binary Search, O(log(n)+log(m)):

class Solution {
public:
    int firstColUpperBound(const vector<vector<int>>& matrix, const int& target){
        int n = matrix.size();
        // FT First T
        int lo = 0, hi = n-1, mid;
        while(lo<hi){
            mid = lo+(hi-lo)/2;
            if(matrix[mid][0] > target){
                hi = mid;
            } else {
                lo = mid+1;
            }
        }
        if(matrix[lo][0] > target) return lo;
        else return n;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        
        int rowIndex = firstColUpperBound(matrix, target);
        rowIndex--;
        if(rowIndex == -1) return false;
        
        int colIndex = lower_bound(matrix[rowIndex].begin(), matrix[rowIndex].end(), target)-matrix[rowIndex].begin();
        if(colIndex == m) return false;
        
        return matrix[rowIndex][colIndex] == target;
    }
};

// Method 3 (Double Binary Search, O(n+log(m))):

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

// Method 4 (Diagonal traversal, O(n+m)):

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int row = n-1, col = 0;
        while(row>=0 and col<m){
            if(matrix[row][col] == target) return true;
            else if(matrix[row][col] > target) row--;
            else col++;
        }
        return false;
    }
};