// https://leetcode.com/problems/merge-sorted-array/

// Method 1 (3 pointer, O(n)):

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m-1, p2 = n-1;
        for(int i=m+n-1; i>=0; i--){
            if(p1 < 0){
                nums1[i] = nums2[p2];
                p2--;
            } else if(p2 < 0){
                nums1[i] = nums1[p1];
                p1--;
            } else if(nums1[p1] < nums2[p2]){
                nums1[i] = nums2[p2];
                p2--;
            } else {
                nums1[i] = nums1[p1];
                p1--;
            }
        }
    }
};

// Method 2 (3 pointer, O(n)):

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=m-1; i>=0; i--) nums1[n+i] = nums1[i];
        int p1 = n, p2 = 0, pCombined = 0;
        while(p1<m+n and p2<n){
            if(nums1[p1] <= nums2[p2]){
                nums1[pCombined++] = nums1[p1++];
            } else {
                nums1[pCombined++] = nums2[p2++];
            }
        }
        while(p1<m+n){
            nums1[pCombined++] = nums1[p1++];
        }
        while(p2<n){
            nums1[pCombined++] = nums2[p2++];
        }
        return;
    }
};