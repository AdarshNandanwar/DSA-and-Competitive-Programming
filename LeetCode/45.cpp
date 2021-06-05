// https://leetcode.com/problems/jump-game-ii/

// Method (Implicit BFS, O(n)):

class Solution {
public:
    
    int jump(vector<int>& nums) {
        
        // implicit BFS
        
        int n = nums.size();
        if(n == 0) return 0;
        int count = 0, curEnd = 0, maxChildEnd = 0;
        for(int i = 0; i<n-1; i++){
            // calculating the max range of that the next child/spot can offer
            maxChildEnd = max(maxChildEnd, i+nums[i]);
            if(i == curEnd){
                // going to the next child/spot which offers the max End
                curEnd = maxChildEnd;
                count++;
            }
        }
        return count;
    }
};

// Alternate Code

class Solution {
public:
    int jump(vector<int>& nums) {
        int max_range = 0, cur_range = 0, n = nums.size(), pos = 0, hops = 0;
        while(cur_range < n-1){
            if(pos > cur_range){
                if(max_range == cur_range) return -1;
                cur_range = max_range;
                hops++;
            }
            max_range = max(max_range, pos+nums[pos]);
            pos++;
        }
        return hops;
    }
};