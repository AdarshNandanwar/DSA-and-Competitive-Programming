// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/

// Method 1 (Binary Search, O(nlog(max))):

class Solution {
    bool predicate(const vector<int> & bloomDay, int day, int m, int k){
        int bouquets = 0, streak = 0;
        for(int i=0; i<bloomDay.size(); i++){
            if(day >= bloomDay[i]){
                streak++;
            } else {
                streak = 0;
            }
            if(streak == k){
                streak = 0;
                bouquets++;
            }
            if(bouquets >= m){
                return true;
            }
        }
        return false;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        // FT First T
        int lo = 1, hi = *max_element(bloomDay.begin(), bloomDay.end());
        while(lo<hi){
            int mid = lo + (hi-lo)/2;
            if(predicate(bloomDay, mid, m, k)){
                hi = mid;
            } else {
                lo = mid+1;
            }
        }
        if(predicate(bloomDay, lo, m, k)){
            return lo;
        }
        return -1;
    }
};
