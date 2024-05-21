// https://leetcode.com/problems/intersection-of-two-arrays/

// Method 1 (Hash set, O(n) time, O(n) space):

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_set<int> s1, s2;
        for(auto i:nums1) s1.insert(i);
        for(auto i:nums2) s2.insert(i);
        for(auto i:s1) if(s2.count(i)) res.push_back(i);
        return res;
    }
};

// Method 2 (2 pointers, O(nlogn) time):

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int n1 = nums1.size(), n2 = nums2.size();
        int i = 0, j = 0;
        vector<int> ans;
        while(i<n1 and j<n2){
            while(i<n1 and nums1[i] < nums2[j]){
                i++;
            }
            while(j<n2 and nums1[i] > nums2[j]){
                j++;
            }
            while(i<n1 and j<n2 and nums1[i] == nums2[j]){
                if(ans.size() == 0 or ans.back()!=nums1[i]){
                    ans.push_back(nums1[i]);
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};

// Alternate Code:

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int n1 = nums1.size(), n2 = nums2.size();
        int p1 = 0, p2 = 0;
        vector<int> res;
        while(p1 < n1 and p2 < n2){
            while(p1<n1 and nums1[p1] < nums2[p2]){
                p1++;
            }
            while(p2<n2 and nums1[p1] > nums2[p2]){
                p2++;
            }
            if(p1<n1 and p2<n2 and nums1[p1] == nums2[p2]){
                res.push_back(nums1[p1]);
                int cur = nums1[p1];
                while(p1<n1 and nums1[p1] == cur){
                    p1++;
                }
            }
        }
        return res;
    }
};