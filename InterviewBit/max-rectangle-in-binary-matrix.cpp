// https://www.interviewbit.com/problems/max-rectangle-in-binary-matrix/

int Solution::maximalRectangle(vector<vector<int> > &A) {
    
    int n = A.size();
    if(n == 0) return 0;
    int m = A[0].size(), res = 0;
    
    // prefix sum along the col
    
    for(int i = 1; i<n; i++){
        for(int j = 0; j<m; j++){
            if(A[i][j]) A[i][j] += A[i-1][j];
        }
    }
    
    for(int i = 0; i<n; i++){
        
        // histogram logic
        
        vector<int> nextSmaller(m, m);
        stack<int> st; // index
        for(int j = 0; j<m; j++){
            while(!st.empty() and A[i][st.top()] > A[i][j]){
                nextSmaller[st.top()] = j;
                st.pop();
            }
            st.push(j);
        }
        
        vector<int> prevSmaller(m, -1);
        while(!st.empty()) st.pop();
        for(int j = m-1; j>=0; j--){
            while(!st.empty() and A[i][st.top()] > A[i][j]){
                prevSmaller[st.top()] = j;
                st.pop();
            }
            st.push(j);
        }
        
        for(int j = 0; j<m; j++){
            res = max(res, (nextSmaller[j]-prevSmaller[j]-1)*A[i][j]);
        }
    }
    return res;
}
