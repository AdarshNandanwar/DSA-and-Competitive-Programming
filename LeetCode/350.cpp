// https://leetcode.com/problems/intersection-of-two-arrays-ii/

// Method 1 (Hashing, O(n)):

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