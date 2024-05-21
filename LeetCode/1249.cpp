// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/

// Method 1 (Stack, Hash Set, O(n) time, O(n) space):

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.length();
        unordered_set<int> skip;
        stack<int> st;
        for(int i=0; i<n; i++){
            if(s[i] == '('){
                st.push(i);
            } else if(s[i] == ')'){
                if(st.empty()){
                    skip.insert(i);
                    continue;
                } else {
                    st.pop();
                }
            }
        }
        while(!st.empty()){
            skip.insert(st.top());
            st.pop();
        }
        string res;
        for(int i=0; i<n; i++){
            if(skip.count(i)){
                continue;
            }
            res.push_back(s[i]);
        }
        return res;
    }
};

// Method 2 (New string, O(n) time, O(n) space):

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
