// https://leetcode.com/problems/remove-invalid-parentheses/

class Solution {
public:
    
    void helper(string & s, int index, int open, int close, int mismatch, string & cur, vector<int> & suffixValid, unordered_set<string> & ans){
        int n = s.length();
        if(mismatch == 0){
            if(open-close == suffixValid[index]) ans.insert(cur+s.substr(index));
            return;
        }
        if(index == n) return;
        
        if(s[index] == '(' or s[index] == ')'){
            // include
            cur.push_back(s[index]);
            if(s[index] == '('){
                helper(s, index+1, open+1, close, mismatch, cur, suffixValid, ans);
            } else if(s[index] == ')'){
                if(open > close) helper(s, index+1, open, close+1, mismatch, cur, suffixValid, ans);
            }
            cur.pop_back();
            // exclude
            helper(s, index+1, open, close, mismatch-1, cur, suffixValid, ans);
        } else {
            // include
            cur.push_back(s[index]);
            helper(s, index+1, open, close, mismatch, cur, suffixValid, ans);
            cur.pop_back();
        }
    }
    
    vector<string> removeInvalidParentheses(string s) {
        int open = 0, mismatch = 0, n = s.length();
        for(auto i:s){
            if(i == '('){
                open++;
            } else if (i == ')'){
                if(open) open--;
                else mismatch++;
            }
        }
        mismatch += open;
        
        // suffixValid[i] = is number of open bracket required before to make [i..n) valid
        vector<int> suffixValid(n+1, -1);
        suffixValid[n] = 0;
        int close = 0;
        for(int i = n-1; i>=0; i--){
            if(s[i] == '('){
                if(close) close--;
                else break;
            } else if(s[i] == ')'){
                close++;
            }
            suffixValid[i] = close;
        }
        
        unordered_set<string> ans;
        string cur = "";
        helper(s, 0, 0, 0, mismatch, cur, suffixValid, ans);
        return vector<string>(ans.begin(), ans.end());
    }
};