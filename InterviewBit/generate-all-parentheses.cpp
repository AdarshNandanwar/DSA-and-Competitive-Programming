// https://www.interviewbit.com/problems/generate-all-parentheses/

int Solution::isValid(string A) {
    stack<char> st;
    for(auto i:A){
        if(i == '(' or i == '{' or i == '[') st.push(i);
        else if(i == ')'){
            if(st.empty() or st.top() != '(') return 0;
            else st.pop();
        } else if(i == '}'){
            if(st.empty() or st.top() != '{') return 0;
            else st.pop();
        } else if(i == ']'){
            if(st.empty() or st.top() != '[') return 0;
            else st.pop();
        } else return 0;
    }
    return st.size()?0:1;
}
