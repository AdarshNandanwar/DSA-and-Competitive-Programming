// https://leetcode.com/problems/diagonal-traverse/

// Method 1 (tightest bounds, O(n*m)):

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n == 0) return {};
        int m = matrix[0].size(), j, dir = 1;
        vector<int> res;
        for(int d = 0; d<=n+m-2; d++, dir=!dir){
            for(int i = min(n-1, d); dir and i>=max(0, d-m+1); i--) res.push_back(matrix[i][d-i]);
            for(int i = max(0, d-m+1); !dir and i<=min(n-1, d); i++) res.push_back(matrix[i][d-i]);
        }
        return res;
    }
};

// Method 2 (loose bounds, O(max(n, m)*max(n, m))):

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n == 0) return {};
        int m = matrix[0].size(), j, dir = 1;
        vector<int> res;
        for(int d = 0; d<=n+m-2; d++){
            if(dir){
                for(int i = n-1; i>=0; i--){
                    j = d-i;
                    if(0<=j and j<m) res.push_back(matrix[i][d-i]);
                }
            } else {
                for(int i = 0; i<n; i++){
                    j = d-i;
                    if(0<=j and j<m) res.push_back(matrix[i][d-i]);
                }
            }
            dir = !dir;
        }
        return res;
    }
};