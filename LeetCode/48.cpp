// https://leetcode.com/problems/rotate-image/

// Method 2

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i<n/2; i++){
            for(int j = 0; j<(n+1)/2; j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n-1-j][i];
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
                matrix[j][n-1-i] = temp;
            }
        }
    }
};

// Method 2

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int oi, oj, ni, nj, n = matrix.size();
        for(int i = 0; i<=(n-1)/2; i++){
            for(int j = 0; j<n/2; j++){
                oi = i; 
                oj = j;
                for(int k = 0; k<3; k++){
                    ni = n-1-oj;
                    nj = oi;
                    swap(matrix[oi][oj], matrix[ni][nj]);
                    oi = ni; 
                    oj = nj;
                }
            }
        }
    }
};