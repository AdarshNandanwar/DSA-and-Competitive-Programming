// https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/

// Method 1 (Stack, O(n)):

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int n = nums.size();
        // next greater or equal, prev strictly greater
        vector<int> next(n, n), prev(n, -1);
        stack<int> st;
        for(int i = 0; i<n; i++){
            while(!st.empty() and nums[st.top()]<=nums[i]){     // equal 
                next[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i = n-1; i>=0; i--){
            while(!st.empty() and nums[st.top()]<nums[i]){      // no equal
                prev[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()) st.pop();
        int res = 0;
        for(int i = 0; i<n; i++){
            if(nums[i] >= left and nums[i] <= right){
                res += ((i-prev[i])*(next[i]-i));
            }
        }
        return res;
    }
};