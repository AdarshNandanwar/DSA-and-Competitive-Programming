// https://leetcode.com/problems/make-the-string-great/

// Method 1 (Stack, O(n) time, O(n) space):

class Solution {
public:
    string makeGood(string s) {
        int n = s.length();
        stack<char> st;
        for(int i=0; i<n; i++){
            if(!st.empty() and abs(st.top()-s[i]) == abs('A'-'a')){
                st.pop();
            } else {
                st.push(s[i]);
            }
        }
        string res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
