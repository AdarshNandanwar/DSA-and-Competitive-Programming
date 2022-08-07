// https://leetcode.com/problems/contains-duplicate/

// Method 1 (Hash map, O(n))

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        return unordered_set<int>(nums.begin(), nums.end()).size() < nums.size();
    }
};