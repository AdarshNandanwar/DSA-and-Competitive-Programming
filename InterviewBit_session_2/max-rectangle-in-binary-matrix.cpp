// https://www.interviewbit.com/problems/max-rectangle-in-binary-matrix/

int Solution::maximalRectangle(vector<vector<int> > &A) {
    int n = A.size();
    if(n == 0) return 0;
    int m = A[0].size(), res = 0;
    for(int i = 1; i<n; i++){
        for(int j = 0; j<m; j++){
            if(A[i][j]) A[i][j] += A[i-1][j];
        }
    }
    
    for(int i = 0; i<n; i++){
        vector<int> prev(m, -1), next(m, m);    // smaller
        stack<int> st;
        for(int j = 0; j<m; j++){
            while(!st.empty() and A[i][st.top()]>A[i][j]){
                next[st.top()] = j;
                st.pop();
            }
            st.push(j);
        }
        while(!st.empty()) st.pop();
        for(int j = m-1; j>=0; j--){
            while(!st.empty() and A[i][st.top()]>A[i][j]){
                prev[st.top()] = j;
                st.pop();
            }
            st.push(j);
        }
        for(int j = 0; j<m; j++){
            res = max(res, A[i][j]*(next[j]-prev[j]-1));
        }
    }
    return res;
}
