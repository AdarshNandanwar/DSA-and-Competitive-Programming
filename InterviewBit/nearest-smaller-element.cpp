// https://www.interviewbit.com/problems/nearest-smaller-element/

// Method 1 (Stack, O(n)):

vector<int> Solution::prevSmaller(vector<int> &A) {
    int n = A.size();
    vector<int> res(n);
    stack<int> st;
    for(int i = n-1; i>=0; i--){
        while(!st.empty() and A[st.top()]>A[i]){
            res[st.top()] = A[i];
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()){
        res[st.top()] = -1;
        st.pop();
    }
    return res;
}
