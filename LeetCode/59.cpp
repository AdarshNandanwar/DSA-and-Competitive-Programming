// https://leetcode.com/problems/spiral-matrix-ii/submissions/

// Method 1 (dist method):

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> v(n, vector<int>(n, 0));
        int dist = 0, cur = 1;
        while(dist<(n+1)/2){
            for(int j = dist; j<n-dist; j++) v[dist][j] = cur++;
            for(int i = dist+1; i<n-dist; i++) v[i][n-1-dist] = cur++;
            for(int j = n-1-dist-1; j>=dist; j--) v[n-1-dist][j] = cur++;
            for(int i = n-1-dist-1; i>=dist+1; i--) v[i][dist] = cur++;
            dist++;
        }
        return v;
    }
};