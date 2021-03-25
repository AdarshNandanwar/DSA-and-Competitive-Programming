// https://leetcode.com/problems/contiguous-array/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> f;
        f.push_back(0);
        for(int i=0; i<n; i++){
            if(nums[i]) 
                f.push_back(f.back()+1);
            else 
                f.push_back(f.back()-1);
        }
        
        int ans = 0;
        unordered_map<int, int> minMap;
        for(int i = 0; i<=n; i++){
            if(minMap.find(f[i]) == minMap.end())
                minMap[f[i]] = i;
            else
                ans = max(ans, i-minMap[f[i]]);
        }
        return ans;
    }
};