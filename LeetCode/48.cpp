// https://leetcode.com/problems/rotate-image/

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