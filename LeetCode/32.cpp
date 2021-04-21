// https://leetcode.com/problems/longest-valid-parentheses/

// Method 1 (Stack, O(n)):

class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        stack<int> st;
        // base of the stack has the start of the current valid sequence
        st.push(-1);
        for(auto i = 0; i<s.length(); i++){
            if(s[i] == '('){
                st.push(i);
            } else {
                if(st.size() == 1){
                    // stack is empty
                    st.pop();
                    st.push(i);
                } else {
                    st.pop();
                    ans = max(ans, i-st.top());
                }
            }
        }
        return ans;
    }
};