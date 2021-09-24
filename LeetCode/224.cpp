// https://leetcode.com/problems/basic-calculator/

// Method 1 (Stack, O(n)):

class Solution {
public:
    int calculate(string s) {
        // {sum till now i.e. before '(', 
        //  sign before '(' i.e. whether to add or subtract the result of expression inside bracket}
        stack<pair<int, bool>> st;
        int n = s.length(), sum = 0;
        bool sign = true;
        for(int i = 0; i<n; i++){
            switch(s[i]){
                case ' ':  break;
                case '+': {
                    sign = true;
                    break;
                }
                case '-': {
                    sign = false;
                    break;
                }
                case '(': {
                    st.push(make_pair(sum, sign));
                    sum = 0;
                    sign = true;
                    break;
                }
                case ')': {
                    if(st.top().second){
                        sum = st.top().first + sum;
                    } else {
                        sum = st.top().first - sum;
                    }
                    st.pop();
                    sign = true;
                    break;
                }
                default: {
                    int j = i;
                    while(j<n and '0' <= s[j] and s[j] <= '9') j++;
                    if(sign){
                        sum += stoi(s.substr(i, j-i));
                    } else {
                        sum -= stoi(s.substr(i, j-i));
                    }
                    i = j-1;
                }
            }
        }
        return sum;
    }
};