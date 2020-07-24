// https://www.interviewbit.com/problems/nextgreater/

vector<int> Solution::nextGreater(vector<int> &A) {
    int n = A.size();
    vector<int> res(n, -1);
    stack<int> st;
    for(int i = 0; i<n; i++){
        while(!st.empty() and A[st.top()]<A[i]){
            int ind = st.top();
            st.pop();
            res[ind] = A[i];
        }
        st.push(i);
    }
    return res;
}
