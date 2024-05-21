// https://leetcode.com/problems/evaluate-reverse-polish-notation/

// Method 1 (Stack, O(n)):

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> operands;
        for(const string& token:tokens){
            if(token == "+" or token == "-" or token == "*" or token == "/"){
                int operand2 = operands.top();
                operands.pop();
                int operand1 = operands.top();
                operands.pop();
                if(token == "+"){
                        operands.push(operand1 + operand2);
                } else if(token == "-"){
                        operands.push(operand1 - operand2);
                } else if(token == "*"){
                        operands.push(operand1 * operand2);
                } else if(token == "/"){
                        operands.push(operand1 / operand2);
                }
            } else {
                operands.push(stoi(token));
            }
        }
        return operands.top();
    }
};

// Alternate Code:

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if(tokens.size() == 0) return 0;
        stack<int> st;
        for(auto i:tokens){
            if(i != "+" and i != "-" and i != "*" and i != "/"){
                st.push(stoi(i));
            } else {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                if(i == "+") st.push(a+b);
                else if(i == "-") st.push(a-b);
                else if(i == "*") st.push(a*b);
                else if(i == "/") st.push(a/b);
            }
        }
        return st.top();
    }
};