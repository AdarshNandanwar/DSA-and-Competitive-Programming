// https://www.interviewbit.com/problems/redundant-braces/

// Method 1 (Stack, O(n)):

int Solution::braces(string A) {
    int n = A.length();
    // operatorCount[i] = operator count in the level of brackets with '(' at index i
    vector<int> operatorCount(n, 0);
    stack<int> st;
    for(auto i = 0; i<n; i++){
        if(A[i] == '('){
            st.push(i);
        } else if(A[i] == ')'){
            if(operatorCount[st.top()] == 0) return 1;
            st.pop();
        } else if(A[i] == '+' or A[i] == '-' or A[i] == '*' or A[i] == '/'){
            if(!st.empty()) operatorCount[st.top()]++;
        }
    }
    return 0;
}
