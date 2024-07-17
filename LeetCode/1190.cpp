// https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/

// Method 1 (Recursion, O(n2)):

class Solution {
    string helper(string s){
        string res = "";
        int depth = 0;
        int lastOpen = -1;
        int n = s.length();
        for(int i=0; i<n; i++){
            if(s[i] == '('){
                if(depth == 0){
                    lastOpen = i;
                }
                depth++;
            } else if(s[i] == ')'){
                depth--;
                if(depth == 0){
                    res += helper(s.substr(lastOpen + 1, i - lastOpen - 1));
                }
            } else if(depth == 0){
                res.push_back(s[i]);
            }
        }

        reverse(res.begin(), res.end());

        return res;
    }
public:
    string reverseParentheses(string s) {
        string res = helper(s);
        reverse(res.begin(), res.end());
        return res;
    }
};
