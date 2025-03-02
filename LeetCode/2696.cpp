// https://leetcode.com/problems/minimum-string-length-after-removing-substrings/

// Method 1 (Stack, O(n)):

class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        int n = s.length();
        for(int i=0; i<n; i++){
            if(s[i] == 'B' and !st.empty() and st.top() == 'A'){
                st.pop();
            } else if(s[i] == 'D' and !st.empty() and st.top() == 'C'){
                st.pop();
            } else {
                st.push(s[i]);
            }
        }
        return st.size();
    }
};
