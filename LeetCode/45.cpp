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