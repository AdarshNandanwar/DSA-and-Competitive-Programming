// https://leetcode.com/problems/generate-parentheses/

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