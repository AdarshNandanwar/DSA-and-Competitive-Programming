// https://leetcode.com/problems/spiral-matrix/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int dist = 0, n = matrix.size();
        vector<int> res;
        if(n == 0) return res;
        int m = matrix[0].size();
        while(1){
            for(int j = dist; j+dist<m and dist <= n-1-dist; j++) res.push_back(matrix[dist][j]);
            for(int i = dist+1; i+dist<n and dist <= m-1-dist; i++) res.push_back(matrix[i][m-1-dist]);
            for(int j = m-1-dist-1; j>=dist and dist < n-1-dist; j--) res.push_back(matrix[n-1-dist][j]);
            for(int i = n-1-dist-1; i>=dist+1 and m-1-dist > dist; i--) res.push_back(matrix[i][dist]);
            if(dist++ >= (n+1)/2) break;
        }
        return res;
    }
};

// Alternate Code:

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> ans;
        int dist = 0;
        while(dist <= (min(n, m)-1)/2){
            for(int j=dist; j<m-dist; j++){
                ans.push_back(matrix[dist][j]);
            }
            for(int i=dist+1; i<n-dist; i++){
                ans.push_back(matrix[i][m-dist-1]);
            }
            for(int j=m-dist-2; dist!=n-1-dist and j>=dist; j--){
                ans.push_back(matrix[n-1-dist][j]);
            }
            for(int i=n-dist-2; dist!=m-1-dist and i>dist; i--){
                ans.push_back(matrix[i][dist]);
            }
            dist++;
        }
        return ans;
    }
};