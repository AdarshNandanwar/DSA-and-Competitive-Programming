// https://leetcode.com/problems/remove-k-digits/

class Solution {
public:
    string removeKdigits(string num, int k) {
        int index = 0, removed = 0;
        stack<char> st;
        while(index<num.length() && removed<k){
            while(!st.empty() && st.top()>num[index] && removed<k){
                st.pop();
                removed++;
            }
            st.push(num[index]);
            index++;
        }
        while(removed<k){
            st.pop();
            removed++;
        }
        string ans = num.substr(index);
        while(!st.empty()){
            ans = st.top()+ans;
            st.pop();
        }
        
        index = 0;
        for(index = 0; index<ans.length() && ans[index]=='0'; index++);
        
        if(index == ans.length()) 
            return "0";
        else
            return ans.substr(index);
    }
};