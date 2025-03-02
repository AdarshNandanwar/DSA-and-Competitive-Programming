// https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/

// Method 1 (Loops, O(n+m)):

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int p1 = 0, p2 = 0;
        vector<vector<int>> res;
        while(p1 < n1 and p2 < n2){
            if(nums1[p1][0] == nums2[p2][0]){
                res.push_back({nums1[p1][0], nums1[p1][1]+nums2[p2][1]});
                p1++;
                p2++;
            } else if(nums1[p1][0] < nums2[p2][0]){
                res.push_back(nums1[p1]);
                p1++;
            } else if(nums1[p1][0] > nums2[p2][0]){
                res.push_back(nums2[p2]);
                p2++;
            }
        }
        while(p1 < n1){
            res.push_back(nums1[p1]);
            p1++;
        }
        while(p2 < n2){
            res.push_back(nums2[p2]);
            p2++;
        }
        return res;
    }
};
