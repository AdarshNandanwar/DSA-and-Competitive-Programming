// https://leetcode.com/problems/jump-game/

// Method 1 (implicit BFS, O(n)):

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cur_range = 0, next_range = 0, pos = 0;
        while(next_range < nums.size()-1){
            while(pos <= cur_range){
                next_range = max(next_range, pos+nums[pos]);
                pos++;
            }
            if(next_range >= nums.size()-1) return 1;
            if(cur_range == next_range) return 0;
            cur_range = next_range;
        }
        return 1;
    }
};