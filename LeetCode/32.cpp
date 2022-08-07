// https://leetcode.com/problems/longest-valid-parentheses/

// Method 1 (DP, O(n)):

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        if(n == 0) return 0;
        // dp[i] = Longest Valid Parentheses ending at index i
        vector<int> dp(n, 0);
        for(int i=1; i<n; i++){
            if(s[i] == ')'){
                int lvp = dp[i-1];
                if(i-(lvp+1) >= 0 and s[i-(lvp+1)] == '('){
                    dp[i] = lvp+2;
                    if(i-(lvp+2) >= 0){
                        dp[i] += dp[i-(lvp+2)];
                    }
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

// Method 2 (Stack, O(n)):

class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        stack<int> st;
        // base of the stack has the start_index-1 of the current valid sequence
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