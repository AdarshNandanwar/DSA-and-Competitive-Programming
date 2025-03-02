// https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/

// Method 1 (HashMap + Max Heap, O(n)):

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> vals;

        for(int num:nums){
            int digitSum = 0;
            for(int i=num; i>0; i/=10){
                digitSum += (i%10);
            }
            vals[digitSum].push(num);
            if(vals[digitSum].size() > 2){
                vals[digitSum].pop();
            }
        }

        int maxSum = -1;
        for(auto itr:vals){
            if(itr.second.size() == 2){
                int sum = itr.second.top();
                itr.second.pop();
                sum += itr.second.top();
                if(sum > maxSum) {
                    maxSum = sum;
                }
            }
        }

        return maxSum;
    }
};
