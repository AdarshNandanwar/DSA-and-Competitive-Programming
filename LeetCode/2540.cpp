// https://leetcode.com/problems/minimum-common-value/

// Method 1 (2 Pointer, O(n+m) time, O(1) space):

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int p1 = 0, p2 = 0;
        while(p1<n1 and p2<n2){
            while(p1<n1 and nums1[p1] < nums2[p2]){
                p1++;
            }
            while(p2<n2 and nums1[p1] > nums2[p2]){
                p2++;
            }
            if(p1<n1 and p2<n2 and nums1[p1] == nums2[p2]){
                return nums1[p1];
            }
        }
        return -1;
    }
};

// Method 2 (Binary Search, O(nlogm) time, O(1) space):

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        for(int i=0; i<n1; i++){
            // FT First T
            int lo = 0, hi = n2-1;
            while(lo<hi){
                int mid = lo + (hi-lo)/2;
                if(nums1[i] <= nums2[mid]){
                    hi = mid;
                } else {
                    lo = mid+1;
                }
            }
            if(nums1[i] == nums2[lo]){
                return nums2[lo];
            }
        }
        return -1;
    }
};