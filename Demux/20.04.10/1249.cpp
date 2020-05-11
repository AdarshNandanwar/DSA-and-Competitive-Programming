// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int buffer = 0;
        string ns = "";
        for(int i = 0; i<s.length(); i++){
            if(s[i] == ')' && buffer>0){
                ns += s[i];
                buffer--;
            } else if (s[i] == '('){
                ns += s[i];
                buffer++;
            } else if(s[i] != ')'){
                ns += s[i];
            }
        }
        s = ns;
        buffer = 0;
        ns = "";
        for(int i = s.length()-1; i>=0; i--){
            if(s[i] == '(' && buffer){
                ns += s[i];
                buffer--;
            } else if (s[i] == ')'){
                ns += s[i];
                buffer++;
            } else if(s[i] != '('){
                ns += s[i];
            }
        }
        reverse(ns.begin(), ns.end());
        return ns;
    }
};