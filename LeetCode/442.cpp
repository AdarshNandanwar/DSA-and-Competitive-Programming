// https://leetcode.com/problems/find-all-duplicates-in-an-array/

// Method 1 (number encoding, negative sign, O(n) time, O(1) space):

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for(int i = 0; i<nums.size(); i++){
            if(nums[abs(nums[i])-1] < 0) ans.push_back(abs(nums[i]));
            else nums[abs(nums[i])-1] *= -1;
        }
        return ans;        
    }
};

// Method 2 (Swapping, O(n) time, O(ans.length()) space):

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_set<int> s;
        for(int i = 0; i<nums.size(); i++){
            while(nums[i] != nums[nums[i]-1]) swap(nums[i], nums[nums[i]-1]);
            if(nums[i]-1 != i) s.insert(nums[i]);
        }
        return vector<int>(s.begin(), s.end());        
    }
};