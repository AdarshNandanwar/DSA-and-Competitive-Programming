// https://leetcode.com/problems/intersection-of-two-arrays-ii/

// Method 1 (Hashing, O(n) time, O(n) space):

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        vector<int> freq(1001, 0);
        for(auto &i:nums1) freq[i]++;
        for(auto &i:nums2){
            if(freq[i]){
                res.push_back(i);
                freq[i]--;
            }
        }
        return res;
    }
};

// Method 2 (Sorting, 2 Pointers, O(nlogn) time, O(1) space):

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int p1 = 0, p2 = 0;
        int n1 = nums1.size(), n2 = nums2.size();
        while(p1 < n1 and p2 < n2){
            if(nums1[p1] == nums2[p2]){
                res.push_back(nums1[p1]);
                p1++;
                p2++;
            } else if(nums1[p1] < nums2[p2]){
                p1++;
            } else {
                p2++;
            }
        }
        return res;
    }
};
