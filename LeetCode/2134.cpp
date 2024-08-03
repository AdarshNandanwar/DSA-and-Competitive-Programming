// https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/

// Method 1 (2 Pointers Slidig Window, O(n) time, O(1) space):

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int ones = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == 1){
                ones++;
            }
        }

        int start = 0, end = ones, onesInWindow = 0;
        for(int i=start; i<end; i++){
            if(nums[i] == 1){
                onesInWindow++;
            }
        }

        end = end % n; // for case where all elements are 1
        int ans = INT_MAX;
        while(start < n){
            int swaps = ones - onesInWindow;
            ans = min(ans, swaps);

            if(nums[start] == 1){
                onesInWindow--;
            }
            start++;

            if(nums[end] == 1){
                onesInWindow++;
            }
            end = (end + 1) % n;
        }

        return ans;
    }
};
