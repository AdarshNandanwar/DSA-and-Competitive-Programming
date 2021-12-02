// https://leetcode.com/problems/maximal-rectangle/

// Method 1 (Stack, Histogram Logic, O(n*m)):

class Solution {
public:
    
    int histogram(vector<int> & v){
        int n = v.size(), res = 0;
        vector<int> nextLower(n, n), prevLower(n, -1);
        stack<int> st;
        st.push(-1);
        for(int i=0; i<n; i++){
            while(st.size() > 1 and v[st.top()]>=v[i]) st.pop();
            prevLower[i] = st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        st.push(n);
        for(int i=n-1; i>=0; i--){
            while(st.size() > 1 and v[st.top()]>=v[i]) st.pop();
            nextLower[i] = st.top();
            st.push(i);
        }
        for(int i=0; i<n; i++){
            res = max(res, v[i]*(nextLower[i]-prevLower[i]-1));
        }
        return res;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if(n == 0) return 0;
        int m = matrix[0].size(), ans = 0;
        vector<vector<int>> v(n, vector<int>(m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                v[i][j] = matrix[i][j] == '1';
                if(i>0 and v[i][j]) v[i][j] += v[i-1][j];
            }
        }
        for(int i=0; i<n; i++){
            ans = max(ans, histogram(v[i]));
        }
        return ans;
    }
};

// Alternate Code:

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if(n == 0) return 0;
        int m = matrix[0].size();
        
        vector<vector<int>> mat(n, vector<int>(m, 0));
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(matrix[i][j] == '1'){
                    mat[i][j] = 1;
                } else {
                    mat[i][j] = 0;
                }
            }
        }
        
        for(int i = 1; i<n; i++){
            for(int j = 0; j<m; j++){
                if(mat[i][j]){
                    mat[i][j] += mat[i-1][j];
                }
            }
        }
        int ans = 0;
        for(int i = 0; i<n; i++){
            
            // largest rect in histogram logic
            
            stack<int> st1;
            vector<int> next(m, m);
            for(int j = 0; j<m; j++){
                while(!st1.empty() && mat[i][j]<mat[i][st1.top()]){
                    next[st1.top()] = j;
                    st1.pop();
                }
                st1.push(j);
            }
            stack<int> st2;
            vector<int> prev(m, -1);
            for(int j = m-1; j>=0; j--){
                while(!st2.empty() && mat[i][j]<mat[i][st2.top()]){
                    prev[st2.top()] = j;
                    st2.pop();
                }
                st2.push(j);
            }
            for(int j = 0; j<m; j++){
                ans = max(ans, mat[i][j]*(next[j]-prev[j]-1));
            }
        }
        return ans;
        
    }
};