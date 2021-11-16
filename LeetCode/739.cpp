// https://leetcode.com/problems/daily-temperatures/

// Method 1 (Stack, O(n)):

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans;
        stack<int> st;
        for(int i = n-1; i>=0; i--){
            while(st.size() and temperatures[st.top()] <= temperatures[i]) st.pop();
            if(st.empty()) ans.push_back(0);
            else ans.push_back(st.top()-i);
            st.push(i);
        }
        return vector<int>(ans.rbegin(), ans.rend());
    }
};