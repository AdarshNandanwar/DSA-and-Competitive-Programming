// https://leetcode.com/problems/3sum/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i<n; i++){
            if(i>0 and nums[i]==nums[i-1]) continue;
            int p1 = i+1, p2 = n-1, target = -nums[i];
            while(p1<p2){
                if(nums[p1] + nums[p2] == target){
                    ans.push_back(vector<int>({nums[i], nums[p1], nums[p2]}));
                    p1++;
                    while(p1<n and nums[p1]==nums[p1-1]) p1++;
                }else if(nums[p1] + nums[p2] < target){
                    p1++;
                }else {
                    p2--;
                }
            }
        }
        return ans;
    }
};