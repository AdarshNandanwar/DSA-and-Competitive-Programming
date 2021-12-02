// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/

// Method 1 (Encoding, O(n) time, O(1) space):

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        for(int i=0; i<nums.size(); i++){
            nums[abs(nums[i])-1] = -abs(nums[abs(nums[i])-1]);
        }
        for(int i=0; i<nums.size(); i++){
            if(nums[i] > 0) res.push_back(i+1);
        }
        return res;
    }
};

// Method 2 (Hash Set, O(n) time, O(n) space)

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        unordered_set<int> s;
        for(auto &i:nums) s.insert(i);
        for(int i = 1; i<=nums.size(); i++){
            if(!s.count(i)) res.push_back(i);
        }
        return res;
    }
};