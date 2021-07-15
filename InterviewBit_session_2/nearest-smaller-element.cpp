// https://www.interviewbit.com/problems/nearest-smaller-element/

vector<int> Solution::prevSmaller(vector<int> &A) {
    int n = A.size();
    vector<int> v(n, -1);
    stack<int> st;
    for(int i = n-1; i>=0; i--){
        while(!st.empty() and A[st.top()]>A[i]){
            v[st.top()] = A[i];
            st.pop();
        }
        st.push(i);
    }
    return v;
}
