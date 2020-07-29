// https://leetcode.com/problems/evaluate-reverse-polish-notation/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if(tokens.size() == 0) return 0;
        stack<int> st;
        for(auto i:tokens){
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
};