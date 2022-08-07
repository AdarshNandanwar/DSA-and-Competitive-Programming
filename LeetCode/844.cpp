// https://leetcode.com/problems/backspace-string-compare/

// Method 1 (Stack, O(n+m)):

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string sFinal = "", tFinal = "";
        stack<char> st;
        for(auto &c:s){
            if(c=='#'){
                if(!st.empty()){
                    st.pop();
                }
            } else {
                st.push(c);
            }
        }
        while(!st.empty()){
            sFinal.push_back(st.top());
            st.pop();
        }
        for(auto &c:t){
            if(c=='#'){
                if(!st.empty()){
                    st.pop();
                }
            } else {
                st.push(c);
            }
        }
        while(!st.empty()){
            tFinal.push_back(st.top());
            st.pop();
        }
        return sFinal == tFinal;
    }
};