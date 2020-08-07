// https://leetcode.com/problems/parsing-a-boolean-expression/

// Method 1 (parsing, stack, O(n2)):

class Solution {
public:
    bool parseBoolExpr(string expression) {
        int n = expression.length();
        if(n == 1) return expression[0] == 't';
        istringstream iss(expression.substr(2, n-3));
        string exp;
        bool res;
        if(expression[0] == '!'){
            res = !parseBoolExpr(expression.substr(2, n-3));
        } else if(expression[0] == '&'){
            res = 1;
            // p1 is the start of the substring
            int bracket = 0, p1 = 2, i;
            for(i = 2; i<n-1; i++){
                if(expression[i] == '(') bracket++;
                if(expression[i] == ')') bracket--;
                if(expression[i] == ',' and bracket == 0){
                    res &= parseBoolExpr(expression.substr(p1, i-p1));
                    p1 = i+1;
                }
            }
            res &= parseBoolExpr(expression.substr(p1, i-p1));
        } else {
            res = 0;
            // p1 is the start of the substring
            int bracket = 0, p1 = 2, i;
            for(i = 2; i<n-1; i++){
                if(expression[i] == '(') bracket++;
                if(expression[i] == ')') bracket--;
                if(expression[i] == ',' and bracket == 0){
                    res |= parseBoolExpr(expression.substr(p1, i-p1));
                    p1 = i+1;
                }
            }
            res |= parseBoolExpr(expression.substr(p1, i-p1));
        }
        return res;        
    }
};