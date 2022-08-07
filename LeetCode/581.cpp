// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

// Method 1 (Prefix max, Suffix min, O(n)):

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxLeft = INT_MIN, rightmostFalse = -1;
        for(int i=0; i<n; i++){
            if(nums[i] >= maxLeft){
                maxLeft = nums[i];
            } else {
                rightmostFalse = i;
            }
        }
        int minRight = INT_MAX, leftmostFalse = n;
        for(int i=n-1; i>=0; i--){
            if(nums[i] <= minRight){
                minRight = nums[i];
            } else {
                leftmostFalse = i;
            }
        }
        int len = rightmostFalse-leftmostFalse+1;
        return len>=0 ? len : 0;
    }
};

// Method 2 (Sorting, O(nlofn)):

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sortedNums(nums);
        sort(sortedNums.begin(), sortedNums.end());
        int left = 0, right = nums.size()-1;
        while(left <= right){
            if(nums[left] != sortedNums[left]){
                break;
            }
            left++;
        }
        while(left <= right){
            if(nums[right] != sortedNums[right]){
                break;
            }
            right--;
        }
        return left<=right ? right-left+1 : 0;
    }
};