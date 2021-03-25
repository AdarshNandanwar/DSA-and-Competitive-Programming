// https://leetcode.com/problems/majority-element/

// Method 1 (Boyer–Moore majority vote algorithm, O(n) time, O(1) space):

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        // Boyer–Moore majority vote algorithm

        // See https://leetcode.com/problems/majority-element-ii/ too

        int n = nums.size();
        if(n == 1) return nums[0];
        
        int num = nums[0], count = 0;
        for(auto i:nums){
            if(i == num){
                count++;
            } else if(count == 0){
                num = i;
                count++;
            } else {
                count--;
            } 
        }
        
        // not exists check:
        // count = 0;
        // for(auto i:nums) count += (i == num);
        // return count > n/2 ? num : -1;
        
        return num;
    }
};

// Method 2 (Hash Table, O(n) time, O(n) space):

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> m;
        for(auto i:nums){
            m[i]++;
            if(m[i] > n/2) return i;
        }
        return -1;
    }
};