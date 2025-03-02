// https://leetcode.com/problems/3sum/

// Method 1 (2 Pointer + avoid duplicates, O(n2)):

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<vector<int>> triplets;
        int p1 = 0;
        while(p1<n){
            int p2 = p1+1, p3 = n-1;
            while(p2 < p3){
                if(nums[p2] + nums[p3] == -nums[p1]){
                    triplets.push_back({nums[p1], nums[p2], nums[p3]});
                    p2++;
                    while(p2 < p3 and nums[p2] == nums[p2-1]){
                        p2++;
                    }
                } else if(nums[p2] + nums[p3] < -nums[p1]){
                    p2++;
                    while(p2 < p3 and nums[p2] == nums[p2-1]){
                        p2++;
                    }
                } else if(nums[p2] + nums[p3] > -nums[p1]){
                    p3--;
                    while(p2 < p3 and nums[p3] == nums[p3+1]){
                        p3--;
                    }
                }
            }

            p1++;
            while(p1<n and nums[p1-1]==nums[p1]){
                p1++;
            }
        }

        return triplets;
    }
};
