// https://leetcode.com/problems/sort-colors/

// Method 1 (3 pointers, O(n) time, O(1) space):

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int p1 = 0, p2 = 0, p3 = n-1;
        while(p2 <= p3){
            if(nums[p2] == 0){
                if(p1 != p2){
                    swap(nums[p1], nums[p2]);
                }
                p1++;
                p2++;
            } else if (nums[p2] == 2){
                swap(nums[p2], nums[p3]);
                p3--;
            } else {
                p2++;
            }
        }
    }
};

// Alternate Code:

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int lo = 0, hi = nums.size()-1, p = 0;
        while(p <= hi){
            if(nums[p] == 0) swap(nums[p++], nums[lo++]);
            else if(nums[p] == 2) swap(nums[p], nums[hi--]);
            else p++;
        }
    }
};

// Method 2 (Counting Sort, O(n) time, O(1) space):

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int * freq = new int[3]();
        for(auto i:nums){
            freq[i]++;
        }
        nums.clear();
        for(int i = 0; i<3; i++){
            while(freq[i]--){
                nums.push_back(i);
            }
        }
    }
};