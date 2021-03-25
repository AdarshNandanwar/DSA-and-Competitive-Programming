// https://leetcode.com/problems/next-greater-element-ii/

// Method 1 (start from greatest element)

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int greatest = 0, n = nums.size();
        if(!n) return nums;
        for(int i = 0; i<n; i++){
            if(nums[greatest] < nums[i]){
                greatest = i;
            }
        }
        vector<int> ans(n, -1);
        int start = (greatest+1)%n, i = start;
        stack<int> st;
        do{
            while(!st.empty() && nums[st.top()]<nums[i]){
                ans[st.top()] = nums[i];
                st.pop();
            }
            st.push(i);
            i = (i+1)%n;
        }while(i!=start);
        return ans;
    }
};

// Method 2 (run loop form 0 to 2*n)