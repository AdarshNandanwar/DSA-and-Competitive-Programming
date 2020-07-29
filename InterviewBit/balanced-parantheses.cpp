// https://www.interviewbit.com/problems/balanced-parantheses/

// Method 1 (O(n) time, O(1) space):

int Solution::solve(string A) {
    int count = 0;
    for(auto i:A){
        if(i == '('){
            count++;
        } else {
            if(!count) return 0;
            count--;
        }
    }
    if(count) return 0;
    return 1;
}

// Method 2 (Stack, O(n) time, O(n) space):

int Solution::solve(string A) {
    stack<char> st;
    for(auto i:A){
        if(i == '('){
            st.push(i);
        } else {
            if(st.empty()) return 0;
            st.pop();
        }
    }
    if(st.empty()) return 1;
    return 0;
}