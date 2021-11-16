// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/

// Method 1 (Modified Binary Search, O(n)):

class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0, hi = nums.size()-1, mid;
        while(lo<hi){
            mid = lo+(hi-lo)/2;
            if(nums[mid] > nums[hi]){
                lo = mid+1;
            } else if(nums[lo] > nums[mid]){
                hi = mid;
                lo++;
            } else {
                hi--;
            }
        }
        return nums[lo];
    }
};

// Method 2 (Binary Search, O(n)):

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        // FT First T
        int lo = 0, hi = n-1, mid;
        while(hi>=0 and nums[hi] == nums[0]) hi--;
        while(lo<hi){
            mid = lo+(hi-lo)/2;
            if(nums[mid] < nums[0]){
                hi = mid;
            } else {
                lo = mid+1;
            }
        }
        if(nums[lo] < nums[0]) return nums[lo];
        else return nums[0];
    }
};

// Method 3 (STL, O(n)):

class Solution {
public:
    int findMin(vector<int>& nums) {
        return *min_element(nums.begin(), nums.end());
    }
};

// Method 4 (Brute Force, O(n)):

class Solution {
public:
    int findMin(vector<int>& nums) {
        for(auto i:nums) if(i<nums[0]) return i;
        return nums[0];
    }
};