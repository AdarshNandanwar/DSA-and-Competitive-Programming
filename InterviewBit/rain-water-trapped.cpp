// https://www.interviewbit.com/problems/rain-water-trapped/

int Solution::trap(const vector<int> &A) {
    int n = A.size(), base, water = 0, height;
    stack<int> st;
    for(int i = 0; i<n; i++){
        while(!st.empty() and A[st.top()] < A[i]){
            base = A[st.top()];
            st.pop();
            if(!st.empty()){
                height = min(A[st.top()], A[i])-base;
                water += ((i-st.top()-1)*height);
            }
        }
        st.push(i);
    }
    return water;
}
