// https://www.interviewbit.com/problems/generate-all-parentheses-ii/

void helper(int & n, int open, int close, string & cur, vector<string> & res){
    if(open+close == 2*n){
        res.push_back(cur);
        return;
    }
    if(open < n){
        cur.push_back('(');
        helper(n, open+1, close, cur, res);
        cur.pop_back();
    }
    if(close < n and open>close){
        cur.push_back(')');
        helper(n, open, close+1, cur, res);
        cur.pop_back();
    }
}

vector<string> Solution::generateParenthesis(int n) {
    vector<string> res;
    string cur = "";
    int open = 0, close = 0;
    helper(n, open, close, cur, res);
    return res;
}
