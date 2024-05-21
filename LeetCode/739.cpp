// https://leetcode.com/problems/daily-temperatures/

// Method 1 (Stack, O(n)):

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n, 0);
        stack<int> decreasingTemperatureIndex;
        for(int i=0; i<n; i++){
            while(!decreasingTemperatureIndex.empty() and temperatures[decreasingTemperatureIndex.top()] < temperatures[i]){
                answer[decreasingTemperatureIndex.top()] = i-decreasingTemperatureIndex.top();
                decreasingTemperatureIndex.pop();
            }
            decreasingTemperatureIndex.push(i);
        }
        return answer;
    }
};