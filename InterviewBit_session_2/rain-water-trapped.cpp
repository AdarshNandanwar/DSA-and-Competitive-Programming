// https://www.interviewbit.com/problems/rain-water-trapped/

int Solution::trap(const vector<int> &A) {
    int n = A.size();
    // prev_greater
    stack<int> st;
    int res = 0;
    for(int i = 0; i<n; i++){
        while(!st.empty() and A[st.top()] <= A[i]){
            int base = A[st.top()];
            st.pop();
            if(!st.empty())
                res += ((i-st.top()-1)*(min(A[i], A[st.top()])-base));
        }
        st.push(i);
    }
    return res;
}
