// https://leetcode.com/problems/longest-consecutive-sequence/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(auto i:nums) s.insert(i);
        int res = 0, lo, hi;
        for(auto i:nums){
            if(s.count(i)){
                lo = i-1; hi = i+1;
                s.erase(i);
                while(s.count(hi)) s.erase(hi++);
                while(s.count(lo)) s.erase(lo--);
                res = max(res, hi-lo-1);
            }
        }
        return res;
    }
};