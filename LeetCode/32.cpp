// https://leetcode.com/problems/longest-valid-parentheses/

// Method 1 (Stack, O(n)):

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

// Method 2 (DP, O(n)):

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length(), maxLen = 0;
        //  dp[i] = Longest Valid Parentheses ending at i
        vector<int> dp(n, 0);
        for(int i=1; i<n; i++){
            if(s[i]==')' and i-1-dp[i-1]>=0 and s[i-1-dp[i-1]] == '('){
                dp[i] = 2+dp[i-1];
                if(i-1-dp[i-1]-1>=0)
                    dp[i] += dp[i-1-dp[i-1]-1];
            }
            maxLen = max(maxLen, dp[i]);
        }
        return maxLen;
    }
};