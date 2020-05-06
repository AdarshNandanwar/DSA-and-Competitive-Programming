class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closest_sum = INT_MAX, min_diff = INT_MAX;
        for(int i = 0; i<nums.size(); i++){
            int new_target = target-nums[i];
            int p1 = i+1, p2 = nums.size()-1;
            while(p1<p2){
                if(abs(nums[p1]+nums[p2] - new_target) < min_diff){
                    min_diff = abs(nums[p1]+nums[p2] - new_target);
                    closest_sum = nums[i] + nums[p1] + nums[p2];
                }
                if(nums[p1]+nums[p2] > new_target){
                    p2--;
                } else {
                    p1++;
                }
            }
        }
        return closest_sum;
    }
};