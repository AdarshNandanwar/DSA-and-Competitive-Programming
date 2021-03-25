// https://leetcode.com/problems/valid-parentheses/

// Method 1 (Stack, O(n)):

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto i:s){
            if(i == '(' or i == '{' or i == '[') st.push(i);
            else if(i == ')' and !st.empty() and st.top() == '(') st.pop();
            else if(i == '}' and !st.empty() and st.top() == '{') st.pop();
            else if(i == ']' and !st.empty() and st.top() == '[') st.pop();
            else return 0;
        }
        return st.empty();
    }
};