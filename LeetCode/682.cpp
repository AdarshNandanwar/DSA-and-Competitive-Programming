// https://leetcode.com/problems/baseball-game/

// Method 1 (Stack, O(n)):

class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        for(auto &op:ops){
            if(op == "+"){
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.push(num1);
                st.push(num1+num2);
            } else if(op == "D"){
                int num = st.top();
                st.push(2*num);
            } else if(op == "C"){
                st.pop();
            } else {
                st.push(stoi(op));
            }
        }
        int totalScore = 0;
        while(!st.empty()){
            totalScore += st.top();
            st.pop();
        }
        return totalScore;
    }
};