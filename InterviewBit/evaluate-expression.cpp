// https://www.interviewbit.com/problems/evaluate-expression/

int Solution::evalRPN(vector<string> &A) {
    if(A.size() == 0) return 0;
    stack<int> st;
    for(auto i:A){
        if(i != "+" and i != "-" and i != "*" and i != "/"){
            st.push(stoi(i));
        } else {
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
            if(i == "+") st.push(a+b);
            else if(i == "-") st.push(a-b);
            else if(i == "*") st.push(a*b);
            else if(i == "/") st.push(a/b);
        }
    }
    return st.top();
}
