// https://leetcode.com/problems/contains-duplicate-ii/

// Method 1 (Hash map, O(n)):

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> s;
        for(auto i=0; i<nums.size(); i++){
            if(i-k-1>=0) s.erase(nums[i-k-1]);
            if(s.count(nums[i])) return true;
            s.insert(nums[i]);
        }
        return false;
    }
};