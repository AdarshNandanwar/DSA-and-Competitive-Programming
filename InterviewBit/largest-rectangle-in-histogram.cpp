// https://www.interviewbit.com/problems/largest-rectangle-in-histogram/

int Solution::largestRectangleArea(vector<int> &A) {
    
    int n = A.size();
    stack<int> st;
    
    // next shorter
    vector<int> nextShorter(n, n);
    for(int i = 0; i<n; i++){
        while(!st.empty() and A[st.top()] > A[i]){
            int cur = st.top();
            st.pop();
            nextShorter[cur] = i;
        }
        st.push(i);
    }
    
    // prev shorter
    vector<int> prevShorter(n, -1);
    for(int i = n-1; i>=0; i--){
        while(!st.empty() and A[st.top()] > A[i]){
            int cur = st.top();
            st.pop();
            prevShorter[cur] = i;
        }
        st.push(i);
    }
    
    int maxArea = 0;
    for(int i = 0; i<n; i++){
        maxArea = max(maxArea, A[i]*(nextShorter[i]-prevShorter[i]-1));
    }
    return maxArea;
}
