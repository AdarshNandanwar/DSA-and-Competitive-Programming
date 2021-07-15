// https://leetcode.com/problems/generate-parentheses/

class Solution {
public:
    
    void helper(int open, int close, string &s, vector<string> &ans){
        if(open == 0 and close == 0){
            ans.push_back(s);
            return;
        }
        if(open){
            s.push_back('(');
            helper(open-1, close+1, s, ans);
            s.pop_back();
        } 
        if(close){
            s.push_back(')');
            helper(open, close-1, s, ans);
            s.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";
        helper(n, 0, s, ans);
        return ans;
    }
};

// Alternate Code:

class Solution {
public:
    
    void helper(int & n, int open, int close, string cur, vector<string> & res){
        if(open + close == 2*n){
            if(open == n) res.push_back(cur);
            return;
        }
        if(open<n) helper(n, open+1, close, cur+'(', res);
        if(open>close) helper(n, open, close+1, cur+')', res);
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper(n, 0, 0, "", res);
        return res;
    }
};