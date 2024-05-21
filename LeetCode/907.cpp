// https://leetcode.com/problems/sum-of-subarray-minimums/description/

// Method 1 (Monotonic Stack, O(n)):

#define MOD 1000000007

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> nextLower(n, n), prevLowerOrEqual(n, -1);
        for(int i=0; i<n; i++){
            while(!st.empty() and arr[st.top()] > arr[i]){
                int prevIndex = st.top();
                st.pop();
                nextLower[prevIndex] = i;
            }
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        for(int i=n-1; i>=0; i--){
            while(!st.empty() and arr[st.top()] >= arr[i]){
                int prevIndex = st.top();
                st.pop();
                prevLowerOrEqual[prevIndex] = i;
            }
            st.push(i);
        }

        int minB = 0;
        for(int i=0; i<n; i++){
            long subarrayCount = (i - prevLowerOrEqual[i]) * (nextLower[i] - i);
            long sumOfMinOfSubarrays = (arr[i] * subarrayCount) % MOD;
            minB = (minB + sumOfMinOfSubarrays) % MOD;
        }

        return minB;
    }
};
