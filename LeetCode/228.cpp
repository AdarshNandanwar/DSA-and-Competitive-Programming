// https://leetcode.com/problems/summary-ranges/

// Method 1 (O(n)):

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int start = 0, n = nums.size();
        if(n == 0){
            return {};
        }
        
        vector<string> ans;
        for(int i=1; i<n; i++){
            if(nums[i] == nums[i-1]+1){
                continue;
            }
            
            string range = "";
            if(start == i-1){
                range = to_string(nums[start]);
            } else {
                range = to_string(nums[start])+"->"+to_string(nums[i-1]);
            }
            ans.push_back(range);
            start = i;
        }
        
        string range = "";
        if(start == n-1){
            range = to_string(nums[start]);
        } else {
            range = to_string(nums[start])+"->"+to_string(nums[n-1]);
        }
        ans.push_back(range);
        
        return ans;
    }
};