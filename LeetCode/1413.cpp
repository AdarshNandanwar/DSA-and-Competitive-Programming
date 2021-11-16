// https://leetcode.com/problems/minimum-value-to-get-positive-step-by-step-sum/

class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int min_running_sum = 0, running_sum = 0;
        for(auto &i:nums){
            running_sum += i;
            min_running_sum = min(min_running_sum, running_sum);
        }
        return 1-min_running_sum;
    }
};