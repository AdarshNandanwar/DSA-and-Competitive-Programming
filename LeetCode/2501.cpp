// https://leetcode.com/problems/longest-square-streak-in-an-array/

// Method 1 (Hash Map + Sorting, O(nlogn) time, O(n) space):

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        unordered_map<long, int> streak;
        int longestStreak = -1;
        for(int i=n-1; i>=0; i--){
            if(streak.count(nums[i])){
                continue;
            }
            
            long square = (long)nums[i]*nums[i];
            if(streak.count(square)){
                streak[nums[i]] = streak[square] + 1;
                longestStreak = max(longestStreak, streak[nums[i]]);
            } else {
                streak[nums[i]] = 1;
            }
        }
        return longestStreak;
    }
};
